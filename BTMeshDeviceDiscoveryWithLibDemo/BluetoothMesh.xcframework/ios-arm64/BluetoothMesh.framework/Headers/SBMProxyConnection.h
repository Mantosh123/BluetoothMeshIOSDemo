//
//  SBMProxyConnection.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 04.12.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMConnectableDevice.h"
#import "SBMSubnet.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object that is used to connect and disconnect to proxy.
 */
@interface SBMProxyConnection : NSObject<NSCopying>

/**
 Callback for successful proxy connection attempt.

 @param device Device for which the proxy connection was established.
 */
typedef void(^SBMProxyConnectionSuccess)(id<SBMConnectableDevice> device);

/**
 Callback for failed proxy connection attempt.

 @param device Device for which the proxy connection failed.
 @param error Error that specifies reason for proxy connection failure.
 */
typedef void(^SBMProxyConnectionError)(id<SBMConnectableDevice> device, NSError *error);

/**
 Callback for successful proxy connection termination attempt.
 
 @param device Device for which the proxy connection was terminated.
 */
typedef void(^SBMProxyDisconnectionSuccess)(id<SBMConnectableDevice> device);

/**
 Callback for failed proxy connection termination attempt.
 
 @param device Device for which the proxy connection termination failed.
 @param error Error that specifies reason for proxy connection termination failure.
 */
typedef void(^SBMProxyDisconnectionError)(id<SBMConnectableDevice> device, NSError *error);

/**
 Device that is used for proxy connection.
 */
@property (nonatomic, readonly) id<SBMConnectableDevice> connectableDevice;

/**
 Boolean value that determines whether proxy connection is established or not.
 */
@property (nonatomic, readonly) BOOL isConnected;

/**
 Initializes new proxy connection object.

 @param connectableDevice Device for which proxy connection object should be created.
 @return An initialized proxy connection object, or nil if an object could not be created.
 */
- (instancetype)initWithConnectableDevice:(id<SBMConnectableDevice>)connectableDevice;

/**
 Not available. Use initWithConnectableDevice instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithConnectableDevice instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Method used to connect to proxy. If device is already connected, calling connect will result in immediate success.

 @param successCallback Action invoked on successful proxy connection attempt.
 @param errorCallback Action invoked when error during proxy connection occurs.
 */
- (void)connectToProxy:(SBMProxyConnectionSuccess)successCallback errorCallback:(SBMProxyConnectionError)errorCallback;

/**
  Replaces an error callback used by the active proxy connection.
  If the connection is not active, the operation won't succeed.
 
  Can be used for objects returned by the library which are already in a connected state. For
  example, during provisioning with configuration, proxy connection with a device is established
  to perform configuration tasks. Since the connection is being established by the library, there
  is no user-supplied callback for proxy connection errors. In that case, when the ownership of
  the proxy connection object is taken by a user, the method can be used to ensure proper handling
  of connection errors.
 
  @param errorCallback Action invoked when error during proxy connection occurs. Overrides errorCallback supplied in connectToProxy:errorCallback: method.
  @return The boolean that informs if the error callback was replaced successfully.
 */
- (BOOL)replaceErrorCallback:(SBMProxyConnectionError)errorCallback;

/**
 Method used to terminate proxy connection. If device is already disconnected, calling disconnect will result in immediate success.
 
 @param successCallback Action invoked on successful proxy disconnection termination attempt.
 @param errorCallback Action invoked when error during proxy disconnection termination attempt occurs.
 */
- (void)disconnect:(SBMProxyDisconnectionSuccess)successCallback errorCallback:(SBMProxyDisconnectionError)errorCallback;

/**
 Action invoked when when a secure network beacon is successfully received
 
 @param netKeyIndex Index of NetworkKey
 @param keyRefresh flag is set if key refresh procedure is used
 @param ivUpdate flag is set if iv index is updated
 @param ivIndex ivIndex value
 */
typedef void(^SBMSecureNetworkBeaconCallback)(NSInteger netKeyIndex, BOOL keyRefresh, BOOL ivUpdate, UInt32 ivIndex);

/**
 Add observer to secure network beacon.
 It's called after successful connection to proxy service and if validation passed.
 Connection to nodes which are not known will not trigger the event
 
 @param callback Method called when secure network beacon received
 */
- (void)observeForSecureNetworkBeacon:(SBMSecureNetworkBeaconCallback)callback;

/**
 The Mesh Proxy Service.
 */
+ (NSString*)meshProxyServiceUUID;

/**
 The Mesh Proxy Data In characteristic is used to write data to proxy device.
 */
+ (NSString*)characteristicMeshProxyDataInUUID;

/**
 The Mesh Proxy Data Out characteristic is used to read data from proxy device.
 */
+ (NSString*)characteristicMeshProxyDataOutUUID;

@end

NS_ASSUME_NONNULL_END
