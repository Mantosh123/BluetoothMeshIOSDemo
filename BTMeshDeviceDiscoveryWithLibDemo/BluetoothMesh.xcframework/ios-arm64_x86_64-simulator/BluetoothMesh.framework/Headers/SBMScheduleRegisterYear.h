//
//  SBMScheduleRegisterYear.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines year of occurence of event.
 Value of SBMScheduleRegisterYearAny means action should happen every year.
 Otherwise, specific year is set and value of 2 least significant digits should be set.
 */
typedef NS_ENUM(UInt8, SBMScheduleRegisterYearEnum) {
    SBMScheduleRegisterYearSpecific = 0x00,
    SBMScheduleRegisterYearAny = 0x64
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating year property in schedule register
 */
@interface SBMScheduleRegisterYear : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
 */
@property (nonatomic, readonly) UInt8 rawValue;

/**
 Initializes object with specific year.
 @param year 2 least-significant digits of year
 @return initialized object
 */
- (instancetype)initWithSpecific:(UInt8)year;

/**
 Initializes object with predefined year.
 @param year predefined value. Value should be one from the defined in SBMScheduleRegisterYearEnum. To set specific year, initWithSpecific should be used.
        Using SBMScheduleRegisterYearSpecific in this init will result in the same behaviour as passing value of 0 to initWithSpecific.
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterYearEnum)year;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that informs if specific value is set or predefined one.
 */
- (SBMScheduleRegisterYearEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
