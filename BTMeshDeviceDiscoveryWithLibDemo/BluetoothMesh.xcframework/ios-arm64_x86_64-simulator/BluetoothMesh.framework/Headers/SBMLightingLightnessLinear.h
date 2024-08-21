//
//  SBMLightingLightnessLinear.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Lighting LightnessLinear functionality object. It represents the lightness of a light on a linear scale.
 */
@interface SBMLightingLightnessLinear : NSObject<SBMControlValueGetSigModel, SBMControlValueSetSigModel>

/**
 Present value of Lighting LightnessLinear functionality.
 */
@property (nonatomic, readonly) UInt16 lightness;

/**
 Target value of Lighting LightnessLinear functionality.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) UInt16 targetLightness;

/**
 Indicates the time it will take the element to complete the transition to the target state.
 This property is nil if used as set request or no transition is in progress.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

/**
 Initialize new Lighting LightnessLinear functionality object.

 @param lightness Lightness value that functionality should be initialized with.
 @return An initialized Lighting LightnessLinear functionality object, or nil if an object could not be created.
 */
- (instancetype)initWithLightness:(UInt16)lightness;

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
