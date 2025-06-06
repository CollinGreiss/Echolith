// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitData.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitSerializationHelpers.h"
#include "MRUtilityKitTelemetry.h"
#include "OculusXRAnchorBPFunctionLibrary.h"
#include "OculusXRScene.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "GameFramework/WorldSettings.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

AMRUKLocalizer::AMRUKLocalizer()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AMRUKLocalizer::Tick(float DeltaTime)
{
	for (int i = 0; i < AnchorsData.Num(); ++i)
	{
		const auto Query = AnchorsData[i];
		if (UOculusXRAnchorBPFunctionLibrary::GetAnchorTransformByHandle(Query->SpaceQuery.Space, Query->Transform))
		{
			Query->NeedAnchorLocalization = false;
			if (Query->SemanticClassifications.IsEmpty())
			{
				UE_LOG(LogMRUK, Log, TEXT("Localized anchor %s"), *Query->SpaceQuery.UUID.ToString());
			}
			else
			{
				UE_LOG(LogMRUK, Log, TEXT("Localized anchor %s - %s"), *Query->SpaceQuery.UUID.ToString(), *Query->SemanticClassifications[0]);
			}
			AnchorsData.RemoveAt(i);
			--i;
		}
	}

	if (AnchorsData.IsEmpty())
	{
		UE_LOG(LogMRUK, Log, TEXT("All anchors localized"));
		OnComplete.Broadcast(true);
	}
}

void UMRUKAnchorData::LoadFromDevice(const FOculusXRAnchorsDiscoverResult& AnchorsDiscoverResult)
{
	SpaceQuery = AnchorsDiscoverResult;

	Transform = FTransform::Identity;
	NeedAnchorLocalization = false;
	if (!UOculusXRAnchorBPFunctionLibrary::GetAnchorTransformByHandle(SpaceQuery.Space, Transform))
	{
		UE_LOG(LogMRUK, Log, TEXT("Anchor %s is not localized yet. Localize it async."), *SpaceQuery.UUID.ToString());
		NeedAnchorLocalization = true;
	}

	EOculusXRAnchorResult::Type Result = OculusXRScene::FOculusXRScene::GetSemanticClassification(SpaceQuery.Space.Value, SemanticClassifications);
	if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(Result))
	{
		UE_LOG(LogMRUK, Error, TEXT("Failed to get semantic classification space for %s."), *SpaceQuery.UUID.ToString());
	}

	const UWorld* World = GetWorld();
	const float WorldToMeters = World ? World->GetWorldSettings()->WorldToMeters : 100.0;

	FVector ScenePlanePos;
	FVector ScenePlaneSize;
	Result = OculusXRScene::FOculusXRScene::GetScenePlane(SpaceQuery.Space, ScenePlanePos, ScenePlaneSize);
	if (UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(Result))
	{
		const FVector2D PlanePos = FVector2D(ScenePlanePos.Y, ScenePlanePos.Z) * WorldToMeters;
		const FVector2D PlaneSize = FVector2D(ScenePlaneSize.Y, ScenePlaneSize.Z) * WorldToMeters;
		PlaneBounds = FBox2D(PlanePos, PlanePos + PlaneSize);
		TArray<FVector2f> SpaceBoundary2D;
		Result = OculusXRScene::FOculusXRScene::GetBoundary2D(SpaceQuery.Space, SpaceBoundary2D);
		if (UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(Result))
		{
			PlaneBoundary2D.Reserve(SpaceBoundary2D.Num());
			for (int i = 0; i < SpaceBoundary2D.Num(); ++i)
			{
				PlaneBoundary2D.Push(FVector2D(SpaceBoundary2D[i].X * WorldToMeters, SpaceBoundary2D[i].Y * WorldToMeters));
			}
		}
	}

	FVector SceneVolumePos;
	FVector SceneVolumeSize;
	Result = OculusXRScene::FOculusXRScene::GetSceneVolume(SpaceQuery.Space, SceneVolumePos, SceneVolumeSize);
	if (UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(Result))
	{
		const FVector VolumePos = SceneVolumePos * WorldToMeters;
		const FVector VolumeSize = SceneVolumeSize * WorldToMeters;
		VolumeBounds = FBox(VolumePos, VolumePos + VolumeSize);
	}
}

void UMRUKAnchorData::LoadFromJson(const FJsonValue& Value)
{
	const auto Object = Value.AsObject();
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("UUID")), SpaceQuery.UUID);
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("SemanticClassifications")), SemanticClassifications);
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Transform")), Transform);
	if (const auto JsonValue = Object->TryGetField(TEXT("PlaneBounds")))
	{
		MRUKDeserialize(*JsonValue, PlaneBounds);
	}
	if (const auto JsonValue = Object->TryGetField(TEXT("PlaneBoundary2D")))
	{
		MRUKDeserialize(*JsonValue, PlaneBoundary2D);
	}
	if (const auto JsonValue = Object->TryGetField(TEXT("VolumeBounds")))
	{
		MRUKDeserialize(*JsonValue, VolumeBounds);
	}
	NeedAnchorLocalization = false;
}

