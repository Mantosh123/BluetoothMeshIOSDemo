//
//  SBMScheduleRegisterHour.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines hour of occurence of event.
 Value of SBMScheduleRegisterHourAny means action should happen every year.
 Value of SBMScheduleRegisterHourRandom means action should happen once a day at random hour.
 Otherwise, value of specific hour must be set.
*/
typedef NS_ENUM(UInt8, SBMScheduleRegisterHourEnum) {
    SBMScheduleRegisterHourSpecific = 0x00,
    SBMScheduleRegisterHourAny = 0x18,
    SBMScheduleRegisterHourRandom = 0x19
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating hour property in schedule register
*/
@interface SBMScheduleRegisterHour : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
*/
@property (nonatomic, readonly) UInt8 rawValue;

/**
 Initializes object with specific hour.
 @param hour specific hour of the day
 @return initialized object
*/
- (instancetype)initWithSpecific:(UInt8)hour;

/**
 Initializes object with predefined hour.
 @param hour predefined value from SBMScheduleRegisterHourEnum. To set specific minute, initWithSpecific should be used.
        Using SBMScheduleRegisterHourSpecific in this init will result in the same behaviour as passing value of 0 to initWithSpecific.
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterHourEnum)hour;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that informs if specific value is set or predefined one.
*/
- (SBMScheduleRegisterHourEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
