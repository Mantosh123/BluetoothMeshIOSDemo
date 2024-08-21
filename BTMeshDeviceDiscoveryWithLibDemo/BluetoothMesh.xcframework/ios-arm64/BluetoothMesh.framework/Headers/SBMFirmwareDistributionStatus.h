//
//  SBMFirmwareDistributionStatus.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMDistributionParameters.h"
#import "SBMFirmwareDistributionPhase.h"
#import "SBMFirmwareDistributionStatusCode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Response sent by a Firmware Distribution server.
 @see SBMFirmwareDistribution
 @see SBMFirmwareDistributionHandler
 
 Reports the current status and parameters of an ongoing distribution.
 */
@interface SBMFirmwareDistributionStatus : NSObject

/**
 Status code of the operation.
 */
@property (nonatomic, readonly) SBMFirmwareDistributionStatusCode status;

/**
 Phase of the firmware image distribution.
 */
@property (nonatomic, readonly) SBMFirmwareDistributionPhase phase;

/**
 Distribution details of an update.
 Present only if distribution is in progress. (Optional)
 */
@property (nonatomic, readonly, strong, nullable) SBMDistributionParameters *distributionParameters;

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
