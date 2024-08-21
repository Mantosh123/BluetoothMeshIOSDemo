//
//  SBMScheduleRegisterDay.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines day of occurence of event.
 Value of SBMScheduleRegisterDayAny means action should happen everyday.
 Otherwise, value of specific day must be set.
*/
typedef NS_ENUM(UInt8, SBMScheduleRegisterDayEnum) {
    SBMScheduleRegisterDayAny = 0x00,
    SBMScheduleRegisterDaySpecific = 0x01
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating day property in schedule register
*/
@interface SBMScheduleRegisterDay : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
*/
@property(nonatomic, readonly) UInt8 rawValue;

/**
 Initializes object with specific day.
 @param day specific day in the month. Value of 1 represents first day of the month.
        Valid value is between 1-31 but day shouldn't exceed number of days in specific month if set.
 @return initialized object
*/
- (instancetype)initWithSpecific:(UInt8)day;

/**
 Initializes object with predefined day.
 @param day predefined value. Only SBMScheduleRegisterDayAny value is possible.
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterDayEnum)day;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that informs if specific value is set or predefined one.
*/
- (SBMScheduleRegisterDayEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
