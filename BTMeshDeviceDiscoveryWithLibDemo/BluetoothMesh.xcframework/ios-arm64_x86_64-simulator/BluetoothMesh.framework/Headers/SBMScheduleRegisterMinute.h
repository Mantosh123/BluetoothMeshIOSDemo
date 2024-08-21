//
//  SBMScheduleRegisterMinute.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines minute of occurence of event.
 Value of SBMScheduleRegisterMinuteAny means action should happen every minute.
 Value of SBMScheduleRegisterMinuteEvery15Minutes means action should happen every 15 minutes (0, 15, 30, 45).
 Value of SBMScheduleRegisterMinuteEvery20Minutes means action should happen every 20 minutes (0, 20, 40).
 Value of SBMScheduleRegisterMinuteRandom means action should happen at random minute of the hour.
 Otherwise, value of specific minute must be set.
*/
typedef NS_ENUM(UInt8, SBMScheduleRegisterMinuteEnum) {
    SBMScheduleRegisterMinuteSpecific = 0x00,
    SBMScheduleRegisterMinuteAny = 0x3C,
    SBMScheduleRegisterMinuteEvery15Minutes = 0x3D,
    SBMScheduleRegisterMinuteEvery20Minutes = 0x3E,
    SBMScheduleRegisterMinuteRandom = 0x3F,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating minute property in schedule register
*/
@interface SBMScheduleRegisterMinute : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
*/
@property (nonatomic, readonly) UInt8 rawValue;

/**
 Initializes object with specific minute.
 @param minute specific minute within the hour
 @return initialized object
*/
- (instancetype)initWithSpecific:(UInt8)minute;

/**
 Initializes object with predefined minute.
 @param minute predefined value from SBMScheduleRegisterMinuteEnum. To set specific minute, initWithSpecific should be used.
        Using SBMScheduleRegisterMinuteSpecific in this init will result in the same behaviour as passing value of 0 to initWithSpecific.
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterMinuteEnum)minute;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that informs if specific value is set or predefined one.
*/
- (SBMScheduleRegisterMinuteEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
