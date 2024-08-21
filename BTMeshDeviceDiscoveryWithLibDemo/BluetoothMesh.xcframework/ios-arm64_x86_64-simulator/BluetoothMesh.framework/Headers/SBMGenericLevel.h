//
//  SBMGenericLevel.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 23/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Generic Level functionality object. It represents the state of an element. The meaning of the state is determined by the model.
 */
@interface SBMGenericLevel : NSObject<SBMControlValueGetSigModel, SBMControlValueSetSigModel>

/**
 Value of Generic Level functionality.
 */
@property (nonatomic, readonly) SInt16 level;

/**
 Target value of Generic Level functionality.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) SInt16 targetLevel;

/**
 Indicates the time it will take the element to complete the transition to the target state.
 This property is nil if used as set request or no transition is in progress.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

/**
 Initialize new Generic Level functionality object.

 @param level Level value that functionality should be initialized with.
 @return An initialized Generic Level functionality object, or nil if an object could not be created.
 */
- (instancetype)initWithLevel:(SInt16)level;

/**
 Not available. Use initWithLevel instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithLevel instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
