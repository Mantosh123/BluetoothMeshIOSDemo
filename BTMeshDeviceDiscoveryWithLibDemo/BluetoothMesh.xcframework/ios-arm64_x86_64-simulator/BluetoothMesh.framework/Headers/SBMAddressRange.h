//
//  SBMAddressRange.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 24/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A range of addresses.
 */
@interface SBMAddressRange : NSObject

/**
 The lowest possible address.
 */
@property (nonatomic, readonly) UInt16 lowAddress;

/**
 The highest possible address.
 */
@property (nonatomic, readonly) UInt16 highAddress;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithLowAddress:(UInt16) lowAddress highAddress:(UInt16)highAddress;
@end

NS_ASSUME_NONNULL_END
