//
//  SBMSubscriptionControl.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 22/11/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMSigModel.h"
#import "SBMAddress.h"
#import "SBMPublicationSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object used to get/set subscription and publication settings of a model.
 */
@interface SBMSubscriptionControl : NSObject

/**
 Callback for successfull operation on publication settings.

 @param subscriptionControl Subscription control object used for operation.
 @param settings Subscription settings.
 */
typedef void (^SBMSubscriptionControlPublicationSuccess)(SBMSubscriptionControl *subscriptionControl, SBMPublicationSettings * settings);

/**
 Callback for failed operation on publication settings.

 @param subscriptionControl Subscription control object used for operation.
 @param error Error describing reason of failure.
 */
typedef void (^SBMSubscriptionControlPublicationError)(SBMSubscriptionControl *subscriptionControl, NSError * _Nullable error);

/**
 Callback for successfull operation on subscriptions settings.

 @param subscriptionControl Subscription control object used for operation.
 @param address Group address.
 */
typedef void (^SBMSubscriptionControlSubscriptionSuccess)(SBMSubscriptionControl *subscriptionControl, SBMAddress *address);

/**
 Callback for successfull operation on setting subscriptions settings.

 @param subscriptionControl Subscription control object used for operation.
 @param addresses Groups' addresses.
 */
typedef void (^SBMSubscriptionControlSetSubscriptionSuccess)(SBMSubscriptionControl *subscriptionControl, NSSet<SBMAddress *> *addresses);

/**
 Callback for failed operation on subscription settings.

 @param subscriptionControl Subscription control object used for operation.
 @param error Error describing reason of failure.
 */
typedef void (^SBMSubscriptionControlSubscriptionError)(SBMSubscriptionControl *subscriptionControl, NSError * _Nullable error);

/**
 Initialize new subscription control object.

 @param model Model which will be controlled.
 @return Initialized subscription control object, or nil if an object could not be created for some reason that would not result in an exception.
 */
- (instancetype)initWithModel:(SBMSigModel *)model;

/**
 Initialize new subscription control object.
 
 @param model SBMVendorModel which will be controlled.
 @return Initialized subscription control object, or nil if an object could not be created for some reason that would not result in an exception.
 */
- (instancetype)initWithVendorModel:(SBMVendorModel *)model;

/**
 Not available. Use initWithModel instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithModel instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Gets publication settings of a model from a node.

 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)publicationSettings:(SBMSubscriptionControlPublicationSuccess)successCallback
              errorCallback:(SBMSubscriptionControlPublicationError)errorCallback;

/**
 Sets publication settings of a model on a node.

 @param publicationSettings Publication settings to set to a model.
 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)setPublicationSettings:(SBMPublicationSettings *)publicationSettings
               successCallback:(SBMSubscriptionControlPublicationSuccess)successCallback
                 errorCallback:(SBMSubscriptionControlPublicationError)errorCallback;

/**
 Clears publication settings from a model on a node.

 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)clearPublicationSettings:(SBMSubscriptionControlPublicationSuccess)successCallback
                   errorCallback:(SBMSubscriptionControlPublicationError)errorCallback;

/**
 Gets subscriptions settings from a model on a node.

 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)subscriptionSettings:(SBMSubscriptionControlSetSubscriptionSuccess)successCallback
               errorCallback:(SBMSubscriptionControlSubscriptionError)errorCallback;

/**
 Sets (overwrites) subscription to a group on a model.

 @param group Group to be set subscription to.
 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)setSubscriptionSettings:(SBMGroup *)group
                successCallback:(SBMSubscriptionControlSetSubscriptionSuccess)successCallback
                  errorCallback:(SBMSubscriptionControlSubscriptionError)errorCallback;

/**
 Clears subscriptions from a model on a node.

 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)clearSubscriptionSettings:(SBMSubscriptionControlSetSubscriptionSuccess)successCallback
                    errorCallback:(SBMSubscriptionControlSubscriptionError)errorCallback;

/**
 Adds subscription to a group on a model.

 @param group Group subscription to be added to a model.
 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)addSubscriptionSettings:(SBMGroup *)group
                successCallback:(SBMSubscriptionControlSubscriptionSuccess)successCallback
                  errorCallback:(SBMSubscriptionControlSubscriptionError)errorCallback;

/**
 Removes group subscription from a model.

 @param group Group subscription to be removed from a model.
 @param successCallback Action invoked when operation succeeds.
 @param errorCallback Action invoked when operation fails.
 */
- (void)removeSubscriptionSettings:(SBMGroup *)group
                   successCallback:(SBMSubscriptionControlSubscriptionSuccess)successCallback
                     errorCallback:(SBMSubscriptionControlSubscriptionError)errorCallback;

@end

NS_ASSUME_NONNULL_END
