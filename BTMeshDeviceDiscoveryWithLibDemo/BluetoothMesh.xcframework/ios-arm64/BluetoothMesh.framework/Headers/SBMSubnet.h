//
//  SBMSubnet.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 13/11/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMNode.h"
#import "SBMNetworkKey.h"
#import "SBMTuple.h"
#import "SBMSubnetSecurity.h"
@class SBMNetwork;

NS_ASSUME_NONNULL_BEGIN

/**
 A SBMSubnet object contains informations about the Bluetooth Mesh Network.
 */
@interface SBMSubnet : NSObject

/**
 Subnet key.
 */
@property (nonatomic, readonly) SBMNetworkKey* netKey;

/**
 Subnet's network.
 */
@property (nonatomic, readonly, weak) SBMNetwork* network;

/**
 Subnet's application keys.
 */
@property (nonatomic, readonly) NSArray<SBMApplicationKey*>* appKeys;

/**
 Subnet's nodes.
 */
@property (nonatomic, readonly) NSArray<SBMNode*>* nodes;

/**
 Subnet's security options
 */
@property (nonatomic, readonly) SBMSubnetSecurity* subnetSecurity;


/**
 Remove the application key.
 
 This method is not checking if the key is currently used or not.
 Using this method can cause an unexpected effect if you remove the object that is in use by your network.
 
 @param appKey appkey to be removed.
 @param error out parameter. Set if the application key removing failed.
 @return Return YES if success NO if failed
 */
- (BOOL)removeAppKey:(SBMApplicationKey *)appKey error:(NSError **)error;

/**
 Creates a new application key and binds it to the subnet.
 
 The initialized key takes the lowest free index unless the keys limit is reached.
 The key data is generated using a cryptographically secure random number generator.

 @param error Error that specifies reason of failure when creating an application key. Can be nil.
 @return Created application key, or nil if application key could not be created.
 */
- (SBMApplicationKey *)createAppKey:(NSError *__autoreleasing  _Nullable *)error NS_SWIFT_NAME(createAppKey(error:));

/**
 Creates a new application key and binds it to the subnet.
 
 @param key 16 bytes of application key data generated using random number generator.
 @param index Application key index.
 @param error Error that specifies reason of failure when creating an application key. Can be nil.
 @return Created application key, or nil if application key could not be created.
 */
- (SBMApplicationKey *)createAppKeyWithKey:(NSData *)key index:(UInt16)index error:(NSError *__autoreleasing  _Nullable *)error;

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
