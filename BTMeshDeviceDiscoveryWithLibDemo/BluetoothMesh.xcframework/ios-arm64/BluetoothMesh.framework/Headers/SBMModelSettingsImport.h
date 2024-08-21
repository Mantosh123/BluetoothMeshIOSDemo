//
//  SBMModelSettingsImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMPublishImport.h"
#import "SBMAddressImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Contains publication and subscriptions settings for the Model.
 */
@interface SBMModelSettingsImport : NSObject

/**
 Publish object describing the configuration of the Model's publication.
// */
//@property (nonatomic, readonly, nullable) SBMPublishImport* publish;
//
///**
// Addresses to which the model is subscribed.
// */
@property (nonatomic, readonly) NSArray<SBMAddressImport*>* subscriptions;

///**
// creates and return new Publish object to be imported
// @return created object to be configured
// */
- (SBMPublishImport*)createPublish;
//
/**
 Creates and return new subscribed address.
 */
- (SBMAddressImport*)createSubscriptionWithAddress:(UInt32)address;

///**
// Creates and return new subscribed virtual address.
// */
//- (SBMAddressImport*)createSubscriptionWithVirtualAddress:(NSData*)virtualAddress;

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
