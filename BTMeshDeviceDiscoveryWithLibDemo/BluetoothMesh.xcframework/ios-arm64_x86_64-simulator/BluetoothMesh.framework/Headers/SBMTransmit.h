//
//  SBMTransmit.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 03/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Base class for SBMNetworkTransmit, SBMRelayRetransmit and SBMRetransmit
 */
@interface SBMTransmit : NSObject

/**
 Number of transmissions or retransmissions.
 */
@property (nonatomic, readonly) NSInteger count;

/**
 Represent the interval in miliseconds between transmissions or retransmissions.
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
