//
//  SBMRemoteProvisioningScanCapabilitiesStatus.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 22/08/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message sent by the Remote Provisioning Server to report the current value of the Remote Provisioning Scan Capabilities state of a Remote Provisioning Server.
 */
@interface SBMRemoteProvisioningScanCapabilitiesStatus : NSObject

/**
 Identifies the maximum number of UUIDs that can be reported during scanning.
 */
@property (nonatomic, readonly) UInt8 maxScannedItems;

/**
 Indication if active scan is supported.
 */
@property (nonatomic, readonly) BOOL activeScanSupported;

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
