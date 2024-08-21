//
//  SBMProvisionerOOBDelegate.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 08/04/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Delegate to provide an out-of-band public key or out-of-band authentication data to the Bluetooth device.
 */
@protocol SBMProvisionerOOBDelegate <NSObject>

/**
 Provides an out-of-band device public key of a device to the Bluetooth device. Call this method after the platform has requested an out-of-band public key for a device.

 @param publicKey NSData with the Device public key. Pass nil if the retrieval did not succeed.
 @param uuid NSUUID uuid of the device being provisioned.
 @return error NSError return nil if the data is successfully passed to the provisioning session.
 */
- (nullable NSError *)providePublicKey:(nullable NSData *)publicKey forUuid:(NSUUID *)uuid;

/**
 Provides out-of-band authentication data of a device to the Bluetooth device. Call this method after the platform has requested out-of-band static authentication data or output authentication data. Data is padded with zeros or truncated to match the size required by the used provisioning algorithm.
 
 In cases when:
    - output authentication method is used
    - static authentication method is used and and the authentication data is a number or an alphanumeric string
 `provideNumericAuthData:forUuid` or  `provideAlphanumericAuthData:forUuid` methods can be used to provide authentication data without conversion to bytes.
 
 @see provideNumericAuthData:forUuid
 @see provideAlphanumericAuthData:forUuid
 
 @param authData NSData with the Device authentication data. Pass nil if the retrieval did not succeed.
 @param uuid NSUUID uuid of the device being provisioned.
 @return error NSError return nil if the data is successfully passed to the provisioning session.
 */
- (nullable NSError *)provideAuthData:(nullable NSData *)authData forUuid:(NSUUID *)uuid;

/**
 Convenience method that provides out-of-band numeric authentication data of a device to the Bluetooth device. Call this method after the platform has requested out-of-band static authentication data or output authentication data.
 
 Output authentication data will have numeric type when selected Output Action is one of Numeric, Blink, Beep, Vibrate.
 
 @see provideAuthData:forUuid
 @see provideAlphanumericAuthData:forUuid
 
 @param authNumber NSNumber which represents the Device authentication data. Pass nil if the retrieval did not succeed.
 @param uuid NSUUID uuid of the device being provisioned.
 @return error NSError return nil if the data is successfully passed to the provisioning session.
 */
- (nullable NSError *)provideNumericAuthData:(nullable NSNumber *)authNumber forUuid:(NSUUID *)uuid;

/**
 Convenience method that provides out-of-band alphanumeric authentication data of a device to the Bluetooth device. Call this method after the platform has requested out-of-band static authentication data or output authentication data. Data is padded with zeros or truncated to match the size required by the used provisioning algorithm.
 
 Output authentication data will have alphanumeric type when selected Output Action is Alpha.
 `authString` must consist of uppercase Latin letters and digits.
 
 @see provideAuthData:forUuid
 @see provideNumericAuthData:forUuid
 
 @param authString NSString which represents the Device authentication data. Pass nil if the retrieval did not succeed.
 @param uuid NSUUID uuid of the device being provisioned.
 @return error NSError return nil if the data is successfully passed to the provisioning session.
 */
- (nullable NSError *)provideAlphanumericAuthData:(nullable NSString *)authString forUuid:(NSUUID *)uuid;

@end

NS_ASSUME_NONNULL_END
