//
//  SBMStandaloneUpdaterEventHandler.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 17/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareDistributionUpdatingNodeEntry.h"
#import "SBMStandaloneDistributionPhase.h"

NS_ASSUME_NONNULL_BEGIN

/**
  Event handler during Standalone Distribution.
 */
@protocol SBMStandaloneUpdaterEventHandler <NSObject>

/**
 Invoked on the Standalone Updater's phase change.
 
 Requires a usage of a BLOB Transfer Client when SBMStandaloneDistributionPhase.transferringImage occurs.
 @see SBMBlobTransfer
 
 @param phase Current phase of the Standalone Updater.
 */
- (void)handleStateChanged:(SBMStandaloneDistributionPhase)phase;

@optional

/**
 Invoked on a receiver's update failure.
 If the Firmware Update Client message was rejected, SBMFirmwareUpdateStatusCode is different than SBMFirmwareUpdateStatusCodeSuccess.
 If the BLOB Transfer Client message was rejected, SBMBlobTransferStatusCode is different than SBMBlobTransferStatusCodeSuccess.
 If both fields - SBMFirmwareUpdateStatusCode and SBMBlobTransferStatusCode - are zero, timeout occured.
 
 @param failedReceiver Entry containing updating node whose update has failed.
 */
- (void)handleNodeFailed:(SBMFirmwareDistributionUpdatingNodeEntry *)failedReceiver;

@end

NS_ASSUME_NONNULL_END
