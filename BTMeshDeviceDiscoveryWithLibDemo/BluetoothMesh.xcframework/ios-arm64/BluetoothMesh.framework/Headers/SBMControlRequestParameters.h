//
//  SBMRequestParameters.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 25/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMBluetoothMeshMacros.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object used to specify parameters used when sending control request.
 */
@interface SBMControlRequestParameters : NSObject

/**
 Transition time in milliseconds, or zero for immediate change request.
 */
@property (nonatomic, readonly) UInt32 transitionTime;

/**
 Delay in milliseconds before the server acts on the request, or zero for immediate action.
 */
@property (nonatomic, readonly) UInt16 delayTime;

/**
 A boolean value that determines whether an explicit response (status message) is required.
 */
@property (nonatomic, readonly) BOOL requestReply;

/**
 Transaction ID for the request.
 */
@property (nonatomic, readonly) UInt8 transactionId;

/**
 Initialize new control request parameters object.

 @attention Do NOT use deprecated method when new one is used. Library is not adapted to use these two constructors alternately during lifetime of application.

 It is intended to use it with set messages to control:
 
 - Generic OnOff,
 
 - Generic Level,
 
 - Generic Delta,
 
 - Generic Move,
 
 - Generic Power Level,
 
 - Light Lightness,
 
 - Light Lightness Linear,
 
 - Light CTL,
 
 - Light CTL Temperature

 @param transitionTime Transition time in milliseconds from one value to other.
 @param delayTime Delay time in milliseconds before the server acts on the request.
 @param requestReply A boolean value that determines whether an explicit response (status message) is required.
 @param transactionId Transaction ID for the request.
 @return An initialized control request parameters object, or nil if an object could not be created.
*/
- (instancetype)initWithTransitionTime:(UInt32)transitionTime delayTime:(UInt16)delayTime requestReply:(BOOL)requestReply transactionId:(UInt8)transactionId;

/**
 Initialize new control request parameters object.
 
 This constructor does NOT use transitionTime, delayTime and transactionId. It is intended to use it with set messages to control:
 
 - Generic Default Transition Time,
 
 - Generic OnPowerUp,
 
 - Generic Power Default,
 
 - Generic Power Range,
 
 - Generic Location Global,
 
 - Generic Location Local,
 
 - Generic User Property,
 
 - Generic Admin Property,
 
 - Generic Manufacturer Property,
 
 - Light Lightness Default,
 
 - Light Lightness Range,
 
 - Light CTL Temperature Range,
 
 - Light CTL Default

 @param requestReply A boolean value that determines whether an explicit response (status message) is required.
 @return An initialized control request parameters object, or nil if an object could not be created.
*/
- (instancetype)initWithRequestReply:(BOOL)requestReply;

/**
 Not available. Use initWithTransitionTime instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithTransitionTime instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
