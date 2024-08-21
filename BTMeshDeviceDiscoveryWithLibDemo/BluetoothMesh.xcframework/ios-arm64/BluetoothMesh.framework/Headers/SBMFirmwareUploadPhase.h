//
//  SBMFirmwareUploadPhase.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 20/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 The phase of a firmware image delivery to a Firmware Distribution Server.
 */
typedef NS_ENUM(NSInteger, SBMFirmwareUploadPhase)
{
    /**
     No firmware transfer nor OOB download is in progress.
     */
    SBMFirmwareUploadPhaseIdle = 0,
    /**
     Firmware transfer or OOB download is in progress.
     */
    SBMFirmwareUploadPhaseTransferInProgress = 1,
    /**
     Firmware transfer or OOB download has failed.
     */
    SBMFirmwareUploadPhaseTransferError = 2,
    /**
     Firmware transfer or OOB download has been completed successfully.
     */
    SBMFirmwareUploadPhaseTransferCompleted = 3,
    /**
     Value not defined.
     */
    SBMFirmwareUploadPhaseNotDefined
};
