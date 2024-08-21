//
//  SBMSensorCadenceStatus.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 05/07/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMControlValueGetSensorModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Request to Sensor Server to fetch Sensor Cadence state present
 for sensor specified by the property ID
 */
@interface SBMSensorCadenceStatus : NSObject<SBMControlValueGetSensorModel>

/**
 Sensor Cadence state. Structure is defined by Bluetooth SIG Mesh Specification. Please look at 4.2.6 Sensor Cadence Status from the Mesh Model Bluetooth®Specification.
 */
@property (nonatomic, readonly) NSData *status;

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
