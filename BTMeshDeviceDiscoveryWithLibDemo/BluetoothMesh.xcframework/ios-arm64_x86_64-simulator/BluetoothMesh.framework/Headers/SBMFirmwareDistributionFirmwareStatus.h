//
//  SBMFirmwareDistributionFirmwareStatus.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareDistributionStatusCode.h"
#import "SBMFirmwareId.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Response sent by a Firmware Distribution server.
 @see SBMFirmwareDistribution
 @see SBMFirmwareDistributionHandler
 
 Reports the status of an operation on a stored firmware image.
 */
@interface SBMFirmwareDistributionFirmwareStatus : NSObject

/**
 Status code of the operation.
 */
@property (nonatomic, readonly) SBMFirmwareDistributionStatusCode status;

/**
 The number of firmware images currently stored on the Firmware Distribution Server
 */
@property (nonatomic, readonly) UInt16 entriesNumber;

/**
 Entry’s index in the Firmware List state.
 The value of 0xFFFF indicates that a firmware with a given ID is not listed in the Firmware Images List state.
 */
@property (nonatomic, readonly) UInt16 index;

/**
 (Optional)
 The Firmware ID field shall be present in either of the following conditions:
 1) if the Firmware Images List state lists the firmware image identified by the Distribution Firmware Image Index field;
 2) if the message is sent in response to a Firmware Distribution Firmware Get message;
 otherwise, the Firmware ID field shall be omitted.

 Contains the Firmware ID of the firmware image at the index in the Firmware Images List state that is identified by the Distribution Firmware Image Index field.
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
