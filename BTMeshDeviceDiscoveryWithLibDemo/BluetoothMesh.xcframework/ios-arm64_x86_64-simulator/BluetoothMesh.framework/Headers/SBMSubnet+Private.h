//
//  SBMSubnet+Private.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 13/11/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSubnet.h"
#import "SBMInSubnetContainedNodes.h"

NS_ASSUME_NONNULL_BEGIN

@interface SBMSubnet(Private) <SBMInSubnetContainedNodes>

@property (nonatomic, readwrite, weak) SBMNetwork* network;

- (instancetype)initWithNetKey:(SBMNetworkKey*)netKey
                     network:(SBMNetwork*)network;

- (void)addNode:(SBMNode*)node;
- (void)removeNode:(SBMNode*)node;
- (void)addAppKey:(SBMApplicationKey *)appKey;
- (NSNumber*)firstAvailableGroupAddress;

- (void)updateKeyRefreshPhase:(UInt8)phase;

@end

NS_ASSUME_NONNULL_END
