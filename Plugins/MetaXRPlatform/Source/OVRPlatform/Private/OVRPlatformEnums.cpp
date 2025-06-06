// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#include "OVRPlatformEnums.h"

ovrAbuseReportType ConvertAbuseReportType(EOvrAbuseReportType Value)
{
    switch (Value)
    {
        case EOvrAbuseReportType::Object:
            return ovrAbuseReportType::ovrAbuseReportType_Object;
        case EOvrAbuseReportType::User:
            return ovrAbuseReportType::ovrAbuseReportType_User;
        default:
        return ovrAbuseReportType::ovrAbuseReportType_Unknown;
    }
}

EOvrAbuseReportType ConvertAbuseReportType(ovrAbuseReportType Value)
{
    switch (Value)
    {
        case ovrAbuseReportType::ovrAbuseReportType_Object:
            return EOvrAbuseReportType::Object;
        case ovrAbuseReportType::ovrAbuseReportType_User:
            return EOvrAbuseReportType::User;
        default:
            return EOvrAbuseReportType::Unknown;
    }
}

ovrAccountAgeCategory ConvertAccountAgeCategory(EOvrAccountAgeCategory Value)
{
    switch (Value)
    {
        case EOvrAccountAgeCategory::Ch:
            return ovrAccountAgeCategory::ovrAccountAgeCategory_Ch;
        case EOvrAccountAgeCategory::Tn:
            return ovrAccountAgeCategory::ovrAccountAgeCategory_Tn;
        case EOvrAccountAgeCategory::Ad:
            return ovrAccountAgeCategory::ovrAccountAgeCategory_Ad;
        default:
        return ovrAccountAgeCategory::ovrAccountAgeCategory_Unknown;
    }
}

EOvrAccountAgeCategory ConvertAccountAgeCategory(ovrAccountAgeCategory Value)
{
    switch (Value)
    {
        case ovrAccountAgeCategory::ovrAccountAgeCategory_Ch:
            return EOvrAccountAgeCategory::Ch;
        case ovrAccountAgeCategory::ovrAccountAgeCategory_Tn:
            return EOvrAccountAgeCategory::Tn;
        case ovrAccountAgeCategory::ovrAccountAgeCategory_Ad:
            return EOvrAccountAgeCategory::Ad;
        default:
            return EOvrAccountAgeCategory::Unknown;
    }
}

ovrAchievementType ConvertAchievementType(EOvrAchievementType Value)
{
    switch (Value)
    {
        case EOvrAchievementType::Simple:
            return ovrAchievementType::ovrAchievement_TypeSimple;
        case EOvrAchievementType::Bitfield:
            return ovrAchievementType::ovrAchievement_TypeBitfield;
        case EOvrAchievementType::Count:
            return ovrAchievementType::ovrAchievement_TypeCount;
        default:
        return ovrAchievementType::ovrAchievement_TypeUnknown;
    }
}

EOvrAchievementType ConvertAchievementType(ovrAchievementType Value)
{
    switch (Value)
    {
        case ovrAchievementType::ovrAchievement_TypeSimple:
            return EOvrAchievementType::Simple;
        case ovrAchievementType::ovrAchievement_TypeBitfield:
            return EOvrAchievementType::Bitfield;
        case ovrAchievementType::ovrAchievement_TypeCount:
            return EOvrAchievementType::Count;
        default:
            return EOvrAchievementType::Unknown;
    }
}

ovrAppAgeCategory ConvertAppAgeCategory(EOvrAppAgeCategory Value)
{
    switch (Value)
    {
        case EOvrAppAgeCategory::Ch:
            return ovrAppAgeCategory::ovrAppAgeCategory_Ch;
        case EOvrAppAgeCategory::Nch:
            return ovrAppAgeCategory::ovrAppAgeCategory_Nch;
        default:
        return ovrAppAgeCategory::ovrAppAgeCategory_Unknown;
    }
}

EOvrAppAgeCategory ConvertAppAgeCategory(ovrAppAgeCategory Value)
{
    switch (Value)
    {
        case ovrAppAgeCategory::ovrAppAgeCategory_Ch:
            return EOvrAppAgeCategory::Ch;
        case ovrAppAgeCategory::ovrAppAgeCategory_Nch:
            return EOvrAppAgeCategory::Nch;
        default:
            return EOvrAppAgeCategory::Unknown;
    }
}

ovrAppInstallResult ConvertAppInstallResult(EOvrAppInstallResult Value)
{
    switch (Value)
    {
        case EOvrAppInstallResult::LowStorage:
            return ovrAppInstallResult::ovrAppInstallResult_LowStorage;
        case EOvrAppInstallResult::NetworkError:
            return ovrAppInstallResult::ovrAppInstallResult_NetworkError;
        case EOvrAppInstallResult::DuplicateRequest:
            return ovrAppInstallResult::ovrAppInstallResult_DuplicateRequest;
        case EOvrAppInstallResult::InstallerError:
            return ovrAppInstallResult::ovrAppInstallResult_InstallerError;
        case EOvrAppInstallResult::UserCancelled:
            return ovrAppInstallResult::ovrAppInstallResult_UserCancelled;
        case EOvrAppInstallResult::AuthorizationError:
            return ovrAppInstallResult::ovrAppInstallResult_AuthorizationError;
        case EOvrAppInstallResult::Success:
            return ovrAppInstallResult::ovrAppInstallResult_Success;
        default:
        return ovrAppInstallResult::ovrAppInstallResult_Unknown;
    }
}

EOvrAppInstallResult ConvertAppInstallResult(ovrAppInstallResult Value)
{
    switch (Value)
    {
        case ovrAppInstallResult::ovrAppInstallResult_LowStorage:
            return EOvrAppInstallResult::LowStorage;
        case ovrAppInstallResult::ovrAppInstallResult_NetworkError:
            return EOvrAppInstallResult::NetworkError;
        case ovrAppInstallResult::ovrAppInstallResult_DuplicateRequest:
            return EOvrAppInstallResult::DuplicateRequest;
        case ovrAppInstallResult::ovrAppInstallResult_InstallerError:
            return EOvrAppInstallResult::InstallerError;
        case ovrAppInstallResult::ovrAppInstallResult_UserCancelled:
            return EOvrAppInstallResult::UserCancelled;
        case ovrAppInstallResult::ovrAppInstallResult_AuthorizationError:
            return EOvrAppInstallResult::AuthorizationError;
        case ovrAppInstallResult::ovrAppInstallResult_Success:
            return EOvrAppInstallResult::Success;
        default:
            return EOvrAppInstallResult::Unknown;
    }
}

ovrAppStatus ConvertAppStatus(EOvrAppStatus Value)
{
    switch (Value)
    {
        case EOvrAppStatus::Entitled:
            return ovrAppStatus::ovrAppStatus_Entitled;
        case EOvrAppStatus::DownloadQueued:
            return ovrAppStatus::ovrAppStatus_DownloadQueued;
        case EOvrAppStatus::Downloading:
            return ovrAppStatus::ovrAppStatus_Downloading;
        case EOvrAppStatus::Installing:
            return ovrAppStatus::ovrAppStatus_Installing;
        case EOvrAppStatus::Installed:
            return ovrAppStatus::ovrAppStatus_Installed;
        case EOvrAppStatus::Uninstalling:
            return ovrAppStatus::ovrAppStatus_Uninstalling;
        case EOvrAppStatus::InstallQueued:
            return ovrAppStatus::ovrAppStatus_InstallQueued;
        default:
        return ovrAppStatus::ovrAppStatus_Unknown;
    }
}

EOvrAppStatus ConvertAppStatus(ovrAppStatus Value)
{
    switch (Value)
    {
        case ovrAppStatus::ovrAppStatus_Entitled:
            return EOvrAppStatus::Entitled;
        case ovrAppStatus::ovrAppStatus_DownloadQueued:
            return EOvrAppStatus::DownloadQueued;
        case ovrAppStatus::ovrAppStatus_Downloading:
            return EOvrAppStatus::Downloading;
        case ovrAppStatus::ovrAppStatus_Installing:
            return EOvrAppStatus::Installing;
        case ovrAppStatus::ovrAppStatus_Installed:
            return EOvrAppStatus::Installed;
        case ovrAppStatus::ovrAppStatus_Uninstalling:
            return EOvrAppStatus::Uninstalling;
        case ovrAppStatus::ovrAppStatus_InstallQueued:
            return EOvrAppStatus::InstallQueued;
        default:
            return EOvrAppStatus::Unknown;
    }
}

ovrChallengeCreationType ConvertChallengeCreationType(EOvrChallengeCreationType Value)
{
    switch (Value)
    {
        case EOvrChallengeCreationType::UserCreated:
            return ovrChallengeCreationType::ovrChallengeCreationType_UserCreated;
        case EOvrChallengeCreationType::DeveloperCreated:
            return ovrChallengeCreationType::ovrChallengeCreationType_DeveloperCreated;
        default:
        return ovrChallengeCreationType::ovrChallengeCreationType_Unknown;
    }
}

