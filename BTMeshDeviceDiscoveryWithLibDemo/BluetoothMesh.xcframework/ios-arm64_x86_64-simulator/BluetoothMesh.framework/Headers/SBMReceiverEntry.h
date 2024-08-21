//
//  SBMReceiverEntry.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 15/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMNode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Receiver Entry consisting of an Updating Node and an index value of its firmware to be updated.
 Object of this class is used in:
 @see SBMFirmwareDistribution.addReceivers(to: UInt16, receivers: [SBMReceiverEntry])
 @see SBMStandaloneUpdater
 
 Object of this class should be created with the provided initialisation method.  
 */
@interface SBMReceiverEntry : NSObject

/**
 The Updating Node. Its address is sent in the Receivers Add message to populate the Distribution Receivers List of a Distributor.
 */
@property (nonatomic, strong, readonly) SBMNode *node;

/**
 The index of a firmware image in the Firmware Information List state of the Updating node to be updated.
 */
@property (nonatomic, readonly) UInt8 firmwareIndex;

/**
 Initialization method for SBMReceiverEntry object.
 
 @param node The Updating Node.
 @param firmwareIndex The index of a firmware image in the Firmware Information List state of the Updating node to be updated.
 @return Return instance of an object.
 */
- (instancetype)initWith:(SBMNode *)node firmwareIndex:(UInt8)firmwareIndex;

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
