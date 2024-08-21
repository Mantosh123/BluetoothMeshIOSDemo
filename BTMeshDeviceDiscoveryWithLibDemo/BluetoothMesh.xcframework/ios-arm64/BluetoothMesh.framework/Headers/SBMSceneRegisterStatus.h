//
//  SBMSceneRegisterStatus.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 06/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSceneResponse.h"
#import "SBMSceneStatusCode.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a message that is used to report the current status of the Scene Register of an element
 (see 5.2.2.8 Scene Register Status from the Mesh Model Bluetooth Specification).
 */
@interface SBMSceneRegisterStatus : NSObject<SBMSceneResponse>

/*
Status Code for the previous operation.
*/
@property(nonatomic, readonly) SBMSceneStatusCodeType status;

/*
Scene Number of a current scene.
*/
@property(nonatomic, readonly) UInt16 currentScene;

/*
Array of scene numbers (16-bit value) stored within an element.
*/
@property(nonatomic, readonly) NSArray<NSNumber* > *scenes;

@end

NS_ASSUME_NONNULL_END
