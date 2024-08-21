//
//  SBMFirmwareDistribution.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 10/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareDistributionStart.h"
#import "SBMFirmwareDistributionUploadStart.h"
#import "SBMFirmwareDistributionReceiversGet.h"
#import "SBMFirmwareDistributionSetup.h"
#import "SBMFirmwareDistributionHandler.h"
#import "SBMFirmwareId.h"
#import "SBMReceiverEntry.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Class for handling Firmware Distribution Client.
 */
@interface SBMFirmwareDistribution : NSObject

/**
 Setups communication parameters for the Firmware Distribution Client.
 Calling this method changes behaviour of all SBMFirmwareDistribution objects.
 
 @param setup Object containing parameters for messages sent by the Firmware Distribution Client.
 @param handler Handler for incoming Firmware Distribution messages.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
+ (BOOL)setup:(SBMFirmwareDistributionSetup *)setup handler:(id<SBMFirmwareDistributionHandler>)handler error:(NSError **)error;

/**
 Starts a firmware image distribution on a distributor node. It is an acknowledged message.
 The response is a Firmware Distribution Status message.
 @see SBMFirmwareDistributionHandler.handleDistributionStatus(from: SBMElement, status: SBMFirmwareDistributionStatus)
 
 Firmware Distribution Start message can also resume a suspended distribution.
 @see SBMFirmwareDistribution.suspendDistribution(at: UInt16)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param parameters SBMFirmwareDistributionStart containing information needed to start Firmware Distribution.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)startDistribution:(SBMAddress *)address parameters:(SBMFirmwareDistributionStart *)parameters error:(NSError **)error NS_SWIFT_NAME(startDistribution(at:parameters:));

/**
 Initiates a procedure on a Distributor to apply a firmware image on Target Nodes. It is an acknowledged message.
 The response is a Firmware Distribution Status message.
 @see SBMFirmwareDistributionHandler.handleDistributionStatus(from: SBMElement, status: SBMFirmwareDistributionStatus)
 
 This message shall be sent only if SBMFirmwareDistributionStart.updatePolicy used to start firmware distribution is set to SBMFirmwareUpdatePolicy.verifyOnly.
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)applyDistribution:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(applyDistribution(at:));

/**
 Cancels a firmware image distribution on a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Status message.
 @see SBMFirmwareDistributionHandler.handleDistributionStatus(from: SBMElement, status: SBMFirmwareDistributionStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)cancelDistribution:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(cancelDistribution(at:));

/**
 Suspends a firmware image distribution on a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Status message.
 @see SBMFirmwareDistributionHandler.handleDistributionStatus(from: SBMElement, status: SBMFirmwareDistributionStatus)
 
 To resume a distribution, Firmware Distribution Start should be sent with the same parameters as the suspended distribution.
 @see SBMFirmwareDistribution.startDistribution(at: UInt16, parameters: SBMFirmwareDistributionStart)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)suspendDistribution:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(suspendDistribution(at:));

/**
 Queries a Distributor about its current state of a firmware image distribution. It is an acknowledged message.
 The response is a Firmware Distribution Status message.
 @see SBMFirmwareDistributionHandler.handleDistributionStatus(from: SBMElement, status: SBMFirmwareDistributionStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getDistribution:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(getDistribution(from:));

/**
 Queries a Distributor about its capabilities. It is an acknowledged message.
 The response is a Firmware Distribution Capabilities Status message.
 @see SBMFirmwareDistributionHandler.handleDistributionCapabilitiesStatus(from: SBMElement, status: SBMFirmwareDistributionCapabilitiesStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getCapabilities:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(getCapabilities(from:));

/**
 Starts a firmware image upload to a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Upload Status message.
 @see SBMFirmwareDistributionHandler.handleUploadStatus(from: SBMElement, status: SBMFirmwareDistributionUploadStatus)
 
 The upload requires a usage of a BLOB Transfer Client
 @see SBMBlobTransfer
 
 This call also overwrites a previous transfer setup of a BLOB object and cancels previous upload, if any is pending.
 @see SBMFirmwareDistribution.cancelUpload()
 @see SBMBlobTransfer.setupUnicast(for: [SBMElement], setup: SBMBlobTransferSetup)
 
 Depending on Distributor's capabilities, the firmware size can be too large.
 @see SBMFirmwareDistribution.getCapabilities(from: UInt16)
 
 @param element Element containing the Firmware Distribution Server to which the message should be sent.
 @param parameters SBMFirmwareDistributionUploadStart containing parameters required for Firmware Distribution Upload Start message.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)startUpload:(SBMElement *)element parameters:(SBMFirmwareDistributionUploadStart *)parameters error:(NSError **)error NS_SWIFT_NAME(startUpload(to:parameters:));

/**
 Cancels the ongoing firmware image upload initiated by the local Firmware Distribution Client. It is an acknowledged message.
 The response is a Firmware Distribution Upload Status message.
 @see SBMFirmwareDistributionHandler.handleUploadStatus(from: SBMElement, status: SBMFirmwareDistributionUploadStatus)

 @see SBMFirmwareDistribution.startUpload(to: UInt16, parameters: SBMFirmwareDistributionUploadStart)
 
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)cancelUpload:(NSError **)error;

/**
 Queries a Distributor about the status of a firmware image upload. It is an acknowledged message.
 The response is a Firmware Distribution Upload Status message.
 @see SBMFirmwareDistributionHandler.handleUploadStatus(from: SBMElement, status: SBMFirmwareDistributionUploadStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getUpload:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(getUpload(from:));

/**
 Queries a Distributor whether it stores a firmware image with a given Firmware ID. It is an acknowledged message.
 The response is a Firmware Distribution Firmware Status message.
 @see SBMFirmwareDistributionHandler.handleFirmwareStatus(from: SBMElement, status: SBMFirmwareDistributionFirmwareStatus)
 
 The firmware is present if SBMFirmwareDistributionFirmwareStatus.index field value is other than 0xffff (firmware not found).
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param identifier The Firmware ID to be checked in the Firmware List state of the server.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getFirmware:(SBMAddress *)address identifier:(SBMFirmwareId *)identifier error:(NSError **)error NS_SWIFT_NAME(getFirmware(from:identifier:));

/**
 Queries a Distributor about a Firmware ID stored at an entry with a given index. It is an acknowledged message.
 The response is a Firmware Distribution Firmware Status message.
 @see SBMFirmwareDistributionHandler.handleFirmwareStatus(from: SBMElement, status: SBMFirmwareDistributionFirmwareStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param index The index of the entry in the Firmware Images List state of the Firmware Distribution server.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getFirmware:(SBMAddress *)address index:(UInt16)index error:(NSError **)error NS_SWIFT_NAME(getFirmware(from:index:));

/**
 Deletes a firmware image on a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Firmware Status message.
 @see SBMFirmwareDistributionHandler.handleFirmwareStatus(from: SBMElement, status: SBMFirmwareDistributionFirmwareStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param identifier The Firmware ID of the firmware image to be deleted from the Firmware Images List state of the server.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)deleteFirmware:(SBMAddress *)address identifier:(SBMFirmwareId *)identifier error:(NSError **)error NS_SWIFT_NAME(deleteFirmware(from:identifier:));

/**
 Delete all firmware images stored on a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Firmware Status message.
 @see SBMFirmwareDistributionHandler:handleFirmwareStatus(from: SBMElement, status: SBMFirmwareDistributionFirmwareStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)deleteAllFirmwares:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(deleteAllFirmwares(from:));

/**
 Adds new receiver entries (targets for a Distribute Firmware procedure) to a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Receivers Status message.
 @see SBMFirmwareDistributionHandler.handleReceiversStatus(from: SBMElement, status: SBMFirmwareDistributionReceiversStatus)
 
 The Firmware Distribution Receivers Add message shall contain at least one Receiver Entry.
 For each Receiver Entry field in the message, the value of the Address field (thus node object) shall be unique.
 
 The amount of entries stored by a Firmware Distribution Server is limited by its capabilities.
 @see SBMFirmwareDistribution.getCapabilities(from: UInt16)
 
 @param address Distributor address to which message should be sent.
 @param receiversArray An array containing list of receiver entries.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)addReceivers:(SBMAddress *)address receivers:(NSArray<SBMReceiverEntry *> *)receiversArray error:(NSError **)error NS_SWIFT_NAME(addReceivers(to:receivers:));

/**
 Remove all receiver entries on a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Receivers Status message.
 @see SBMFirmwareDistributionHandler.handleReceiversStatus(from: SBMElement, status: SBMFirmwareDistributionReceiversStatus)
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)deleteAllReceivers:(SBMAddress *)address error:(NSError **)error NS_SWIFT_NAME(deleteAllReceivers(from:));

/**
 Queries a part of the Distribution Receivers List state of a Distributor. It is an acknowledged message.
 The response is a Firmware Distribution Receivers List message.
 @see SBMFirmwareDistributionHandler.handleReceiversList(from: SBMElement, nodes: SBMFirmwareDistributionReceiversList)
 
 The response can contain progresses of all the receivers present on a Distributor.
 
 @param address Address of the Firmware Distribution Server to which message should be sent.
 @param parameters SBMFirmwareDistributionReceiversGet containing firstReceiverIndex and receiverEntriesLimit
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getReceivers:(SBMAddress *)address parameters:(SBMFirmwareDistributionReceiversGet *)parameters error:(NSError **) error NS_SWIFT_NAME(getReceivers(from:parameters:));

@end

NS_ASSUME_NONNULL_END
