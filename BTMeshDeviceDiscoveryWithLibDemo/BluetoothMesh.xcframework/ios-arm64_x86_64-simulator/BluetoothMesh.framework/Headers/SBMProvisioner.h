//
//  SBMProvisioner.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 24/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMAddressRange.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A Provisioner is a mesh node that is capable of adding a device to a mesh network.
 */
@interface SBMProvisioner : NSObject

/**
 Name of provisioner within the mesh network.
 */
@property (nonatomic, readonly) NSString *provisionerName;

/**
 Provisioner UUID.
 */
@property (nonatomic, readonly) NSString *uuid;

/**
 Range of unicast addresses that the Provisioner can allocate to new devices when
 they are provisioned into a mesh network, without needing to coordinate the node additions
 with other Provisioners.
 */
@property (nonatomic, readonly) NSArray<SBMAddressRange*> *allocatedUnicastRange;

/**
 Range of group addresses that the Provisioner can allocate to newly created groups
 when they are provisioned into a mesh network, without needing to coordinate the group
 additions with other Provisioners.
 */
@property (nonatomic, readonly) NSArray<SBMAddressRange*> *allocatedGroupRange;

/**
 Range of scene numbers that the Provisioner can use to register new scenes in a mesh
 network, without needing to coordinate the allocated scene numbers with other Provisioners.
 */
@property (nonatomic, readonly) NSArray<SBMAddressRange*> *allocatedSceneRange;

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
