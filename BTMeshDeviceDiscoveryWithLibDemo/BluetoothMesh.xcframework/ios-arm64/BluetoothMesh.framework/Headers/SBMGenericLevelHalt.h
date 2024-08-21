//
//  SBMGenericLevelHalt.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Generic LevelHalt functionality object.
 */
@interface SBMGenericLevelHalt : NSObject<SBMControlValueSetSigModel>

/**
 Value of Generic Level functionality.
 This property is valid only if object is received as response to set request.
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

@end

NS_ASSUME_NONNULL_END