EOvrChallengeCreationType ConvertChallengeCreationType(ovrChallengeCreationType Value)
{
    switch (Value)
    {
        case ovrChallengeCreationType::ovrChallengeCreationType_UserCreated:
            return EOvrChallengeCreationType::UserCreated;
        case ovrChallengeCreationType::ovrChallengeCreationType_DeveloperCreated:
            return EOvrChallengeCreationType::DeveloperCreated;
        default:
            return EOvrChallengeCreationType::Unknown;
    }
}

ovrChallengeViewerFilter ConvertChallengeViewerFilter(EOvrChallengeViewerFilter Value)
{
    switch (Value)
    {
        case EOvrChallengeViewerFilter::AllVisible:
            return ovrChallengeViewerFilter::ovrChallengeViewerFilter_AllVisible;
        case EOvrChallengeViewerFilter::Participating:
            return ovrChallengeViewerFilter::ovrChallengeViewerFilter_Participating;
        case EOvrChallengeViewerFilter::Invited:
            return ovrChallengeViewerFilter::ovrChallengeViewerFilter_Invited;
        case EOvrChallengeViewerFilter::ParticipatingOrInvited:
            return ovrChallengeViewerFilter::ovrChallengeViewerFilter_ParticipatingOrInvited;
        default:
        return ovrChallengeViewerFilter::ovrChallengeViewerFilter_Unknown;
    }
}

EOvrChallengeViewerFilter ConvertChallengeViewerFilter(ovrChallengeViewerFilter Value)
{
    switch (Value)
    {
        case ovrChallengeViewerFilter::ovrChallengeViewerFilter_AllVisible:
            return EOvrChallengeViewerFilter::AllVisible;
        case ovrChallengeViewerFilter::ovrChallengeViewerFilter_Participating:
            return EOvrChallengeViewerFilter::Participating;
        case ovrChallengeViewerFilter::ovrChallengeViewerFilter_Invited:
            return EOvrChallengeViewerFilter::Invited;
        case ovrChallengeViewerFilter::ovrChallengeViewerFilter_ParticipatingOrInvited:
            return EOvrChallengeViewerFilter::ParticipatingOrInvited;
        default:
            return EOvrChallengeViewerFilter::Unknown;
    }
}

ovrChallengeVisibility ConvertChallengeVisibility(EOvrChallengeVisibility Value)
{
    switch (Value)
    {
        case EOvrChallengeVisibility::InviteOnly:
            return ovrChallengeVisibility::ovrChallengeVisibility_InviteOnly;
        case EOvrChallengeVisibility::Public:
            return ovrChallengeVisibility::ovrChallengeVisibility_Public;
        case EOvrChallengeVisibility::Private:
            return ovrChallengeVisibility::ovrChallengeVisibility_Private;
        default:
        return ovrChallengeVisibility::ovrChallengeVisibility_Unknown;
    }
}

EOvrChallengeVisibility ConvertChallengeVisibility(ovrChallengeVisibility Value)
{
    switch (Value)
    {
        case ovrChallengeVisibility::ovrChallengeVisibility_InviteOnly:
            return EOvrChallengeVisibility::InviteOnly;
        case ovrChallengeVisibility::ovrChallengeVisibility_Public:
            return EOvrChallengeVisibility::Public;
        case ovrChallengeVisibility::ovrChallengeVisibility_Private:
            return EOvrChallengeVisibility::Private;
        default:
            return EOvrChallengeVisibility::Unknown;
    }
}

ovrKeyValuePairType ConvertKeyValuePairType(EOvrKeyValuePairType Value)
{
    switch (Value)
    {
        case EOvrKeyValuePairType::String:
            return ovrKeyValuePairType::ovrKeyValuePairType_String;
        case EOvrKeyValuePairType::Int:
            return ovrKeyValuePairType::ovrKeyValuePairType_Int;
        case EOvrKeyValuePairType::Double:
            return ovrKeyValuePairType::ovrKeyValuePairType_Double;
        default:
        return ovrKeyValuePairType::ovrKeyValuePairType_Unknown;
    }
}

EOvrKeyValuePairType ConvertKeyValuePairType(ovrKeyValuePairType Value)
{
    switch (Value)
    {
        case ovrKeyValuePairType::ovrKeyValuePairType_String:
            return EOvrKeyValuePairType::String;
        case ovrKeyValuePairType::ovrKeyValuePairType_Int:
            return EOvrKeyValuePairType::Int;
        case ovrKeyValuePairType::ovrKeyValuePairType_Double:
            return EOvrKeyValuePairType::Double;
        default:
            return EOvrKeyValuePairType::Unknown;
    }
}

ovrLaunchResult ConvertLaunchResult(EOvrLaunchResult Value)
{
    switch (Value)
    {
        case EOvrLaunchResult::Success:
            return ovrLaunchResult::ovrLaunchResult_Success;
        case EOvrLaunchResult::FailedRoomFull:
            return ovrLaunchResult::ovrLaunchResult_FailedRoomFull;
        case EOvrLaunchResult::FailedGameAlreadyStarted:
            return ovrLaunchResult::ovrLaunchResult_FailedGameAlreadyStarted;
        case EOvrLaunchResult::FailedRoomNotFound:
            return ovrLaunchResult::ovrLaunchResult_FailedRoomNotFound;
        case EOvrLaunchResult::FailedUserDeclined:
            return ovrLaunchResult::ovrLaunchResult_FailedUserDeclined;
        case EOvrLaunchResult::FailedOtherReason:
            return ovrLaunchResult::ovrLaunchResult_FailedOtherReason;
        default:
        return ovrLaunchResult::ovrLaunchResult_Unknown;
    }
}

EOvrLaunchResult ConvertLaunchResult(ovrLaunchResult Value)
{
    switch (Value)
    {
        case ovrLaunchResult::ovrLaunchResult_Success:
            return EOvrLaunchResult::Success;
        case ovrLaunchResult::ovrLaunchResult_FailedRoomFull:
            return EOvrLaunchResult::FailedRoomFull;
        case ovrLaunchResult::ovrLaunchResult_FailedGameAlreadyStarted:
            return EOvrLaunchResult::FailedGameAlreadyStarted;
        case ovrLaunchResult::ovrLaunchResult_FailedRoomNotFound:
            return EOvrLaunchResult::FailedRoomNotFound;
        case ovrLaunchResult::ovrLaunchResult_FailedUserDeclined:
            return EOvrLaunchResult::FailedUserDeclined;
        case ovrLaunchResult::ovrLaunchResult_FailedOtherReason:
            return EOvrLaunchResult::FailedOtherReason;
        default:
            return EOvrLaunchResult::Unknown;
    }
}

ovrLaunchType ConvertLaunchType(EOvrLaunchType Value)
{
    switch (Value)
    {
        case EOvrLaunchType::Normal:
            return ovrLaunchType::ovrLaunchType_Normal;
        case EOvrLaunchType::Invite:
            return ovrLaunchType::ovrLaunchType_Invite;
        case EOvrLaunchType::Coordinated:
            return ovrLaunchType::ovrLaunchType_Coordinated;
        case EOvrLaunchType::Deeplink:
            return ovrLaunchType::ovrLaunchType_Deeplink;
        default:
        return ovrLaunchType::ovrLaunchType_Unknown;
    }
}

EOvrLaunchType ConvertLaunchType(ovrLaunchType Value)
{
    switch (Value)
    {
        case ovrLaunchType::ovrLaunchType_Normal:
            return EOvrLaunchType::Normal;
        case ovrLaunchType::ovrLaunchType_Invite:
            return EOvrLaunchType::Invite;
        case ovrLaunchType::ovrLaunchType_Coordinated:
            return EOvrLaunchType::Coordinated;
        case ovrLaunchType::ovrLaunchType_Deeplink:
            return EOvrLaunchType::Deeplink;
        default:
            return EOvrLaunchType::Unknown;
    }
}

ovrLeaderboardFilterType ConvertLeaderboardFilterType(EOvrLeaderboardFilterType Value)
{
    switch (Value)
    {
        case EOvrLeaderboardFilterType::None:
            return ovrLeaderboardFilterType::ovrLeaderboard_FilterNone;
        case EOvrLeaderboardFilterType::Friends:
            return ovrLeaderboardFilterType::ovrLeaderboard_FilterFriends;
        case EOvrLeaderboardFilterType::UserIds:
            return ovrLeaderboardFilterType::ovrLeaderboard_FilterUserIds;
        default:
        return ovrLeaderboardFilterType::ovrLeaderboard_FilterUnknown;
    }
}

EOvrLeaderboardFilterType ConvertLeaderboardFilterType(ovrLeaderboardFilterType Value)
{
    switch (Value)
    {
        case ovrLeaderboardFilterType::ovrLeaderboard_FilterNone:
            return EOvrLeaderboardFilterType::None;
        case ovrLeaderboardFilterType::ovrLeaderboard_FilterFriends:
            return EOvrLeaderboardFilterType::Friends;
        case ovrLeaderboardFilterType::ovrLeaderboard_FilterUserIds:
            return EOvrLeaderboardFilterType::UserIds;
        default:
            return EOvrLeaderboardFilterType::Unknown;
    }
}

