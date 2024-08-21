//
//  SBMScheduleRegisterMonth.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines month of occurence of event.
*/
typedef NS_ENUM(NSUInteger, SBMScheduleRegisterMonthEnum) {
    SBMScheduleRegisterMonthJanuary = 1,
    SBMScheduleRegisterMonthFebruary,
    SBMScheduleRegisterMonthMarch,
    SBMScheduleRegisterMonthApril,
    SBMScheduleRegisterMonthMay,
    SBMScheduleRegisterMonthJune,
    SBMScheduleRegisterMonthJuly,
    SBMScheduleRegisterMonthAugust,
    SBMScheduleRegisterMonthSeptember,
    SBMScheduleRegisterMonthOctober,
    SBMScheduleRegisterMonthNovember,
    SBMScheduleRegisterMonthDecember
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating month property in schedule register
*/
@interface SBMScheduleRegisterMonth : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
*/
@property(nonatomic, readonly) UInt8 rawValue;

/**
 Initializes object with specific month.
 @param month value representing month, where 1 is January and 12 is December
 @return initialized object
*/
- (instancetype)initWithSpecific:(UInt8)month;

/**
 Initializes object with predefined month.
 @param month predefined value from SBMScheduleRegisterMonthEnum
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterMonthEnum)month;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that represents month set.
*/
- (SBMScheduleRegisterMonthEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
