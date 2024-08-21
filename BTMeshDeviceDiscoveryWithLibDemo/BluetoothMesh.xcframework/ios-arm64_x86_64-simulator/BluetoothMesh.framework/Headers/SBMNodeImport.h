//
//  SBMNodeImport.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 16/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMNodeSecurityImport.h"
#import "SBMNodeSettingsImport.h"
#import "SBMDeviceCompositionDataImport.h"
#import "SBMDevKeyImport.h"
#import "SBMElementImport.h"
#import "SBMAppKeyImport.h"

@class SBMSubnetImport;
@class SBMGroupImport;

NS_ASSUME_NONNULL_BEGIN
/**
 SBMNodeImport is class used to import Node.
 It contains all the information about a Bluetooth Mesh device in a Network.
 */
@interface SBMNodeImport : NSObject

/**
 Node's uuid
 */
@property (nonatomic, readwrite) NSData *uuid;

/**
 Node name.
 */
@property (nonatomic, readwrite, nullable) NSString *name;

/**
 Mesh device primary element address
 */
@property (nonatomic, readwrite) NSInteger primaryElementAddress;

/**
 Informations about the Node security.
 */
@property (nonatomic, readonly) SBMNodeSecurityImport *security;

/**
 Informations about the Node settings.
 */
@property (nonatomic, readonly) SBMNodeSettingsImport *settings;

/**
 Node device composition data.
 It could be created using createDeviceCompositionData
 */
@property (nonatomic, readonly, nullable) SBMDeviceCompositionDataImport *deviceCompositionData;

/**
 Device crypto key.
 */
@property (nonatomic, readonly) SBMDevKeyImport *devKey;

/**
 Node elements.
 To add new element use createElementWithIndex:andLocation:
 */
@property (nonatomic, readonly) NSArray<SBMElementImport*> *elements;

/**
 Array of subnets that this node is in.
 Use addSubnet: to add new subnet
 */
@property (nonatomic, readonly) NSArray<SBMSubnetImport*> *subnets;

/**
 Array of groups that this node is in.
 Use addGroup: to add new group
 */
@property (nonatomic, readonly) NSArray<SBMGroupImport*> *groups;

@property (nonatomic, readonly) NSArray<SBMAppKeyImport*> *appkeys;

/**
 Adds new this node to the subnet
 */
- (void)addSubnet:(SBMSubnetImport*)subnet;

/**
 Adds this node to group
 */
- (void)addGroup:(SBMGroupImport*)group;
- (void)addAppkey:(SBMAppKeyImport *)appkey;

/**
 Creates and adds new Element
 @param index index of created element
 @param location location of created element
 @return new created element to be configured
 */
- (SBMElementImport*)createElementWithIndex:(UInt8)index andLocation:(UInt32)location;

/**
 Creates and set new DeviceCompositionData
 @return new created object to be configured
 */
- (SBMDeviceCompositionDataImport*)createDeviceCompositionData;

/**
 Not available. Use SBMSubnetImport addNodeWithUuid:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMSubnetImport addNodeWithUuid:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
