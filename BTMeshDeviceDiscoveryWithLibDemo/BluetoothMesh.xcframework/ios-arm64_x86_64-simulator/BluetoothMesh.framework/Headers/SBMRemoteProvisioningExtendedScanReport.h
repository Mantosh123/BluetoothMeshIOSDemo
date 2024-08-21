//
//  SBMRemoteProvisioningExtendedScanReport.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 24/08/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMOobInformation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message sent by the Remote Provisioning Server to report the advertising data requested by the client in a Remote Provisioning Extended Scan Start message.
 */
@interface SBMRemoteProvisioningExtendedScanReport : NSObject

/**
 Device UUID of either the unprovisioned device or the Remote Provisioning Server.
 */
@property (nonatomic, readonly) NSUUID* uuid;

/**
 OOB Information of either the unprovisioned device or the Remote Provisioning Server.
 */
@property (nonatomic, readonly) SBMOobInformation oobInformation;

/**
 Contains the concatenated list of AD Structures that match the AD Types requested by the client in the ADTypeFilter field. Has the same format as advertising data or scan response data.
 
 The AdvStructures field is an optional field present only when OOBInformation field is also present.
 */
@property (nonatomic, nullable, readonly) NSDictionary<NSNumber *, NSData *> *advStructures;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
