//
//  SBMFirmwareDistributionUploadStart.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 01/03/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmware.h"

NS_ASSUME_NONNULL_BEGIN
/**
 It is an acknowledged message sent by the Firmware Distribution Client to the Firmware Distribution Server.
 @see SBMFirmwareDistribution.startUpload(to: UInt16, parameters: SBMFirmwareDistributionUploadStart)
 Message is sent to start a firmware image upload to a Distributor node using BLOB Transfer process.
 Firmware Distribution Upload Status is a response.
 
 Object of this class should be created with the provided initialisation method.  
 */
@interface SBMFirmwareDistributionUploadStart : NSObject

/**
 Packets TTL (time to live) value. Valid values: 0x00, 0x02–0x7F, 0xFF (default network TTL).
 */
@property (nonatomic, readonly) UInt8 ttl;

/**
 Base value used to calculate a firmware image upload timeout.
 The upload will be suspended if no messages are received in a given time.
 
 The Initiator propagates the value to its BLOB Client.
 
 For all Client models (including the BLOB Client) the actual timeout value is:
 (10 * (timeoutBase + 2) + (100 * ttl)) seconds
  
 For all Server models (including the BLOB Server) the actual timeout value is:
 (10 * (timeoutBase + 1)) seconds
 */
@property (nonatomic, readonly) UInt16 timeoutBase;

/**
 Object that represents the firmware image.
 */
@property (nonatomic, readonly) SBMFirmware *firmware;

/**
 Initialisation method for the Firmware Distribution Upload Start object.
 
 @param ttl Packets TTL (time to live) during Firmware Upload.
 @param timeoutBase Value that is used to calculate when firmware image upload will be suspended.
 @param firmware Object that represents the firmware image.
 @return Return instance of an object.
 */
- (instancetype)initWithTtl:(UInt8)ttl
                timeoutBase:(UInt16)timeoutBase
                   firmware:(SBMFirmware*)firmware;

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
