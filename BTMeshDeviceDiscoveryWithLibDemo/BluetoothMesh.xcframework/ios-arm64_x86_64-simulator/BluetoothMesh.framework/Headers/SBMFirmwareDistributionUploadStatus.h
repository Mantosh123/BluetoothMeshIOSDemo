//
//  SBMFirmwareDistributionUploadStatus.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareDistributionStatusCode.h"
#import "SBMFirmwareUploadPhase.h"
#import "SBMUploadType.h"
#import "SBMFirmwareId.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Response sent by a Firmware Distribution server.
 @see SBMFirmwareDistribution
 @see SBMFirmwareDistributionHandler
 
 Reports the status of a firmware image upload.
 */
@interface SBMFirmwareDistributionUploadStatus : NSObject

/**
 Status code of the operation.
 */
@property (nonatomic, readonly) SBMFirmwareDistributionStatusCode status;

/**
 Phase of the firmware upload process.
 */
@property (nonatomic, readonly) SBMFirmwareUploadPhase phase;

/**
 A percentage indicating the progress of the firmware upload. (Optional)
 */
@property (nonatomic, readonly, strong, nullable) NSNumber *progress;

/**
 The type of an upload.
 */
@property (nonatomic, readonly) SBMUploadType type;

/**
 Firmware ID identifying the firmware image being uploaded.
 
 If OOB download is in progress, this is the firmware ID used to form the query string
 to retrieve a newer firmware image with a different firmware ID.
 
 Present only when the progress field is present. (Optional)
 */
@property (nonatomic, readonly, strong, nullable) SBMFirmwareId *firmwareId;

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
