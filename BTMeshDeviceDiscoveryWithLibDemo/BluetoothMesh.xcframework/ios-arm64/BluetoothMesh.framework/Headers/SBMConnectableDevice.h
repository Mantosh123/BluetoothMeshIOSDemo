//
//  SBMConnectableDevice.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 04/12/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMDevice.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SBMConnectableDevice;

/**
 Connectable device delegate.
 */
@protocol SBMConnectableDeviceDelegate <NSObject>

/**
 Call this method on device's delegate when device data changes.

 @param data Updated data.
 @param device Object implementing SBMConnectableDevice protocol for which the data changed.
 @param service Service for which the data changed.
 @param characteristic Characteristic for which the data changed.
 */
- (void)didUpdateData:(NSData* _Nullable)data forDevice:(id)device service:(NSData*)service characteristic:(NSData*)characteristic;

/**
 Call this method on device's delegate when connection with device has been interrupted.
 
 @param device Object implementing SBMConnectableDevice protocol with which connection error has occured.
 */
- (void)didEncounterConnectionErrorForDevice:(id<SBMConnectableDevice>)device;

/**
 Call this method on device's delegate when its services have been modified.
 Calling this method is crucial for enabling proper operation of provisioning with configuration
 using one connection process. See `SBMProvisionerConfiguration.useOneGattConnection`.
 
 @param modifiedServices array of UUID string of modified services
 @param device connectable device which services have been modified
 */
- (void)didModifyServices:(NSArray<NSString *> *)modifiedServices forDevice:(id<SBMConnectableDevice>)device;
@end

/**
 Connectable device.
 */
@protocol SBMConnectableDevice <SBMDevice>

/**
 Action invoked when connection or disconnection operation was completed.

 @param device Device for which the connection/disconnection process completed.
 @param success A boolean value that determines whether the request completed with success.
 */
typedef void (^SBMConnectableDeviceConnectionCallback)(id<SBMConnectableDevice> device, BOOL success);

/**
 Action invoked when service check was performed.

 @param device Device for which the check was performed.
 @param service Service data.
 @param hasService A boolean value that determines whether given service is present on a device.
 */
typedef void (^SBMConnectableDeviceHasServiceCallback)(id<SBMConnectableDevice> device, NSData *service, BOOL hasService);

/**
 Action invoked when MTU check was performed.
 @note MTU value is a size of both payload and header.

 @param device Device for which the MTU was received.
 @param service Service data.
 @param characteristic Characteristic data.
 @param mtu Maximum transmission unit.
 */
typedef void (^SBMConnectableDeviceMTUCallback)(id<SBMConnectableDevice> device, NSData *service, NSData *characteristic, NSUInteger mtu);

/**
 Action invoked when requested operation was completed.

 @param device Device for which the operation was performed.
 @param service Service data.
 @param characteristic Characteristic data.
 @param success A boolean value that determines whether operation succeeded.
 */
typedef void (^SBMConnectableDeviceOperationCallback)(id<SBMConnectableDevice> device, NSData *service, NSData *characteristic, BOOL success);

/**
 Device delegate.
 */
@property (nonatomic, weak) id<SBMConnectableDeviceDelegate> delegate;

/**
 Device advertisement data.

 @return Device advertisement data.
 */
- (NSDictionary *)advertisementData;

/**
 A boolean value that determines whether device is connected.

 @return Connected state of the device.
 */
- (BOOL)isConnected;

/**
 Method used to connect to device.

 @param completion Action invoked when device connection succeeded or failed.
 */
- (void)connect:(SBMConnectableDeviceConnectionCallback)completion;

/**
 Method used to disconnect from device.

 @param completion Action invoked when device disconnection succeeded or failed.
 */
- (void)disconnect:(SBMConnectableDeviceConnectionCallback)completion;

/**
 Method used to check whether given service is available on device.

 @param service Service data.
 @param completion Action invoked when check was performed.
 */
- (void)hasService:(NSData *)service completion:(SBMConnectableDeviceHasServiceCallback)completion;

/**
 Method used to check maximum transmission unit for given service and characteristic.
 @note MTU value passed in callback is a size of both payload and header.

 @param serviceUuid Service data.
 @param characteristic Characteristic data.
 @param completion Action invoked when check was performed.
 */
- (void)mtuForService:(NSData *)serviceUuid characteristic:(NSData *)characteristic completion:(SBMConnectableDeviceMTUCallback)completion;

/**
 Method used to write data to given service and characteristic.

 @param data Data to write.
 @param service Service data.
 @param characteristic Characteristic data.
 @param completion Action invoked when write operation was completed.
 */
- (void)writeData:(NSData *)data service:(NSString *)service characteristic:(NSString *)characteristic completion:(SBMConnectableDeviceOperationCallback)completion;

/**
 Method used to subscribe to given service and characteristic.

 @param service Service data.
 @param characteristic Characteristic data.
 @param completion Action invoked when subscription operation was completed.
 */
- (void)subscribeForService:(NSString *)service characteristic:(NSString *)characteristic completion:(SBMConnectableDeviceOperationCallback)completion;

@optional
/**
 Method used to unsubscribe from given characteristic of service.
 This method is mandatory for proper operation of provisioning with configuration using one connection
 process. See `SBMProvisionerConfiguration.useOneGattConnection`
 
 @param service Service data.
 @param characteristic Characteristic data.
 @param completion Action invoked when subscription operation was completed.
 */
- (void)unsubscribeFromService:(NSString*)service characteristic:(NSString*)characteristic completion:(SBMConnectableDeviceOperationCallback)completion;

@end

NS_ASSUME_NONNULL_END
