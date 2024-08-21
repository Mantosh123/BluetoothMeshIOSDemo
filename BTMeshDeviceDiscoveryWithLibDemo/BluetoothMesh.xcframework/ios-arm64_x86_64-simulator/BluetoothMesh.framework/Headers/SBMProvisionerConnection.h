//
//  SBMProvisionerConnection.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 11/12/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMProvisioningBearer.h"
#import "SBMConnectableDevice.h"
#import "SBMSubnet.h"
#import "SBMProvisionerOOB.h"
#import "SBMProvisionerParameters.h"
#import "SBMProxyConnection.h"
#import "SBMProvisioningRecordsControl.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object that is used to provision device.
 */
@interface SBMProvisionerConnection : NSObject

/**
 Action invoked on provisioning completion.

 @param provisioner Provisioner connection.
 @param node Provisioned node, or nil if provisioning failed.
 @param error Error describing reason of failure, or nil if provisioning completed successfully. Error's userInfo can contain InnerError which is of type NSError. Inner error's code is an error code from mesh stack.
 */
typedef void (^SBMProvisionerProvisioningCallback)(SBMProvisionerConnection *provisioner, SBMNode * _Nullable node, NSError * _Nullable error);


/**
 Call this closure to continue provisioning after finishing operations related to provisioning records.
 */
typedef void (^SBMProvisioningContinue)(void);

/**
 Call this closure to abort provisioning.
 */
typedef void (^SBMProvisioningAbort)(void);

/**
  Handler for managing provisioning records on provisionee.
  Setting this handler is causing that provisioning will be suspended before send Provisioner Invite PDU to Provisionee.
 
  @param provisioningRecordsControl Object used to fetch items from provisioning records control list
  @param continueProvisioning Callback that should be invoked once operations in the handler are finished
  @param abortProvisioning Callback that should be invoked once operations in the handler are aborted
 */

typedef void (^SBMProvisioningRecordsHandler)(SBMProvisioningRecordsControl* provisioningRecordsControl, SBMProvisioningContinue continueProvisioning, SBMProvisioningAbort abortProvisioning);

/**
 Provisioning bearer with parameters used.
 */
@property (nonatomic, strong, readonly) id<SBMProvisioningBearer> provisioningBearer;

/**
 Out of band provisioner object.
 */
@property (nonatomic, strong, nullable) id<SBMProvisionerOOB> provisionerOOB;

/**
 Handler for managing provisioning records on provisionee.
 */
@property (nonatomic, nullable, readwrite) SBMProvisioningRecordsHandler provisioningRecordsHandler;

/**
 Initialize new provisioner connection object.

 @param provisioningBearer Provisioning bearer with parameters used.
 @return An initialized provisioner connection object, or nil if an object could not be created.
 */
- (instancetype)initWithProvisioningBearer:(id<SBMProvisioningBearer>)provisioningBearer;

/**
 Not available. Use initForDevice instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initForDevice instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Method used to provision device with specified configuration and parameters.
 Provisioned device is added to subnet as a node. Device can be connected to before provisioning.
 
 If provisioning process is performed with configuration, following operations are performed:
 - proxy connection is estabilished; Use proxyConnection property to access object used to manage this connection
 - Device Composition Data is retrieved using [SBMConfigurationControl getDeviceCompositionData:errorCallback]
 - if configuration.proxyEnabled is YES and Device Composition Data indicate that device supports proxy feature, proxy is set using [SBMConfigurationControl setProxy:with:errorCallback:]
 - if configuration.nodeIdentityEnabled is YES, node identity is set using [SBMConfigurationControl setNodeIdentity:enabled:with:errorCallback:]

 @param parameters Parameters of the device to be provisioned. Pass nil to provision without attention timer and specific address.
 @param retryCount Number of times that connecting to device should be retried during provisioning.
 @param callback Action invoked on completed provisioning.
 */
- (void)provisionWithParameters:(SBMProvisionerParameters* _Nullable)parameters
                     retryCount:(NSUInteger)retryCount
                       callback:(SBMProvisionerProvisioningCallback)callback
NS_SWIFT_NAME(provision(withParameters:retryCount:callback:));

/**
 The Mesh Provisioning Service.
 */
+ (NSString*)meshProvisioningServiceUUID;

/**
 The Mesh Provisioning Data In characteristic is used to write data to device during provisioning process,
 */
+ (NSString*)characteristicMeshProvisioningDataInUUID;

/**
 The Mesh Provisioning Data Out characteristic is used to read data from device during provisioning process.
 */
+ (NSString*)characteristicMeshProvisioningDataOutUUID;

@end

NS_ASSUME_NONNULL_END
