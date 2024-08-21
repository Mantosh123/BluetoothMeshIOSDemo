//
//  SBMGroup.h
//  ble_mesh-lib
//
// Created by Maciej Siciarz on 2021-04-09.
// Copyright (c) 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMAddress.h"

@class SBMNode;
@class SBMNetwork;
@class SBMSigModel;
@class SBMVendorModel;

NS_ASSUME_NONNULL_BEGIN

/**
 SBMGroup object that contains information about mesh group.
 */
@interface SBMGroup : NSObject

/**
 Nodes with at least one model subscribing to the group.
 
 @see SBMSubscriptionControl.addSubscriptionSettings(group: SBMGroup, successCallback: SBMSubscriptionControlSubscriptionSuccess, errorCallback: SBMSubscriptionControlSubscriptionError) -> ()
 */
@property (nonatomic, readonly) NSArray<SBMNode *> *nodes;

/**
 SIG Models subscribing to the group.
 
 @see SBMSubscriptionControl.addSubscriptionSettings(group: SBMGroup, successCallback: SBMSubscriptionControlSubscriptionSuccess, errorCallback: SBMSubscriptionControlSubscriptionError) -> ()
 */
@property (nonatomic, readonly) NSArray<SBMSigModel *> *sigModels;

/**
 Vendor Models subscribing to the group.
 
 @see SBMSubscriptionControl.addSubscriptionSettings(group: SBMGroup, successCallback: SBMSubscriptionControlSubscriptionSuccess, errorCallback: SBMSubscriptionControlSubscriptionError) -> ()
 */
@property (nonatomic, readonly) NSArray<SBMVendorModel *> *vendorModels;

/**
 Network that group is contained in.
 */
@property (nonatomic, readonly, weak) SBMNetwork *network;

/**
 Group address.
 */
@property (nonatomic, readonly) SBMAddress *address;

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
