//
//  SBMNodeSecurity.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 02/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMNodeAppKey.h"
#import "SBMNodeNetKey.h"
#import "SBMSecurityType.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Properties that define Node security
 */
@interface SBMNodeSecurity : NSObject

/**
 Reflects if the Node is in the process of being deleted and is excluded
 from the new network key distribution during key refresh procedure.
 */
@property (nonatomic, readonly) BOOL blacklisted;

/**
 Represents the level of security for the subnet on which the node has beed originally provisioned.
 */
@property (nonatomic, readonly) SBMSecurityType security;

/**
 Represents whether the node is configured to send Secure Network beacons.
 Currently it's not updated.
 */
@property (nonatomic, readonly) BOOL isSecureNetworkBeacon;

/**
 Application keys known to this node.
 */
@property (nonatomic, readonly) NSArray<SBMNodeAppKey*>* appKeys;

/**
 Network keys known to this node.
 */
@property (nonatomic, readonly) NSArray<SBMNodeNetKey*>* netKeys;

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
