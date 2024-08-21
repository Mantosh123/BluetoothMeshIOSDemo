//
//  SBMFirmwareDistributionUpdatingNodeEntry.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 22/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareUpdateStatusCode.h"
#import "SBMFirmwareRetrievedUpdatePhase.h"
#import "SBMBlobTransferStatusCode.h"
#import "SBMNode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Updating Node Entry which is a part of the SBMFirmwareDistributionReceiversList class message.
 */
@interface SBMFirmwareDistributionUpdatingNodeEntry : NSObject

/**
 A Node pointed by the address received in the message.
 */
@property (nonatomic, readonly, strong, nullable) SBMNode *node;

/**
 Phase of the firmware image update.
 */
@property (nonatomic, readonly) SBMFirmwareRetrievedUpdatePhase phase;

/**
 Status of the last operation with the Firmware Update Server.
 */
@property (nonatomic, readonly) SBMFirmwareUpdateStatusCode updateServerStatus;

/**
 Status of the last operation with the BLOB Transfer Server.
 */
@property (nonatomic, readonly) SBMBlobTransferStatusCode blobTransferStatus;

/**
 Percentage progress of the BLOB Transfer. (The value range is 0-100)
 */
@property (nonatomic, readonly) UInt8 transferProgress;

/**
 The index of the firmware image on the Firmware Information List state of the Updating node that is being updated
 */
@property (nonatomic, readonly) UInt8 firmwareIndex;

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
