//
//  SBMStandaloneUpdaterState.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 17/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMStandaloneDistributionPhase.h"
#import "SBMFirmwareDistributionUpdatingNodeEntry.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object that represents state of Standalone Updater.
 */
@interface SBMStandaloneUpdaterState : NSObject

/**
 Phase of Standalone Distribution.
 */
@property (nonatomic, readonly) SBMStandaloneDistributionPhase phase;

/**
 Update State of receivers.
 */
@property (nonatomic, strong, readonly) NSArray<SBMFirmwareDistributionUpdatingNodeEntry*> *receivers;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
