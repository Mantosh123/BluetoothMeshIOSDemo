//
//  SBMFirmwareDistributionReceiversList.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareDistributionUpdatingNodeEntry.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Response sent by the Firmware Distribution server.
 @see SBMFirmwareDistribution
 @see SBMFirmwareDistributionHandler
 
 Reports the firmware distribution status of each receiver.
 */
@interface SBMFirmwareDistributionReceiversList : NSObject

/**
 Index of the first Updating Node Item on the Distribution Receivers List state on the Firmware Distribution server.
 */
@property (nonatomic, readonly) UInt16 startIndex;

/**
 The number of entries in the Distribution Receivers List state
 */
@property (nonatomic, readonly) UInt16 receiversListCount;

/**
 Entries from the Distribution Receivers List state.
 */
@property (nonatomic, readonly, strong) NSArray<SBMFirmwareDistributionUpdatingNodeEntry *> *updatingNodeEntries;

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
