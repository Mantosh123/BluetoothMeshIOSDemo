//
//  SBMGenericLevelMove.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Generic LevelMove functionality object. It represents the step to calculate move speed of the element's level state.
 */
@interface SBMGenericLevelMove : NSObject<SBMControlValueSetSigModel>

/**
 Level step to calculate move speed of the level state.
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
@property (nonatomic, readonly) NSNumber *remainingTime;

/**
 Initialize new Generic LevelMove functionality object.

 @param level Delta value that functionality should be initialized with.
 @return An initialized Generic LevelMove functionality object, or nil if an object could not be created.
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
