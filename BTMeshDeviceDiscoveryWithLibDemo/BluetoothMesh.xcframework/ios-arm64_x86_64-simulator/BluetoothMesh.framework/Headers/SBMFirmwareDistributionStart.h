//
//  SBMFirmwareDistributionStart.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 10/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMApplicationKey.h"
#import "SBMBlobTransferMode.h"
#import "SBMFirmwareUpdatePolicy.h"
#import "SBMGroup.h"

NS_ASSUME_NONNULL_BEGIN
/**
 It is an acknowledged message sent by the Firmware Distribution Client to the Firmware Distribution Server.
 @see SBMFirmwareDistribution.startDistribution(at: UInt16, parameters: SBMFirmwareDistributionStart)
 
 Message is sent to start a firmware image distribution to Target nodes in the Server's Distribution Receivers List.
 Firmware Distribution Status is a response.
 
 Object of this class should be created with the provided initialisation method.  
 */
@interface SBMFirmwareDistributionStart : NSObject

/**
 Application key used to encrypt messages during Firmware Distribution.
 */
@property (nonatomic, strong, readonly) SBMApplicationKey *appKey;

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
 Multicast Address used by a Distributor for sending messages to the Target Nodes.
 Group to which firmware should be distributed.
 */
@property (nonatomic, strong, readonly, nullable) SBMGroup *multicast;

/**
 Firmware's entry index from Firmware Images List of Firmware Distribution Server.
 Can be acquired with a Firmware Distribution Firmware Get message.
 */
@property (nonatomic, readonly) UInt16 firmwareIndex;

/**
 Initialisation method for the Firmware Distribution Start message with multicast group address distribution.
 
 @param appKey Application key used during Firmware Distribution.
 @param ttl Packets TTL (time to live) during Firmware Distribution.
 @param timeout Value that is used to calculate when firmware image distribution will be suspended.
 @param transferMode Indicates the mode used to transfer the BLOB to the Updating node.
 @param updatePolicy Firmware update policy used for distribution.
 @param groupDestination Group to which firmware should be distributed.
 @param fwIndex Index from Firmware Images List on Distribution Server.
 @return Return instance of an object.
 */
- (instancetype)initWithAppKey:(SBMApplicationKey *)appKey
                           ttl:(UInt8)ttl
                   timeoutBase:(UInt16)timeout
                  transferMode:(SBMBlobTransferMode)transferMode
                  updatePolicy:(SBMFirmwareUpdatePolicy)updatePolicy
                     multicast:(SBMGroup *)groupDestination
                 firmwareIndex:(UInt16)fwIndex;

/**
 Initialisation method for the Firmware Distribution Start message with unicast address distribution.
 
 @param appKey Application key used during Firmware Distribution.
 @param ttl Packets TTL (time to live) during Firmware Distribution.
 @param timeout Value that is used to calculate when firmware image distribution will be suspended.
 @param transferMode Indicates the mode used to transfer the BLOB to the Updating node.
 @param updatePolicy Firmware update policy used for distribution.
 @param fwIndex Index from Firmware Images List on Distribution Server.
 @return Return instance of an object.
 */
- (instancetype)initWithAppKey:(SBMApplicationKey *)appKey
                           ttl:(UInt8)ttl
                   timeoutBase:(UInt16)timeout
                  transferMode:(SBMBlobTransferMode)transferMode
                  updatePolicy:(SBMFirmwareUpdatePolicy)updatePolicy
                 firmwareIndex:(UInt16)fwIndex;

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
