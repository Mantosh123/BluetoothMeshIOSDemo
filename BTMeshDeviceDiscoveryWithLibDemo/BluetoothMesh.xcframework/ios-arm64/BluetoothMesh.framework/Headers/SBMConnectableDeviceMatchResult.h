//
//  SBMConnectableDeviceMatchResult.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 12/06/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Enum describing possible match results.
 */
typedef NS_ENUM (NSUInteger, SBMMatchResult) {
    /** Advertising data does not match requested network ID or node identity */
    SBMMatchResultNoMatch = 0,
    /** Advertising data matches requested network ID */
    SBMMatchResultNetworkMatch = 1,
    /** Advertising data matches requested node identity */
    SBMMatchResultIdentityMatch = 2
};

/**
 Object that contains results of network match.
 */
@interface SBMConnectableDeviceMatchResult : NSObject

/**
 Network key index of matching key.
 */
@property (nonatomic, readonly) NSUInteger networkIndex;

/**
 Result of network match.
 */
@property (nonatomic, readonly) SBMMatchResult matchResult;

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
