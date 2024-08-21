//
//  SBMBlobServerStatusDetailed.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 14/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMElement.h"
#import "SBMBlobServerState.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Detailed status of a BLOB Transfer to a target identified by SBMElement.
 */
@interface SBMBlobServerStatusDetailed : NSObject

/**
 Transfer target.
 */
@property (nonatomic, readonly) SBMElement *element;

/**
 Current status of a BLOB transfer to the target's BLOB Server.
 */
@property (nonatomic, readonly) SBMBlobServerState currentState;

/**
 Number of delivered and confirmed BLOB Transfer blocks.
 */
@property (nonatomic, readonly) UInt16 receivedBlocks;

/**
 Number of confirmed BLOB Transfer chunks delivered within the current block. Valid only in push transfer mode.
 */
@property (nonatomic, readonly) UInt16 receivedChunks;

/**
 Progress of the transfer in range from 0 to 1.
 */
@property (nonatomic, readonly) NSNumber *progress;

/**
 Unavailable
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Unavailable
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
