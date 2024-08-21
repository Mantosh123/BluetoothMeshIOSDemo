//
//  SBMDescriptor.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 21/05/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Sensor Sampling Function values
*/
typedef NS_ENUM (NSUInteger, SBMSensorSamplingFunction) {
    /** Unspecified */
    SBMSensorSamplingFunctionUnspecified = 0x00,
    /** Instantaneous sampling */
    SBMSensorSamplingFunctionInstantaneous = 0x01,
    /** Arithmetic mean */
    SBMSensorSamplingFunctionArithmeticMean = 0x02,
    /** Root mean square */
    SBMSensorSamplingFunctionRMS = 0x03,
    /** Maximum value */
    SBMSensorSamplingFunctionMaximum = 0x04,
    /** Minimum value */
    SBMSensorSamplingFunctionMinimum = 0x05,
    /** Cumulative moving average updated with the frequency given by Sensor Update Interval */
    SBMSensorSamplingFunctionAccumulated = 0x06,
    /** Number of "events" over the period of time defined by the Measurement Period */
    SBMSensorSamplingFunctionCount = 0x07
};

/**
 Sensor Descriptor
 
 @discussion The Sensor Descriptor state represents the attributes describing the sensor data. This state does not change throughout the lifetime of an element. One sensor model can have multiple Sensor Descriptor states in case of a multisensor setup.
 */
@interface SBMDescriptor : NSObject

/**
 Sensor Property ID, 16-bit ID referencing a device property
 */
@property (nonatomic, readonly) UInt16 propertyID;

/**
 Sensor Positive Tolerance
 
 @discussion 12-bit Positive Tolerance value (0x001 - 0xFFF), the value is derived as Possible Positive Error % = 100 % * Positive Tolerance / 4095
 */
@property (nonatomic, readonly) UInt16 positiveTolerance;

/**
 Sensor Negative Tolerance
 
 @discussion 12-bit Negative Tolerance value (0x001 - 0xFFF), the value is derived as Possible Negative Error % = 100 % * Negative Tolerance / 4095
 */
@property (nonatomic, readonly) UInt16 negativeTolerance;

/**
 Sensor Sampling Function
 */
@property (nonatomic, readonly) SBMSensorSamplingFunction samplingFunction;

/**
 Sensor Measurement Period
 
 @discussion 8-bit value n representing the averaging time span, accumulation time or measurement period in seconds. Represented value = 1.1ˆ(n-64), ranging from approximately 2.5ms to about 932 days.Value zero means undefined, definitive values start from 1
 */
@property (nonatomic, readonly) UInt8 measurementPeriod;

/**
 Sensor Update Interval
 
 @discussion 8-bit value representing the frequency at which the measurement value is updated internally. Represented value = 1.1ˆ(n-64), ranging from approximately 2.5ms to about 932 days. Value zero means undefined, definitive values start from 1
 */
@property (nonatomic, readonly) UInt8 updateInterval;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
