//
//  SBMGenericPowerLevel.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 23/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Generic PowerLevel functionality object. It represents the power level state of an element.
 */
@interface SBMGenericPowerLevel : NSObject<SBMControlValueGetSigModel, SBMControlValueSetSigModel>

/**
 Value of Generic PowerLevel functionality.
 */
@property (nonatomic, readonly) UInt16 powerLevel;

/**
 Target value of Generic PowerLevel functionality.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) UInt16 targetPowerLevel;

/**
 Indicates the time it will take the element to complete the transition to the target state.
 This property is nil if used as set request or no transition is in progress.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

/**
 Initialize new Generic PowerLevel functionality object.

 @param powerLevel PowerLevel value that functionality should be initialized with.
 @return An initialized Generic PowerLevel functionality object, or nil if an object could not be created.
 */
- (instancetype)initWithPowerLevel:(UInt16)powerLevel;

/**
 Not available. Use initWithPowerLevel instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithPowerLevel instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
