//
//  SBMFirmwareUpdateStatusCode.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 20/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 The status codes for the Firmware Update Server model and the Firmware Update Client model.
 */
typedef NS_ENUM(NSInteger, SBMFirmwareUpdateStatusCode)
{
    /**
     The message was processed successfully.
     */
    SBMFirmwareUpdateStatusCodeSuccess = 0,
    /**
     Insufficient resources on the node.
     */
    SBMFirmwareUpdateStatusCodeInsufficientResources = 1,
    /**
     The operation cannot be performed while the server is in the current phase.
     */
    SBMFirmwareUpdateStatusCodeWrongPhase = 2,
    /**
     An internal error occurred on the node.
     */
    SBMFirmwareUpdateStatusCodeInternalError = 3,
    /**
     The message contains a firmware index value that is not expected.
     */
    SBMFirmwareUpdateStatusCodeWrongFirmwareIndex = 4,
    /**
     The metadata check failed.
     */
    SBMFirmwareUpdateStatusCodeMetadataCheckFailed = 5,
    /**
     The server cannot start a firmware update.
     */
    SBMFirmwareUpdateStatusCodeTemporarilyUnavailable = 6,
    /**
     Another BLOB transfer is in progress.
     */
    SBMFirmwareUpdateStatusCodeBlobTransferBusy = 7,
    /**
     Value not defined.
     */
    SBMFirmwareUpdateStatusCodeNotDefined
};
