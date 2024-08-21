//
//  SBMSensorSettingSet.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 10/07/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueSetSensorSetupModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Request to Sensor Server to set setting state for a given sensor.
 */
@interface SBMSensorSettingSet : NSObject<SBMControlValueSetSensorSetupModel>

/**
 Sensor Property ID, 16-bit ID referencing a device property.
 */
@property (nonatomic) UInt16 settingPropertyID;

/**
 Sensor setting data identifying setting within sensor.
 */
@property (nonatomic) NSData* settingRaw;

@end

NS_ASSUME_NONNULL_END
