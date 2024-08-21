//
//  SBMModelImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMModelSettingsImport.h"
@class SBMGroupImport;

NS_ASSUME_NONNULL_BEGIN

/**
 Class used to import model to Device Composition Data of the node
 */
@interface SBMModelImport : NSObject

/**
 Identifier of the model.
 */
@property (nonatomic, readonly) NSInteger identifier;

/**
 Publication and subscriptions settings for the Model.
 */
@property (nonatomic, readonly) SBMModelSettingsImport* settings;

/**
 Array of groups that are bound to this model.
 */
@property (nonatomic, readonly) NSArray<SBMGroupImport*> *boundGroups;

/**
 Adds group to model
 */
- (void)addGroup:(SBMGroupImport*)group;

/**
 Not available. Use SBMElementImport addModel
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMElementImport addModel
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
