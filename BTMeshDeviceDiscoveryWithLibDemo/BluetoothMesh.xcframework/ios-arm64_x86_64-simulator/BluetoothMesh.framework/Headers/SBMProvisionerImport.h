//
//  SBMProviderImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMAddressRangeImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A SBMProvisionerImport object contains informations used to import
 */
@interface SBMProvisionerImport : NSObject

/**
 Name of provisioner within the mesh network.
 */
@property (nonatomic, readwrite, nullable) NSString *name;

/**
 Provisioner UUID.
 */
@property (nonatomic, readonly) NSData *uuid;

/**
 Range of unicast addresses that the Provisioner can allocate to new devices when
 they are provisioned into a mesh network, without needing to coordinate the node additions
 with other Provisioners.
 */
@property (nonatomic, readonly) NSArray<SBMAddressRangeImport*> *allocatedUnicastRange;

/**
 Range of group addresses that the Provisioner can allocate to newly created groups
 when they are provisioned into a mesh network, without needing to coordinate the group
 additions with other Provisioners.
 */
@property (nonatomic, readonly) NSArray<SBMAddressRangeImport*> *allocatedGroupRange;

/**
 Range of scene numbers that the Provisioner can use to register new scenes in a mesh
 network, without needing to coordinate the allocated scene numbers with other Provisioners.
 */
@property (nonatomic, readonly) NSArray<SBMAddressRangeImport*> *allocatedSceneRange;

/**
 Creates and adds new unicastRange with values
 @param lowAddress the lowest possible address
 @param highAddress the highest possible address
 @return new created object
 */
- (SBMAddressRangeImport*) createUnicastRangeWithLowAddress:(UInt16)lowAddress andHighAddress:(UInt16)highAddress;

/**
 Creates and adds new groupRange with values
 @param lowAddress the lowest possible address
 @param highAddress the highest possible address
 @return new created object
 */
- (SBMAddressRangeImport*) createGroupRangeWithLowAddress:(UInt16)lowAddress andHighAddress:(UInt16)highAddress;

/**
 Creates and adds new sceneRange with values
 @param lowAddress the lowest possible address
 @param highAddress the highest possible address
 @return new created object
 */
- (SBMAddressRangeImport*) createSceneRangeWithLowAddress:(UInt16)lowAddress andHighAddress:(UInt16)highAddress;

/**
 Not available. Use SBMNetworkImport addProvisionerWithUUID:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMNetworkImport addProvisionerWithUUID:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
