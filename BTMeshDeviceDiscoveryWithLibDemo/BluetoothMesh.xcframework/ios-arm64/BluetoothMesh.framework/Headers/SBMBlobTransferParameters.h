//
//  SBMBlobTransferParameters.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 13/07/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The container for values specifying BLOB transfer parameters.
 
 If any of the values exceeds server capabilities, an error is thrown when attempting to send BLOB Start Transfer message.
 Server capabilities are received in a BLOB Information Status message.
 */
@interface SBMBlobTransferParameters : NSObject

/**
 Binary logarithm of a block size.
 blockSizeLog = ceil(log2(blockSize))
 */
@property (nonatomic) UInt8 blockSizeLog;

/**
 Chunk size in bytes.
 */
@property (nonatomic) UInt16 blobChunkSize;

/**
 Initializer method for SBMBlobTransferParameters.
 
 @param blockSizeLog Binary logarithm of a block size.
 @param blobChunkSize Chunk size in bytes.
 @return Return instance of an object.
 */
- (instancetype)initWithBlockSizeLog:(UInt8)blockSizeLog
                       blobChunkSize:(UInt16)blobChunkSize;

/**
 Not available. Use initWithBlockSizeLog:blobChunkSize instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available. Use initWithBlockSizeLog:blobChunkSize instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
