//
//  SBMSensorCadenceSet.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 12/07/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueSetSensorSetupModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Enum describing possible status trigger type.
 */
typedef NS_ENUM (NSUInteger, SBMStatusTriggerType) {
    /** Format shall be defined by the Format Type of the characteristic that the Sensor Property ID state references */
    SBMStatusTriggerTypeDefined = 0,
    /** Unit is unitless */
    SBMStatusTriggerTypeUnitless = 1,
};

/**
 Request to Sensor Server to set cadence state for a given sensor.
 */
@interface SBMSensorCadenceSet : NSObject<SBMControlValueSetSensorSetupModel>

/**
 Fast Cadence Period Divisor, 7-bit value. Divisor for the Publish Period.
 */
@property (nonatomic) UInt8 fastCadencePeriodDivisor;

/**
 Status Trigger Type, 1-bit value. Defines the unit and format of the Status Trigger Delta fields.
*/
@property (nonatomic) SBMStatusTriggerType statusTriggerType;

/**
 Status Trigger Delta Down. Data with delta down value that triggers a status message.
 */
@property (nonatomic, strong) NSData *statusTriggerDeltaDown;

/**
 Status TTrigger Delta Up. Data with delta up value that triggers a status message.
 */
@property (nonatomic, strong) NSData *statusTriggerDeltaUp;

/**
 Status Min Interval, 8-bit value. Minimum interval between two consecutive Status messages.
 */
@property (nonatomic) UInt8 statusMinInterval;

/**
 Fast Cadence Low. Data with low value for the fast cadence range.
 */
@property (nonatomic, strong) NSData *fastCadenceLow;

/**
 Fast Cadence High. Data with high value fot the fast cadence range.
 */
@property (nonatomic, strong) NSData *fastCadenceHigh;

@end

NS_ASSUME_NONNULL_END
