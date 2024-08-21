//
//  SBMSubnetSecurity+Private.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 25/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#ifndef SBMSubnetSecurity_Private_h
#define SBMSubnetSecurity_Private_h

#import "SBMSubnetSecurity.h"

@interface SBMSubnetSecurity(Private)

@property (nonatomic, readwrite) UInt8 keyRefreshPhase;
@property (nonatomic, readwrite) long keyRefreshTimestamp;
@property (nonatomic, readwrite) SBMSecurityType minSecurity;

- (void)updateKeyRefreshPhase:(UInt8)phase;

@end

#endif /* SBMSubnetSecurity_Private_h */
