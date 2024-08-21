//
//  SBMFirmwareUpdateHandler.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 31/03/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMElement.h"
#import "SBMFirmwareUpdateInformationStatus.h"
#import "SBMFirmwareUpdateFirmwareMetadataStatus.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Handler for responses of a Firmware Update Server.
 */
@protocol SBMFirmwareUpdateHandler <NSObject>

/**
 Handles an incoming Firmware Update Information Status message.

 @param element The element containing the server that sent the status.
 @param status  The information about firmware images installed on a node.
 */
- (void)handleInformationStatusFrom:(SBMElement *)element status:(SBMFirmwareUpdateInformationStatus *)status;

/**
 Handles an incoming Firmware Update Firmware Metadata Status message.

 @param element The element containing the server that sent the status.
 @param status  The firmware metadata check result.
 */
- (void)handleFirmwareMetadataStatusFrom:(SBMElement *)element status:(SBMFirmwareUpdateFirmwareMetadataStatus *)status;

@end

NS_ASSUME_NONNULL_END
