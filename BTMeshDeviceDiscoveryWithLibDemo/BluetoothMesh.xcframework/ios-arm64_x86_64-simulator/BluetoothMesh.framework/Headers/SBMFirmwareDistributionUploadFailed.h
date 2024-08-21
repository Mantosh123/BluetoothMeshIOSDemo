//
//  SBMFirmwareDistributionUploadFailed.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 27/09/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Contains information about failure of an upload process.
 This event is sent only if upload has failed.
 @see SBMFirmwareDistributionUploadComplete
 */
@interface SBMFirmwareDistributionUploadFailed : NSObject

/**
 A percentage indicating the progress of the firmware upload.
 */
@property (nonatomic, readonly) UInt8 progress;

/**
 Reason of upload's failure.
 */
@property (nonatomic, readonly) NSError* error;

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
