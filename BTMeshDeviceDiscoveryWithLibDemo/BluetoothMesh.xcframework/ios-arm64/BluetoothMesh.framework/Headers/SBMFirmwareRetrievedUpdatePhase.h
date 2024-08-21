//
//  SBMFirmwareRetrievedUpdatePhase.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 24/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 The phase of the firmware update on the Firmware Update Server.
 The value of the Retrieved Update Phase field is either the retrieved value of the Update Phase state or a value set by the client.
 */
typedef NS_ENUM(NSInteger, SBMFirmwareRetrievedUpdatePhase)
{
    /**
     No firmware transfer is in progress.
     */
    SBMFirmwareRetrievedUpdatePhaseIdle = 0,
    /**
     Firmware transfer failed because of a BLOB Transfer protocol error such as a timeout.
     */
    SBMFirmwareRetrievedUpdatePhaseTransferError = 1,
    /**
     Firmware transfer is in progress.
     */
    SBMFirmwareRetrievedUpdatePhaseTransferInProgress = 2,
    /**
     Verification of the firmware image is in progress.
     */
    SBMFirmwareRetrievedUpdatePhaseVerificationInProgress = 3,
    /**
     Firmware image verification succeeded.
     */
    SBMFirmwareRetrievedUpdatePhaseVerificationSucceeded = 4,
    /**
     Firmware image verification failed.
     */
    SBMFirmwareRetrievedUpdatePhaseVerificationFailed = 5,
    /**
     Firmware applying is in progress
     */
    SBMFirmwareRetrievedUpdatePhaseApplyInProgress = 6,
    /**
     Firmware transfer has been canceled.
     */
    SBMFirmwareRetrievedUpdatePhaseTransferCanceled = 7,
    /**
     Firmware applying succeeded. (value set by the Firmware Update client, not retrieved)
     */
    SBMFirmwareRetrievedUpdatePhaseApplySuccess = 8,
    /**
     Firmware applying failed. (value set by the Firmware Update client, not retrieved)
     */
    SBMFirmwareRetrievedUpdatePhaseApplyFailed = 9,
    /**
     Phase of a node was not yet retrieved. (value set by the Firmware Update client, not retrieved)
     */
    SBMFirmwareRetrievedUpdatePhaseUnknown = 10,
    /**
     Value not defined.
     */
    SBMFirmwareRetrievedUpdatePhaseNotDefined
};
