//
//  SBMSensorSettingsStatus.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 18.06.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMControlValueGetSensorModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Request to Sensor Server to fetch sensor setting IDs list for a given sensor
 */
@interface SBMSensorSettingsStatus : NSObject<SBMControlValueGetSensorModel>

/**
 List of sensor setting property IDs identifying settings within sensor. Property ID raw value is type of UInt16
 */
@property (nonatomic, readonly, nullable) NSArray<NSNumber *>* sensorSettingPropertyIDs;

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
