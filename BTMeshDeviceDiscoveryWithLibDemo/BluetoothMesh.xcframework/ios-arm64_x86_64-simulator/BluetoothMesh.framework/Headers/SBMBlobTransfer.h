//
//  SBMBlobTransfer.h
//  BluetoothMesh
//
//  Created by Vasyl Haievyi on 12/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMElement.h"
#import "SBMBlobTransferSetup.h"
#import "SBMBlobTransferParameters.h"
#import "SBMBlobClientStateInformation.h"
#import "SBMBlobServersCapabilities.h"
#import "SBMBlobServerStatusDetailed.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Response callback for BLOB Transfer
 
 Handles completion of BLOB transfer.
 @param error error that happened during transfer or nil if transfer completed succesfully
 */
typedef void(^SBMStartTransferCallback)(NSError * _Nullable error);

/**
 Callback with concatenated capabilities of all the servers set up for the transfer.
 
 @param capabilities Concatenated capabilities of the servers.
 */
typedef void(^SBMBlobServersCapabilitiesCallback)(SBMBlobServersCapabilities *capabilities);

/**
 Controller for BLOB transfer.

 Except for calling startTransfer, all actions are performed automatically by a State Machine.
 */
@interface SBMBlobTransfer : NSObject

/**
 An interval between resending a message to a BLOB Server, if it isn't responding.
 */
@property (nonatomic, readonly) NSTimeInterval retryInterval;

/**
 Initialization method for SBMBlobTransferInternal object.
 Retry Interval has a default value of 2 seconds.
 
 This object takes use of a handler that is overwritten during the initialization. If overwritten by an another instance, it will cause a malfunction of this object.
 
 @return Return instance of an object.
 */
- (instancetype)init;

/**
 Initialization method for SBMBlobTransferInternal object.
 
 This object takes use of a handler that is overwritten during the initialization. It can also get overwritten which will cause a malfunction of this object.
 
 @param retryInterval An interval between resending a message to a BLOB Server, if it isn't responding. Input 0 to disable.
 @return Return instance of an object.
 */
- (instancetype)initWithRetryInterval:(NSTimeInterval)retryInterval;

/**
 Setups a new transfer of BLOB that can be controlled with an instantiated object of this class.
 The previous setup gets overwritten.
 
 The SIG DFU models (Firmware Update and Firmware Distribution) already setup the BLOB object on their start messages.
 @see SBMFirmwareDistribution.startUpload(to address: UInt16, parameters: SBMFirmwareDistributionUploadStart)
 @see SBMStandaloneUpdater

 @param elements Elements to which the BLOB should be transferred.
 @param setup The setup of a BLOB transfer.
 @param error The return parameter that will be set if initialization failed.
 @return Return YES if setup success, NO if failed.
 */
+ (BOOL)setupUnicastFor:(NSArray<SBMElement *> *)elements
                  setup:(SBMBlobTransferSetup *)setup
                  error:(NSError **)error;

/**
 Setups a new multicast transfer of Blob that can be controlled with instantiated object.
 Previous setup gets overwritten.
 
 SIG DFU models (Firmware Update and Firmware Distribution) already setup the BLOB object on their start messages.
 @see SBMFirmwareDistribution.startUpload(to address: UInt16, parameters: SBMFirmwareDistributionUploadStart)
 @see SBMFirmwareUpdate.startUpdate(to address: UInt16, parameters: SBMFirmwareUpdateStart)

 @param group The multicast address that will be used as messages destination.
 @param elements Elements to which the BLOB should be transferred.
 @param setup The setup of a BLOB transfer. 
 @param error The return parameter that will be set if initialization failed.
 @return Return YES if setup success, NO if failed.
 */
+ (BOOL)setupMulticastFor:(SBMGroup *)group
                 elements:(NSArray<SBMElement *> *)elements
                    setup:(SBMBlobTransferSetup *)setup
                    error:(NSError **)error;

/**
 Starts a new BLOB transfer. Only one transfer should be active at a given time.
 
 The controller handles the whole transaction with its state machine: starts block transfers and sends chunks.
 Transfer uses parameters passed in the argument or sets them automatically if nil is passed.
 
 @param blob BLOB object to be transferred.
 @param parameters Parameters for the BLOB transfer. Pass nil if optimal parameters should be set automatically.
 @param completion Called when transfer has been completed successfully or has failed.
 */
- (void)startTransferWithBlob:(SBMBlob *)blob
                   parameters:(nullable SBMBlobTransferParameters *)parameters
                   completion:(SBMStartTransferCallback)completion
    NS_SWIFT_NAME(startTransfer(with:parameters:completion:));

/**
 Cancels the ongoing transfers by sending BLOB Transfer Cancel message to servers which were set as transfer targets.
 The state machine resends the messages if required.
 
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
*/
- (BOOL)cancelTransfers:(NSError **)error;

/**
 Queries capabilities of BLOB servers set up for a transfer.
 Use to confirm that custom block and chunk size are valid for a transfer. Not required if default values are to be used.
 
 @param completion Called when action has been completed successfully.
 @param error out parameter. Set if failed to send a message.
 @return Return YES if message is sent with success, NO if failed. 
*/
- (BOOL)getServersCapabilities:(SBMBlobServersCapabilitiesCallback)completion error:(NSError **)error;

/**
 Returns current state of the BLOB Client.
 
 @param error out parameter. Set if getting state failed.
 @return Return BlobClientStateInformation or nil if failed.
 */
- (nullable SBMBlobClientStateInformation *)getClientState:(NSError **)error;

/**
 Returns state of the BLOB Servers participating in the current BLOB Transfer.
 
 @param error out parameter. Set if getting state failed.
 @return Return SBMBlobServerStatusDetailed array of nil if failed. 
 */
- (nullable NSArray<SBMBlobServerStatusDetailed *> *)getBlobServerDetails:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
