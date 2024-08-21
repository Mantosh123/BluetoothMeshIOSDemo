//
//  SBMControlValueSetSensorSetupModel.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 10/07/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSensorMessageFlags.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Base functionality protocol. Any functionality that can be used to set Sensor model values should conform to this protocol.
 */
@protocol SBMControlValueSetSensorSetupModel <NSObject>

/**
 Sensor Property ID. 0 is prohibited.
 */
@property (nonatomic) UInt16 sensorPropertyID;

/**
 Message flags used to indicate specific behavior for sensor control messages.
 */
@property (nonatomic) SBMSensorMessageFlags* messageFlags;

@end

NS_ASSUME_NONNULL_END
