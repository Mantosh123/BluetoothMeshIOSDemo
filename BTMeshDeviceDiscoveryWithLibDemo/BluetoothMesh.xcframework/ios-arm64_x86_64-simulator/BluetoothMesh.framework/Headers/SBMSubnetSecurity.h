//
//  SBMSubnetSecurity.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 25/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMSecurityType.h"
NS_ASSUME_NONNULL_BEGIN


/**
 Properties that define Subnet security
 */
@interface SBMSubnetSecurity : NSObject

/**
 Integer with a value of 0, 1, or 2 that represents the Key Refresh phase for the subnet.
 */
@property (nonatomic, readonly) UInt8 keyRefreshPhase;

/**
The timestamp property contains a UNIX timestamp (seconds since 1/1/1970) the value of the phase property has been updated.
 */
@property (nonatomic, readonly) long keyRefreshTimestamp;

/**
 Minimal security for subnet.
 It has value "high" if all node that knows the NetKey was provisioned with "high" security.
 */
@property (nonatomic, readwrite) SBMSecurityType minSecurity;

@end

NS_ASSUME_NONNULL_END
