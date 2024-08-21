//
//  SBMHeartbeatHandler.h
//  BluetoothMesh
//
//  Created by Vasyl Haievyi on 28/07/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBMIntegerAddress;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Handler for incoming Heartbeat messages.
 
 Action invoked when heartbeat message is received.
 
 @param sourceAddress Source address of the received heartbeat.
 @param destinationAddress Destination address of the received heartbeat.
 @param hops Number of hops travelled by the heartbeat.
 */
typedef void (^SBMHeartbeatReceivedHandler)(SBMIntegerAddress *sourceAddress, SBMIntegerAddress *destinationAddress, UInt8 hops);

NS_ASSUME_NONNULL_END
