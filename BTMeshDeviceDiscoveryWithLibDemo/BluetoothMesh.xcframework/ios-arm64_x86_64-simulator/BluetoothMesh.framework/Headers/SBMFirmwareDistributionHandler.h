//
//  SBMFirmwareDistributionHandler.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMElement.h"
#import "SBMFirmwareDistributionStatus.h"
#import "SBMFirmwareDistributionCapabilitiesStatus.h"
#import "SBMFirmwareDistributionUploadStatus.h"
#import "SBMFirmwareDistributionReceiversStatus.h"
#import "SBMFirmwareDistributionReceiversList.h"
#import "SBMFirmwareDistributionFirmwareStatus.h"
#import "SBMFirmwareDistributionUploadComplete.h"
#import "SBMFirmwareDistributionUploadFailed.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Handler for responses of a Firmware Distribution Server.
 */
@protocol SBMFirmwareDistributionHandler <NSObject>

/**
 Handle for the Firmware Distribution Status message which reports the status of a firmware image distribution.
 
 @param element Element that the status message origins from.
 @param status Received status message of SBMFirmwareDistributionStatus class type.
 */
- (void)handleDistributionStatusFrom:(SBMElement *)element status:(SBMFirmwareDistributionStatus *)status;

/**
 Handle for the Firmware Distribution Capabilities Status message which reports Distributor capabilities.
 
 @param element Element that the status message origins from.
 @param status Received status message of SBMFirmwareDistributionCapabilitiesStatus class type.
 */
- (void)handleDistributionCapabilitiesStatusFrom:(SBMElement *)element status:(SBMFirmwareDistributionCapabilitiesStatus *)status;

/**
 Handle for the Firmware Distribution Upload Status message which reports the status of a firmware image upload.
 
 @param element Element that the status message origins from.
 @param status Received status message of SBMFirmwareDistributionUploadStatus class type.
 */
- (void)handleUploadStatusFrom:(SBMElement *)element status:(SBMFirmwareDistributionUploadStatus *)status;

/**
 Handle for the Firmware Distribution Receivers Status message which reports the current size of the Distribution Receivers List state.
 
 @param element Element that the status message origins from.
 @param status Received status message of SBMFirmwareDistributionReceiversStatus class type.
 */
- (void)handleReceiversStatusFrom:(SBMElement *)element status:(SBMFirmwareDistributionReceiversStatus *)status;

/**
 Handle for the Firmware Distribution Receivers List message which reports the firmware distribution status of each receiver.
 
 @param element Element that the status message origins from.
 @param receiversList Received message of SBMFirmwareDistributionReceiversList class type containing receivers list.
 */
- (void)handleReceiversListFrom:(SBMElement *)element receiversList:(SBMFirmwareDistributionReceiversList *)receiversList;

/**
 Handle for the Firmware Distribution Firmware Status message which reports the status of an operation on a stored firmware image.
 
 @param element Element that the status message origins from.
 @param status Received status message of SBMFirmwareDistributionFirmwareStatus class type.
 */
- (void)handleFirmwareStatusFrom:(SBMElement *)element status:(SBMFirmwareDistributionFirmwareStatus *)status;

/**
 Handle for the Upload Complete event which reports completion of an upload process.
 
 @param element Element that the status message origins from.
 @param complete Received message of SBMFirmwareDistributionUploadComplete class type.
 */
- (void)handleUploadCompleteFrom:(SBMElement *)element complete:(SBMFirmwareDistributionUploadComplete *)complete;

/**
 Handle for the Upload Failed event which reports failure of an upload process.
 
 @param element Element that the status message origins from.
 @param failed Received message of SBMFirmwareDistributionUploadFailed class type.
 */
- (void)handleUploadFailedFrom:(SBMElement *)element failed:(SBMFirmwareDistributionUploadFailed *)failed;

@end

NS_ASSUME_NONNULL_END
