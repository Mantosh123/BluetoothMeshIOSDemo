//
//  SBMNodeSecurityImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMSecurityType.h"
#import "SBMNodeAppKeyImport.h"
#import "SBMNodeNetKeyImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Properties that define Node security
 */
@interface SBMNodeSecurityImport : NSObject

/**
 Reflects if the Node is in the process of being deleted and is excluded
 from the new network key distribution during key refresh procedure.
 */
@property (nonatomic, readwrite) BOOL blacklisted;

/**
 Represents the level of security for the subnet on which the node has beed originally provisioned.
 */
@property (nonatomic, readwrite) SBMSecurityType security;

/**
 Represents whether the node is configured to send Secure Network beacons.
 Optional Boolean value.
 */
@property (nonatomic, readwrite, nullable) NSNumber* isSecureNetworkBeacon;

/**
 Application keys known to this node.
 To add new key use method createNodeAppKey
 */
@property (nonatomic, readonly) NSArray<SBMNodeAppKeyImport*>* appKeys;

/**
 Network keys known to this node.
  To add new key use method createNodeNetKey
 */
@property (nonatomic, readonly) NSArray<SBMNodeNetKeyImport*>* netKeys;

/**
 Creates new NodeAppKey with index.
 Updated shall be set to 'false' unless a Key Refresh procedure is in progress
 */
- (SBMNodeAppKeyImport*)createNodeAppKeyWithIndex:(NSInteger)index isUpdated:(BOOL)isUpdated;

/**
 Creates new NodeNetKey with index.
 Updated shall be set to 'false' unless a Key Refresh procedure is in progress
 */
- (SBMNodeNetKeyImport*)createNodeNetKeyWithIndex:(NSInteger)index isUpdated:(BOOL)isUpdated;

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
