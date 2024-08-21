//
//  SBMLightControlOccupancyModeStatus.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 02/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlResponse.h"
#import "SBMLightControlOccupancyModeType.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a status message received as a response after Occupancy Mode get or set request send to Light Control Server
 (see 6.3.5.2.4 Light LC Mode Status from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlOccupancyModeStatus : NSObject<SBMLightControlResponse>

/**
 The LightControlOccupancyMode value.
 */
@property (nonatomic, readonly) SBMLightControlOccupancyModeType mode;

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
