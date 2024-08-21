//
//  SBMFirmwareDistributionReceiversGet.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 15/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 Firmware Distribution Receivers Get is an acknowledged message sent by a Firmware Distribution Client to a Firmware Distribution Server.
 @see SBMFirmwareDistribution.addReceivers(to: UInt16, receivers: [SBMReceiverEntry])
 Message is sent to get the current firmware distribution status of the Target Nodes from the Distribution Receivers List state of a Firmware Distribution Server.
 Firmware Distribution Receivers List is a response.
 
 Object of this class should be created with the provided initialisation method. 
 */
@interface SBMFirmwareDistributionReceiversGet : NSObject

/**
 Index of the first requested entry from the Distribution Receivers List state.
 */
@property (nonatomic, readonly) UInt16 firstReceiverIndex;

/**
 Maximum number of list entries to be reported.
 Value of 0 (zero) is prohibited.
 */
@property (nonatomic, readonly) UInt16 receiverEntriesLimit;

/**
 Initialization method for SBMFirmwareDistributionReceiversGet message.
 
 @param firstReceiverIndex Index of the first entry in the Distribution Receivers List state to report.
 @param receiverEntriesLimit Maximum number of list entries to be reported.
 @return Return instance of an object.
 */
- (instancetype)initWithFirstIndex:(UInt16)firstReceiverIndex count:(UInt16)receiverEntriesLimit;

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
