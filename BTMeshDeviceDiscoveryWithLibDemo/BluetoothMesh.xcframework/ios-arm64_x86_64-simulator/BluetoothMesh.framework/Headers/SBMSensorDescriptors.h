//
//  SBMSensorDescriptors.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 28/05/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMControlValueGetSensorModel.h"
#import "SBMDescriptor.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Descriptor Request to Sensor Server to fetch all Sensor Descriptor states present
 for the sensor server or a given sensor specified by the property ID
 */
@interface SBMSensorDescriptors : NSObject<SBMControlValueGetSensorModel>

/**
 Sensor Descriptors list. One if request will be send for sensor specified property ID.
 SBMElement will be updated after receive descriptors. To get descriptors from the local database call sensorsFromSensorServerModel() from the SBMElement.
 SBMDescriptor is part of SBMSensor.
 */
@property (nonatomic, readonly, nullable) NSArray<SBMDescriptor *> *descriptors;

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
