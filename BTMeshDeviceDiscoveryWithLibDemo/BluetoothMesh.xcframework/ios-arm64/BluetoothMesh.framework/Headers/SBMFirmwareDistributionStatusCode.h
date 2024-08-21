//
//  SBMFirmwareDistributionStatusCode.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 20/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 The status codes for the Firmware Distribution Server model and the Firmware Distribution Client.
 */
typedef NS_ENUM(NSInteger, SBMFirmwareDistributionStatusCode)
{
    /**
     The message was processed successfully.
     */
    SBMFirmwareDistributionStatusCodeSuccess = 0,
    /**
     Insufficient resources on the node.
     */
    SBMFirmwareDistributionStatusCodeInsufficientResources = 1,
    /**
     The operation cannot be performed while the server is in the current phase.
     */
    SBMFirmwareDistributionStatusCodeWrongPhase = 2,
    /**
     An internal error occurred on the node.
     */
    SBMFirmwareDistributionStatusCodeInternalError = 3,
    /**
     The requested firmware image is not stored on the Distributor.
     */
    SBMFirmwareDistributionStatusCodeFirmwareNotFound = 4,
    /**
     The AppKey identified by the AppKey Index is not known to the node.
     */
    SBMFirmwareDistributionStatusCodeInvalidAppKeyIndex = 5,
    /**
     There are no Target nodes in the Distribution Receivers List state.
     */
    SBMFirmwareDistributionStatusCodeReceiversListEmpty = 6,
    /**
     Another firmware image distribution is in progress.
     */
    SBMFirmwareDistributionStatusCodeBusyWithDistribution = 7,
    /**
     Another upload is in progress.
     */
    SBMFirmwareDistributionStatusCodeBusyWithUpload = 8,
    /**
     The URI scheme name indicated by the Update URI is not supported.
     */
    SBMFirmwareDistributionStatusCodeUriNotSupported = 9,
    /**
     The format of the Update URI is invalid.
     */
    SBMFirmwareDistributionStatusCodeUriMalformed = 0xa,
    /**
     The URI is currently unreachable
     */
    SBMFirmwareDistributionStatusCodeUriUnreachable = 0xb,
    /**
     No new firmware was available with given the URI and Firmware ID
     */
    SBMFirmwareDistributionStatusCodeNewFirmwareNotAvailable = 0xc,
    /**
     Suspending the distribution failed
     */
    SBMFirmwareDistributionStatusCodeSuspendFailed = 0xd,
    /**
     Value not defined.
     */
    SBMFirmwareDistributionStatusCodeNotDefined
};
