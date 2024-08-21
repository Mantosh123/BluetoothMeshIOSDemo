//
//  SBMDevice.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 17.8.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Object representing a device.
 */
@protocol SBMDevice <NSObject>

/**
 Device uuid.

 @return Device uuid.
 */
- (NSUUID *)uuid;

/**
 Device name.

 @return Device name.
 */
- (NSString *)name;

@optional

/**
 OOB Information of the device.

 @return OOB Information of the device.
 */
- (UInt16)oob;

/**
 RSSI value.

 @return RSSI value.
 */
- (NSNumber *)rssi;

/**
 URI Hash of the device.

 @return URI Hash of the device.
 */
- (NSData *)uriHash;

@end

NS_ASSUME_NONNULL_END
