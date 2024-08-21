//
//  SBMTimeSet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 12.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeSetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Time Set is an acknowledged message used to set the Time state of an element.
 The response to the Time Set message is a Time Status message.
*/
@interface SBMTimeSet : NSObject <SBMTimeSetRequest>

/*
 The current TAI time in seconds
 If the TAI Seconds field is 0x0000000000 the Subsecond, Uncertainty,
 Time Authority, TAI-UTC Delta and Time Zone Offset fields shall be omitted.
 Otherwise these fields shall be present.
*/
@property (nonatomic) UInt64 taiSeconds;

/*
 The sub-second time in units of 1/256th second.
*/
@property (nonatomic) UInt8 subsecond;

/*
 The estimated uncertainty in 10-milisecond steps.
*/
@property (nonatomic) UInt8 uncertainty;

/*
 Represents whether the element has a reliable source of TAI.
*/
@property (nonatomic) BOOL timeAuthority;

/*
 Current difference between TAI and UTC in seconds.
*/
@property (nonatomic) SInt32 taiUtcDelta;

/*
 The local time zone offset in 15-minute increments.
*/
@property (nonatomic) SInt16 timeZoneOffset;

/**
 Initializer for Time set message
 @param taiSeconds value to initialize taiSeconds property
 @param subsecond value to initialize subsecond property
 @param uncertainty value to initialize uncertainty property
 @param timeAuthority value to initialize timeAuthority property
 @param taiUtcDelta value to initialize taiUtcDelta property
 @param timeZoneOffset value to initialize timeZoneOffset property
 @return object representing Time Set message
 */
- (instancetype)initWithTaiSeconds:(UInt64)taiSeconds
                        subseconds:(UInt8)subsecond
                       uncertainty:(UInt8)uncertainty
                     timeAuthority:(BOOL)timeAuthority
                       taiUtcDelta:(SInt32)taiUtcDelta
                    timeZoneOffset:(SInt16)timeZoneOffset;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