void UMRUKRoomData::LoadFromDevice(UMRUKSceneData* Data, const FOculusXRAnchorsDiscoverResult& AnchorsDiscoverResult)
{
	SceneData = Data;

	SpaceQuery = AnchorsDiscoverResult;

	const auto Subsystem = GetWorld()->GetGameInstance()->GetSubsystem<UMRUKSubsystem>();

	if (!Subsystem->GetRoomLayoutManager()->GetRoomLayout(SpaceQuery.Space.Value, RoomLayout))
	{
		UE_LOG(LogMRUK, Error, TEXT("Could not query room layout"));
		FinishQuery(false);
		return;
	}

	EOculusXRAnchorResult::Type Result{};

	const auto Filter = NewObject<UOculusXRSpaceDiscoveryIdsFilter>(this);
	Filter->Uuids = RoomLayout.RoomObjectUUIDs;
	FOculusXRSpaceDiscoveryInfo DiscoveryInfo{};
	DiscoveryInfo.Filters.Push(Filter);

	OculusXRAnchors::FOculusXRAnchors::DiscoverAnchors(DiscoveryInfo, FOculusXRDiscoverAnchorsResultsDelegate::CreateUObject(this, &UMRUKRoomData::RoomDataLoadedIncrementalResults), FOculusXRDiscoverAnchorsCompleteDelegate::CreateUObject(this, &UMRUKRoomData::RoomDataLoadedComplete), Result);
	if (Result != EOculusXRAnchorResult::Success)
	{
		UE_LOG(LogMRUK, Error, TEXT("Failed to discover anchors"));
		FinishQuery(false);
	}
}

void UMRUKRoomData::LoadFromJson(UMRUKSceneData* Data, const FJsonValue& Value)
{
	SceneData = Data;

	const auto Object = Value.AsObject();
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("UUID")), SpaceQuery.UUID);
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("RoomLayout")), RoomLayout);
	auto AnchorsJson = Object->GetArrayField(TEXT("Anchors"));
	for (const auto& AnchorJson : AnchorsJson)
	{
		auto AnchorQuery = NewObject<UMRUKAnchorData>(this);
		AnchorsData.Push(AnchorQuery);
		RoomLayout.RoomObjectUUIDs.Add(AnchorQuery->SpaceQuery.UUID);
		AnchorQuery->LoadFromJson(*AnchorJson);
	}
	FinishQuery(true);
}

void UMRUKRoomData::FinishQuery(bool Success)
{
	OnComplete.Broadcast(Success);
}

void UMRUKRoomData::RoomDataLoadedComplete(EOculusXRAnchorResult::Type Result)
{
	if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(Result))
	{
		UE_LOG(LogMRUK, Error, TEXT("Discovering room data failed"));
		FinishQuery(false);
		return;
	}

	if (AnchorsData.Num() == 0)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Discovered room which doesn't contain any anchors. Skip that room"));
		SceneData->RoomsData.Remove(this);
		AnchorsInitialized(true);
		return;
	}

	TArray<UMRUKAnchorData*> AnchorQueriesLocalization;

	for (auto& AnchorQuery : AnchorsData)
	{
		if (AnchorQuery->NeedAnchorLocalization)
		{
			AnchorQueriesLocalization.Push(AnchorQuery);
		}
	}

	if (!AnchorQueriesLocalization.IsEmpty())
	{
		UE_LOG(LogMRUK, Log, TEXT("Could not localize all anchors. Going to localize them async"));
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		LocalizationActor = GetWorld()->SpawnActor<AMRUKLocalizer>(ActorSpawnParams);
		LocalizationActor->AnchorsData = AnchorQueriesLocalization;
		LocalizationActor->OnComplete.AddDynamic(this, &UMRUKRoomData::AnchorsInitialized);
	}
	else
	{
		AnchorsInitialized(true);
	}
}

void UMRUKRoomData::RoomDataLoadedIncrementalResults(const TArray<FOculusXRAnchorsDiscoverResult>& DiscoverResults)
{
	// NOTE: This function may be called multiple times in batches. E.g. if there are 18 anchors in a room, this may
	// be called once with 10 anchors and a second time with 8 anchors in DiscoverResults.
	UE_LOG(LogMRUK, Log, TEXT("Received %d anchors from device"), DiscoverResults.Num());

	for (auto& DiscoverResult : DiscoverResults)
	{
		auto AnchorQuery = NewObject<UMRUKAnchorData>(this);
		AnchorQuery->LoadFromDevice(DiscoverResult);
		AnchorsData.Push(AnchorQuery);
	}
}

void UMRUKRoomData::AnchorsInitialized(bool Success)
{
	UE_LOG(LogMRUK, Log, TEXT("Anchors data initialized Success==%d"), Success);
	if (IsValid(LocalizationActor))
	{
		LocalizationActor->Destroy();
		LocalizationActor = nullptr;
	}
	FinishQuery(Success);
}

