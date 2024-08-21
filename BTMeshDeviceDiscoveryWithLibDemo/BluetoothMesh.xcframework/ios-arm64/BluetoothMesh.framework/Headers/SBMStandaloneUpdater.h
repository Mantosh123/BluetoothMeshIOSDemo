//
//  SBMStandaloneUpdater.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 16/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMApplicationKey.h"
#import "SBMStandaloneParameters.h"
#import "SBMStandaloneDistributionPhase.h"
#import "SBMGroup.h"
#import "SBMReceiverEntry.h"
#import "SBMStandaloneUpdaterEventHandler.h"
#import "SBMFirmware.h"
#import "SBMBlobTransferMode.h"
#import "SBMStandaloneUpdaterState.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Controller for Standalone Updater role in a Firmware Update.
 Only one object of this class should be active at a given time.
 */
@interface SBMStandaloneUpdater : NSObject

/**
 Application key used to encrypt messages.
 */
@property (nonatomic, strong, readonly) SBMApplicationKey *appKey;

/**
 Configuration parameters for Standalone Distribution.
 */
@property (nonatomic, strong, readonly) SBMStandaloneParameters *parameters;

/**
 Initialization method for SBMStandaloneUpdater object.
 
 @param appKey Application key used to encrypt messages originating from the Firmware Update Client.
 @param parameters Configuration parameters for Standalone Distribution.
 @return Return instance of an object.
 */
- (instancetype)initWith:(SBMApplicationKey *)appKey parameters:(SBMStandaloneParameters *)parameters;

/**
 Initialization method for SBMStandaloneUpdater object with default values of configuration parameters:
 TTL = 0xff , timeoutBase = 0, retryInterval = 2
 @see SBMStandaloneParameters
 
 @param appKey Application key used to encrypt messages originating from the Firmware Update Client.
 @return Return instance of an object.
 */
- (instancetype)initWith:(SBMApplicationKey *)appKey;

/**
 Starts a new mutlicast firmware update.
 BLOB Transfer Push mode is used.
 
 Standalone Updater requires a usage of a BLOB Transfer Client.
 @see SBMBlobTransfer
 @see SBMStandaloneUpdaterEventHandler.handleStateChanged
 
 @param receivers Receiver entries meant for the update.
 @param firmware Firmware to be transferred to nodes.
 @param multicast Group address which Target nodes subscribe to.
 @param handler The handler to be used when a standalone updater change state or failure occurs.
 @param error Error describing reason of failure.
 @return A boolean value indicates if the start multicast update succeeded.
 */
- (BOOL)startMulticastUpdateTo:(NSArray<SBMReceiverEntry *> *)receivers
                      firmware:(SBMFirmware*)firmware
                     multicast:(SBMGroup *)multicast
                       handler:(id<SBMStandaloneUpdaterEventHandler>)handler
                         error:(NSError *__autoreleasing  _Nullable * _Nullable)error;

/**
 Starts a new unicast firmware update.
 
 Standalone Updater requires a usage of a BLOB Transfer Client
 @see SBMBlobTransfer
 @see SBMStandaloneUpdaterEventHandler.handleStateChanged 
 
 @param receivers Receiver entries meant for the update.
 @param firmware Firmware to be transferred to nodes.
 @param mode BLOB Transfer mode used to transfer firmware to nodes.
 @param handler The handler to be used when a standalone updater change state or failure occurs.
 @param error Error describing reason of failure.
 @return A boolean value indicates if the start unicast update succeeded.
 */
- (BOOL)startUnicastUpdateTo:(NSArray<SBMReceiverEntry *> *)receivers
                    firmware:(SBMFirmware*)firmware
                        mode:(SBMBlobTransferMode)mode
                     handler:(id<SBMStandaloneUpdaterEventHandler>)handler
                       error:(NSError *__autoreleasing  _Nullable * _Nullable)error;

/**
 Returns current state of standalone updater and its updating node entries.
  
 @param error Error describing reason of failure.
 @return An object with information about current state of the firmware update.
 */
- (nullable SBMStandaloneUpdaterState *)getUpdateState:(NSError *__autoreleasing  _Nullable * _Nullable)error;

/**
 Stops a firmware update and deletes any stored information.
 
 @param error Error describing reason of failure.
 @return A boolean value indicates if the cancel update succeeded.
 */
- (BOOL)cancelUpdate:(NSError *__autoreleasing  _Nullable * _Nullable)error;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available. 
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
