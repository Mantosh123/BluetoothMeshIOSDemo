//
//  SBMFirmwareDistributionPhase.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 20/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 The phase of a firmware image distribution being performed by the Firmware Distribution Server.
 */
typedef NS_ENUM(NSInteger, SBMFirmwareDistributionPhase)
{
    /**
     No firmware distribution is in progress.
     */
    SBMFirmwareDistributionPhaseIdle = 0,
    /**
     Firmware distribution is in progress.
     */
    SBMFirmwareDistributionPhaseActive = 1,
    /**
     The Transfer BLOB procedure has completed successfully.
     */
    SBMFirmwareDistributionPhaseTransferred = 2,
    /**
     The Apply Firmware on Target Nodes procedure is being executed.
     */
    SBMFirmwareDistributionPhaseApplying = 3,
    /**
     The Distribute Firmware procedure has completed successfully.
     */
    SBMFirmwareDistributionPhaseCompleted = 4,
    /**
     The Distribute Firmware procedure has failed.
     */
    SBMFirmwareDistributionPhaseFailed = 5,
    /**
     The Cancel Firmware Update procedure is being executed.
     */
    SBMFirmwareDistributionPhaseCancelling = 6,
    /**
     The Distribute Firmware procedure has been temporarily suspended
     */
    SBMFirmwareDistributionPhaseSuspended = 7,
    /**
     Value not defined.
     */
    SBMFirmwareDistributionPhaseNotDefined
};
