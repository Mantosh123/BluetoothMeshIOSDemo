//
//  SBMStandaloneDistributionPhase.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 17/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Possible states of Standalone Distribution.
 */
typedef NS_ENUM(NSUInteger, SBMStandaloneDistributionPhase) {
    /** No distribution is active */
    SBMStandaloneDistributionPhaseIdle = 0,
    /** Sending Update Start messages */
    SBMStandaloneDistributionPhaseStartingUpdate = 1,
    /** BLOB Transfer is in progress */
    SBMStandaloneDistributionPhaseTransferringImage = 2,
    /** Sending Update Get messages to check verification status */
    SBMStandaloneDistributionPhaseCheckingVerification = 3,
    /** Wait for Distribution Apply. Internal use only */
    SBMStandaloneDistributionPhaseWaitingForApply = 4,
    /** Sending Update Apply messages */
    SBMStandaloneDistributionPhaseApplyingUpdate = 5,
    /** Sending Information Get messages to determine if new firmware has been applied */
    SBMStandaloneDistributionPhaseCheckingUpdateResult = 6,
    /** Completed successfully for at least one Updating Node */
    SBMStandaloneDistributionPhaseCompleted = 7,
    /** Distribution failed for all Target Nodes */
    SBMStandaloneDistributionPhaseFailed = 8,
    /** Cancelling an ongoing distribution */
    SBMStandaloneDistributionPhaseCancelling = 9,
    /** The BLOB transfer is suspended */
    SBMStandaloneDistributionPhaseSuspended = 10
};
