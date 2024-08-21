//
//  SBMFirmwareDistributionReceiversStatus.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareDistributionStatusCode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Response sent by the Firmware Distribution server.
 @see SBMFirmwareDistribution
 @see SBMFirmwareDistributionHandler
 
 Consists of the current size of the Distribution Receivers List state.
 */
@interface SBMFirmwareDistributionReceiversStatus : NSObject

/**
 Status code of the operation.
 */
@property (nonatomic, readonly) SBMFirmwareDistributionStatusCode status;

/**
 The number of entries present in the Distribution Receivers List state.
 */
@property (nonatomic, readonly) UInt16 receiversCount;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
