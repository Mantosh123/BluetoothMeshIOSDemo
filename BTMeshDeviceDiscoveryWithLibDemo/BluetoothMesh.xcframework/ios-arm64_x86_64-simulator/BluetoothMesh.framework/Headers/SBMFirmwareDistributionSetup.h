//
//  SBMFirmwareDistributionSetup.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 04/06/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMApplicationKey.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Object that represents communication parameters of the local Firmware Distribution Client.
 */
@interface SBMFirmwareDistributionSetup : NSObject

/**
 Application key used to encrypt messages.
 */
@property (readonly, strong) SBMApplicationKey *appKey;

/**
 Packets TTL (time to live) value. Valid values: 0x00, 0x02–0x7F, 0xFF (default network TTL).
 */
@property (readonly) UInt8 ttl;

/**
 Initialisation method for the Firmware Distribution Setup
 
 @param appKey Application key used to communicate with Firmware Distribution Server.
 @param ttl TTL(time to live) for packets sent to Firmware Distribution Server.
 @return Return instance of an object.
 */
- (instancetype)initWithAppKey:(SBMApplicationKey *)appKey ttl:(UInt8)ttl;

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
