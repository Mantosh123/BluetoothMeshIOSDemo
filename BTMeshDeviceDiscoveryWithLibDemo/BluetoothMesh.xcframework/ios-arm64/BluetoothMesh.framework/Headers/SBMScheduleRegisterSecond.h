//
//  SBMScheduleRegisterSecond.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines minute of occurence of event.
 Value of SBMScheduleRegisterSecondAny means action should happen every second.
 Value of SBMScheduleRegisterSecondEvery15Seconds means action should happen every 15 seconds (0, 15, 30, 45).
 Value of SBMScheduleRegisterSecondEvery20Seconds means action should happen every 20 seconds (0, 20, 40).
 Value of SBMScheduleRegisterSecondRandom means action should happen at random minute of the hour.
 Otherwise, value of specific minute must be set.
*/
typedef NS_ENUM(UInt8, SBMScheduleRegisterSecondEnum) {
    SBMScheduleRegisterSecondSpecific = 0x00,
    SBMScheduleRegisterSecondAny = 0x3C,
    SBMScheduleRegisterSecondEvery15Seconds = 0x3D,
    SBMScheduleRegisterSecondEvery20Seconds = 0x3E,
    SBMScheduleRegisterSecondRandom = 0x3F,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating second property in schedule register
*/
@interface SBMScheduleRegisterSecond : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
*/
@property (nonatomic, readonly) UInt8 rawValue;

/**
 Initializes object with specific second.
 @param second specific second within minute
 @return initialized object
*/
- (instancetype)initWithSpecific:(UInt8)second;

/**
 Initializes object with predefined second.
 @param second predefined value from SBMScheduleRegisterSecondEnum. To set specific second, initWithSpecific should be used.
        Using SBMScheduleRegisterSecondSpecific in this init will result in the same behaviour as passing value of 0 to initWithSpecific.
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterSecondEnum)second;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that informs if specific value is set or predefined one.
*/
- (SBMScheduleRegisterSecondEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
