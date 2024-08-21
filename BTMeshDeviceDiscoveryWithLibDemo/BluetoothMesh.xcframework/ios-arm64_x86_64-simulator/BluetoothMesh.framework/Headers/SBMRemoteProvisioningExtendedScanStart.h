//
//  SBMRemoteProvisioningExtendedScanStart.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 24/08/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Remote provisioning message used to request additional information about a specific unprovisioned device or about the Remote Provisioning Server itself.
 */
@interface SBMRemoteProvisioningExtendedScanStart : NSObject

/**
 Set of AD Types to be reported during the Extended Scan procedure.
 
 The ADTypeFilter shall not contain:
  - Shortened Local Name AD Type,
  - Incomplete List of 16-bit Service UUIDs AD Type,
  - Incomplete List of 32-bit Service UUIDs AD Type,
  - Incomplete List of 128-bit Service UUIDs AD Type.
 
 The ADTypeFilter shall not contain duplicate values.
 */
@property (nonatomic) NSSet<NSNumber *> *adTypeFilter;

/**
 Identifies the Device UUID of the unprovisioned device for which additional information is requested.
 
 If the field is absent, the request retrieves information about the Remote Provisioning Server.
 */
@property (nonatomic, strong, nullable) NSUUID *uuid;

/**
 Indicates how long the Remote Provisioning Client requests the Remote Provisioning Server to collect information about the unprovisioned device identified by the UUID.
 
 Ignored if the UUID field is absent.
 */
@property (nonatomic) UInt8 timeout;

/**
 Method used to initialize the SBMRemoteProvisioningExtendedScanStart object with parameters needed for performing an extended scan of a device with given UUID.
 
 @param adTypeFilter Set of AD Types (can not be empty and contain more than 10 values).
 @param uuid UUID of unprovisioned device for which additional information is requested.
 @param timeout Timeout after which the unprovisioned device information collection stops.
 
 @return Initialized SBMRemoteProvisioningExtendedScanStart object.
 */
- (instancetype)initWith:(NSSet<NSNumber *> *)adTypeFilter
                    uuid:(NSUUID *)uuid
                 timeout:(UInt8)timeout;

/**
 Method used to initialize the SBMRemoteProvisioningExtendedScanStart object with parameters needed for retrieving information about the Remote Provisioning Server.
 
 @param adTypeFilter Set of AD Types (can not be empty and contain more than 10 values).
 
 @return Initialized SBMRemoteProvisioningExtendedScanStart object.
 */
- (instancetype)initWithAdTypeFilter:(NSSet<NSNumber *> *)adTypeFilter;

/**
 Not available. Use initWith initWithAdTypeFilter or instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWith or initWithAdTypeFilter instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
