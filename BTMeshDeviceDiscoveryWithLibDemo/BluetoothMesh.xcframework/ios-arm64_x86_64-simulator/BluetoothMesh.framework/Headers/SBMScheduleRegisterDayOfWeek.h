//
//  SBMScheduleRegisterDayOfWeek.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines day of week of occurence of event.
*/
typedef NS_ENUM(UInt8, SBMScheduleRegisterDayOfWeekEnum) {
    SBMScheduleRegisterDayOfWeekMonday = 0,
    SBMScheduleRegisterDayOfWeekTuesday,
    SBMScheduleRegisterDayOfWeekWednesday,
    SBMScheduleRegisterDayOfWeekThursday,
    SBMScheduleRegisterDayOfWeekFriday,
    SBMScheduleRegisterDayOfWeekSaturday,
    SBMScheduleRegisterDayOfWeekSunday
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating day of week property in schedule register
*/
@interface SBMScheduleRegisterDayOfWeek : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
*/
@property (nonatomic, readonly) UInt8 rawValue;

/**
 Initializes object with specific day of week.
 @param dayOfWeek specific day of the week, where 0 is Monday and 6 is Sunday
 @return initialized object
*/
- (instancetype)initWithSpecific:(UInt8)dayOfWeek;

/**
 Initializes object with predefined day of week.
 @param dayOfWeek predefined value from SBMScheduleRegisterDayOfWeekEnum
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterDayOfWeekEnum)dayOfWeek;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that informs if specific value is set or predefined one.
*/
- (SBMScheduleRegisterDayOfWeekEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
