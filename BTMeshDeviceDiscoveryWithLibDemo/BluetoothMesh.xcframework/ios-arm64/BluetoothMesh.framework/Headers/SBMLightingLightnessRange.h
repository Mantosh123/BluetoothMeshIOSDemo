//
//  SBMLightingLightnessRange.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 23/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"
#import "SBMGenericRangeStatus.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Lighting LightnessRange functionality object. It represents the minimum and maximum lightness of and element.
 */
@interface SBMLightingLightnessRange : NSObject<SBMControlValueGetSigModel, SBMControlValueSetSigModel>

/**
 Value of Lighting LightnessRange functionality minimum. 0 is prohibited.
 */
@property (nonatomic, readonly) UInt16 min;

/**
 Value of Lighting LightnessRange functionality maximum. 0 is prohibited.
 */
@property (nonatomic, readonly) UInt16 max;

/**
 Represents status of last operation on lightness range state.
 This property is valid only if object represents response message.
 */
@property (nonatomic, readonly) SBMGenericRangeStatus rangeStatus;

/**
 Initialize new Lighting LightnessRange functionality object.

 @param min Lightness minimum value that functionality should be initialized with.
 @param max Lightness maximum value that functionality should be initialized with.
 @return An initialized Lighting LightnessRange functionality object, or nil if an object could not be created.
 */
- (instancetype)initWithMin:(UInt16)min max:(UInt16)max;

/**
 Not available. Use initWithMin instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithMin instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
