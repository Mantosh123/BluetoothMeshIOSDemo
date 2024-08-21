//
//  SBMBlobTransferSetup.h
//  BluetoothMesh
//
//  Created by Vasyl Haievyi on 14/12/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMBlob.h"
#import "SBMApplicationKey.h"
#import "SBMBlobSupportedTransferMode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The container for values used to initialize a SBMBlobTransferInternal object.
 */
@interface SBMBlobTransferSetup : NSObject

/**
 The Blob object to be transferred.
 */
@property (nonatomic, readonly) SBMBlob *blob;

/**
 Application key used to encrypt BLOB transfer messages.
 */
@property (nonatomic, readonly) SBMApplicationKey *appKey;

/**
 Supported BLOB Transfer modes. Default value is both (Push and Pull mode).
 */
@property (nonatomic, readwrite) SBMBlobSupportedTransferMode supportedTransferMode;

/**
 Packets TTL (time to live) value. Valid values: 0x00, 0x02–0x7F, 0xFF (default network TTL).
 
 Default value is 0xFF.
 */
@property (nonatomic, readwrite) UInt8 ttl;

/**
 Base value used to calculate a transfer timeout.
 The transfer will be suspended if no messages are received in a given time.
 
 Default value is set to 0.
 
 For all Client models (including the BLOB Client) the actual timeout value is:
 (10 * (timeoutBase + 2) + (100 * ttl)) seconds
  
 For all Server models (including the BLOB Server) the actual timeout value is:
 (10 * (timeoutBase + 1)) seconds
 */
@property (nonatomic, readwrite) UInt16 timeoutBase;

/**
 Initialization method with mandatory parameters.
 
 @param blob Binary Large Object to be sent in a transfer.
 
 @return initialized SBMBlobTransferSetup object.
 */
- (instancetype)initWithBlob:(SBMBlob *)blob appKey:(SBMApplicationKey *)appKey;

/**
 Not available. Use initWithBlobId:blobSize instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available. Use initWithBlobId:blobSize instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
