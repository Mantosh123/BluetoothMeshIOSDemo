//
//  SBMRelayRetransmit.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 02/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTransmit.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents the parameters of retransmissions of network layer messages relayed by a mesh node
 */
@interface SBMRelayRetransmit : SBMTransmit

/**
 Number of transmissions for relay messages. Could be from 1 to 8
 */
@property (nonatomic, readonly) NSInteger count;

/**
 Represents the interval in miliseconds between transmissions. Could be from 10 to 320
 */
@property (nonatomic, readonly) NSInteger interval;

@end

NS_ASSUME_NONNULL_END
