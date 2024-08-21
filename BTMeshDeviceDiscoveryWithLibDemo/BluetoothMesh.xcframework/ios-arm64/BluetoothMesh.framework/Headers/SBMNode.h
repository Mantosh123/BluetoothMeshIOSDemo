//
//  SBMNode.h
//  ble_mesh-lib
//
//  Created by Michal Lenart on 23/04/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMDeviceCompositionData.h"
#import "SBMDeviceKey.h"
#import "SBMElement.h"
#import "SBMIntegerAddress.h"
#import "SBMNodeSecurity.h"
#import "SBMNodeSettings.h"


@class SBMNodeControl;
@class SBMSubnet;
@class SBMGroup;
@class SBMApplicationKey;

NS_ASSUME_NONNULL_BEGIN

/**
 A SBMNode is the object that contains all the information about a Bluetooth Mesh device in a Network. It is created right after provision a device. After add node to group (Configure available models from DCD), it will be possible to get all configured Elements and Models from the configuration object. DCD can be also downloaded manually without adding to the specific group.
 */
@interface SBMNode : NSObject

/**
 Node name.
 */
@property (nonatomic, readwrite) NSString *name;

/**
 Mesh device primary element address
 */
@property (nonatomic, readonly) SBMIntegerAddress *primaryElementAddress;

/**
 Mesh device UUID taken from the Bluetooth device advertisement.
 */
@property (nonatomic, readonly) NSUUID *uuid;

/**
 Device crypto key.
 */
@property (nonatomic, readonly) SBMDeviceKey *devKey;

/**
 Array of subnets that this node is in.
 */
@property (nonatomic, readonly) NSArray<SBMSubnet *> *subnets;

/**
 Node elements.
 */
@property (nonatomic, readonly) NSArray<SBMElement *> *elements;

/**
 Application keys bound to the node.
 */
@property (nonatomic, readonly) NSArray<SBMApplicationKey *> *boundAppKeys;

/**
 Node device composition data.
 */
@property (nonatomic, readonly, nullable) SBMDeviceCompositionData *deviceCompositionData;

/**
 Informations about the Node security.
 */
@property (nonatomic, readonly) SBMNodeSecurity* security;

/**
 Settings of the Node.
 */
@property (nonatomic, readonly) SBMNodeSettings* settings;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Check whether node is connected to the network as proxy.

 @return BOOL value specifying whether node is connected to the network as proxy.
 */
- (BOOL)isConnectedAsProxy;

/**
 Removes node only from local storage.
 */
- (void)removeOnlyFromLocalStructure;

/**
 Overrides old device composition data with new one.
 Be aware this method replace old elements and models with new ones.
 Thus, infomation about boundAppKeys to model is lost.
 It is recommended to use this method once after provisioning and after every OTA update.
 
 To fetch new composiition data use 'SBMConfigurationControl.getCompositionData'.
 Use 'SBMFunctionalityBinder.bindAppKey' to bind appKey to new models.
 
 @param newDeviceCompositionData Data received from the `successCallback` of `SBMConfigurationControl.getCompositionData`.
 */
- (void)overrideDeviceCompositionData:(NSData *)newDeviceCompositionData;

@end

NS_ASSUME_NONNULL_END