ovrLeaderboardStartAt ConvertLeaderboardStartAt(EOvrLeaderboardStartAt Value)
{
    switch (Value)
    {
        case EOvrLeaderboardStartAt::Top:
            return ovrLeaderboardStartAt::ovrLeaderboard_StartAtTop;
        case EOvrLeaderboardStartAt::CenteredOnViewer:
            return ovrLeaderboardStartAt::ovrLeaderboard_StartAtCenteredOnViewer;
        case EOvrLeaderboardStartAt::CenteredOnViewerOrTop:
            return ovrLeaderboardStartAt::ovrLeaderboard_StartAtCenteredOnViewerOrTop;
        default:
        return ovrLeaderboardStartAt::ovrLeaderboard_StartAtUnknown;
    }
}

EOvrLeaderboardStartAt ConvertLeaderboardStartAt(ovrLeaderboardStartAt Value)
{
    switch (Value)
    {
        case ovrLeaderboardStartAt::ovrLeaderboard_StartAtTop:
            return EOvrLeaderboardStartAt::Top;
        case ovrLeaderboardStartAt::ovrLeaderboard_StartAtCenteredOnViewer:
            return EOvrLeaderboardStartAt::CenteredOnViewer;
        case ovrLeaderboardStartAt::ovrLeaderboard_StartAtCenteredOnViewerOrTop:
            return EOvrLeaderboardStartAt::CenteredOnViewerOrTop;
        default:
            return EOvrLeaderboardStartAt::Unknown;
    }
}

ovrLivestreamingStartStatus ConvertLivestreamingStartStatus(EOvrLivestreamingStartStatus Value)
{
    switch (Value)
    {
        case EOvrLivestreamingStartStatus::Success:
            return ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_Success;
        case EOvrLivestreamingStartStatus::NoPackageSet:
            return ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_NoPackageSet;
        case EOvrLivestreamingStartStatus::NoFbConnect:
            return ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_NoFbConnect;
        case EOvrLivestreamingStartStatus::NoSessionId:
            return ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_NoSessionId;
        case EOvrLivestreamingStartStatus::MissingParameters:
            return ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_MissingParameters;
        default:
        return ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_Unknown;
    }
}

EOvrLivestreamingStartStatus ConvertLivestreamingStartStatus(ovrLivestreamingStartStatus Value)
{
    switch (Value)
    {
        case ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_Success:
            return EOvrLivestreamingStartStatus::Success;
        case ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_NoPackageSet:
            return EOvrLivestreamingStartStatus::NoPackageSet;
        case ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_NoFbConnect:
            return EOvrLivestreamingStartStatus::NoFbConnect;
        case ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_NoSessionId:
            return EOvrLivestreamingStartStatus::NoSessionId;
        case ovrLivestreamingStartStatus::ovrLivestreamingStartStatus_MissingParameters:
            return EOvrLivestreamingStartStatus::MissingParameters;
        default:
            return EOvrLivestreamingStartStatus::Unknown;
    }
}

ovrLogEventName ConvertLogEventName(EOvrLogEventName Value)
{
    switch (Value)
    {
        case EOvrLogEventName::AdClick:
            return ovrLogEventName::ovrLogEventName_AdClick;
        case EOvrLogEventName::AdImpression:
            return ovrLogEventName::ovrLogEventName_AdImpression;
        case EOvrLogEventName::VrCompleteRegistration:
            return ovrLogEventName::ovrLogEventName_VrCompleteRegistration;
        case EOvrLogEventName::VrTutorialCompletion:
            return ovrLogEventName::ovrLogEventName_VrTutorialCompletion;
        case EOvrLogEventName::Contact:
            return ovrLogEventName::ovrLogEventName_Contact;
        case EOvrLogEventName::CustomizeProduct:
            return ovrLogEventName::ovrLogEventName_CustomizeProduct;
        case EOvrLogEventName::Donate:
            return ovrLogEventName::ovrLogEventName_Donate;
        case EOvrLogEventName::FindLocation:
            return ovrLogEventName::ovrLogEventName_FindLocation;
        case EOvrLogEventName::VrRate:
            return ovrLogEventName::ovrLogEventName_VrRate;
        case EOvrLogEventName::Schedule:
            return ovrLogEventName::ovrLogEventName_Schedule;
        case EOvrLogEventName::VrSearch:
            return ovrLogEventName::ovrLogEventName_VrSearch;
        case EOvrLogEventName::SmartTrial:
            return ovrLogEventName::ovrLogEventName_SmartTrial;
        case EOvrLogEventName::SubmitApplication:
            return ovrLogEventName::ovrLogEventName_SubmitApplication;
        case EOvrLogEventName::Subscribe:
            return ovrLogEventName::ovrLogEventName_Subscribe;
        case EOvrLogEventName::VrContentView:
            return ovrLogEventName::ovrLogEventName_VrContentView;
        case EOvrLogEventName::VrSdkInitialize:
            return ovrLogEventName::ovrLogEventName_VrSdkInitialize;
        case EOvrLogEventName::VrSdkBackgroundStatusAvailable:
            return ovrLogEventName::ovrLogEventName_VrSdkBackgroundStatusAvailable;
        case EOvrLogEventName::VrSdkBackgroundStatusDenied:
            return ovrLogEventName::ovrLogEventName_VrSdkBackgroundStatusDenied;
        case EOvrLogEventName::VrSdkBackgroundStatusRestricted:
            return ovrLogEventName::ovrLogEventName_VrSdkBackgroundStatusRestricted;
        case EOvrLogEventName::VrAddPaymentInfo:
            return ovrLogEventName::ovrLogEventName_VrAddPaymentInfo;
        case EOvrLogEventName::VrAddToCart:
            return ovrLogEventName::ovrLogEventName_VrAddToCart;
        case EOvrLogEventName::VrAddToWishlist:
            return ovrLogEventName::ovrLogEventName_VrAddToWishlist;
        case EOvrLogEventName::VrInitiatedCheckout:
            return ovrLogEventName::ovrLogEventName_VrInitiatedCheckout;
        case EOvrLogEventName::VrPurchase:
            return ovrLogEventName::ovrLogEventName_VrPurchase;
        case EOvrLogEventName::VrCatalogUpdate:
            return ovrLogEventName::ovrLogEventName_VrCatalogUpdate;
        case EOvrLogEventName::VrPurchaseFailed:
            return ovrLogEventName::ovrLogEventName_VrPurchaseFailed;
        case EOvrLogEventName::VrPurchaseRestored:
            return ovrLogEventName::ovrLogEventName_VrPurchaseRestored;
        case EOvrLogEventName::SubscriptionInitiatedCheckout:
            return ovrLogEventName::ovrLogEventName_SubscriptionInitiatedCheckout;
        case EOvrLogEventName::SubscriptionFailed:
            return ovrLogEventName::ovrLogEventName_SubscriptionFailed;
        case EOvrLogEventName::SubscriptionRestore:
            return ovrLogEventName::ovrLogEventName_SubscriptionRestore;
        case EOvrLogEventName::VrLevelAchieved:
            return ovrLogEventName::ovrLogEventName_VrLevelAchieved;
        case EOvrLogEventName::VrAchievementUnlocked:
            return ovrLogEventName::ovrLogEventName_VrAchievementUnlocked;
        case EOvrLogEventName::VrSpentCredits:
            return ovrLogEventName::ovrLogEventName_VrSpentCredits;
        case EOvrLogEventName::VrObtainPushToken:
            return ovrLogEventName::ovrLogEventName_VrObtainPushToken;
        case EOvrLogEventName::VrPushOpened:
            return ovrLogEventName::ovrLogEventName_VrPushOpened;
        case EOvrLogEventName::VrActivateApp:
            return ovrLogEventName::ovrLogEventName_VrActivateApp;
        case EOvrLogEventName::VrDeactivateApp:
            return ovrLogEventName::ovrLogEventName_VrDeactivateApp;
        default:
        return ovrLogEventName::ovrLogEventName_Unknown;
    }
}

