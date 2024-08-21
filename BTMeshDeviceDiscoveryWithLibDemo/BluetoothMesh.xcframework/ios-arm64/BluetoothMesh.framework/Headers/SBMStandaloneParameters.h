//
//  SBMStandaloneParameters.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 16/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Configuration parameters for Standalone Distribution.
 */
@interface SBMStandaloneParameters : NSObject

/**
 Packets TTL (time to live) value. Valid values: 0x00, 0x02–0x7F, 0xFF (default network TTL).
 */
@property (nonatomic, readonly) UInt8 ttl;

/**
 Base value used to calculate an update timeout.
 The update will be suspended if no messages are received in a given time.
 
 The Updater propagates the value to its BLOB Client.
 
 For all Client models (including the BLOB Client) the actual timeout value is:
 (10 * (timeoutBase + 2) + (100 * ttl)) seconds
  
 For all Server models (including the BLOB Server) the actual timeout value is:
 (10 * (timeoutBase + 1)) seconds
 */
@property (nonatomic, readonly) UInt8 timeoutBase;

/**
 The interval in seconds between Standalone Distribution message retransmissions.
 */
@property (nonatomic, readonly) NSTimeInterval retryInterval;

/**
 Initialization method for SBMStandaloneParameters object.

 @param ttl Packets TTL (time to live) during Firmware Update.
 @param timeoutBase Contains the value that is used to calculate when firmware update will be suspended if no messages are received in a given time.
 @param retryInterval The interval in seconds between Standalone Distribution message retransmissions.
 @return Return instance of an object.
 */
- (instancetype)initWithTtl:(UInt8)ttl timeoutBase:(UInt8)timeoutBase retryInterval:(NSTimeInterval)retryInterval;

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
