//
//  SBMConnectableDeviceHelper.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 30.11.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMConnectableDevice.h"
#import "SBMConnectableDeviceMatchResult.h"
#import "SBMSubnet.h"
#import "SBMNode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Helper class that contains methods to retrieve objects associated with given device.
 */
@interface SBMConnectableDeviceHelper : NSObject

/**
 Not available. Use class methods instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use class methods instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Method used to filter devices that are unprovisioned.

 @param devices Array of devices to filter.
 @return Array of devices that are unprovisioned.
 */
+ (NSArray<id<SBMConnectableDevice>> *)filterUnprovisionedDevices:(NSArray<id<SBMConnectableDevice>> *)devices;

/**
 Method used to get node that represents given device.

 @param device Device for which to retrieve node object.
 @return Node object, or nil if no node is found for given device.
 */
+ (nullable SBMNode *)node:(id<SBMConnectableDevice>)device;

/**
 Returns mesh address of the device. Returns 0 if address could not be retrieved.

 @param uuid UUID of the device.
 @return Device's mesh address.
 */
+ (NSUInteger)addressForDeviceUUID:(NSData*)uuid;

/**
 Checks if service advertisement is for a known mesh network.

 @param address Element address to match when node identity advertisements are matched; can be left to 0x0000 if only network ID matching is done.
 @param data Advertising data.
 @note SBMNode instance for given SBMConnectableDevice can be retrieved using method node:inSubnet:
 @return Result of a match.
 */
+ (SBMConnectableDeviceMatchResult*)networkMatchResultForAddress:(NSInteger)address advertisingData:(NSData*)data;

/**
 Method used to get node that represents given device in specific subnet.

 @param device Device for which to retrieve node object.
 @param subnet Subnet in which to look for node object.
 @return Node object, or nil if no node is found for given device in subnet.
 */
+ (nullable SBMNode *)node:(id<SBMConnectableDevice>)device inSubnet:(SBMSubnet*)subnet;

/**
 Method used to get all subnets for given device.

 @param device Device for which to retrieve subnets.
 @return Array of subnets that are found for given device.
 */
+ (NSArray<SBMSubnet *> *)allSubnets:(id<SBMConnectableDevice>)device;

/**
 Checks if device advertising data matches known network key value.
 It match successfully only if the connectable Device has disabled node identity feature.
 
 @param netKey  Network key value.
 @param device  ConnectableDevice which advertisingData shall be matched
 @param error   Error describing reason of failure.
 @return Information if the NetKey matches.
 */
+ (BOOL)doesNetKey:(NSData*)netKey matchAdvertisingData:(id<SBMConnectableDevice>)device error:(NSError**)error;

@end

NS_ASSUME_NONNULL_END
