//
//  SBMServerConfigurationControl.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 12.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMHeartbeatHandler.h"
#import "SBMServerHeartbeatSubscription.h"
@class SBMElement;
@class SBMIntegerAddress;

NS_ASSUME_NONNULL_BEGIN

/**
 Helper class used for configuring a server (eg setting default Time To Live value)
 */
@interface SBMServerConfigurationControl : NSObject

/**
 Gets default TTL value that is used when sending messages
 
 @return default TTL value
 */
- (UInt8)getTTL;

/**
 Changes the default TTL value that is used when sending messages
 
 The value 0 can only be used when we are communicating directly with proxy node,
 otherwise message will be lost.
 
 Lowering this value may improve network performance during node configuration process, since number of messages in network will be decreased.
 If such change has been made, it is important to restore TTL to higher value after configuration is done to ensure proper operation of network.
 
 @param ttl New ttl value to use as a default. Valid values are 0 and 2..127.
 */
- (BOOL)setTTL:(UInt8)ttl error:(NSError * _Nullable *)error;

/**
 Gets local configuration of Heartbeat Subscription.
 */
- (SBMServerHeartbeatSubscription *)getHeartbeatSubscription;

/**
 Subscribes to Heartbeat messages.
 
 Changes local configuration of the Heartbeat Subscription state. Only one Heartbeat subscription can be active at a time.
 
 @param sourceAddress Heartbeat source address.
 @param destinationAddress Heartbeat destination address (group address).
 @param periodLog Heartbeat subscription period logarithm of 2 value.
 @param heartbeatReceivedHandler  Handler for incoming heartbeat messages.
 */
- (BOOL)setHeartbeatSubscription:(nullable SBMElement *)sourceAddress
              destinationAddress:(nullable SBMIntegerAddress *)destinationAddress
                       periodLog:(UInt8)periodLog
        heartbeatReceivedHandler:(SBMHeartbeatReceivedHandler)heartbeatReceivedHandler
                           error:(NSError **)error __attribute__((swift_error(nonnull_error)));

/**
 Unsubscribes to Heartbeat messages.
 
 Clears local configuration of the Heartbeat Subscription state and removes Heartbeat handler.
 */
- (BOOL)clearHeartbeatSubscription:(NSError **)error __attribute__((swift_error(nonnull_error)));

@end

NS_ASSUME_NONNULL_END

