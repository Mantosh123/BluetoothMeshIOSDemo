//
//  SBMSubnetSecurityImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Properties that define Subnet security to be imported
 */
@interface SBMSubnetSecurityImport : NSObject

/**
 Integer with a value of 0, 1, or 2 that represents the Key Refresh phase for the subnet.
 */
@property (nonatomic, readonly) UInt8 keyRefreshPhase;

/**
 The timestamp property contains a UNIX timestamp (seconds since 1/1/1970) the value of the phase property has been updated.
 */
@property (nonatomic, readonly) NSInteger keyRefreshTimestamp;

/**
 Not available. Use SBMSubnetImport createSubnetSecurityWithRefreshPhase:andRefreshTimestamp:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMSubnetImport createSubnetSecurityWithRefreshPhase:andRefreshTimestamp:
 */
- (instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
