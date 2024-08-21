//
//  SBMBlobServersCapabilities.h
//  BluetoothMesh
//
//  Created by Vasyl Haievyi on 30/12/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMBlobSupportedTransferMode.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Class representing information about common Servers capabilities.
 */
@interface SBMBlobServersCapabilities : NSObject

/**
 The largest common Minimum Block Size Log for all Servers.
 */
@property (nonatomic, readonly) UInt8 minBlockSizeLog;

/**
 The smallest common Maximum Block Size Log for all Servers.
 */
@property (nonatomic, readonly) UInt8 maxBlockSizeLog;

/**
 The smallest common Maximum Chunks Number per Block for all Servers.
 */
@property (nonatomic, readonly) UInt16 maxChunksNumber;

/**
 The smallest common Maximum Chunk Size for all Servers.
 */
@property (nonatomic, readonly) UInt16 maxChunkSize;

/**
 Transfer Modes supported by at least one Server and the Client
 */
@property (nonatomic, readonly) SBMBlobSupportedTransferMode supportedTransferMode;

/**
 Transfer Modes supported by all Servers and the Client
 */
@property (nonatomic, readonly) SBMBlobSupportedTransferMode commonTransferMode;

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
