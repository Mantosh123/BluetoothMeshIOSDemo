//
//  SBMTimeStatus.h
//  BluetoothMesh
//
//  Created by Michal Barnas on 24/02/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMTimeResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message representing Time state of an element.
 Response to Time Get or Time Set message.
*/
@interface SBMTimeStatus : NSObject <SBMTimeResponse>

/**
 The current TAI time in seconds
 If the TAI Seconds field is 0x0000000000 the Subsecond, Uncertainty,
 Time Authority, TAI-UTC Delta and Time Zone Offset fields shall be omitted.
 Otherwise these fields shall be present.
 */
@property (nonatomic, readonly) UInt64 taiSeconds;

/**
 The sub-second time in units of 1/256th second.
 8-bit unsigned integer value, optional.
 */
@property (nonatomic, readonly, nullable) NSNumber *subsecond;

/**
 The estimated uncertainty in 10-milisecond steps.
 8-bit unsigned integer value, optional
 */
@property (nonatomic, readonly, nullable) NSNumber *uncertainty;

/**
 Represents whether the element has a reliable source of TAI.
 Boolean value, optional
 */
@property (nonatomic, readonly, nullable) NSNumber *timeAuthority;

/**
 Current difference between TAI and UTC in seconds.
 16-bit integer value, optional.
 */
@property (nonatomic, readonly, nullable) NSNumber *taiUtcDelta;

/**
 The local time zone offset in 15-minute increments.
 8-bit integer value, optional.
 */
@property (nonatomic, readonly, nullable) NSNumber *timeZoneOffset;

@end

NS_ASSUME_NONNULL_END
