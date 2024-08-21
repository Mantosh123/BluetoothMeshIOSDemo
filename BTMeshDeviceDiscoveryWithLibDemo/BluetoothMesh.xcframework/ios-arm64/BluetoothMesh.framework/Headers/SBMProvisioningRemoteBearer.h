//
//  SBMProvisioningRemoteBearer.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 27.7.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMProvisioningBearer.h"
#import "SBMSubnet.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object used to establish connection with the unprovisioned device using remote provisioning.
 */
@interface SBMProvisioningRemoteBearer: NSObject <SBMProvisioningBearer>

/**
 Element that Remote Provisioning Server model is contained in.
 */
@property (nonatomic, strong, readonly) SBMElement *rpServerElement;

/**
 Initializes SBMProvisioningRemoteBearer object.
 
 @param device Unprovisioned device.
 @param subnet Subnet to which the provisioned device should be added.
 @param rpServerElement Element that Remote Provisioning Server model is contained in.
 
 @return Initialized SBMProvisioningRemoteBearer object.
 */
- (instancetype)initWithdevice:(id<SBMDevice>)device
                        subnet:(SBMSubnet *)subnet
               rpServerElement:(SBMElement *)rpServerElement;

/**
 Not available. Use class methods instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use class methods instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
