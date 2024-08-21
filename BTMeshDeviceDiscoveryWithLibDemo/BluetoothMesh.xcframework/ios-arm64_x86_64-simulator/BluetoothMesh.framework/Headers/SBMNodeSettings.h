//
//  SBMNodeSettings.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 02/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMFeatures.h"
#import "SBMNetworkTransmit.h"
#import "SBMRelayRetransmit.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Properties that define Node settings
 */
@interface SBMNodeSettings : NSObject

/**
 Represents whether the Mesh Manager finished configuring this node. Should be set by developer.
 */
@property (nonatomic, readwrite) BOOL isConfigComplete;

/**
 Default Time to live (TTL) value used when sending messages.
 */
@property (nonatomic, readonly) UInt32 defaultTTL;

/**
 Contains a features object of Node.
 */
@property (nonatomic, readonly) SBMFeatures *feature;

/**
 Network transmit object. Property is set to NULL when value is not known.
 */
@property (nonatomic, readonly, nullable) SBMNetworkTransmit *networkTransmit;

/**
 Relay transmit object. Property is set to NULL when value is not known.
 */
@property (nonatomic, readonly, nullable) SBMRelayRetransmit *relayRetransmit;

@end

NS_ASSUME_NONNULL_END
