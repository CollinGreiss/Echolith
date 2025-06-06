/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#ifndef OVR_REQUESTS_USER_H
#define OVR_REQUESTS_USER_H

#include "OVR_Types.h"
#include "OVR_Platform_Defs.h"

#include "OVR_AbuseReportOptions.h"
#include "OVR_BlockedUserArray.h"
#include "OVR_UserArray.h"
#include "OVR_UserCapabilityArray.h"
#include "OVR_UserOptions.h"

/// \file
/// Overview:
/// User objects represent people in the real world; their hopes, their dreams, and their current presence information.
///
/// Verifying Identify:
/// You can pass the result of ovr_UserProof_Generate() and ovr_GetLoggedInUserID()
/// to your your backend. Your server can use our api to verify identity.
/// 'https://graph.oculus.com/user_nonce_validate?nonce=USER_PROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
///
/// NOTE: the nonce is only good for one check and then it's invalidated.
///
/// App-Scoped IDs:
/// To protect user privacy, users have a different ovrID across different applications. If you are caching them,
/// make sure that you're also restricting them per application.


/// \file
/// This class provides methods to access information about the
/// ::ovrUserHandle. It allows you to retrieve a user's ID, access token, and
/// org-scoped ID, as well as their friends list and recently met users.
/// Additionally, it provides methods to launch various flows such as blocking,
/// unblocking, reporting, and sending friend requests. It's useful when you
/// need to manage user relationships or perform actions that require user
/// authentication within your application.

/// Retrieve the user with the given ID. This might fail if the ID is invalid
/// or the user is blocked.
///
/// NOTE: Users will have a unique ID per application.
/// \param userID User ID retrieved with this application.
///
/// A message with type ::ovrMessage_User_Get will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUser().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_Get(ovrID userID);

/// Return an access token string for this user, suitable for making REST calls
/// against graph.oculus.com.
///
/// A message with type ::ovrMessage_User_GetAccessToken will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ovr_Message_GetString().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetAccessToken();

/// Return the IDs of users entitled to use the current app that are blocked by
/// the specified user
///
/// A message with type ::ovrMessage_User_GetBlockedUsers will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrBlockedUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetBlockedUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetBlockedUsers();

/// Retrieve the currently signed in user. This call is available offline.
///
/// NOTE: This will not return the user's presence as it should always be
/// 'online' in your application.
///
/// NOTE: Users will have a unique ID per application.
///
/// <b>Error codes</b>
/// - \b 100: Something went wrong.
///
/// A message with type ::ovrMessage_User_GetLoggedInUser will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUser().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUser();

/// Retrieve a list of the logged in user's bidirectional followers. The
/// payload type will be an array of ::ovrUserHandle
///
/// A message with type ::ovrMessage_User_GetLoggedInUserFriends will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUserFriends();

/// Retrieve the currently signed in user's managed info. This call is not
/// available offline.
///
/// NOTE: This will return data only if the logged in user is a managed Meta
/// account (MMA).
///
/// A message with type ::ovrMessage_User_GetLoggedInUserManagedInfo will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUser().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetLoggedInUserManagedInfo();

/// Get the next page of entries
/// \param handle The handle to the array to get the next page of entries.
///
/// A message with type ::ovrMessage_User_GetNextBlockedUserArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrBlockedUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetBlockedUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetNextBlockedUserArrayPage(ovrBlockedUserArrayHandle handle);

/// Get the next page of entries
/// \param handle The handle to the array to get the next page of entries.
///
/// A message with type ::ovrMessage_User_GetNextUserArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetNextUserArrayPage(ovrUserArrayHandle handle);

/// Get the next page of entries
/// \param handle The handle to the array to get the next page of entries.
///
/// A message with type ::ovrMessage_User_GetNextUserCapabilityArrayPage will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserCapabilityArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserCapabilityArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetNextUserCapabilityArrayPage(ovrUserCapabilityArrayHandle handle);

/// returns an ovrID which is unique per org. allows different apps within the
/// same org to identify the user.
/// \param userID The id of the user that we are going to get its org scoped ID ::ovrOrgScopedIDHandle.
///
/// A message with type ::ovrMessage_User_GetOrgScopedID will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrOrgScopedIDHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetOrgScopedID().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetOrgScopedID(ovrID userID);

/// Returns all accounts belonging to this user. Accounts are the Oculus user
/// and x-users that are linked to this user.
///
/// A message with type ::ovrMessage_User_GetSdkAccounts will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrSdkAccountArrayHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetSdkAccountArray().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetSdkAccounts();

/// Part of the scheme to confirm the identity of a particular user in your
/// backend. You can pass the result of ovr_User_GetUserProof() and a user ID
/// from ovr_User_GetID() to your backend. Your server can then use our api to
/// verify identity. 'https://graph.oculus.com/user_nonce_validate?nonce=USER_P
/// ROOF&user_id=USER_ID&access_token=ACCESS_TOKEN'
///
/// NOTE: The nonce is only good for one check and then it is invalidated.
///
/// A message with type ::ovrMessage_User_GetUserProof will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrUserProofHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetUserProof().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_GetUserProof();

/// Launch the flow for blocking the given user. You can't follow, be followed,
/// invited, or searched by a blocked user, for example. You can remove the
/// block via ovr_User_LaunchUnblockFlow.
/// \param userID The ID of the user that the viewer is going to launch the block flow request.
///
/// A message with type ::ovrMessage_User_LaunchBlockFlow will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLaunchBlockFlowResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLaunchBlockFlowResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_LaunchBlockFlow(ovrID userID);

/// Launch the flow for sending a follow request to a user.
/// \param userID The ID of the target user that is going to send the friend follow request to.
///
/// A message with type ::ovrMessage_User_LaunchFriendRequestFlow will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLaunchFriendRequestFlowResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLaunchFriendRequestFlowResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_LaunchFriendRequestFlow(ovrID userID);

/// Launch the flow for unblocking a user that the viewer has blocked.
/// \param userID The ID of the user that the viewer is going to launch the unblock flow request.
///
/// A message with type ::ovrMessage_User_LaunchUnblockFlow will be generated in response.
///
/// First call ::ovr_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ovrLaunchUnblockFlowResultHandle.
/// Extract the payload from the message handle with ::ovr_Message_GetLaunchUnblockFlowResult().
OVRP_PUBLIC_FUNCTION(ovrRequest) ovr_User_LaunchUnblockFlow(ovrID userID);

#endif
