//
//  SBMSubnetImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMSubnetSecurityImport.h"
#import "SBMNetKeyImport.h"
#import "SBMNodeImport.h"
#import "SBMAppKeyImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 SBMSubnetImport represents the Subnet which will be imported
 */
@interface SBMSubnetImport : NSObject

/**
 Human-readable Subnet name
 */
@property (nonatomic, readwrite, nullable) NSString *name;

/**
 Subnet's security options
 */
@property (nonatomic, readonly, nullable) SBMSubnetSecurityImport *subnetSecurity;

/**
 Network Key used for this Subnet
 */
@property (nonatomic, readonly) SBMNetKeyImport *netKey;

/////**
// Groups in this network.

@property (nonatomic, readonly) NSArray<SBMAppKeyImport*> *appKeys;

/**
 Creates and adds new group
 @param address address of group. It have to be unique in subnets
 @param appKey application key for group. Could be shared between few groups
 @return returns created object to be configures
 */
- (SBMAppKeyImport*)createAndAddAppkey:(SBMAppKeyImport*)appKey;

/**
 Creates and sets subnet security object
 @param refreshPhase represetns the Key Refresh phase for the subnet. Value could be 0, 1 or 2
 @param refreshTimestamp property contains a UNIX timestamp (seconds since 1/1/1970) the value of the phase property has been updated.
 @return created object
 */
- (SBMSubnetSecurityImport*)createSubnetSecurityWithRefreshPhase:(UInt8)refreshPhase andRefreshTimestamp:(NSInteger)refreshTimestamp;

///**
// Not available. Use SBMNetworkImport addSubnet
// */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMNetworkImport addSubnet
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
