//
//  SBMLightingCTLGet.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 23/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Lighting CTLGet functionality object. It represents the color temperature of tunable white light emitted by an element.
 */
@interface SBMLightingCTLGet : NSObject<SBMControlValueGetSigModel>

/**
 Present value of Lighting CTLGet functionality lightness.
 */
@property (nonatomic, readonly) UInt16 lightness;

/**
 Present value of Lighting CTLGet functionality temperature.
 */
@property (nonatomic, readonly) UInt16 temperature;

/**
 Target value of Lighting CTLGet functionality lightness.
 */
@property (nonatomic, readonly) UInt16 targetLightness;

/**
 Target value of Lighting CTLGet functionality temperature.
 */
@property (nonatomic, readonly) UInt16 targetTemperature;

/**
 Indicates the time it will take the element to complete the transition to the target state.
 This property is nil if used as set request or no transition is in progress.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

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
