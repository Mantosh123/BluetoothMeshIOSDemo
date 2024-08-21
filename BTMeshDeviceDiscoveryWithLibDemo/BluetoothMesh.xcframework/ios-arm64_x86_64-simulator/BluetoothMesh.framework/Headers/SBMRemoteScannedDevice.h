//
//  SBMRemoteScannedDevice.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 25.7.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object representing an uprovisioned device containing the information acquired during the remote scanning process.
 */
@interface SBMRemoteScannedDevice: NSObject <SBMDevice>

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

