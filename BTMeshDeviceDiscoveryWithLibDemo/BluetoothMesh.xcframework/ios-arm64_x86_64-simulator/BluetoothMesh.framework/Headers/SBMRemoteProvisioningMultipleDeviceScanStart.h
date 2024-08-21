//
//  SBMRemoteProvisioningMultipleScanStart.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 21.7.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Remote provisioning message used to start the Remote Provisioning Scan procedure, which finds unprovisioned devices within the immediate radio range of the Remote Provisioning Server.
 */
@interface SBMRemoteProvisioningMultipleDeviceScanStart : NSObject

/**
 Identifies the maximum number of unprovisioned devices the Remote Provisioning Server can report.
 
 Value 0 doesn't set the limit.
 */
@property (nonatomic) UInt8 maxNumberOfScanItemsToReport;

/**
 Time limit for a scan in seconds. Can't be 0.
 */
@property (nonatomic) UInt8 scanTimeoutInSeconds;

/**
 Method used to initialize the SBMRemoteProvisioningMultipleScanStart object.
 
 @param maxNumberOfScanItemsToReport Maximum number of devices to be reported.
 @param scanTimeoutInSeconds Timeout value to be set.
 */
- (instancetype)initWithMaxNumberOfScanItemsToReport:(UInt8)maxNumberOfScanItemsToReport
                                scanTimeoutInSeconds:(UInt8)scanTimeoutInSeconds;

/**
 Not available. Use initWithMaxNumberOfScanItemsToReport instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithMaxNumberOfScanItemsToReport instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