EOvrLogEventName ConvertLogEventName(ovrLogEventName Value)
{
    switch (Value)
    {
        case ovrLogEventName::ovrLogEventName_AdClick:
            return EOvrLogEventName::AdClick;
        case ovrLogEventName::ovrLogEventName_AdImpression:
            return EOvrLogEventName::AdImpression;
        case ovrLogEventName::ovrLogEventName_VrCompleteRegistration:
            return EOvrLogEventName::VrCompleteRegistration;
        case ovrLogEventName::ovrLogEventName_VrTutorialCompletion:
            return EOvrLogEventName::VrTutorialCompletion;
        case ovrLogEventName::ovrLogEventName_Contact:
            return EOvrLogEventName::Contact;
        case ovrLogEventName::ovrLogEventName_CustomizeProduct:
            return EOvrLogEventName::CustomizeProduct;
        case ovrLogEventName::ovrLogEventName_Donate:
            return EOvrLogEventName::Donate;
        case ovrLogEventName::ovrLogEventName_FindLocation:
            return EOvrLogEventName::FindLocation;
        case ovrLogEventName::ovrLogEventName_VrRate:
            return EOvrLogEventName::VrRate;
        case ovrLogEventName::ovrLogEventName_Schedule:
            return EOvrLogEventName::Schedule;
        case ovrLogEventName::ovrLogEventName_VrSearch:
            return EOvrLogEventName::VrSearch;
        case ovrLogEventName::ovrLogEventName_SmartTrial:
            return EOvrLogEventName::SmartTrial;
        case ovrLogEventName::ovrLogEventName_SubmitApplication:
            return EOvrLogEventName::SubmitApplication;
        case ovrLogEventName::ovrLogEventName_Subscribe:
            return EOvrLogEventName::Subscribe;
        case ovrLogEventName::ovrLogEventName_VrContentView:
            return EOvrLogEventName::VrContentView;
        case ovrLogEventName::ovrLogEventName_VrSdkInitialize:
            return EOvrLogEventName::VrSdkInitialize;
        case ovrLogEventName::ovrLogEventName_VrSdkBackgroundStatusAvailable:
            return EOvrLogEventName::VrSdkBackgroundStatusAvailable;
        case ovrLogEventName::ovrLogEventName_VrSdkBackgroundStatusDenied:
            return EOvrLogEventName::VrSdkBackgroundStatusDenied;
        case ovrLogEventName::ovrLogEventName_VrSdkBackgroundStatusRestricted:
            return EOvrLogEventName::VrSdkBackgroundStatusRestricted;
        case ovrLogEventName::ovrLogEventName_VrAddPaymentInfo:
            return EOvrLogEventName::VrAddPaymentInfo;
        case ovrLogEventName::ovrLogEventName_VrAddToCart:
            return EOvrLogEventName::VrAddToCart;
        case ovrLogEventName::ovrLogEventName_VrAddToWishlist:
            return EOvrLogEventName::VrAddToWishlist;
        case ovrLogEventName::ovrLogEventName_VrInitiatedCheckout:
            return EOvrLogEventName::VrInitiatedCheckout;
        case ovrLogEventName::ovrLogEventName_VrPurchase:
            return EOvrLogEventName::VrPurchase;
        case ovrLogEventName::ovrLogEventName_VrCatalogUpdate:
            return EOvrLogEventName::VrCatalogUpdate;
        case ovrLogEventName::ovrLogEventName_VrPurchaseFailed:
            return EOvrLogEventName::VrPurchaseFailed;
        case ovrLogEventName::ovrLogEventName_VrPurchaseRestored:
            return EOvrLogEventName::VrPurchaseRestored;
        case ovrLogEventName::ovrLogEventName_SubscriptionInitiatedCheckout:
            return EOvrLogEventName::SubscriptionInitiatedCheckout;
        case ovrLogEventName::ovrLogEventName_SubscriptionFailed:
            return EOvrLogEventName::SubscriptionFailed;
        case ovrLogEventName::ovrLogEventName_SubscriptionRestore:
            return EOvrLogEventName::SubscriptionRestore;
        case ovrLogEventName::ovrLogEventName_VrLevelAchieved:
            return EOvrLogEventName::VrLevelAchieved;
        case ovrLogEventName::ovrLogEventName_VrAchievementUnlocked:
            return EOvrLogEventName::VrAchievementUnlocked;
        case ovrLogEventName::ovrLogEventName_VrSpentCredits:
            return EOvrLogEventName::VrSpentCredits;
        case ovrLogEventName::ovrLogEventName_VrObtainPushToken:
            return EOvrLogEventName::VrObtainPushToken;
        case ovrLogEventName::ovrLogEventName_VrPushOpened:
            return EOvrLogEventName::VrPushOpened;
        case ovrLogEventName::ovrLogEventName_VrActivateApp:
            return EOvrLogEventName::VrActivateApp;
        case ovrLogEventName::ovrLogEventName_VrDeactivateApp:
            return EOvrLogEventName::VrDeactivateApp;
        default:
            return EOvrLogEventName::Unknown;
    }
}

ovrLogEventParameter ConvertLogEventParameter(EOvrLogEventParameter Value)
{
    switch (Value)
    {
        case EOvrLogEventParameter::VrCurrency:
            return ovrLogEventParameter::ovrLogEventParameter_VrCurrency;
        case EOvrLogEventParameter::VrRegistrationMethod:
            return ovrLogEventParameter::ovrLogEventParameter_VrRegistrationMethod;
        case EOvrLogEventParameter::VrContentType:
            return ovrLogEventParameter::ovrLogEventParameter_VrContentType;
        case EOvrLogEventParameter::VrContent:
            return ovrLogEventParameter::ovrLogEventParameter_VrContent;
        case EOvrLogEventParameter::VrContentId:
            return ovrLogEventParameter::ovrLogEventParameter_VrContentId;
        case EOvrLogEventParameter::VrSearchString:
            return ovrLogEventParameter::ovrLogEventParameter_VrSearchString;
        case EOvrLogEventParameter::VrSuccess:
            return ovrLogEventParameter::ovrLogEventParameter_VrSuccess;
        case EOvrLogEventParameter::VrMaxRatingValue:
            return ovrLogEventParameter::ovrLogEventParameter_VrMaxRatingValue;
        case EOvrLogEventParameter::VrPaymentInfoAvailable:
            return ovrLogEventParameter::ovrLogEventParameter_VrPaymentInfoAvailable;
        case EOvrLogEventParameter::VrNumItems:
            return ovrLogEventParameter::ovrLogEventParameter_VrNumItems;
        case EOvrLogEventParameter::VrLevel:
            return ovrLogEventParameter::ovrLogEventParameter_VrLevel;
        case EOvrLogEventParameter::VrDescription:
            return ovrLogEventParameter::ovrLogEventParameter_VrDescription;
        case EOvrLogEventParameter::AdType:
            return ovrLogEventParameter::ovrLogEventParameter_AdType;
        case EOvrLogEventParameter::VrOrderId:
            return ovrLogEventParameter::ovrLogEventParameter_VrOrderId;
        case EOvrLogEventParameter::EventName:
            return ovrLogEventParameter::ovrLogEventParameter_EventName;
        case EOvrLogEventParameter::LogTime:
            return ovrLogEventParameter::ovrLogEventParameter_LogTime;
        case EOvrLogEventParameter::ImplicitlyLogged:
            return ovrLogEventParameter::ovrLogEventParameter_ImplicitlyLogged;
        case EOvrLogEventParameter::InBackground:
            return ovrLogEventParameter::ovrLogEventParameter_InBackground;
        case EOvrLogEventParameter::VrPushCampaign:
            return ovrLogEventParameter::ovrLogEventParameter_VrPushCampaign;
        case EOvrLogEventParameter::VrPushAction:
            return ovrLogEventParameter::ovrLogEventParameter_VrPushAction;
        case EOvrLogEventParameter::VrIapProductType:
            return ovrLogEventParameter::ovrLogEventParameter_VrIapProductType;
        case EOvrLogEventParameter::VrContentTitle:
            return ovrLogEventParameter::ovrLogEventParameter_VrContentTitle;
        case EOvrLogEventParameter::VrTransactionId:
            return ovrLogEventParameter::ovrLogEventParameter_VrTransactionId;
        case EOvrLogEventParameter::VrTransactionDate:
            return ovrLogEventParameter::ovrLogEventParameter_VrTransactionDate;
        case EOvrLogEventParameter::VrIapSubsPeriod:
            return ovrLogEventParameter::ovrLogEventParameter_VrIapSubsPeriod;
        case EOvrLogEventParameter::VrIapIsStartTrial:
            return ovrLogEventParameter::ovrLogEventParameter_VrIapIsStartTrial;
        case EOvrLogEventParameter::VrIapHasFreeTrial:
            return ovrLogEventParameter::ovrLogEventParameter_VrIapHasFreeTrial;
        case EOvrLogEventParameter::VrIapTrialPeriod:
            return ovrLogEventParameter::ovrLogEventParameter_VrIapTrialPeriod;
        case EOvrLogEventParameter::VrIapTrialPrice:
            return ovrLogEventParameter::ovrLogEventParameter_VrIapTrialPrice;
        case EOvrLogEventParameter::SessionId:
            return ovrLogEventParameter::ovrLogEventParameter_SessionId;
        default:
        return ovrLogEventParameter::ovrLogEventParameter_Unknown;
    }
}

