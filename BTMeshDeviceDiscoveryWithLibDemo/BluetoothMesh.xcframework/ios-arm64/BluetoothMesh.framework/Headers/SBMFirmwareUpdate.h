//
//  SBMFirmwareUpdate.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 31/03/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareUpdateHandler.h"
#import "SBMApplicationKey.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Class for controlling the local Firmware Update Client.
 
 For already implemented Standalone Updater,
 @see SBMStandaloneUpdater
 */
@interface SBMFirmwareUpdate : NSObject

/**
 Application key used to encrypt messages.
 */
@property (nonatomic, strong, readonly) SBMApplicationKey *appKey;

/**
 Packets TTL (time to live) value. Valid values: 0x00, 0x02–0x7F, 0xFF (default network TTL).
 */
@property (nonatomic, readonly) UInt8 ttl;

/**
 Initialization method with communication parameters for Firmware Update Client messages.
 
 @param appKey Application key used to encrypt messages sent by the local Firmware Update Client.
 @param ttl Time to live (TTL) value used for messages sent by the local Firmware Update Client.
 @return Return instance of an object.
 */
- (instancetype)initWith:(SBMApplicationKey *)appKey ttl:(UInt8)ttl;

/**
 Setup handler for Firmware Update Server messages.
 
 @param handler Handler for response messages from Firmware Update Servers.
 */
+ (void)setupHandler:(id<SBMFirmwareUpdateHandler>)handler;

/**
 Queries information about the firmware images installed on an Updating node. It is an acknowledged message.
 The response is a Firmware Update Information Status message.
 @see SBMFirmwareUpdateHandler.handleInformationStatus(from: SBMElement, status: SBMFirmwareUpdateInformationStatus)
 
 @param address Address of the Firmware Update Server to which message should be sent.
 @param firstIndex Index of the first requested entry from the Firmware Information List state.
 @param maxEntries Maximum number of entries that will be included in a response.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getInformation:(SBMAddress *)address firstIndex:(UInt8)firstIndex maxEntries:(UInt8)maxEntries error:(NSError **)error NS_SWIFT_NAME(getInformation(from:firstIndex:maxEntries:));

/**
 Verifies whether a node can accept an update signed with a given metadata. It is an acknowledged message.
 The response is a Firmware Metadata Status message.
 @see SBMFirmwareUpdateHandler.handleMetadataStatus(from: SBMElement, status: SBMFirmwareUpdateFirmwareMetadataStatus)
 
 @param address Address of the Firmware Update Server to which message should be sent.
 @param firmwareIndex Index of the firmware in the node's Firmware Information List state to be checked.
 @param metadata Vendor-specific firmware metadata associated with the queried firmware index. (Optional)
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)checkFirmwareMetadata:(SBMAddress *)address firmwareIndex:(UInt8)firmwareIndex metadata:(nullable NSData *)metadata error:(NSError **)error NS_SWIFT_NAME(checkFirmwareMetadata(at:firmwareIndex:metadata:));

@end

NS_ASSUME_NONNULL_END
