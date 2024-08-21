//
//  SBMPublishPeriod.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 30.11.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Possible values for publish period step resolution.
 
 @discussion Step resolution is an order of magnitude by which we multiply the number of steps, this is a base for calculations of the period.
 For example, if step resolution is SBMPublishPeriodStepResolutionSecond and the number of steps is 5, the publish period is calculated from the formula
 1 second * 5 = 5 seconds.
 */
typedef NS_ENUM(NSUInteger, SBMPublishPeriodStepResolution) {
    /** Multiply number of steps by 100 miliseconds */
    SBMPublishPeriodStepResolution100Milliseconds = 0,
    /** Multiply number of steps by 1 second */
    SBMPublishPeriodStepResolutionSecond = 1,
    /** Multiply number of steps by 10 seconds */
    SBMPublishPeriodStepResolution10Seconds = 2,
    /** Multiply number of steps by 10 minutes  */
    SBMPublishPeriodStepResolution10Minutes = 3
};

/**
 Manages the publish period calculation and its representations
 
 @discussion Value of publish period is calculated from the formula:
 Publish Period = Number Of Steps * Step Resolution
 This object returns the value of the publish period in milliseconds.
 
 @see intervalInMilliseconds property
 */
@interface SBMPublishPeriod : NSObject

/**
 Number by which multiply the step resolution to calculate publish period value.
 
 @discussion Its value can be from range 0 to 63.
 If you insert 0 it means that the publish period is disabled.
 */
@property (nonatomic, readonly) NSInteger steps;

/**
 Step resolution value. One of the SBMPublishPeriodStepResolution enum cases.
 
 @see Definition of SBMPublishPeriodStepResolution enum.
 */
@property (nonatomic, readonly) SBMPublishPeriodStepResolution stepResolution;

/**
 The raw value of publish period.
 
 @discussion It is a byte which contains the step resolution (2 bits) and a number of steps (6 bits).
 */
@property (nonatomic, readonly) UInt8 rawValue;

/**
 The calculated value of publish period in milliseconds.
 
 @discussion This value is calculated from the formula: Number Of Steps * Step Resolution and after that, the result is represented in milliseconds.
 */
@property (nonatomic, readonly) NSInteger intervalInMilliseconds;

/**
 Creates an object using the number of steps and step resolution value.
 
 @discussion Calculates internally publish period value and raw value of the period.
 */
- (instancetype)initWithSteps:(NSInteger)steps stepResolution:(SBMPublishPeriodStepResolution)stepResolution;

/**
 Creates an object using the raw value of the period.
 
 @discussion Calculated internally a number of steps, step resolution, and publish period value.
 */
- (instancetype)initWithRawValue:(UInt8)period;

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
