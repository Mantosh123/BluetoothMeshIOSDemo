//
//  SBMRetransmit.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 03/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMTransmit.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Properties that describe the number of times a message is published and the interval between retransmissions of the published messages.
 */
@interface SBMRetransmit : SBMTransmit

/**
 Number of retransmissions for published messages. Could be from 0 to 7
 */
@property (nonatomic, readonly) NSInteger count;

/**
 Represents the interval in miliseconds between retransmissions. Could be from 50 to 1600
 */
@property (nonatomic, readonly) NSInteger interval;

@end

NS_ASSUME_NONNULL_END