void UMRUKSceneData::LoadFromDevice()
{
	NumRoomsLeftToInitialize = 0;

	EOculusXRAnchorResult::Type Result{};

	const auto Filter = NewObject<UOculusXRSpaceDiscoveryComponentsFilter>(this);
	Filter->ComponentType = EOculusXRSpaceComponentType::RoomLayout;
	FOculusXRSpaceDiscoveryInfo DiscoveryInfo{};
	DiscoveryInfo.Filters.Push(Filter);

	OculusXRAnchors::FOculusXRAnchors::DiscoverAnchors(DiscoveryInfo, FOculusXRDiscoverAnchorsResultsDelegate::CreateUObject(this, &UMRUKSceneData::SceneDataLoadedComplete), FOculusXRDiscoverAnchorsCompleteDelegate::CreateUObject(this, &UMRUKSceneData::SceneDataLoadedResult), Result);
	if (Result != EOculusXRAnchorResult::Success)
	{
		UE_LOG(LogMRUK, Error, TEXT("Failed to discover room layouts"));
		FinishQuery(false);
	}
}


void UMRUKSceneData::LoadFromJson(const FString& Json)
{
	TSharedPtr<FJsonValue> Value;
	const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Json);
	if (!FJsonSerializer::Deserialize(JsonReader, Value))
	{
		UE_LOG(LogMRUK, Warning, TEXT("Could not deserialize JSON scene data: %s"), *JsonReader->GetErrorMessage());
		FinishQuery(false);
		return;
	}

	const auto Object = Value->AsObject();
	auto RoomsJson = Object->GetArrayField(TEXT("Rooms"));

#if WITH_EDITOR
	OculusXRTelemetry::TScopedMarker<MRUKTelemetry::FLoadSceneFromJsonMarker> Event;
	Event.AddAnnotation("NumRooms", TCHAR_TO_ANSI(*FString::FromInt(RoomsJson.Num())));
	Event.SetResult(RoomsJson.Num() > 0 ? OculusXRTelemetry::EAction::Success : OculusXRTelemetry::EAction::Fail);
#endif

	if (RoomsJson.IsEmpty())
	{
		UE_LOG(LogMRUK, Warning, TEXT("Could not find Rooms in JSON"));
		FinishQuery(false);
		return;
	}
	NumRoomsLeftToInitialize = RoomsJson.Num();
	UE_LOG(LogMRUK, Log, TEXT("Found %d rooms in JSON"), NumRoomsLeftToInitialize);
	for (const auto& RoomJson : RoomsJson)
	{
		auto RoomQuery = NewObject<UMRUKRoomData>(this);
		RoomsData.Push(RoomQuery);
		RoomQuery->OnComplete.AddDynamic(this, &UMRUKSceneData::RoomQueryComplete);
		RoomQuery->LoadFromJson(this, *RoomJson);
	}
}

void UMRUKSceneData::FinishQuery(bool Success)
{
	if (!Success)
	{
		AnyRoomFailed = true;
	}
	--NumRoomsLeftToInitialize;
	if (NumRoomsLeftToInitialize <= 0)
	{
		OnComplete.Broadcast(!AnyRoomFailed);
	}
}

void UMRUKSceneData::SceneDataLoadedResult(EOculusXRAnchorResult::Type Result)
{
	if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(Result) || RoomsData.IsEmpty())
	{
		UE_LOG(LogMRUK, Error, TEXT("Discovering room layouts failed"));
		FinishQuery(false);
	}
}

void UMRUKSceneData::SceneDataLoadedComplete(const TArray<FOculusXRAnchorsDiscoverResult>& DiscoverResults)
{
	NumRoomsLeftToInitialize = DiscoverResults.Num();
	UE_LOG(LogMRUK, Log, TEXT("Found on %d rooms on the device"), NumRoomsLeftToInitialize);

#if WITH_EDITOR
	OculusXRTelemetry::TScopedMarker<MRUKTelemetry::FLoadSceneFromDeviceMarker> Event;
	Event.AddAnnotation("NumRooms", TCHAR_TO_ANSI(*FString::FromInt(DiscoverResults.Num())));
	Event.SetResult(DiscoverResults.Num() > 0 ? OculusXRTelemetry::EAction::Success : OculusXRTelemetry::EAction::Fail);
#endif

	if (NumRoomsLeftToInitialize == 0)
	{
		UE_LOG(LogMRUK, Error, TEXT("No room layouts discovered"));
		FinishQuery(false);
		return;
	}

	for (auto& DiscoverResult : DiscoverResults)
	{
		auto RoomQuery = NewObject<UMRUKRoomData>(this);
		RoomsData.Push(RoomQuery);
		RoomQuery->OnComplete.AddDynamic(this, &UMRUKSceneData::RoomQueryComplete);
		RoomQuery->LoadFromDevice(this, DiscoverResult);
	}
}

void UMRUKSceneData::RoomQueryComplete(bool Success)
{
	if (!Success)
	{
		AnyRoomFailed = true;
	}
	--NumRoomsLeftToInitialize;
	if (NumRoomsLeftToInitialize == 0)
	{
		FinishQuery(!AnyRoomFailed);
	}
}
