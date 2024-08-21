//
//  SBMSceneDelete.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 16/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSceneControlRequest.h"
#import "SBMSceneMessageFlags.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to delete a Scene from the Scene Register state
 */
@interface SBMSceneDelete : NSObject<SBMSceneControlRequest>

/**
 Scene to be deleted from Scene model in element.
 */
@property (nonatomic) UInt16 sceneNumber;

/**
 Not available. Use initWithFlags:scene: instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithFlags:scene: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize new Scene delete request object.
 
 @param flags Message flags to be used for this message
 @param scene Scene to be deleted from Scene model in element.
 */
- (instancetype)initWithFlags:(SBMSceneMessageFlags *)flags
                        scene:(UInt16)scene;


@end

NS_ASSUME_NONNULL_END
