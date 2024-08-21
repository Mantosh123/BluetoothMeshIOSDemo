//
//  SBMLightControlLightOnOffStatus.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 30/08/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlResponse.h"
#import "SBMLightControlLightOnOff.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Light Control Server status message received as a response to get or set request
 (see 6.3.5.3.4 Light LC Light OnOff Status from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlLightOnOffStatus : NSObject<SBMLightControlResponse>

/*
Present value of the LightControlLightOnOff state.
*/
@property (nonatomic, readonly) SBMLightControlLightOnOffType presentLightOnOff;

/*
 Target value of the LightControlLightOnOff state of type SBMLightControlLightOnOffType. This value is optional.
 */

@property (nonatomic, readonly, nullable) NSNumber* targetLightOnOff;

/*
 The time remaining to complete the transition. The format of this value is as follow:
 2-bits representing a step resolution and 6-bits for number of steps
 (see 3.1.3 Generic Default Transition Time from the Mesh Model Bluetooth Specification).
 This value won't be present unless the Target value is specified.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

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
