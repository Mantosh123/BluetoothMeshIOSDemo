//
//  SBMFirmwareDistributionUploadComplete.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 22/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareId.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Contains information about completion of an upload process.
 This event is sent only if upload has succeeded.
 @see SBMFirmwareDistributionUploadFailed
 */
@interface SBMFirmwareDistributionUploadComplete : NSObject

/**
 BLOB identifier used for the transfer.
 */
@property (nonatomic, strong, readonly) NSData *blobId;

/**
 Size of the uploaded object in bytes.
 */
@property (nonatomic, readonly) UInt32 blobSize;

/**
 Identifier of the uploaded firmware.
 */
@property (nonatomic, strong, readonly) SBMFirmwareId *firmwareId;

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