EOvrLogEventParameter ConvertLogEventParameter(ovrLogEventParameter Value)
{
    switch (Value)
    {
        case ovrLogEventParameter::ovrLogEventParameter_VrCurrency:
            return EOvrLogEventParameter::VrCurrency;
        case ovrLogEventParameter::ovrLogEventParameter_VrRegistrationMethod:
            return EOvrLogEventParameter::VrRegistrationMethod;
        case ovrLogEventParameter::ovrLogEventParameter_VrContentType:
            return EOvrLogEventParameter::VrContentType;
        case ovrLogEventParameter::ovrLogEventParameter_VrContent:
            return EOvrLogEventParameter::VrContent;
        case ovrLogEventParameter::ovrLogEventParameter_VrContentId:
            return EOvrLogEventParameter::VrContentId;
        case ovrLogEventParameter::ovrLogEventParameter_VrSearchString:
            return EOvrLogEventParameter::VrSearchString;
        case ovrLogEventParameter::ovrLogEventParameter_VrSuccess:
            return EOvrLogEventParameter::VrSuccess;
        case ovrLogEventParameter::ovrLogEventParameter_VrMaxRatingValue:
            return EOvrLogEventParameter::VrMaxRatingValue;
        case ovrLogEventParameter::ovrLogEventParameter_VrPaymentInfoAvailable:
            return EOvrLogEventParameter::VrPaymentInfoAvailable;
        case ovrLogEventParameter::ovrLogEventParameter_VrNumItems:
            return EOvrLogEventParameter::VrNumItems;
        case ovrLogEventParameter::ovrLogEventParameter_VrLevel:
            return EOvrLogEventParameter::VrLevel;
        case ovrLogEventParameter::ovrLogEventParameter_VrDescription:
            return EOvrLogEventParameter::VrDescription;
        case ovrLogEventParameter::ovrLogEventParameter_AdType:
            return EOvrLogEventParameter::AdType;
        case ovrLogEventParameter::ovrLogEventParameter_VrOrderId:
            return EOvrLogEventParameter::VrOrderId;
        case ovrLogEventParameter::ovrLogEventParameter_EventName:
            return EOvrLogEventParameter::EventName;
        case ovrLogEventParameter::ovrLogEventParameter_LogTime:
            return EOvrLogEventParameter::LogTime;
        case ovrLogEventParameter::ovrLogEventParameter_ImplicitlyLogged:
            return EOvrLogEventParameter::ImplicitlyLogged;
        case ovrLogEventParameter::ovrLogEventParameter_InBackground:
            return EOvrLogEventParameter::InBackground;
        case ovrLogEventParameter::ovrLogEventParameter_VrPushCampaign:
            return EOvrLogEventParameter::VrPushCampaign;
        case ovrLogEventParameter::ovrLogEventParameter_VrPushAction:
            return EOvrLogEventParameter::VrPushAction;
        case ovrLogEventParameter::ovrLogEventParameter_VrIapProductType:
            return EOvrLogEventParameter::VrIapProductType;
        case ovrLogEventParameter::ovrLogEventParameter_VrContentTitle:
            return EOvrLogEventParameter::VrContentTitle;
        case ovrLogEventParameter::ovrLogEventParameter_VrTransactionId:
            return EOvrLogEventParameter::VrTransactionId;
        case ovrLogEventParameter::ovrLogEventParameter_VrTransactionDate:
            return EOvrLogEventParameter::VrTransactionDate;
        case ovrLogEventParameter::ovrLogEventParameter_VrIapSubsPeriod:
            return EOvrLogEventParameter::VrIapSubsPeriod;
        case ovrLogEventParameter::ovrLogEventParameter_VrIapIsStartTrial:
            return EOvrLogEventParameter::VrIapIsStartTrial;
        case ovrLogEventParameter::ovrLogEventParameter_VrIapHasFreeTrial:
            return EOvrLogEventParameter::VrIapHasFreeTrial;
        case ovrLogEventParameter::ovrLogEventParameter_VrIapTrialPeriod:
            return EOvrLogEventParameter::VrIapTrialPeriod;
        case ovrLogEventParameter::ovrLogEventParameter_VrIapTrialPrice:
            return EOvrLogEventParameter::VrIapTrialPrice;
        case ovrLogEventParameter::ovrLogEventParameter_SessionId:
            return EOvrLogEventParameter::SessionId;
        default:
            return EOvrLogEventParameter::Unknown;
    }
}

ovrMediaContentType ConvertMediaContentType(EOvrMediaContentType Value)
{
    switch (Value)
    {
        case EOvrMediaContentType::Photo:
            return ovrMediaContentType::ovrMediaContentType_Photo;
        default:
        return ovrMediaContentType::ovrMediaContentType_Unknown;
    }
}

EOvrMediaContentType ConvertMediaContentType(ovrMediaContentType Value)
{
    switch (Value)
    {
        case ovrMediaContentType::ovrMediaContentType_Photo:
            return EOvrMediaContentType::Photo;
        default:
            return EOvrMediaContentType::Unknown;
    }
}

ovrMultiplayerErrorErrorKey ConvertMultiplayerErrorErrorKey(EOvrMultiplayerErrorErrorKey Value)
{
    switch (Value)
    {
        case EOvrMultiplayerErrorErrorKey::DestinationUnavailable:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_DestinationUnavailable;
        case EOvrMultiplayerErrorErrorKey::DlcRequired:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_DlcRequired;
        case EOvrMultiplayerErrorErrorKey::General:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_General;
        case EOvrMultiplayerErrorErrorKey::GroupFull:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_GroupFull;
        case EOvrMultiplayerErrorErrorKey::InviterNotJoinable:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_InviterNotJoinable;
        case EOvrMultiplayerErrorErrorKey::LevelNotHighEnough:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_LevelNotHighEnough;
        case EOvrMultiplayerErrorErrorKey::LevelNotUnlocked:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_LevelNotUnlocked;
        case EOvrMultiplayerErrorErrorKey::NetworkTimeout:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_NetworkTimeout;
        case EOvrMultiplayerErrorErrorKey::NoLongerAvailable:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_NoLongerAvailable;
        case EOvrMultiplayerErrorErrorKey::UpdateRequired:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_UpdateRequired;
        case EOvrMultiplayerErrorErrorKey::TutorialRequired:
            return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_TutorialRequired;
        default:
        return ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_Unknown;
    }
}

EOvrMultiplayerErrorErrorKey ConvertMultiplayerErrorErrorKey(ovrMultiplayerErrorErrorKey Value)
{
    switch (Value)
    {
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_DestinationUnavailable:
            return EOvrMultiplayerErrorErrorKey::DestinationUnavailable;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_DlcRequired:
            return EOvrMultiplayerErrorErrorKey::DlcRequired;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_General:
            return EOvrMultiplayerErrorErrorKey::General;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_GroupFull:
            return EOvrMultiplayerErrorErrorKey::GroupFull;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_InviterNotJoinable:
            return EOvrMultiplayerErrorErrorKey::InviterNotJoinable;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_LevelNotHighEnough:
            return EOvrMultiplayerErrorErrorKey::LevelNotHighEnough;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_LevelNotUnlocked:
            return EOvrMultiplayerErrorErrorKey::LevelNotUnlocked;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_NetworkTimeout:
            return EOvrMultiplayerErrorErrorKey::NetworkTimeout;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_NoLongerAvailable:
            return EOvrMultiplayerErrorErrorKey::NoLongerAvailable;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_UpdateRequired:
            return EOvrMultiplayerErrorErrorKey::UpdateRequired;
        case ovrMultiplayerErrorErrorKey::ovrMultiplayerErrorErrorKey_TutorialRequired:
            return EOvrMultiplayerErrorErrorKey::TutorialRequired;
        default:
            return EOvrMultiplayerErrorErrorKey::Unknown;
    }
}

ovrNetSyncConnectionStatus ConvertNetSyncConnectionStatus(EOvrNetSyncConnectionStatus Value)
{
    switch (Value)
    {
        case EOvrNetSyncConnectionStatus::Connecting:
            return ovrNetSyncConnectionStatus::ovrNetSyncConnectionStatus_Connecting;
        case EOvrNetSyncConnectionStatus::Disconnected:
            return ovrNetSyncConnectionStatus::ovrNetSyncConnectionStatus_Disconnected;
        case EOvrNetSyncConnectionStatus::Connected:
            return ovrNetSyncConnectionStatus::ovrNetSyncConnectionStatus_Connected;
        default:
        return ovrNetSyncConnectionStatus::ovrNetSyncConnectionStatus_Unknown;
    }
}

EOvrNetSyncConnectionStatus ConvertNetSyncConnectionStatus(ovrNetSyncConnectionStatus Value)
{
    switch (Value)
    {
        case ovrNetSyncConnectionStatus::ovrNetSyncConnectionStatus_Connecting:
            return EOvrNetSyncConnectionStatus::Connecting;
        case ovrNetSyncConnectionStatus::ovrNetSyncConnectionStatus_Disconnected:
            return EOvrNetSyncConnectionStatus::Disconnected;
        case ovrNetSyncConnectionStatus::ovrNetSyncConnectionStatus_Connected:
            return EOvrNetSyncConnectionStatus::Connected;
        default:
            return EOvrNetSyncConnectionStatus::Unknown;
    }
}

ovrNetSyncDisconnectReason ConvertNetSyncDisconnectReason(EOvrNetSyncDisconnectReason Value)
{
    switch (Value)
    {
        case EOvrNetSyncDisconnectReason::LocalTerminated:
            return ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_LocalTerminated;
        case EOvrNetSyncDisconnectReason::ServerTerminated:
            return ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_ServerTerminated;
        case EOvrNetSyncDisconnectReason::Failed:
            return ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_Failed;
        case EOvrNetSyncDisconnectReason::Lost:
            return ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_Lost;
        default:
        return ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_Unknown;
    }
}

EOvrNetSyncDisconnectReason ConvertNetSyncDisconnectReason(ovrNetSyncDisconnectReason Value)
{
    switch (Value)
    {
        case ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_LocalTerminated:
            return EOvrNetSyncDisconnectReason::LocalTerminated;
        case ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_ServerTerminated:
            return EOvrNetSyncDisconnectReason::ServerTerminated;
        case ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_Failed:
            return EOvrNetSyncDisconnectReason::Failed;
        case ovrNetSyncDisconnectReason::ovrNetSyncDisconnectReason_Lost:
            return EOvrNetSyncDisconnectReason::Lost;
        default:
            return EOvrNetSyncDisconnectReason::Unknown;
    }
}

