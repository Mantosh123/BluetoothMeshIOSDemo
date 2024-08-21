//
//  SBMSensorPropertiesGet.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 30/05/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Properties which are needed for a specific Sensor request.
 */
@interface SBMSensorPropertiesGet : NSObject

@property (nonatomic, readonly, nullable) NSNumber *propertyID;
@property (nonatomic, readonly, nullable) NSNumber *settingPropertyID;
@property (nonatomic, readonly, nullable) NSData *rawValueX;
@property (nonatomic, readonly, nullable) NSData *rawValueX1;
@property (nonatomic, readonly, nullable) NSData *rawValueX2;

/**
 Create properties for SBMSensorDescriptors.
 @param sensorPropertyID Property ID identifying a sensor. Value 0 is used to fetch descriptors for all sensors present at the server element.
 @return Properties for SBMSensorSettingStatus.
 */
+ (SBMSensorPropertiesGet *)descriptorStatus:(UInt16)sensorPropertyID;

/**
 Create properties for SBMSensorStatus.
 @param sensorPropertyID Property ID identifying a sensor. Value 0 is used to fetch values for all sensors present at the server element.
 @return Properties for SBMSensorSettingStatus.
 */
+ (SBMSensorPropertiesGet *)sensorStatus:(UInt16)sensorPropertyID;

/**
 Create properties for SBMSensorCadenceStatus.
 @param sensorPropertyID Property ID identifying a sensor. Value 0 is forbidden.
 @return Properties for SBMSensorSettingStatus.
 */
+ (SBMSensorPropertiesGet *)cadenceStatus:(UInt16)sensorPropertyID;

/**
 Creates properties for SBMSensorSettingStatus.

 @param settingPropertyID Setting ID identifying a setting within a sensor.
 @param sensorPropertyID Property ID identifying a sensor. Value 0 is forbidden.
 @return Properties for SBMSensorSettingStatus.
 */
+ (SBMSensorPropertiesGet *)settingStatus:(UInt16)settingPropertyID sensor:(UInt16)sensorPropertyID;

/**
 Create properties for SBMSensorSettingsStatus.
 @param sensorPropertyID Property ID identifying a sensor. Value 0 is forbidden.
 @return Properties for SBMSensorSettingStatus.
 */
+ (SBMSensorPropertiesGet *)settingsStatus:(UInt16)sensorPropertyID;

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
