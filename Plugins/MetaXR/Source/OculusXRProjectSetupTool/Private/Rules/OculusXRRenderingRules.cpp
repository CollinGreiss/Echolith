// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRRenderingRules.h"
#include "CoreMinimal.h"
#include "AndroidRuntimeSettings.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "EngineUtils.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRPSTUtils.h"
#include "OculusXRRuleProcessorSubsystem.h"
#include "Engine/PostProcessVolume.h"
#include "Engine/RendererSettings.h"
#include "Misc/EngineVersionComparison.h"
#include "Editor.h"
#include "Kismet/KismetSystemLibrary.h"

namespace OculusXRRenderingRules
{
	namespace
	{
		FPreviewPlatformInfo GetAndroidPreviewPlatformInfo()
		{
			const FName AndroidPlatformName(TEXT("AndroidVulkan_Preview"));

			const EShaderPlatform ShaderPlatform = FDataDrivenShaderPlatformInfo::GetShaderPlatformFromName(AndroidPlatformName);

			const ERHIFeatureLevel::Type FeatureLevel = GetMaxSupportedFeatureLevel(ShaderPlatform);

			const auto& AllPreviewPlatforms = FDataDrivenPlatformInfoRegistry::GetAllPreviewPlatformMenuItems();

			for (const auto& Platform : AllPreviewPlatforms)
			{
				if (Platform.PreviewShaderPlatformName == AndroidPlatformName)
				{
					return FPreviewPlatformInfo(FeatureLevel, ShaderPlatform, Platform.PlatformName, Platform.ShaderFormat, Platform.DeviceProfileName,
						true, Platform.PreviewShaderPlatformName);
				}
			}

			return {};
		}
	} // namespace
	bool FUseVulkanRule::IsApplied() const
	{
		const UAndroidRuntimeSettings* Settings = GetMutableDefault<UAndroidRuntimeSettings>();

		return Settings->bSupportsVulkan && !Settings->bBuildForES31;
	}

	void FUseVulkanRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bSupportsVulkan, true);
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bBuildForES31, false);
		OutShouldRestartEditor = false;
	}

	bool FUseHalfPrecisionFloatRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();

		return Settings->MobileFloatPrecisionMode == EMobileFloatPrecisionMode::Half;
	}

	void FUseHalfPrecisionFloatRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, MobileFloatPrecisionMode, EMobileFloatPrecisionMode::Half);
		OutShouldRestartEditor = true;
	}

	bool FEnableInstancedStereoRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();
		return Settings->bMultiView != 0;
	}

	void FEnableInstancedStereoRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMultiView, 1);
		OutShouldRestartEditor = true;
	}

	bool FEnableForwardShadingRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();

		return Settings->MobileShadingPath == EMobileShadingPath::Forward;
	}

	void FEnableForwardShadingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, MobileShadingPath, EMobileShadingPath::Forward);
		OutShouldRestartEditor = true;
	}

	bool FEnablePCForwardShadingRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();

		return Settings->bForwardShading;
	}

	void FEnablePCForwardShadingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bForwardShading, true);
		OutShouldRestartEditor = true;
	}

	bool FEnableMSAARule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();
		return Settings->MobileAntiAliasing == EMobileAntiAliasingMethod::MSAA
			&& Settings->MSAASampleCount == ECompositingSampleCount::Four;
	}

	void FEnableMSAARule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, MobileAntiAliasing, EMobileAntiAliasingMethod::MSAA);
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, MSAASampleCount, ECompositingSampleCount::Four);

		OutShouldRestartEditor = false;
	}

	FEnableOcclusionCullingRule::FEnableOcclusionCullingRule()
		: ISetupRule("Rendering_EnableOcclusionCulling",
			  NSLOCTEXT("OculusXRRenderingRules", "EnableOcclusionCulling_DisplayName", "Enable Occlusion Culling"),
			  NSLOCTEXT("OculusXRRenderingRules", "EnableOcclusionCulling_Description", "Occlusion culling can provide significant performance gains. Cannot be used with tonemap subpass enabled."),
			  ESetupRuleCategory::Rendering,
			  ESetupRuleSeverity::Performance,
			  MetaQuest_All) {}

	bool FEnableOcclusionCullingRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();
		return Settings->bOcclusionCulling;
	}

	bool FEnableOcclusionCullingRule::IsValid()
	{
		static auto* MobileTonemapSubpassPathCvar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.TonemapSubpass"));
		const bool isToneMapSubpassOn = (MobileTonemapSubpassPathCvar && (MobileTonemapSubpassPathCvar->GetValueOnAnyThread() == 1));
		return (!isToneMapSubpassOn);
	}

	void FEnableOcclusionCullingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bOcclusionCulling, 1);
		OutShouldRestartEditor = false;
	}

	FDisableOcculusionCullingRule::FDisableOcculusionCullingRule()
		: ISetupRule("Rendering_DisableOcclusionCulling",
			  NSLOCTEXT("OculusXRRenderingRules", "DisableOcclusionCulling_DisplayName", "Disable Occlusion Culling"),
			  NSLOCTEXT("OculusXRRenderingRules", "DisableOcclusionCulling_Description", "Occlusion culling cannot be used when tonemap subpass enabled."),
			  ESetupRuleCategory::Rendering,
			  ESetupRuleSeverity::Critical,
			  MetaQuest_All) {}

	bool FDisableOcculusionCullingRule::IsApplied() const
	{
		static auto* MobileTonemapSubpassPathCvar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.TonemapSubpass"));
		const bool isToneMapSubpassOn = (MobileTonemapSubpassPathCvar && (MobileTonemapSubpassPathCvar->GetValueOnAnyThread() == 1));

		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();

		const bool bothTurnedOn = (Settings->bOcclusionCulling == true) && (isToneMapSubpassOn == true);
		return !bothTurnedOn;
	}

	bool FDisableOcculusionCullingRule::IsValid()
	{
		static auto* MobileTonemapSubpassPathCvar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.TonemapSubpass"));
		const bool isToneMapSubpassOn = (MobileTonemapSubpassPathCvar && (MobileTonemapSubpassPathCvar->GetValueOnAnyThread() == 1));
		return isToneMapSubpassOn;
	}

	void FDisableOcculusionCullingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		if (IsValid())
		{
			OCULUSXR_UPDATE_SETTINGS(URendererSettings, bOcclusionCulling, 0);
			OutShouldRestartEditor = true;
		}
	}

	bool FEnableDynamicFoveationRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->bDynamicFoveatedRendering;
	}

	void FEnableDynamicFoveationRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, bDynamicFoveatedRendering, true);
		OutShouldRestartEditor = false;
	}

