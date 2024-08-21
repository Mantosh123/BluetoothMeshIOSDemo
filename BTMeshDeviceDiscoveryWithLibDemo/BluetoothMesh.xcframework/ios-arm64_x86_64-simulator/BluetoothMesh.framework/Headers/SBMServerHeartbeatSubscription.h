//
//  SBMServerHeartbeatSubscription.h
//  BluetoothMesh
//
//  Created by Vasyl Haievyi on 28/07/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMIntegerAddress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Mesh heartbeat subscription state.
 */
@interface SBMServerHeartbeatSubscription : NSObject

/**
 Subscription start timestamp.
 */
@property (nonatomic, readonly) UInt64 startTimestamp;

/**
 Heartbeat source address.
 */
@property (nonatomic, readonly) SBMIntegerAddress *sourceAddress;

/**
 Heartbeat destination address.
 */
@property (nonatomic, readonly) SBMIntegerAddress *destinationAddress;

/**
 Observed heartbeat count.
 */
@property (nonatomic, readonly) UInt16 count;

/**
 Heartbeat subscription period log-of-2 value.
 */
@property (nonatomic, readonly) UInt8 periodLog;

/**
 Remaining heartbeat subscription period log-of-2 value.
 */
@property (nonatomic, readonly) UInt8 remainingLog;

/**
 Minimum hops value registered when receiving Heartbeat messages.
 */
@property (nonatomic, readonly) UInt8 hopMinimum;

/**
 Maximum hops value registered when receiving Heartbeat messages.
 */
@property (nonatomic, readonly) UInt8 hopMaximum;

@end

NS_ASSUME_NONNULL_END
