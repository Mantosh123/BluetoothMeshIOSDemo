//
//  SBMRemoteProvisioningSingleDeviceScanStart.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 1.8.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Remote provisioning message used to start the Remote Provisioning Scan procedure, which finds an unprovisioned device with given UUID within the immediate radio range of the Remote Provisioning Server.
 */
@interface SBMRemoteProvisioningSingleDeviceScanStart : NSObject

/**
 UUID of the device to be reported during the Remote Provisioning Scan procedure.
 */
@property (nonatomic, strong) NSUUID *uuid;

/**
 Time limit for a scan in seconds. Can't be 0.
 */
@property (nonatomic) UInt8 scanTimeoutInSeconds;

/**
 Method used to initialize the SBMRemoteProvisioningSingleDeviceScanStart object.
 
 @param uuid Device UUID of unprovisioned device to be reported.
 @param scanTimeoutInSeconds Timeout value to be set.
 */
- (instancetype)initWithUuid:(NSUUID *)uuid scanTimeoutInSeconds:(UInt8)scanTimeoutInSeconds;

/**
 Not available. Use initWithUuid instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithUuid instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
