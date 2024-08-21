//
//  SBMLightingCTLSet.h
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
@interface SBMLightingCTLSet : NSObject<SBMControlValueSetSigModel>

/**
 Value of Lighting CTLSet functionality lightness.
 */
@property (nonatomic, readonly) UInt16 lightness;

/**
 Value of Lighting CTLSet functionality temperature.
 */
@property (nonatomic, readonly) UInt16 temperature;

/**
 Value of Lighting CTLSet functionality deltaUV.
 This property is valid only if object represents set request.
 */
@property (nonatomic, readonly) SInt16 deltaUv;

/**
 Target value of Lighting CTLGet functionality lightness.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) UInt16 targetLightness;

/**
 Target value of Lighting CTLGet functionality temperature.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) UInt16 targetTemperature;

/**
 Indicates the time it will take the element to complete the transition to the target state.
 This property is nil if used as set request or no transition is in progress.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

/**
 Initialize new Lighting CTLSet functionality object.

 @param lightness Lightness value that functionality should be initialized with.
 @param temperature Temperature value that functionality should be initialized with.
 @param deltaUv DeltaUV value that functionality should be initialized with.
 @return An initialized Lighting CTLSet functionality object, or nil if an object could not be created.
 */
- (instancetype)initWithLightness:(UInt16)lightness temperature:(UInt16)temperature deltaUv:(SInt16)deltaUv;

/**
 Not available. Use initWithLightness instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithLightness instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