#ifdef WITH_OCULUS_BRANCH
	bool FEnableDynamicResolutionRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->bDynamicResolution;
	}

	void FEnableDynamicResolutionRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, bDynamicResolution, true);
		OutShouldRestartEditor = false;
	}

	bool FEnableMobileUniformLocalLightsRule::IsApplied() const
	{
		return GetMutableDefault<URendererSettings>()->bMobileUniformLocalLights;
	}

	void FEnableMobileUniformLocalLightsRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileUniformLocalLights, true);
		OutShouldRestartEditor = true;
	}

	bool FEnableEmulatedUniformBuffersRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();
		return Settings->bVulkanUseEmulatedUBs;
	}

	void FEnableEmulatedUniformBuffersRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bVulkanUseEmulatedUBs, true);
		OutShouldRestartEditor = true;
	}
#endif

	bool FDisableLensFlareRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();
		if (!Settings->bMobilePostProcessing)
		{
			return true;
		}

		for (TActorIterator<APostProcessVolume> ActorItr(GEditor->GetEditorWorldContext().World()); ActorItr; ++ActorItr)
		{
			if (ActorItr->Settings.bOverride_LensFlareIntensity && ActorItr->Settings.LensFlareIntensity > 0.0f)
			{
				return false;
			}
		}
		return Settings->bDefaultFeatureLensFlare == 0;
	}

	void FDisableLensFlareRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bDefaultFeatureLensFlare, false);

		UKismetSystemLibrary::BeginTransaction("ProjectSetupTool", NSLOCTEXT("OculusXRRenderingRules", "DisableLensFlare", "Disable Lens Flare"), nullptr);
		for (TActorIterator<APostProcessVolume> ActorItr(GEditor->GetEditorWorldContext().World()); ActorItr; ++ActorItr)
		{
			if (ActorItr->Settings.bOverride_LensFlareIntensity)
			{
				UKismetSystemLibrary::TransactObject(*ActorItr);
				ActorItr->Settings.bOverride_LensFlareIntensity = false;
			}
		}
		UKismetSystemLibrary::EndTransaction();
		OutShouldRestartEditor = false;
	}

	bool FDisablePostProcessingRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();

		return Settings->bMobilePostProcessing == 0;
	}

	void FDisablePostProcessingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobilePostProcessing, 0);
		OutShouldRestartEditor = true;
	}

	bool FDisableAmbientOcclusionRule::IsApplied() const
	{
		const URendererSettings* Settings = GetMutableDefault<URendererSettings>();

		return Settings->bMobileAmbientOcclusion == 0;
	}

	void FDisableAmbientOcclusionRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileAmbientOcclusion, 0);
		OutShouldRestartEditor = true;
	}

	bool FEnableMultiViewRule::IsApplied() const
	{
		return GetMutableDefault<URendererSettings>()->bMobileMultiView != 0;
	}

	void FEnableMultiViewRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileMultiView, 1);
		OutShouldRestartEditor = true;
	}

	bool FEnableStaticLightingRule::IsApplied() const
	{
		return GetMutableDefault<URendererSettings>()->bAllowStaticLighting;
	}

	void FEnableStaticLightingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bAllowStaticLighting, true);
		OutShouldRestartEditor = true;
	}

	bool FDisableMobileShaderStaticAndCSMShadowReceiversRule::IsApplied() const
	{
		return !GetMutableDefault<URendererSettings>()->bMobileEnableStaticAndCSMShadowReceivers;
	}

	void FDisableMobileShaderStaticAndCSMShadowReceiversRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileEnableStaticAndCSMShadowReceivers, false);
		OutShouldRestartEditor = false;
	}

	bool FDisableMobileShaderStaticAndCSMShadowReceiversRule::IsValid()
	{
		const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
		return !RuleProcessorSubsystem->DynamicLightsExistInProject();
	}

	bool FDisableMobileShaderAllowDistanceFieldShadowsRule::IsApplied() const
	{
		return !GetMutableDefault<URendererSettings>()->bMobileAllowDistanceFieldShadows;
	}

	void FDisableMobileShaderAllowDistanceFieldShadowsRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileAllowDistanceFieldShadows, false);
		OutShouldRestartEditor = true;
	}

	bool FDisableMobileShaderAllowDistanceFieldShadowsRule::IsValid()
	{
		const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
		return !RuleProcessorSubsystem->DynamicLightsExistInProject();
	}
