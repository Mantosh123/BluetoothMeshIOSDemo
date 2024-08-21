//
//  SBMModel.h
//  ble_mesh-lib
//
//  Created by Lukasz Rzepka on 04.05.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMModelSettings.h"
@class SBMElement;
@class SBMGroup;
@class SBMApplicationKey;

NS_ASSUME_NONNULL_BEGIN

/**
 Model is an object created after receive the device composition data (DCD) for a Node.
 */
@interface SBMModel: NSObject

/**
 Identifier of the model.
 */
@property (nonatomic, readonly) NSInteger identifier;

/**
 Name of the model.
 */
@property (nonatomic, readonly) NSString* name;

/**
 Element that model is contained in.
 */
@property (nonatomic, readonly, weak) SBMElement* meshElement;

/**
 Application keys bound to the model.
 */
@property (nonatomic, readonly) NSArray<SBMApplicationKey *> *boundAppKeys;

/**
 Publication and subscriptions settings for the Model.
 */
@property (nonatomic, readonly) SBMModelSettings* modelSettings;

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
