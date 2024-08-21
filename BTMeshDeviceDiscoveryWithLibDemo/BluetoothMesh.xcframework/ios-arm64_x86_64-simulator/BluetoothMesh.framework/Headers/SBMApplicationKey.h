//
//  SBMApplicationKey.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 14/09/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class SBMSubnet;
@class SBMNode;
@class SBMSigModel;
@class SBMVendorModel;
@class SBMNetworkKey;

NS_ASSUME_NONNULL_BEGIN

/**
 It is a container for application key. Application key is used to secure and authenticate messages at the access layer.
*/
@interface SBMApplicationKey : NSObject

/**
 Current value of application key data.
 */
@property (nonatomic, readonly) NSData *key;

/**
 Old value of application key data.
 */
@property (nonatomic, readonly, nullable) NSData *oldKey;

/**
 Index of application key.
 */
@property (nonatomic, readonly) NSInteger keyIndex;

/**
 Subnet associated with the application key.
 */
@property (nonatomic, readonly, nullable) SBMSubnet *subnet;

/**
 Nodes that the application key is bound to.
 */
@property (nonatomic, readonly) NSArray<SBMNode *> *nodes;

/**
 SIG Models that the application key is bound to.
 */
@property (nonatomic, readonly) NSArray<SBMSigModel *> *sigModels;

/**
 Vendor Models that the application key is bound to.
 */
@property (nonatomic, readonly) NSArray<SBMVendorModel *> *vendorModels;

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
