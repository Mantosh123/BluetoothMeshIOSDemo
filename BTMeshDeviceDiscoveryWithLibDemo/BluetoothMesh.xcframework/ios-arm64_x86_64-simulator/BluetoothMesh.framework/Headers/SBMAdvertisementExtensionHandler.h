//
//  SBMAdvertisementExtensionHandler.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 06/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMNode.h"
#import "SBMAdvertisementExtensionTxStatus.h"
#import "SBMAdvertisementExtensionNetworkPduStatus.h"
#import "SBMAdvertisementExtensionModelStatus.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Handler for Advertisement Extension configuration responses.
 @see SBMAdvertisementExtension
 */
@protocol SBMAdvertisementExtensionHandler <NSObject>

/**
 Method for handling Advertisement Extension Configuration Status responses.
 
 @param status Response status.
 @param node Source of the response status.
 */
- (void)handleTxStatus:(SBMAdvertisementExtensionTxStatus *)status from:(SBMNode *)node;

/**
 Method for handling Advertisement Extension Network PDU Status responses.
 
 @param status Response status.
 @param node Source of the response status.
 */
- (void)handleNetworkPduStatus:(SBMAdvertisementExtensionNetworkPduStatus *)status from:(SBMNode *)node;

/**
 Method for handling Advertisement Extension Model Status responses.
 
 @param status Response status.
 @param model Source of the response status.
 */
- (void)handleModelConfigurationStatus:(SBMAdvertisementExtensionModelStatus *)status from:(SBMModel *)model;

@end

NS_ASSUME_NONNULL_END
