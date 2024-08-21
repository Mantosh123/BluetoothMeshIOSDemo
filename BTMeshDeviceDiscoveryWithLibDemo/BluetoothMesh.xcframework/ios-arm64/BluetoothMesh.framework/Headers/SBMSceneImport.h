//
//  SBMSceneImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
@class SBMNodeImport;

NS_ASSUME_NONNULL_BEGIN

/**
 SBMSceneImport object contains informations used to import Scene
 */
@interface SBMSceneImport : NSObject

/**
 Human-readable name of the scene
 */
@property (nonatomic, readwrite, nullable) NSString *name;

/**
 Scene's number.
 */
@property (nonatomic, readwrite) NSNumber *number;

/**
 Nodes whose Scene Register contains this scene
 */
@property (nonatomic, readonly) NSArray<SBMNodeImport*> *nodes;

/**
 Adds node to scene for import.
 */
- (void)addNode:(SBMNodeImport*)node;

/**
 Not available. Use SBMNetworkImport addSceneWithNumber:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMNetworkImport addSceneWithNumber:
 */
- (instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
