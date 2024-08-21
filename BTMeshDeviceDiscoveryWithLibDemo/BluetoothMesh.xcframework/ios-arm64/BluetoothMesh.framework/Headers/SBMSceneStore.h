//
//  SBMSceneStore.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 18/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSceneControlRequest.h"
#import "SBMSceneMessageFlags.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to store the current state of an element as a Scene, which can be recalled later
 */
@interface SBMSceneStore : NSObject<SBMSceneControlRequest>

/**
Scene to be stored in Scene model from element.
*/
@property (nonatomic) UInt16 sceneNumber;

/**
 Not available.
 Use initWithFlags:scene: instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 Use initWithFlags:scene: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize new Scene store request object.
 
 @param flags Message flags to be used for this message
 @param scene Scene to be stored in Scene model from element.
 */
- (instancetype)initWithFlags:(SBMSceneMessageFlags *)flags
                        scene:(UInt16)scene;

@end

NS_ASSUME_NONNULL_END
