//
//  SBMFirmwareUpdateFirmwareMetadataStatus.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 08/04/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareUpdateStatusCode.h"
#import "SBMFirmwareUpdateAdditionalInformation.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Response sent by a Firmware Update server.
 @see SBMFirmwareUpdate
 @see SBMFirmwareUpdateHandler
 
 Reports whether a Firmware Update Server can accept a firmware update.
 */
@interface SBMFirmwareUpdateFirmwareMetadataStatus : NSObject

/**
 Firmware metadata check status indicating whether the firmware image can be updated.
 */
@property (nonatomic, readonly) SBMFirmwareUpdateStatusCode status;

/**
 The Firmware Update Additional Information state from the Firmware Update Server.
 */
@property (nonatomic, readonly) SBMFirmwareUpdateAdditionalInformation additionalInformation;

/**
 Index of the firmware image in the Firmware Information List state that was checked.
 */
@property (nonatomic, readonly) UInt8 firmwareIndex;

/**
 Not available
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
