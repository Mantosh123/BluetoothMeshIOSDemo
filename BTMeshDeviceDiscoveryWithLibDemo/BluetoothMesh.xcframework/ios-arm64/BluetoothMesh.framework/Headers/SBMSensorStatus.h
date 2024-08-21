//
//  SBMSensorStatus.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 30/05/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMControlValueGetSensorModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Request to Sensor Server to fetch measurement data states present
 for the all sensors or a given sensor specified by the property ID
 */
@interface SBMSensorStatus : NSObject<SBMControlValueGetSensorModel>

/**
 Measurement data. Structure is defined by Bluetooth SIG Mesh Specification. Please look at 4.1.4 Sensor Data from the Mesh Model Bluetooth®Specification.
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
