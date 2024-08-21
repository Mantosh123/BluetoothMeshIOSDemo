//
//  SBMProvisionerOOB.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 12/12/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMProvisionerOOBDelegate.h"
#import "SBMProvisionerOOBResult.h"
#import "SBMBluetoothMeshMacros.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Possible states of OOB EC public key permissions for provisioning.
 */
typedef NS_ENUM(NSUInteger, SBMProvisionerOOBECPublicKeyAllowed) {
    /** OOB EC public key is not allowed for provisioning. */
    SBMProvisionerOOBECPublicKeyAllowedNo = 0,
    /** OOB EC public key is allowed for provisioning. */
    SBMProvisionerOOBECPublicKeyAllowedYes = 1,
};

/**
 Bitmask of allowed authentication methods.
 */
typedef NS_ENUM(NSUInteger, SBMProvisionerOOBAllowedAuthMethods) {
    /** No OOB authentication is allowed. */
    SBMProvisionerOOBAllowedAuthMethodsNoOOB       = 1 << 0,
    /** Static OOB authentication is allowed. */
    SBMProvisionerOOBAllowedAuthMethodsStaticOOB   = 1 << 1,
    /** Output OOB authentication is allowed. */
    SBMProvisionerOOBAllowedAuthMethodsOutputOOB   = 1 << 2,
    /** Input OOB authentication is allowed */
    SBMProvisionerOOBAllowedAuthMethodsInputOOB    = 1 << 3,
};

/**
 Bitmask of allowed output OOB actions.
 */
typedef NS_ENUM(NSUInteger, SBMProvisionerOOBAllowedOutputActions) {
    /** Output a digit by blinking. */
    SBMProvisionerOOBAllowedOutputActionsBlink      = 1 << 0,
    /** Output a digit by beeping. */
    SBMProvisionerOOBAllowedOutputActionsBeep       = 1 << 1,
    /** Output a digit by vibrating. */
    SBMProvisionerOOBAllowedOutputActionsVibrate    = 1 << 2,
    /** Output numeric data on a display. */
    SBMProvisionerOOBAllowedOutputActionsNumeric    = 1 << 3,
    /** Output alphanumeric data on a display. */
    SBMProvisionerOOBAllowedOutputActionsAlpha      = 1 << 4,
};

/**
 Possible types of output OOB action.
 */
typedef NS_ENUM(NSUInteger, SBMProvisionerOOBOutputAction) {
    /** Output a digit by blinking. */
    SBMProvisionerOOBOutputActionBlink = 0,
    /** Output a digit by beeping. */
    SBMProvisionerOOBOutputActionBeep = 1,
    /** Output a digit by vibrating. */
    SBMProvisionerOOBOutputActionVibrate = 2,
    /** Output numeric data on a display. */
    SBMProvisionerOOBOutputActionNumeric = 3,
    /** Output alphanumeric data on a display. */
    SBMProvisionerOOBOutputActionAlpha = 4,
};

/**
 Bitmask of allowed input OOB actions.
 */
typedef NS_ENUM(NSUInteger, SBMProvisionerOOBAllowedInputActions) {
    /** Input a number by pushing a button. */
    SBMProvisionerOOBAllowedInputActionsPush    = 1 << 0,
    /** Input a number by twisting a knob. */
    SBMProvisionerOOBAllowedInputActionsTwist   = 1 << 1,
    /** Input numeric data. */
    SBMProvisionerOOBAllowedInputActionsNumeric = 1 << 2,
    /** Input alphanumeric data. */
    SBMProvisionerOOBAllowedInputActionsAlpha   = 1 << 3,
};

/**
 Possible types of input OOB action.
 */
typedef NS_ENUM(NSUInteger, SBMProvisionerOOBInputAction) {
    /** Input a number by pushing a button. */
    SBMProvisionerOOBInputActionPush = 0,
    /** Input a number by twisting a knob. */
    SBMProvisionerOOBInputActionTwist = 1,
    /** Input numeric data. */
    SBMProvisionerOOBInputActionNumeric = 2,
    /** Input alphanumeric data. */
    SBMProvisionerOOBInputActionAlpha = 3,
};

/**
 Methods declared by SBMProvisionerOOB allow object to setup OOB authentication requirements.
 */
@protocol SBMProvisionerOOB <NSObject>

