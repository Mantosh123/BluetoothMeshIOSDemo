//
//  SBMRemoteProvisioningControl.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 21.7.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMNode.h"
#import "SBMSubnet.h"
#import "SBMRemoteProvisioningMultipleDeviceScanStart.h"
#import "SBMRemoteProvisioningSingleDeviceScanStart.h"
#import "SBMRemoteProvisioningExtendedScanStart.h"
#import "SBMRemoteProvisioningScanStatus.h"
#import "SBMRemoteProvisioningExtendedScanReport.h"
#import "SBMRemoteProvisioningScanCapabilitiesStatus.h"
#import "SBMRemoteScannedDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 SBMRemoteProvisioningControl methods are used for executing Remote Provisioning procedures on a remote server.
 */
@interface SBMRemoteProvisioningControl : NSObject

#pragma mark - Callbacks

/**
 Callback for successfull operations:
  - Remote Provisioning Scan Start,
  - Remote Provisioning Scan Stop,
  - Remote Provisioning Scan Get.
 
 @param scanStatus Received Remote Provisioning Scan Status sent by Remote Provisioning Server.
 */
typedef void (^SBMRemoteProvisioningScanRequestSuccess)(SBMRemoteProvisioningScanStatus* scanStatus);

/**
 Callback for successfull Scan Capabilities Get operation.
 
 @param scanStatus Received Scan Capabilities Status sent by Remote Provisioning Server.
 */
typedef void (^SBMRemoteProvisioningScanCapabilitiesRequestSuccess)(SBMRemoteProvisioningScanCapabilitiesStatus* scanStatus);

/**
 Callback for successfull Extended Scan Start operation.
 
 @param extendedScanReport Received Extended Scan Report sent by Remote Provisioning Server.
 */
typedef void (^SBMRemoteProvisioningExtendedScanRequestSuccess)(SBMRemoteProvisioningExtendedScanReport* extendedScanReport);

/**
 Callback for failed operations.
 
 @param error Error describing reason of failure.
 */
typedef void (^SBMRemoteProvisioningScanRequestError)(NSError* error);

/**
 Callback for receiving found devices during the execution of the Remote Provisioning Scan procedure.
 
 @param scannedDevice Received unprovisioned device.
 */
typedef void (^SBMRemoteProvisioningScanReport)(SBMRemoteScannedDevice* scannedDevice);

#pragma mark - Properties

/**
 Element that Remote Provisioning Server model is contained in.
 */
@property (nonatomic, readonly) SBMElement *rpServerElement;

/**
 Subnet to which the provisioned device should be added. Its Network Key is also used to encrypt the messages.
 */
@property (nonatomic, readonly) SBMSubnet *subnet;

#pragma mark - Init

/**
 SBMRemoteProvisioningControl initialization.
 
 @param rpServerElement SBMElement object containing Remote Provisioning Server model.
 @param subnet SBMSubnet object to which the provisioned device should be added. Its Network Key is also used to encrypt the messages.
*/
- (instancetype)initWithRpServerElement:(SBMElement *)rpServerElement
                                 subnet:(SBMSubnet *)subnet;

/**
 Not available. Use initWithRpServerElement instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithRpServerElement instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Starts Remote Provisioning Scan Start procedure with certain number of unrpovisioned devices to be reported.
 
 @param parameters Remote Provisioning Scan Start message to be sent to the Remote Provisioning Server.
 @param successCallback Action invoked on successfull Multiple Device Scan Start operation.
 @param errorCallback Action invoked on failed Multiple Device Scan Start operation.
 */
- (void)startMultipleDeviceScanning:(SBMRemoteProvisioningMultipleDeviceScanStart*)parameters
                    successCallback:(SBMRemoteProvisioningScanRequestSuccess)successCallback
                      errorCallback:(SBMRemoteProvisioningScanRequestError)errorCallback;

/**
 Starts Remote Provisioning Scan Start procedure with only one device with given UUID to be reported.
 
 @param parameters Remote Provisioning Scan Start message to be sent to the Remote Provisioning Server.
 @param successCallback Action invoked on successfull Single Device Scan Start operation.
 @param errorCallback Action invoked on failed Single Device Scan Start operation.
 */
- (void)startSingleDeviceScanning:(SBMRemoteProvisioningSingleDeviceScanStart*)parameters
                  successCallback:(SBMRemoteProvisioningScanRequestSuccess)successCallback
                    errorCallback:(SBMRemoteProvisioningScanRequestError)errorCallback;

/**
 Executes Remote Provisioning Scan Stop procedure.
 
 @param successCallback Action invoked on successfull Scan Stop operation.
 @param errorCallback Action invoked on failed Scan Stop operation.
 */
- (void)stopScanningWith:(SBMRemoteProvisioningScanRequestSuccess)successCallback
           errorCallback:(SBMRemoteProvisioningScanRequestError)errorCallback;

/**
 Executes Remote Provisioning Scan Get procedure, used to get the various scanning states of a Remote Provisioning Server model.
 
 @param successCallback Action invoked on successfull Scan Get operation.
 @param errorCallback Action invoked on failed Scan Get operation.
 */
- (void)getScanningStateWith:(SBMRemoteProvisioningScanRequestSuccess)successCallback
               errorCallback:(SBMRemoteProvisioningScanRequestError)errorCallback;

/**
 Executes Remote Provisioning Scan Capabilities Get procedure, used to get the value of the Remote Provisioning Scan Capabilities state.
 
 @param successCallback Action invoked on successfull Scan Capabilities Get operation.
 @param errorCallback Action invoked on failed Scan Capabilites Get operation.
 */
- (void)getScanCapabilitiesStateWith:(SBMRemoteProvisioningScanCapabilitiesRequestSuccess)successCallback
                       errorCallback:(SBMRemoteProvisioningScanRequestError)errorCallback;

/**
 Starts Remote Provisioning Extended Scan Start procedure, used to request additional information about a specific unprovisioned device or about the Remote Provisioning Server itself.
 
 @param parameters Remote Provisioning Extended Scan Start message to be sent to the Remote Provisioning Server.
 @param successCallback Action invoked on successfull Extended Scan Start operation.
 @param errorCallback Action invoked on failed Extended Scan Start operation.
 */
- (void)startExtendedScanning:(SBMRemoteProvisioningExtendedScanStart*)parameters
              successCallback:(SBMRemoteProvisioningExtendedScanRequestSuccess)successCallback
                errorCallback:(SBMRemoteProvisioningScanRequestError)errorCallback;

/**
 Subscribes for scan reports sent during the Remote Provisioning Scan procedure.
 
 @param callback Method called when scan report was received.
 */
- (void)subscribeForScanResults:(SBMRemoteProvisioningScanReport)callback;

/**
 Unsubscribes from scan reports sent during the Remote Provisioning Scan procedure.
 */
- (void)unsubscribeFromScanResults;

@end

NS_ASSUME_NONNULL_END

