//
//  SBMLightControlLightOnOffSet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 10.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlSetRequest.h"
#import "SBMLightControlLightOnOff.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents OnOff set message send to Light Control Server
 (see 6.3.5.3.2 Light LC OM Set from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlLightOnOffSet : NSObject<SBMLightControlSetRequest>

/*
 LightOnOff value to be set
 */
@property (nonatomic) SBMLightControlLightOnOffType lightOnOff;

/**
 The current Transaction Identifier(TID). This value is indicating whether the message
 is a new message or a retransmission of a previously sent message
 (see 6.6.5.4.2 Sending Light LC Light OnOff Set messages from the Mesh Model Bluetooth Specification).
 */
@property (nonatomic) UInt8 transactionId;

/**
 The current Transition Time. This value determines how long an element will take to transition form
 a present state to the target state. The format of this value is as follow:
 2-bits representing a step resolution and 6-bits for number of steps
 (see 3.1.3 Generic Default Transition Time from the Mesh Model Bluetooth Specification).
 This parameter is optional.
 */
@property (nonatomic, nullable) NSNumber* transitionTime;

/**
 Gets the current message execution delay in 5 millisecond steps. Note that this parameter
 won't take effect if TransitionTime is not defined.
 */
@property (nonatomic) UInt32 delay;

/**
 Not available. Use initWithLightOnOff:transactionId: or
 initWithLightOnOff:transactionId:transitionTime:delay: instead.
 */
+ (instancetype)new NS_UNAVAILABLE;
/**
 Not available. Use initWithLightOnOff:transactionId: or
 initWithLightOnOff:transactionId:transitionTime:delay: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFlags:(SBMLightControlMessageFlags *)flags
                   lightOnOff:(SBMLightControlLightOnOffType)lightOnOff
                transactionId:(UInt8)transactionId;

- (instancetype)initWithFlags:(SBMLightControlMessageFlags *)flags
                   lightOnOff:(SBMLightControlLightOnOffType)lightOnOff
                transactionId:(UInt8)transactionId
               transitionTime:(UInt32)transitionTime
                        delay:(UInt32)delay;

@end

NS_ASSUME_NONNULL_END
