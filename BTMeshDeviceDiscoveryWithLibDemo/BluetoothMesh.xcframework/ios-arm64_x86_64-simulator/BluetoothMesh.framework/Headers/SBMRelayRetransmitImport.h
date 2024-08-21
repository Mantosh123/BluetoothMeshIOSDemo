//
//  SBMRelayRetransmitImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import "SBMTransmitImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents the parameters of retransmissions of network layer messages relayed by a mesh node
 */
@interface SBMRelayRetransmitImport : SBMTransmitImport

/**
 Number of retransmissions. Could be from 1 to 8
 */
@property (nonatomic, readonly) NSInteger count;

/**
 Represents the interval in miliseconds between retransmissions. Could be from 10 to 320
 */
@property (nonatomic, readonly) NSInteger interval;

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
