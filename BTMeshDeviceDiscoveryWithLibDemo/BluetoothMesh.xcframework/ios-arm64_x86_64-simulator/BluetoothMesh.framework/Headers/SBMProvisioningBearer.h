//
//  SBMProvisioningBearer.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 27.7.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMDevice.h"
#import "SBMSubnet.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object used to establish connection with the unprovisioned device.
 
 @see SBMProvisioningGATTBearer
 @see SBMProvisioningRemoteBearer
 */
@protocol SBMProvisioningBearer <NSObject>

/**
 Unprovisioned device.
 */
@property (nonatomic, strong, readonly) id<SBMDevice> device;

/**
 Subnet to which the device should be added.
 */
@property (nonatomic, strong, readonly) SBMSubnet *subnet;

/**
 UUID of the unprovisioned device.

 @return UUID of the unprovisioned device.
 */
- (NSUUID *)uuid;

/**
 Name of the unprovisioned device.

 @return Name of the unprovisioned device.
 */
- (NSString *)deviceName;

@end

NS_ASSUME_NONNULL_END