ovrNetSyncVoipMicSource ConvertNetSyncVoipMicSource(EOvrNetSyncVoipMicSource Value)
{
    switch (Value)
    {
        case EOvrNetSyncVoipMicSource::None:
            return ovrNetSyncVoipMicSource::ovrNetSyncVoipMicSource_None;
        case EOvrNetSyncVoipMicSource::Internal:
            return ovrNetSyncVoipMicSource::ovrNetSyncVoipMicSource_Internal;
        default:
        return ovrNetSyncVoipMicSource::ovrNetSyncVoipMicSource_Unknown;
    }
}

EOvrNetSyncVoipMicSource ConvertNetSyncVoipMicSource(ovrNetSyncVoipMicSource Value)
{
    switch (Value)
    {
        case ovrNetSyncVoipMicSource::ovrNetSyncVoipMicSource_None:
            return EOvrNetSyncVoipMicSource::None;
        case ovrNetSyncVoipMicSource::ovrNetSyncVoipMicSource_Internal:
            return EOvrNetSyncVoipMicSource::Internal;
        default:
            return EOvrNetSyncVoipMicSource::Unknown;
    }
}

ovrNetSyncVoipStreamMode ConvertNetSyncVoipStreamMode(EOvrNetSyncVoipStreamMode Value)
{
    switch (Value)
    {
        case EOvrNetSyncVoipStreamMode::Ambisonic:
            return ovrNetSyncVoipStreamMode::ovrNetSyncVoipStreamMode_Ambisonic;
        case EOvrNetSyncVoipStreamMode::Mono:
            return ovrNetSyncVoipStreamMode::ovrNetSyncVoipStreamMode_Mono;
        default:
        return ovrNetSyncVoipStreamMode::ovrNetSyncVoipStreamMode_Unknown;
    }
}

EOvrNetSyncVoipStreamMode ConvertNetSyncVoipStreamMode(ovrNetSyncVoipStreamMode Value)
{
    switch (Value)
    {
        case ovrNetSyncVoipStreamMode::ovrNetSyncVoipStreamMode_Ambisonic:
            return EOvrNetSyncVoipStreamMode::Ambisonic;
        case ovrNetSyncVoipStreamMode::ovrNetSyncVoipStreamMode_Mono:
            return EOvrNetSyncVoipStreamMode::Mono;
        default:
            return EOvrNetSyncVoipStreamMode::Unknown;
    }
}

ovrOfferTerm ConvertOfferTerm(EOvrOfferTerm Value)
{
    switch (Value)
    {
        case EOvrOfferTerm::WEEKLY:
            return ovrOfferTerm::ovrOfferTerm_WEEKLY;
        case EOvrOfferTerm::BIWEEKLY:
            return ovrOfferTerm::ovrOfferTerm_BIWEEKLY;
        case EOvrOfferTerm::MONTHLY:
            return ovrOfferTerm::ovrOfferTerm_MONTHLY;
        case EOvrOfferTerm::QUARTERLY:
            return ovrOfferTerm::ovrOfferTerm_QUARTERLY;
        case EOvrOfferTerm::SEMIANNUAL:
            return ovrOfferTerm::ovrOfferTerm_SEMIANNUAL;
        case EOvrOfferTerm::ANNUAL:
            return ovrOfferTerm::ovrOfferTerm_ANNUAL;
        case EOvrOfferTerm::BIANNUAL:
            return ovrOfferTerm::ovrOfferTerm_BIANNUAL;
        default:
        return ovrOfferTerm::ovrOfferTerm_Unknown;
    }
}

EOvrOfferTerm ConvertOfferTerm(ovrOfferTerm Value)
{
    switch (Value)
    {
        case ovrOfferTerm::ovrOfferTerm_WEEKLY:
            return EOvrOfferTerm::WEEKLY;
        case ovrOfferTerm::ovrOfferTerm_BIWEEKLY:
            return EOvrOfferTerm::BIWEEKLY;
        case ovrOfferTerm::ovrOfferTerm_MONTHLY:
            return EOvrOfferTerm::MONTHLY;
        case ovrOfferTerm::ovrOfferTerm_QUARTERLY:
            return EOvrOfferTerm::QUARTERLY;
        case ovrOfferTerm::ovrOfferTerm_SEMIANNUAL:
            return EOvrOfferTerm::SEMIANNUAL;
        case ovrOfferTerm::ovrOfferTerm_ANNUAL:
            return EOvrOfferTerm::ANNUAL;
        case ovrOfferTerm::ovrOfferTerm_BIANNUAL:
            return EOvrOfferTerm::BIANNUAL;
        default:
            return EOvrOfferTerm::Unknown;
    }
}

ovrOfferType ConvertOfferType(EOvrOfferType Value)
{
    switch (Value)
    {
        case EOvrOfferType::INTROOFFER:
            return ovrOfferType::ovrOfferType_INTROOFFER;
        case EOvrOfferType::FREETRIAL:
            return ovrOfferType::ovrOfferType_FREETRIAL;
        default:
        return ovrOfferType::ovrOfferType_Unknown;
    }
}

EOvrOfferType ConvertOfferType(ovrOfferType Value)
{
    switch (Value)
    {
        case ovrOfferType::ovrOfferType_INTROOFFER:
            return EOvrOfferType::INTROOFFER;
        case ovrOfferType::ovrOfferType_FREETRIAL:
            return EOvrOfferType::FREETRIAL;
        default:
            return EOvrOfferType::Unknown;
    }
}

ovrPartyUpdateAction ConvertPartyUpdateAction(EOvrPartyUpdateAction Value)
{
    switch (Value)
    {
        case EOvrPartyUpdateAction::Join:
            return ovrPartyUpdateAction::ovrPartyUpdateAction_Join;
        case EOvrPartyUpdateAction::Leave:
            return ovrPartyUpdateAction::ovrPartyUpdateAction_Leave;
        case EOvrPartyUpdateAction::Invite:
            return ovrPartyUpdateAction::ovrPartyUpdateAction_Invite;
        case EOvrPartyUpdateAction::Uninvite:
            return ovrPartyUpdateAction::ovrPartyUpdateAction_Uninvite;
        default:
        return ovrPartyUpdateAction::ovrPartyUpdateAction_Unknown;
    }
}

EOvrPartyUpdateAction ConvertPartyUpdateAction(ovrPartyUpdateAction Value)
{
    switch (Value)
    {
        case ovrPartyUpdateAction::ovrPartyUpdateAction_Join:
            return EOvrPartyUpdateAction::Join;
        case ovrPartyUpdateAction::ovrPartyUpdateAction_Leave:
            return EOvrPartyUpdateAction::Leave;
        case ovrPartyUpdateAction::ovrPartyUpdateAction_Invite:
            return EOvrPartyUpdateAction::Invite;
        case ovrPartyUpdateAction::ovrPartyUpdateAction_Uninvite:
            return EOvrPartyUpdateAction::Uninvite;
        default:
            return EOvrPartyUpdateAction::Unknown;
    }
}

ovrPermissionGrantStatus ConvertPermissionGrantStatus(EOvrPermissionGrantStatus Value)
{
    switch (Value)
    {
        case EOvrPermissionGrantStatus::Granted:
            return ovrPermissionGrantStatus::ovrPermissionGrantStatus_Granted;
        case EOvrPermissionGrantStatus::Denied:
            return ovrPermissionGrantStatus::ovrPermissionGrantStatus_Denied;
        case EOvrPermissionGrantStatus::Blocked:
            return ovrPermissionGrantStatus::ovrPermissionGrantStatus_Blocked;
        default:
        return ovrPermissionGrantStatus::ovrPermissionGrantStatus_Unknown;
    }
}

EOvrPermissionGrantStatus ConvertPermissionGrantStatus(ovrPermissionGrantStatus Value)
{
    switch (Value)
    {
        case ovrPermissionGrantStatus::ovrPermissionGrantStatus_Granted:
            return EOvrPermissionGrantStatus::Granted;
        case ovrPermissionGrantStatus::ovrPermissionGrantStatus_Denied:
            return EOvrPermissionGrantStatus::Denied;
        case ovrPermissionGrantStatus::ovrPermissionGrantStatus_Blocked:
            return EOvrPermissionGrantStatus::Blocked;
        default:
            return EOvrPermissionGrantStatus::Unknown;
    }
}

ovrPlatformInitializeResult ConvertPlatformInitializeResult(EOvrPlatformInitializeResult Value)
{
    switch (Value)
    {
        case EOvrPlatformInitializeResult::Success:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_Success;
        case EOvrPlatformInitializeResult::Uninitialized:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_Uninitialized;
        case EOvrPlatformInitializeResult::PreLoaded:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_PreLoaded;
        case EOvrPlatformInitializeResult::FileInvalid:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_FileInvalid;
        case EOvrPlatformInitializeResult::SignatureInvalid:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_SignatureInvalid;
        case EOvrPlatformInitializeResult::UnableToVerify:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_UnableToVerify;
        case EOvrPlatformInitializeResult::VersionMismatch:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_VersionMismatch;
        case EOvrPlatformInitializeResult::InvalidCredentials:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_InvalidCredentials;
        case EOvrPlatformInitializeResult::NotEntitled:
            return ovrPlatformInitializeResult::ovrPlatformInitialize_NotEntitled;
        default:
        return ovrPlatformInitializeResult::ovrPlatformInitialize_Unknown;
    }
}

