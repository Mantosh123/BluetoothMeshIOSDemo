//
//  SBMRemoteProvisioningScanStatus.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 20.7.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMRemoteProvisioningScanState.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message sent by Remote Provisioning Server to report the current value of the Remote Provisioning Scan Parameters state
 and the Remote Provisioning Scan state of a Remote Provisioning Server model.
 */
@interface SBMRemoteProvisioningScanStatus : NSObject

/**
 Value of the Remote Provisioning Scan state.
 */
@property (nonatomic, readonly) SBMRemoteProvisioningScanState rpScanningState;

/**
 Maximum number of scanned items to be reported.
 */
@property (nonatomic, readonly) UInt8 scannedItemsLimit;

/**
 Time limit for a scan (in seconds).
 */
@property (nonatomic, readonly) UInt8 timeout;

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
