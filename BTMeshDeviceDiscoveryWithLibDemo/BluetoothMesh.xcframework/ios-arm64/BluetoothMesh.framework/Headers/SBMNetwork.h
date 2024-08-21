//
//  SBMNetwork.h
//  ble_mesh-lib
//
//  Created by Michal Lenart on 23/04/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMGroup.h"
#import "SBMSubnet.h"
#import "SBMFixedGroupAddress.h"
#import "SBMProvisioner.h"
#import "SBMScene.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A SBMNetwork object contains informations about the Bluetooth Mesh Network.
 */
@interface SBMNetwork : NSObject

/**
 Network's version.
 */
@property (nonatomic, readwrite) NSString* version;

/**
 Network's uuid.
 */
@property (nonatomic, readonly) NSUUID* uuid;
/**
 Network's name.
 */
@property (nonatomic, readwrite, nullable) NSString* name;


/**
 Value that represents the last time the Provisioner database has been modified
 The timestamp property contains a UNIX timestamp (seconds since 1/1/1970)
 */
@property (nonatomic, readonly) long timestamp;

/**
 Network's subnets.
 */
@property (nonatomic, readonly) NSArray<SBMSubnet *> *subnets;

/**
 Network's groups.
 */
@property (nonatomic, readonly) NSArray<SBMGroup *> *groups;

/**
 Network's nodes.
 */
@property (nonatomic, readonly) NSArray<SBMNode *> *nodes;

/**
 Provisioners object
 */
@property (nonatomic, readonly) NSArray<SBMProvisioner *> *provisioners; //BC: - Provisioner

/**
 Network's scenes.
 */
@property (nonatomic, readonly) NSArray<SBMScene *> *scenes; //BC: - Provisioner


/**
 Creates network's subnet.
 
 @param key 16 bytes of network key data. Pass nil to be generated using random number generator.
 @param index Network key index. Pass nil to use the lowest available index.
 @param error Error that specifies reason of failure when creating subnet. Can be nil.
 @return Created subnet, or nil if subnet could not be created.
 */
- (nullable SBMSubnet*)createSubnetWithKey:(nullable NSData*)key index:(nullable NSNumber *)index error:(NSError *__autoreleasing  _Nullable *)error;

/**
 Removes subnet from the network.
 
 @param subnet Name of subnet to remove from the network.
 */
- (void)removeSubnet:(SBMSubnet *)subnet;

/**
 Creates a new group.
 
 @param address Address of the group to create. Has to be a value higher than 0xC000. Pass nil if group should be assigned first available address.
 @param error Error that specifies reason of failure when creating group. Can be nil.
 @return Created group, or nil if group could not be created.
 */
- (nullable SBMGroup*)createGroupWithAddress:(SBMAddress * _Nullable)address error:(NSError *__autoreleasing _Nullable *)error NS_SWIFT_NAME(createGroup(withAddress:));

/**
 Creates a new fixed group with the default name for that fixed address, e.g. "All Proxies".
 
 @param fixedAddress Fixed address of the group to create. Has to be a SBMFixedGroupAddress enum.
 @param error Error that specifies reason of failure when creating group. Can be nil.
 @return Created group, or nil if group could not be created.
 */
- (nullable SBMGroup*)createGroupWithFixedAddress:(SBMFixedGroupAddress)fixedAddress error:(NSError *__autoreleasing _Nullable *)error;


/**
Creates network's scene.

@param name Name of scene to create.
@param number Scene number of the scene to create. The value 0x0 is Prohibited.
@param error Error that specifies reason of failure when creating scene. Can be nil.
@return Created scene, or nil if scene could not be created.
*/
- (nullable SBMScene*)createSceneWithName:(NSString*)name number:(UInt16)number error:(NSError**)error; //BC: - Scene

/**
 Removes group from the network.
 
 @param group Group to be removed from the netowrk.
 */
- (void)removeGroup:(SBMGroup *)group;

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
