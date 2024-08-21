//
//  SBMSensorSettingStatus.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 05/07/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMControlValueGetSensorModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Request to Sensor Server to fetch setting state for a given sensor
 */
@interface SBMSensorSettingStatus : NSObject<SBMControlValueGetSensorModel>

/**
 Sensor setting status identifying setting within sensor.
 */
@property (nonatomic, readonly) NSData* status;

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