#if UE_VERSION_OLDER_THAN(5, 5, 0)
	bool FDisableMobileShaderAllowMovableDirectionalLightsRule::IsApplied() const
	{
		return !GetMutableDefault<URendererSettings>()->bMobileAllowMovableDirectionalLights;
	}

	void FDisableMobileShaderAllowMovableDirectionalLightsRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileAllowMovableDirectionalLights, false);
		OutShouldRestartEditor = true;
	}

	bool FDisableMobileShaderAllowMovableDirectionalLightsRule::IsValid()
	{
		const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
		return !RuleProcessorSubsystem->DynamicLightsExistInProject();
	}
#endif

	bool FDisableMobileGPUSceneRule::IsApplied() const
	{
		return !GetMutableDefault<URendererSettings>()->bMobileSupportGPUScene;
	}

	void FDisableMobileGPUSceneRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileSupportGPUScene, false);
		OutShouldRestartEditor = true;
	}

	// Only disable UE5.3 and below. UE5.4 reimplements GPUScene for mobile, more research is needed.
	bool FDisableMobileGPUSceneRule::IsValid()
	{
#if UE_VERSION_OLDER_THAN(5, 4, 0)
		return true;
#endif // UE_VERSION_OLDER_THAN(5, 4, 0)
		return false;
	}

	FUseAndroidVulkanPreviewPlatform::FUseAndroidVulkanPreviewPlatform()
		: ISetupRule("Rendering_UseAndroidVulkanPreviewPlatform",
			  NSLOCTEXT("OculusXRRenderingRules", "UseAndroidVulkanPreviewPlatform_DisplayName", "Use Android Vulkan Preview Platform"),
			  NSLOCTEXT("OculusXRRenderingRules", "UseAndroidVulkanPreviewPlatform_Description", "Android Vulkan Mobile Preview Platform is necessery for correct behaviour of passthrough over Link."),
			  ESetupRuleCategory::Rendering,
			  ESetupRuleSeverity::Warning,
			  ESetupRulePlatform::MetaLink)
	{
		AndroidVulkanPreview = GetAndroidPreviewPlatformInfo();
	}

	bool FUseAndroidVulkanPreviewPlatform::IsApplied() const
	{
		FName CurrentPlatformName;
		if (!GEditor->GetPreviewPlatformName(CurrentPlatformName))
		{
			return false;
		}
		return CurrentPlatformName == AndroidVulkanPreview.PreviewPlatformName;
	}

	bool FUseAndroidVulkanPreviewPlatform::IsValid()
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
		return Settings->bInsightPassthroughEnabled;
	}

	void FUseAndroidVulkanPreviewPlatform::ApplyImpl(bool& OutShouldRestartEditor)
	{
		GEditor->SetPreviewPlatform(AndroidVulkanPreview, true);
		OutShouldRestartEditor = false;
	}

	FDisableMobileMoveableSpotlightShadowsRule::FDisableMobileMoveableSpotlightShadowsRule()
		: ISetupRule("Rendering_MobileMoveableSpotlightShadows",
			  NSLOCTEXT("OculusXRRenderingRules", "MobileMoveableSpotlightShadows_DisplayName", "Mobile Moveable Spotlight Shadows"),
			  NSLOCTEXT("OculusXRRenderingRules", "MobileMoveableSpotlightShadows_Description", "Mobile Movable Spotlights Shadows are not supported with Mobile Multi-View enabled."),
			  ESetupRuleCategory::Rendering,
			  ESetupRuleSeverity::Critical,
			  MetaQuest_All)
	{
	}

	bool FDisableMobileMoveableSpotlightShadowsRule::IsApplied() const
	{
		const URendererSettings* RenderSettings = GetMutableDefault<URendererSettings>();
		return RenderSettings->bMobileMultiView ? !RenderSettings->bMobileAllowMovableSpotlightShadows : true;
	}

	void FDisableMobileMoveableSpotlightShadowsRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(URendererSettings, bMobileAllowMovableSpotlightShadows, false);
		OutShouldRestartEditor = true;
	}
} // namespace OculusXRRenderingRules