EOvrPlatformInitializeResult ConvertPlatformInitializeResult(ovrPlatformInitializeResult Value)
{
    switch (Value)
    {
        case ovrPlatformInitializeResult::ovrPlatformInitialize_Success:
            return EOvrPlatformInitializeResult::Success;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_Uninitialized:
            return EOvrPlatformInitializeResult::Uninitialized;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_PreLoaded:
            return EOvrPlatformInitializeResult::PreLoaded;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_FileInvalid:
            return EOvrPlatformInitializeResult::FileInvalid;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_SignatureInvalid:
            return EOvrPlatformInitializeResult::SignatureInvalid;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_UnableToVerify:
            return EOvrPlatformInitializeResult::UnableToVerify;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_VersionMismatch:
            return EOvrPlatformInitializeResult::VersionMismatch;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_InvalidCredentials:
            return EOvrPlatformInitializeResult::InvalidCredentials;
        case ovrPlatformInitializeResult::ovrPlatformInitialize_NotEntitled:
            return EOvrPlatformInitializeResult::NotEntitled;
        default:
            return EOvrPlatformInitializeResult::Unknown;
    }
}

ovrProductType ConvertProductType(EOvrProductType Value)
{
    switch (Value)
    {
        case EOvrProductType::DURABLE:
            return ovrProductType::ovrProductType_DURABLE;
        case EOvrProductType::CONSUMABLE:
            return ovrProductType::ovrProductType_CONSUMABLE;
        case EOvrProductType::SUBSCRIPTION:
            return ovrProductType::ovrProductType_SUBSCRIPTION;
        default:
        return ovrProductType::ovrProductType_Unknown;
    }
}

EOvrProductType ConvertProductType(ovrProductType Value)
{
    switch (Value)
    {
        case ovrProductType::ovrProductType_DURABLE:
            return EOvrProductType::DURABLE;
        case ovrProductType::ovrProductType_CONSUMABLE:
            return EOvrProductType::CONSUMABLE;
        case ovrProductType::ovrProductType_SUBSCRIPTION:
            return EOvrProductType::SUBSCRIPTION;
        default:
            return EOvrProductType::Unknown;
    }
}

ovrReportRequestResponse ConvertReportRequestResponse(EOvrReportRequestResponse Value)
{
    switch (Value)
    {
        case EOvrReportRequestResponse::Handled:
            return ovrReportRequestResponse::ovrReportRequestResponse_Handled;
        case EOvrReportRequestResponse::Unhandled:
            return ovrReportRequestResponse::ovrReportRequestResponse_Unhandled;
        case EOvrReportRequestResponse::Unavailable:
            return ovrReportRequestResponse::ovrReportRequestResponse_Unavailable;
        default:
        return ovrReportRequestResponse::ovrReportRequestResponse_Unknown;
    }
}

EOvrReportRequestResponse ConvertReportRequestResponse(ovrReportRequestResponse Value)
{
    switch (Value)
    {
        case ovrReportRequestResponse::ovrReportRequestResponse_Handled:
            return EOvrReportRequestResponse::Handled;
        case ovrReportRequestResponse::ovrReportRequestResponse_Unhandled:
            return EOvrReportRequestResponse::Unhandled;
        case ovrReportRequestResponse::ovrReportRequestResponse_Unavailable:
            return EOvrReportRequestResponse::Unavailable;
        default:
            return EOvrReportRequestResponse::Unknown;
    }
}

ovrRichPresenceExtraContext ConvertRichPresenceExtraContext(EOvrRichPresenceExtraContext Value)
{
    switch (Value)
    {
        case EOvrRichPresenceExtraContext::None:
            return ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_None;
        case EOvrRichPresenceExtraContext::CurrentCapacity:
            return ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_CurrentCapacity;
        case EOvrRichPresenceExtraContext::StartedAgo:
            return ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_StartedAgo;
        case EOvrRichPresenceExtraContext::EndingIn:
            return ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_EndingIn;
        case EOvrRichPresenceExtraContext::LookingForAMatch:
            return ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_LookingForAMatch;
        default:
        return ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_Unknown;
    }
}

EOvrRichPresenceExtraContext ConvertRichPresenceExtraContext(ovrRichPresenceExtraContext Value)
{
    switch (Value)
    {
        case ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_None:
            return EOvrRichPresenceExtraContext::None;
        case ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_CurrentCapacity:
            return EOvrRichPresenceExtraContext::CurrentCapacity;
        case ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_StartedAgo:
            return EOvrRichPresenceExtraContext::StartedAgo;
        case ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_EndingIn:
            return EOvrRichPresenceExtraContext::EndingIn;
        case ovrRichPresenceExtraContext::ovrRichPresenceExtraContext_LookingForAMatch:
            return EOvrRichPresenceExtraContext::LookingForAMatch;
        default:
            return EOvrRichPresenceExtraContext::Unknown;
    }
}

ovrSdkAccountType ConvertSdkAccountType(EOvrSdkAccountType Value)
{
    switch (Value)
    {
        case EOvrSdkAccountType::Oculus:
            return ovrSdkAccountType::ovrSdkAccountType_Oculus;
        case EOvrSdkAccountType::FacebookGameroom:
            return ovrSdkAccountType::ovrSdkAccountType_FacebookGameroom;
        default:
        return ovrSdkAccountType::ovrSdkAccountType_Unknown;
    }
}

EOvrSdkAccountType ConvertSdkAccountType(ovrSdkAccountType Value)
{
    switch (Value)
    {
        case ovrSdkAccountType::ovrSdkAccountType_Oculus:
            return EOvrSdkAccountType::Oculus;
        case ovrSdkAccountType::ovrSdkAccountType_FacebookGameroom:
            return EOvrSdkAccountType::FacebookGameroom;
        default:
            return EOvrSdkAccountType::Unknown;
    }
}

ovrServiceProvider ConvertServiceProvider(EOvrServiceProvider Value)
{
    switch (Value)
    {
        case EOvrServiceProvider::Dropbox:
            return ovrServiceProvider::ovrServiceProvider_Dropbox;
        case EOvrServiceProvider::Facebook:
            return ovrServiceProvider::ovrServiceProvider_Facebook;
        case EOvrServiceProvider::Google:
            return ovrServiceProvider::ovrServiceProvider_Google;
        case EOvrServiceProvider::Instagram:
            return ovrServiceProvider::ovrServiceProvider_Instagram;
        case EOvrServiceProvider::RemoteMedia:
            return ovrServiceProvider::ovrServiceProvider_RemoteMedia;
        default:
        return ovrServiceProvider::ovrServiceProvider_Unknown;
    }
}

EOvrServiceProvider ConvertServiceProvider(ovrServiceProvider Value)
{
    switch (Value)
    {
        case ovrServiceProvider::ovrServiceProvider_Dropbox:
            return EOvrServiceProvider::Dropbox;
        case ovrServiceProvider::ovrServiceProvider_Facebook:
            return EOvrServiceProvider::Facebook;
        case ovrServiceProvider::ovrServiceProvider_Google:
            return EOvrServiceProvider::Google;
        case ovrServiceProvider::ovrServiceProvider_Instagram:
            return EOvrServiceProvider::Instagram;
        case ovrServiceProvider::ovrServiceProvider_RemoteMedia:
            return EOvrServiceProvider::RemoteMedia;
        default:
            return EOvrServiceProvider::Unknown;
    }
}

ovrShareMediaStatus ConvertShareMediaStatus(EOvrShareMediaStatus Value)
{
    switch (Value)
    {
        case EOvrShareMediaStatus::Shared:
            return ovrShareMediaStatus::ovrShareMediaStatus_Shared;
        case EOvrShareMediaStatus::Canceled:
            return ovrShareMediaStatus::ovrShareMediaStatus_Canceled;
        default:
        return ovrShareMediaStatus::ovrShareMediaStatus_Unknown;
    }
}

EOvrShareMediaStatus ConvertShareMediaStatus(ovrShareMediaStatus Value)
{
    switch (Value)
    {
        case ovrShareMediaStatus::ovrShareMediaStatus_Shared:
            return EOvrShareMediaStatus::Shared;
        case ovrShareMediaStatus::ovrShareMediaStatus_Canceled:
            return EOvrShareMediaStatus::Canceled;
        default:
            return EOvrShareMediaStatus::Unknown;
    }
}

ovrSystemVoipStatus ConvertSystemVoipStatus(EOvrSystemVoipStatus Value)
{
    switch (Value)
    {
        case EOvrSystemVoipStatus::Unavailable:
            return ovrSystemVoipStatus::ovrSystemVoipStatus_Unavailable;
        case EOvrSystemVoipStatus::Suppressed:
            return ovrSystemVoipStatus::ovrSystemVoipStatus_Suppressed;
        case EOvrSystemVoipStatus::Active:
            return ovrSystemVoipStatus::ovrSystemVoipStatus_Active;
        default:
        return ovrSystemVoipStatus::ovrSystemVoipStatus_Unknown;
    }
}