/**
 Required method that should return value of type SBMProvisionerOOBECPublicKeyAllowed which is then used to determine whether OOB EC public key is allowed or not during OOB provisioning.

 @return Value that specifies whether OOB EC public key is allowed for provisioning.
 */
- (SBMProvisionerOOBECPublicKeyAllowed)ecPublicKeyAllowed;

/**
 Required method that should return value of type SBMProvisionerOOBAllowedAuthMethods which is then used to determine allowed authentication methods during OOB provisioning.

 @return Value that specifies allowed authentication methods.
 */
- (SBMProvisionerOOBAllowedAuthMethods)allowedAuthMethods;

/**
 Required method that should return value of type SBMProvisionerOOBAllowedOutputActions which is then used to determine allowed output actions during OOB provisioning.

 @return Value that specifies allowed output OOB actions.
 */
- (SBMProvisionerOOBAllowedOutputActions)allowedOutputActions;

/**
 Required method that should return value of type SBMProvisionerOOBAllowedInputActions which is then used to determine allowed input actions during OOB provisioning.

 @return Value that specifies allowed input OOB actions.
 */
- (SBMProvisionerOOBAllowedInputActions)allowedInputActions;

/**
 Required method that should return value of type UInt8 which is then used to determine minimum allowed input/output OOB data length during OOB provisioning.

 @return Value that specifies minimum allowed input/output OOB data length. A value of 0 is interpreted as default value of 1 when setting OOB authentication requirements.
 */
- (UInt8)minLengthOfOOBData;

/**
 Required method that should return value of type UInt8 which is then used to determine maximum allowed input/output OOB data length during OOB provisioning.

 @return Value that specifies maximum allowed input/output OOB data length. A value of 0 is interpreted as default value of 8 when setting OOB authentication requirements.
 */
- (UInt8)maxLengthOfOOBData;

/**
 Delegate to provide an out-of-band public key or out-of-band authentication data to the Bluetooth device. This Is set by the SBMBluetoothMesh library, do NOT override it.
*/
@property (nonatomic, weak) id<SBMProvisionerOOBDelegate> delegate;

@optional

/**
 Optional method called when platform requests an out-of-band public key.

 @param uuid UUID of the device which is being provisioned.
 @param algorithm Type of algorithm.
 @param oobPkeyType Type of public key.
 @return Operation result.
 */
- (SBMProvisionerOOBResult)oobPkeyRequest:(NSUUID *)uuid algorithm:(UInt8)algorithm oobPkeyType:(UInt8)oobPkeyType;

/**
 Optional method called when platform requests an out-of-band output authentication data.

 @param uuid UUID of the device which is being provisioned.
 @param outputAction Type of output OOB action.
 @param outputSize The length of the device output data.
 @return Operation result.
 */
- (SBMProvisionerOOBResult)outputRequest:(NSUUID *)uuid outputAction:(SBMProvisionerOOBOutputAction)outputAction outputSize:(UInt8)outputSize;

/**
 Optional method called when platform requests an out-of-band static authentication data.

 @param uuid UUID of the device which is being provisioned.
 @return Operation result.
 */
- (SBMProvisionerOOBResult)authRequest:(NSUUID *)uuid;

/**
 Optional method called when platform requests an out-of-band input authentication data of numeric type.
 
 Authentication data will have numeric type when selected Input Action is one of Numeric, Push, Twist.
 
 @param uuid UUID of the device which is being provisioned.
 @param inputAction Type of input OOB action.
 @param authNumber The authentication number that should be displayed.
 @return Operation result.
 */
- (SBMProvisionerOOBResult)numericInputDisplay:(NSUUID *)uuid
                                   inputAction:(SBMProvisionerOOBInputAction)inputAction
                                    authNumber:(NSNumber *)authNumber;

/**
 Optional method called when platform requests an out-of-band input authentication data of alphanumeric type.
 
 Authentication data will have alphanumeric type when selected Input Action is Alpha.
 
 @param uuid UUID of the device which is being provisioned.
 @param authString The authentication string that should be displayed.
 @return Operation result.
 */
- (SBMProvisionerOOBResult)alphanumericInputDisplay:(NSUUID *)uuid authString:(NSString *)authString;
@end

NS_ASSUME_NONNULL_END
