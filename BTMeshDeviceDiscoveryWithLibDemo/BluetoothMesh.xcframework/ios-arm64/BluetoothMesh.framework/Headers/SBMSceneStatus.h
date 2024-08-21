//
//  SBMSceneStatus.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 06/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSceneResponse.h"

#import <Foundation/Foundation.h>
#import "SBMSceneStatusCode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message reporting the current status of a currently active scene
 */
@interface SBMSceneStatus : NSObject<SBMSceneResponse>

/**
 Status code for the last operation.
 */
@property(nonatomic, readonly) SBMSceneStatusCodeType status;

/**
 Scene Number of a current scene.
 */
@property(nonatomic, readonly) UInt16 currentScene;

/**
 Scene Number of a target scene, 16-bit value. (Optional)
 */
@property(nonatomic, readonly, nullable) NSNumber *targetScene;

/**
 Indicates the time it will take the element to complete the transition to the target Scene state, 32-bit value. (Optional)
 */
@property(nonatomic, readonly, nullable) NSNumber *remainingTime;

@end

NS_ASSUME_NONNULL_END
