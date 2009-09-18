/*
 * Copyright 2009, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>
#include <string.h>

#include "hardware_legacy/WiMaxAPI.h"

#define LOG_TAG "WiMaxHW"

static BOOL connected = FALSE;
static CHAR connectedNspName[MAX_SIZE_OF_NSP_NAME] = {'\0'};

WIMAX_API_RET WiMaxAPIOpen( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	pDeviceId->structureSize = 24;
	pDeviceId->sdkHandle = 0;
	pDeviceId->privilege = 0;
	pDeviceId->deviceIndex = 1;
	pDeviceId->apiVersion = 10;
	pDeviceId->devicePresenceStatus = FALSE;

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetListDevice( WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_HW_DEVICE_ID_P pHwDeviceIdList, UINT32* pHwDeviceIdListSize ) {
	pHwDeviceIdList[0].structureSize = 524;
	pHwDeviceIdList[0].deviceIndex = 1;
	strcpy(pHwDeviceIdList[0].deviceName, "Test Device");
	pHwDeviceIdList[0].deviceType = WIMAX_API_DEV_TYPE_WIMAX;

	*pHwDeviceIdListSize = 1;

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET WiMaxDeviceOpen( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET WiMaxDeviceClose( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET WiMaxAPIClose( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET CmdControlPowerManagement( WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_RF_STATE powerState) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET CmdResetWimaxDevice( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET CmdResetToFactorySettings( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetErrorString(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_RET errorCode, WIMAX_API_STRING buffer, UINT32* pLength) {
	strcpy(buffer, "Dummy Error Message");
	*pLength = 20;
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SetServiceProviderUnLock(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_STRING lockCode) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetServiceProviderLockStatus(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_LOCK_STATUS_P pLockStatus, WIMAX_API_STRING nspName) {

	*pLockStatus = WIMAX_API_DEVICE_UNLOCKED;
	strcpy(nspName, "CLEAR");

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetNetworkList (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_NSP_INFO_P pNSPInfo, UINT32* pArrayLength) {

	pNSPInfo[0].structureSize = 276;
	strcpy(pNSPInfo[0].NSPName, "CLEAR");
	pNSPInfo[0].NSPid = 4;
	pNSPInfo[0].RSSI = 60;
	pNSPInfo[0].CINR = 25;
	pNSPInfo[0].networkType = WIMAX_API_HOME;

	pNSPInfo[1].structureSize = 276;
	strcpy(pNSPInfo[1].NSPName, "XOHM");
	pNSPInfo[1].NSPid = 4;
	pNSPInfo[1].RSSI = 50;
	pNSPInfo[1].CINR = 35;
	pNSPInfo[1].networkType = WIMAX_API_HOME;

	*pArrayLength = 2;

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET CmdConnectToNetwork (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_STRING nspName, WIMAX_API_PROFILE_ID profileId, WIMAX_API_STRING password) {
	connected = TRUE;
	strcpy(connectedNspName, nspName);
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET CmdDisconnectFromNetwork( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	connected = FALSE;
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET CmdNetworkSearchWideScan( WIMAX_API_DEVICE_ID_P pDeviceId ) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetIPInterfaceIndex(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_INTERFACE_INFO_P pInterfaceInfo) {
	pInterfaceInfo->structureSize = 516;
	strcpy(pInterfaceInfo->interfaceName,"eth3");
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetSelectProfileList (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_PROFILE_INFO_P pProfileList, UINT32* pListSize) {
	pProfileList[0].structureSize = 520;
	pProfileList[0].profileID = 1;
	strcpy(pProfileList[0].profileName, "Dummy Profile");
	*pListSize = 1;

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetLinkStatus (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_LINK_STATUS_INFO_P pLinkStatus) {
	pLinkStatus->structureSize = 20;
	pLinkStatus->centerFrequency = 26700;
	pLinkStatus->RSSI = 60;
	pLinkStatus->CINR = 25;
	pLinkStatus->txPWR = 23;

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetDeviceInformation (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_DEVICE_INFO_P pDeviceInfo) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetDeviceStatus (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_DEVICE_STATUS_P pDeviceStatus, WIMAX_API_CONNECTION_PROGRESS_INFO_P pConnectionProgressInfo) {
	if(connected) {
		*pDeviceStatus = WIMAX_API_DEVICE_STATUS_Data_Connected;
		*pConnectionProgressInfo = WIMAX_API_DEVICE_CONNECTION_PROGRESS_Registered;
	}else {
		*pDeviceStatus = WIMAX_API_DEVICE_STATUS_Ready;
		*pConnectionProgressInfo = WIMAX_API_DEVICE_CONNECTION_PROGRESS_Ranging;
	}
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetConnectedNSP (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_CONNECTED_NSP_INFO_P pConnectedNSP) {
	pConnectedNSP->structureSize = 782;
	strcpy(pConnectedNSP->NSPName, connectedNspName);
	strcpy(pConnectedNSP->NSPRealm, "clearwire.com");
	pConnectedNSP->NSPid = 4;
	pConnectedNSP->activated = 1;
	pConnectedNSP->RSSI = -60;
	pConnectedNSP->CINR = -10;
	pConnectedNSP->networkType = WIMAX_API_HOME;

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SetRoamingMode (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_ROAMING_MODE roamingMode) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetRoamingMode (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_ROAMING_MODE_P pRoamingMode) {
	*pRoamingMode = WIMAX_API_ROAMING_ENABLED;
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetStatistics (WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_CONNECTION_STAT_P pStatistics) {
	pStatistics->structureSize = 40;
	pStatistics->totalRxByte = 232323;
	pStatistics->totalTxByte = 8303;
	pStatistics->totalRxPackets = 2323;
	pStatistics->totalTxPackets = 83;

	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetProvisioningStatus(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_STRING nspName, BOOL* pProvisoningStatus) {
	*pProvisoningStatus = TRUE;
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetContactInformation(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_STRING nspName, WIMAX_API_CONTACT_INFO_P pContactInfo, UINT32* pSizeOfContactList) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET GetPackageInformation(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_PACKAGE_INFO_P pPackageInfo) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SetPackageUpdateState(WIMAX_API_DEVICE_ID_P pDeviceId, WIMAX_API_PACKAGE_UPDATE_STATE packageUpdateState) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribeDeviceStatusChange (WIMAX_API_DEVICE_ID_P pDeviceId, IndDeviceStatusUpdate pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribeDeviceInsertRemove (WIMAX_API_DEVICE_ID_P pDeviceId, IndDeviceInsertRemove pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribeControlPowerManagement (WIMAX_API_DEVICE_ID_P pDeviceId, IndControlPowerManagement pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribeConnectToNetwork (WIMAX_API_DEVICE_ID_P pDeviceId, IndConnectToNetwork pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribeDisconnectToNetwork (WIMAX_API_DEVICE_ID_P pDeviceId, IndDisconnectToNetwork pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribeNetworkSearchWideScan (WIMAX_API_DEVICE_ID_P pDeviceId, IndNetworkSearchWideScan pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribeProvisioningOperation (WIMAX_API_DEVICE_ID_P pDeviceId, IndProvisioningOperation pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET SubscribePackageUpdate (WIMAX_API_DEVICE_ID_P pDeviceId, IndPackageUpdate pCallbackFnc) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribeDeviceStatusChange (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribeDeviceInsertRemove (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribeControlPowerManagement (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribeConnectToNetwork (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribeDisconnectToNetwork (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribeNetworkSearchWideScan (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribeProvisioningOperation (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}

WIMAX_API_RET UnsubscribePackageUpdate (WIMAX_API_DEVICE_ID_P pDeviceId) {
	return WIMAX_API_RET_SUCCESS;
}


