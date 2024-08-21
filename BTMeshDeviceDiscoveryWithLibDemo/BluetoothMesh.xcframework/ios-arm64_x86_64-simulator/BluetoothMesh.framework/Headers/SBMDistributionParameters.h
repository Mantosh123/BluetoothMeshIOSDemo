//
//  SBMDistributionParameters.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 24/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMBlobTransferMode.h"
#import "SBMFirmwareUpdatePolicy.h"
#import "SBMGroup.h"
#import "SBMApplicationKey.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Class describing parameters used for ongoing distribution.
 @see SBMFirmwareDistributionStatus
 */
@interface SBMDistributionParameters : NSObject

/**
 Multicast Address used by a Distributor for sending messages to the Target Nodes.
 Group to which firmware should be distributed.
 
 If nil, unicast distribution is in progress.
 */
@property (nonatomic, readonly, strong, nullable) SBMGroup *multicast;

/**
 Application key used to encrypt messages during Firmware Distribution.
 */
@property (nonatomic, readonly, strong) SBMApplicationKey *appKey;

/**
 Packets TTL (time to live) value. Valid values: 0x00, 0x02–0x7F, 0xFF (default network TTL).
 */
@property (nonatomic, readonly) UInt8 ttl;

/**
 Base value used to calculate a firmware image distribution timeout.
 The distribution will be suspended if no messages are received in a given time.
 
 The Distributor propagates the value to its BLOB Client.
 
 For all Client models (including the BLOB Client) the actual timeout value is:
 (10 * (timeoutBase + 2) + (100 * ttl)) seconds
  
 For all Server models (including the BLOB Server) the actual timeout value is:
 (10 * (timeoutBase + 1)) seconds 
 */
@property (nonatomic, readonly) UInt16 timeoutBase;

/**
 Indicates a mode used by a Distributor to transfer a BLOB to Target nodes.
 */
@property (nonatomic, readonly) SBMBlobTransferMode transferMode;

/**
 Firmware update policy.
 The value is used to determine whether the Distributor will automatically trigger the installation of the new firmware image after it is successfully verified. 
 */
@property (nonatomic, readonly) SBMFirmwareUpdatePolicy updatePolicy;

/**
 Firmware's entry index from Firmware Images List of Firmware Distribution Server.
 */
@property (nonatomic, readonly) UInt16 firmwareIndex;

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
