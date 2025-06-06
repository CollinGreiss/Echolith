// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRControllerLegacyPoseTransformComponent.h"
#include "OpenXR/OculusXROpenXRUtilities.h"

UOculusXRControllerLegacyPoseTransformComponent::UOculusXRControllerLegacyPoseTransformComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UOculusXRControllerLegacyPoseTransformComponent::BeginPlay()
{
	Super::BeginPlay();

	USceneComponent* AttachedParentPtr = GetAttachParent();
	if (OculusXR::IsOpenXRSystem() && AttachedParentPtr != nullptr)
	{
		AttachedParentPtr->AddLocalTransform(FTransform(OculusPoseToGripRotation, OculusPoseToGripPosition * GetWorld()->GetWorldSettings()->WorldToMeters).Inverse());
	}
}
