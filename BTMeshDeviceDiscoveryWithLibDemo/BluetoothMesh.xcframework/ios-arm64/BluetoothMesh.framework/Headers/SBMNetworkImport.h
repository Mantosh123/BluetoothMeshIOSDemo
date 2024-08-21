//
//  SBMNetworkImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMSubnetImport.h"
#import "SBMSceneImport.h"
#import "SBMProvisionerImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A SBMNetworkImport object contains informations used to import
 Network is representation for the whole Mesh structure
 */
@interface SBMNetworkImport : NSObject

/**
 Network's version.
 Represents a version number of the Mesh Configuration Database which this mesh object supports.
 */
@property (nonatomic, readonly) NSString* version;

/**
 Network's uuid. 16-bytes
 It allows differentation among multiple mesh networks.
 */
@property (nonatomic, readonly) NSData* uuid;

/**
 Network's name.
 It is human-readable name for this mesh network
 */
@property (nonatomic, readwrite, nullable) NSString* name;

/**
 Network's subnets.
 */
@property (nonatomic, readonly) NSArray<SBMSubnetImport*> *subnets;

/**
 Network's provisioners.
 */
@property (nonatomic, readonly) NSArray<SBMProvisionerImport*> *provisioners;

/**
 Network's scenes.
 */
@property (nonatomic, readonly) NSArray<SBMSceneImport*> *scenes;

/**
 Network's nodes
 */
@property (nonatomic, readonly) NSArray<SBMNodeImport*> *nodes;


@property (nonatomic, readonly) NSArray<SBMGroupImport*> *groups;

/**
 Creates and adds new scene with number to import
 @param number number of scene to be created
 @return Returns new created object to be configured
 */
- (SBMSceneImport*)createSceneWithNumber:(NSNumber*)number;

/**
 Creates and adds new provisioner with uuid to import
 @param uuid uuid of provisioner to be created
 @return Returns new created object to be configured
 */
- (SBMProvisionerImport*)createProvisionerWithUUID:(NSData*)uuid;

/**
 Creates and adds new subnet to import
 @param netKey NetworkKey which will be assigned to Subnet. There is not possible to share one NetworkKey through many subnets.
 @return Returns new created object to be configured
 */
- (SBMSubnetImport*)createSubnetWithNetKey:(SBMNetKeyImport*)netKey;


/**
 Creates and adds new subnet to import
 */
- (SBMGroupImport*)createGroup:(UInt16)address;


/**
 Creates and adds new node to import
 @param uuid uuid of the Node
 @param primaryAddress primaryElementAddress of the Node
 @param deviceKey deviceKey of the Node
 @return Returns new created object to be configured
 */
- (SBMNodeImport*)createNode:(NSData*)uuid primaryElementAddress:(NSInteger)primaryAddress deviceKey:(SBMDevKeyImport*)deviceKey;

/**
 Not available. Use SBMImporter createNetwork
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMImporter createNetwork
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
