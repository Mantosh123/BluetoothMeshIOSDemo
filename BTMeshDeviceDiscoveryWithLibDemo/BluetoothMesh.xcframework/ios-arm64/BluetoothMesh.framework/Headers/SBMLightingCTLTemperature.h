//
//  SBMLightingCTLTemperature.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 23/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Lighting CTLTemperature functionality object. It represents the color temperature of tunable white light emitted by an element.
 */
@interface SBMLightingCTLTemperature : NSObject<SBMControlValueGetSigModel, SBMControlValueSetSigModel>

/**
 Value of Lighting CTLTemperature functionality temperature.
 */
@property (nonatomic, readonly) UInt16 temperature;

/**
 Value of Lighting CTLTemperature functionality deltaUV. It determines the distance from the Black Body curve.
 */
@property (nonatomic, readonly) SInt16 deltaUv;

/**
 Value of Lighting CTLTemperature functionality temperature.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) UInt16 targetTemperature;

/**
 Value of Lighting CTLTemperature functionality deltaUV. It determines the distance from the Black Body curve.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) SInt16 targetDeltaUv;

/**
 Indicates the time it will take the element to complete the transition to the target state.
 This property is nil if used as set request or no transition is in progress.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

/**
 Initialize new Lighting CTLTemperature functionality object.

 @param temperature Temperature value that functionality should be initialized with.
 @param deltaUv DeltaUV value that functionality should be initialized with.
 @return An initialized Lighting CTLTemperature functionality object, or nil if an object could not be created.
 */
- (instancetype)initWithTemperature:(UInt16)temperature deltaUv:(SInt16)deltaUv;

/**
 Not available. Use initWithTemperature instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithTemperature instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