EOvrSystemVoipStatus ConvertSystemVoipStatus(ovrSystemVoipStatus Value)
{
    switch (Value)
    {
        case ovrSystemVoipStatus::ovrSystemVoipStatus_Unavailable:
            return EOvrSystemVoipStatus::Unavailable;
        case ovrSystemVoipStatus::ovrSystemVoipStatus_Suppressed:
            return EOvrSystemVoipStatus::Suppressed;
        case ovrSystemVoipStatus::ovrSystemVoipStatus_Active:
            return EOvrSystemVoipStatus::Active;
        default:
            return EOvrSystemVoipStatus::Unknown;
    }
}

ovrTimeWindow ConvertTimeWindow(EOvrTimeWindow Value)
{
    switch (Value)
    {
        case EOvrTimeWindow::OneHour:
            return ovrTimeWindow::ovrTimeWindow_OneHour;
        case EOvrTimeWindow::OneDay:
            return ovrTimeWindow::ovrTimeWindow_OneDay;
        case EOvrTimeWindow::OneWeek:
            return ovrTimeWindow::ovrTimeWindow_OneWeek;
        case EOvrTimeWindow::ThirtyDays:
            return ovrTimeWindow::ovrTimeWindow_ThirtyDays;
        case EOvrTimeWindow::NinetyDays:
            return ovrTimeWindow::ovrTimeWindow_NinetyDays;
        default:
        return ovrTimeWindow::ovrTimeWindow_Unknown;
    }
}

EOvrTimeWindow ConvertTimeWindow(ovrTimeWindow Value)
{
    switch (Value)
    {
        case ovrTimeWindow::ovrTimeWindow_OneHour:
            return EOvrTimeWindow::OneHour;
        case ovrTimeWindow::ovrTimeWindow_OneDay:
            return EOvrTimeWindow::OneDay;
        case ovrTimeWindow::ovrTimeWindow_OneWeek:
            return EOvrTimeWindow::OneWeek;
        case ovrTimeWindow::ovrTimeWindow_ThirtyDays:
            return EOvrTimeWindow::ThirtyDays;
        case ovrTimeWindow::ovrTimeWindow_NinetyDays:
            return EOvrTimeWindow::NinetyDays;
        default:
            return EOvrTimeWindow::Unknown;
    }
}

ovrUserOrdering ConvertUserOrdering(EOvrUserOrdering Value)
{
    switch (Value)
    {
        case EOvrUserOrdering::None:
            return ovrUserOrdering::ovrUserOrdering_None;
        case EOvrUserOrdering::PresenceAlphabetical:
            return ovrUserOrdering::ovrUserOrdering_PresenceAlphabetical;
        default:
        return ovrUserOrdering::ovrUserOrdering_Unknown;
    }
}

EOvrUserOrdering ConvertUserOrdering(ovrUserOrdering Value)
{
    switch (Value)
    {
        case ovrUserOrdering::ovrUserOrdering_None:
            return EOvrUserOrdering::None;
        case ovrUserOrdering::ovrUserOrdering_PresenceAlphabetical:
            return EOvrUserOrdering::PresenceAlphabetical;
        default:
            return EOvrUserOrdering::Unknown;
    }
}

ovrUserPresenceStatus ConvertUserPresenceStatus(EOvrUserPresenceStatus Value)
{
    switch (Value)
    {
        case EOvrUserPresenceStatus::Online:
            return ovrUserPresenceStatus::ovrUserPresenceStatus_Online;
        case EOvrUserPresenceStatus::Offline:
            return ovrUserPresenceStatus::ovrUserPresenceStatus_Offline;
        default:
        return ovrUserPresenceStatus::ovrUserPresenceStatus_Unknown;
    }
}

EOvrUserPresenceStatus ConvertUserPresenceStatus(ovrUserPresenceStatus Value)
{
    switch (Value)
    {
        case ovrUserPresenceStatus::ovrUserPresenceStatus_Online:
            return EOvrUserPresenceStatus::Online;
        case ovrUserPresenceStatus::ovrUserPresenceStatus_Offline:
            return EOvrUserPresenceStatus::Offline;
        default:
            return EOvrUserPresenceStatus::Unknown;
    }
}

ovrVoipBitrate ConvertVoipBitrate(EOvrVoipBitrate Value)
{
    switch (Value)
    {
        case EOvrVoipBitrate::B16000:
            return ovrVoipBitrate::ovrVoipBitrate_B16000;
        case EOvrVoipBitrate::B24000:
            return ovrVoipBitrate::ovrVoipBitrate_B24000;
        case EOvrVoipBitrate::B32000:
            return ovrVoipBitrate::ovrVoipBitrate_B32000;
        case EOvrVoipBitrate::B64000:
            return ovrVoipBitrate::ovrVoipBitrate_B64000;
        case EOvrVoipBitrate::B96000:
            return ovrVoipBitrate::ovrVoipBitrate_B96000;
        case EOvrVoipBitrate::B128000:
            return ovrVoipBitrate::ovrVoipBitrate_B128000;
        default:
        return ovrVoipBitrate::ovrVoipBitrate_Unknown;
    }
}

EOvrVoipBitrate ConvertVoipBitrate(ovrVoipBitrate Value)
{
    switch (Value)
    {
        case ovrVoipBitrate::ovrVoipBitrate_B16000:
            return EOvrVoipBitrate::B16000;
        case ovrVoipBitrate::ovrVoipBitrate_B24000:
            return EOvrVoipBitrate::B24000;
        case ovrVoipBitrate::ovrVoipBitrate_B32000:
            return EOvrVoipBitrate::B32000;
        case ovrVoipBitrate::ovrVoipBitrate_B64000:
            return EOvrVoipBitrate::B64000;
        case ovrVoipBitrate::ovrVoipBitrate_B96000:
            return EOvrVoipBitrate::B96000;
        case ovrVoipBitrate::ovrVoipBitrate_B128000:
            return EOvrVoipBitrate::B128000;
        default:
            return EOvrVoipBitrate::Unknown;
    }
}

ovrVoipDtxState ConvertVoipDtxState(EOvrVoipDtxState Value)
{
    switch (Value)
    {
        case EOvrVoipDtxState::Enabled:
            return ovrVoipDtxState::ovrVoipDtxState_Enabled;
        case EOvrVoipDtxState::Disabled:
            return ovrVoipDtxState::ovrVoipDtxState_Disabled;
        default:
        return ovrVoipDtxState::ovrVoipDtxState_Unknown;
    }
}

EOvrVoipDtxState ConvertVoipDtxState(ovrVoipDtxState Value)
{
    switch (Value)
    {
        case ovrVoipDtxState::ovrVoipDtxState_Enabled:
            return EOvrVoipDtxState::Enabled;
        case ovrVoipDtxState::ovrVoipDtxState_Disabled:
            return EOvrVoipDtxState::Disabled;
        default:
            return EOvrVoipDtxState::Unknown;
    }
}

ovrVoipMuteState ConvertVoipMuteState(EOvrVoipMuteState Value)
{
    switch (Value)
    {
        case EOvrVoipMuteState::Muted:
            return ovrVoipMuteState::ovrVoipMuteState_Muted;
        case EOvrVoipMuteState::Unmuted:
            return ovrVoipMuteState::ovrVoipMuteState_Unmuted;
        default:
        return ovrVoipMuteState::ovrVoipMuteState_Unknown;
    }
}

EOvrVoipMuteState ConvertVoipMuteState(ovrVoipMuteState Value)
{
    switch (Value)
    {
        case ovrVoipMuteState::ovrVoipMuteState_Muted:
            return EOvrVoipMuteState::Muted;
        case ovrVoipMuteState::ovrVoipMuteState_Unmuted:
            return EOvrVoipMuteState::Unmuted;
        default:
            return EOvrVoipMuteState::Unknown;
    }
}

ovrVoipSampleRate ConvertVoipSampleRate(EOvrVoipSampleRate Value)
{
    switch (Value)
    {
        case EOvrVoipSampleRate::HZ24000:
            return ovrVoipSampleRate::ovrVoipSampleRate_HZ24000;
        case EOvrVoipSampleRate::HZ44100:
            return ovrVoipSampleRate::ovrVoipSampleRate_HZ44100;
        case EOvrVoipSampleRate::HZ48000:
            return ovrVoipSampleRate::ovrVoipSampleRate_HZ48000;
        default:
        return ovrVoipSampleRate::ovrVoipSampleRate_Unknown;
    }
}

EOvrVoipSampleRate ConvertVoipSampleRate(ovrVoipSampleRate Value)
{
    switch (Value)
    {
        case ovrVoipSampleRate::ovrVoipSampleRate_HZ24000:
            return EOvrVoipSampleRate::HZ24000;
        case ovrVoipSampleRate::ovrVoipSampleRate_HZ44100:
            return EOvrVoipSampleRate::HZ44100;
        case ovrVoipSampleRate::ovrVoipSampleRate_HZ48000:
            return EOvrVoipSampleRate::HZ48000;
        default:
            return EOvrVoipSampleRate::Unknown;
    }
}

