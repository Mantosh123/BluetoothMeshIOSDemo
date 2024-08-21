//
//  SBMAdvertisementExtension.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 05/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMAdvertisementExtensionHandler.h"
#import "SBMAdvertisementExtensionTxConfiguration.h"
#import "SBMApplicationKey.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Class for managing the Advertisement Extension feature on remote nodes.
 A remote requires Silabs Configuration Server vendor model to be present.
 */
@interface SBMAdvertisementExtension : NSObject

/**
 Application Key used to encrypt messages originating from a given object instance.
 */
@property (nonatomic, strong, readonly) SBMApplicationKey *appKey;

/**
 Initializes a new SBMAdvertisementExtension object instance.
 
 @param appKey Application Key used to encrypt messages originating from this object instance.
 */
- (instancetype)initWith:(SBMApplicationKey *)appKey;

/**
 Setups handler for incoming Advertisement Extension configuration responses.
 The previous handler gets overwritten.
 
 @param handler Handler for incoming Advertisement Extension configuration responses.
 */
+ (void)setupHandler:(id<SBMAdvertisementExtensionHandler>)handler;

/**
 Fetches the Advertisement Extension configuration of the remote node.
 @see setTxConfiguration:node:error: for more info.
 
 The response is received in the setup handler.
 @see SBMAdvertisementExtensionHandler.handleTxStatus
 
 @param node Message destination.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getTxConfiguration:(SBMNode *)node error:(NSError **)error;

/**
 Sets the Advertisement Extension configuration of the remote node.
 Other settings related to the Advertisement Extension feature have use only if SBMAdvertisementExtensionTxPhyLe2M is used.
 
 The response is received in the setup handler.
 @see SBMAdvertisementExtensionHandler.handleTxStatus
 
 @param txConfiguration Configuration to be set.
 @param node Message destination.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)setTxConfiguration:(SBMAdvertisementExtensionTxConfiguration *)txConfiguration
                      node:(SBMNode *)node
                     error:(NSError **)error;

/**
 Sets the maximum Network PDU size of the remote node.
 The custom maximum Network PDU size is used only for models with the setting enabled and for relaying all extended advertisements in the network. The node receives only messages with a Network PDU size lower or equal to the maximum Network PDU size set.
 
 The response is received in the setup handler.
 @see SBMAdvertisementExtensionHandler.handleNetworkPduStatus
 
 @param size Maximum Network PDU size to be set in bytes. Valid range: 29 - 398
 @param node Message destination.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)setNetworkPduMaxSize:(UInt16)size
                        node:(SBMNode *)node
                       error:(NSError **)error;

/**
 Fetches the maximum Network PDU size of the remote node.
 @see setNetworkPduMaxSize:node:error: for more info.
 
 The response is received in the setup handler.
 @see SBMAdvertisementExtensionHandler.handleNetworkPduStatus
 
 @param node Message destination.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)getNetworkPduMaxSize:(SBMNode *)node error:(NSError **)error;

/**
 Enables the Advertisement Extension message transmission on a given model. For the detailed Advertisement Extension configuration,
 @see setTxConfiguration:node:error:
 @see setNetworkPduMaxSize:node:error:
 
 The response is received in the setup handler.
 @see SBMAdvertisementExtensionHandler.handleModelConfigurationStatus
 
 @param model Message destination.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)enableTxOnModel:(SBMModel *)model error:(NSError **)error NS_SWIFT_NAME(enableTx(model:));

/**
 Disables the Advertisement Extension message transmission on a given model.
 
 The response is received in the setup handler.
 @see SBMAdvertisementExtensionHandler.handleModelConfigurationStatus
 
 @param model Message destination.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)disableTxOnModel:(SBMModel *)model error:(NSError **)error NS_SWIFT_NAME(disableTx(model:));

/**
 Fetches the Advertisement Extension message transmission setting on a given model.
 @see enableTxOnModel:error: for more info.
 
 The response is received in the setup handler.
 @see SBMAdvertisementExtensionHandler.handleModelConfigurationStatus
 
 @param model Message destination.
 @param error out parameter. Set if sending message failed.
 @return Return YES if message is sent with success, NO if failed.
 */
- (BOOL)checkTxEnablementOnModel:(SBMModel *)model error:(NSError **)error NS_SWIFT_NAME(checkTxEnablement(model:));

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
