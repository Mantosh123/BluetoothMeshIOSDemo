//
//  SBMProvisioningGATTBearer.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 27.7.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMProvisioningBearer.h"
#import "SBMConnectableDevice.h"
#import "SBMSubnet.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object used to establish connection with the unprovisioned device over GATT.
 */
@interface SBMProvisioningGATTBearer: NSObject <SBMProvisioningBearer>

/**
 Unprovisioned device.
 */
@property (nonatomic, strong, readonly) id<SBMConnectableDevice> device;

/**
 Initializes SBMProvisioningGATTBearer object.
 
 @param device Unprovisioned device.
 @param subnet Subnet to which the provisioned device should be added.
 
 @return Initialized SBMProvisioningGATTBearer object.
 */
- (instancetype)initWithDevice:(id<SBMConnectableDevice>)device
                        subnet:(SBMSubnet *)subnet;

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
