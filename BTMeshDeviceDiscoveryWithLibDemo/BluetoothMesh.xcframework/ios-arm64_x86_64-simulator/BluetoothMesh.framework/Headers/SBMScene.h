//
//  SBMScene.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 26/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class SBMNetwork;
@class SBMNode;

NS_ASSUME_NONNULL_BEGIN

@interface SBMScene : NSObject

/**
 Scene's name
 */
@property (nonatomic, readonly) NSString* name;

/**
 Scene's number
 */
@property (nonatomic, readonly) UInt16 number;

/**
 Nodes which Scene Register state contains this scene.
 This value is updated for every received SBMSceneRegisterStatus
 */
@property (nonatomic, readonly) NSArray<SBMNode*>* nodes;

/**
 Scene's network.
 */
@property (nonatomic, readonly, weak) SBMNetwork* network;

/**
Removes node from scene. Action is done only for local storage. Use changeSceneRegister method with SBMSceneDelete as argument from SBMControlElement to delete scene from the node in the mesh network.
*/
- (void)removeNodeFromLocalStructure:(SBMNode*)node;

/**
Adds node to scene. Action is done only for local storage. Use changeSceneRegister method with SBMSceneStore as argument from SBMControlElement to add scene to the node in the mesh network.
*/
- (void)addNodeToLocalStructure:(SBMNode*)node;

/**
 Removes scene only from local storage.
 */
- (void)removeOnlyFromLocalStructure;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
