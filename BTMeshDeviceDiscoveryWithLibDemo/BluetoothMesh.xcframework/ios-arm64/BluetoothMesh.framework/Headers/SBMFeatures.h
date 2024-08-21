//
//  SBMFeatures.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 02/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents the functionality of a mesh node that is determined by the set features that the node supports
 */
@interface SBMFeatures : NSObject

/**
 The value is set to true if Relay feature is enabled.
 Type is BOOL. Property is set to NULL when value is not known.
 */
@property (nonatomic, readwrite, nullable) NSNumber* relayEnabled;

/**
 The value is set to true if Proxy feature is enabled
 Type is BOOL. Property is set to NULL when value is not known.
 */
@property (nonatomic, readwrite, nullable) NSNumber* proxyEnabled;

/**
 The value is set to true if Friend feature is enabled
 Type is BOOL. Property is set to NULL when value is not known.
 */
@property (nonatomic, readwrite, nullable) NSNumber* friendEnabled;

/**
 The value is set to true if LowPower feature is enabled
 Type is BOOL. Property is set to NULL when value is not known.
 */
@property (nonatomic, readwrite, nullable) NSNumber* lowPower;
@end

NS_ASSUME_NONNULL_END
