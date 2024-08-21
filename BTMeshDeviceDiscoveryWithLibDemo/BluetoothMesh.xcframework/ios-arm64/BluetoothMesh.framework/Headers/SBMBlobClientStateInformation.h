//
//  SBMBlobClientStateInformation.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 21/04/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMElement.h"
#import "SBMBlobClientState.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Information about local BLOB Client's state.
 */
@interface SBMBlobClientStateInformation : NSObject
/**
 Current state of the Client.
 */
@property (nonatomic, readonly) SBMBlobClientState currentState;

/**
 8-bytes identifier of the BLOB being transferred.
 */
@property (nonatomic, strong, nullable, readonly) NSData *blobId;

/**
 Size of the BLOB being transferred.
 */
@property (nonatomic, readonly) UInt32 blobSize;

/**
 Packets TTL (time to live) value. Valid values: 0x00, 0x02–0x7F, 0xFF (default network TTL).
 */
@property (nonatomic, readonly) UInt8 ttl;

/**
 Base value used to calculate a transfer timeout.
 The transfer will be suspended if no messages are received in a given time.
 
 For all Client models (including the BLOB Client) the actual timeout value is:
 (10 * (timeoutBase + 2) + (100 * ttl)) seconds
  
 For all Server models (including the BLOB Server) the actual timeout value is:
 (10 * (timeoutBase + 1)) seconds
 */
@property (nonatomic, readonly) UInt16 timeoutBase;

/**
 Group used in a multicast transfer.
 */
@property (nonatomic, strong, nullable, readonly) SBMGroup *multicast;

/**
 Number of servers set up for a BLOB transfer.
 */
@property (nonatomic, readonly) UInt16 serversCount;

/**
 The logarithm of the block size used in the transfer.
 */
@property (nonatomic, readonly) UInt8 blockSizeLog;

/**
 Number of the current block.
 */
@property (nonatomic, readonly) UInt16 currentBlock;

/**
 Size of the current block. The last block's size differs from the standard size indicated by the logarithmic size.
 */
@property (nonatomic, readonly) UInt32 currentBlockSize;

/**
 Total number of BLOB Transfer blocks.
 */
@property (nonatomic, readonly) UInt16 totalBlocks;

/**
 Total number of BLOB Transfer chunks within the current block, 0 if there's no active Block.
 */
@property (nonatomic, readonly) UInt16 currentBlockTotalChunks;

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
