//
//  SBMAddressImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Class containing one of three possible types of addresses:
 - unicast address: value property is set, virtualLabel is nil
 - group address: value property is set, virtualLabel is nil
 - virtual address: value is a hash of virtual label, virtualLabel is set to virtual address
 */
@interface SBMAddressImport : NSObject

/**
 Unicast or group address. Is null when virtualLabel
 */
@property (nonatomic, readonly, nullable) NSNumber* value;

/**
 UUID of virtual address. Is null when address is a unicast or group address.
 */
@property (nonatomic, readonly, nullable) NSData* virtualLabel;

/**
 Not available. Use SBMPublishImport or SBMModelSettingsImport createAddress
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMPublishImport or SBMModelSettingsImport createAddress
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
