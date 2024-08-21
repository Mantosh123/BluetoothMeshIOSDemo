//
//  SBMNodeSettingsImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMFeaturesImport.h"
#import "SBMNetworkTransmitImport.h"
#import "SBMRelayRetransmitImport.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Properties that define Node settings
 */
@interface SBMNodeSettingsImport : NSObject

/**
 Represents whether the Mesh Manager finished configuring this node.
 */
@property (nonatomic, readwrite) BOOL configComplete;

/**
 Default Time to live (TTL) value used when sending messages.
 */
@property (nonatomic, readwrite) UInt32 defaultTTL;

/**
 Contains a features object of Node.
 */
@property (nonatomic, readonly) SBMFeaturesImport  *features;

/**
 Network transmit object. Property should be NULL when value is not known.
 When it's know use createNetworkTransmitWithCount:interval:
 */
@property (nonatomic, readonly, nullable) SBMNetworkTransmitImport *networkTransmit;

/**
 Relay transmit object. Property should be NULL when value is not known.
 When it's know use createRelayRetransmitWithCount:interval:
 */
@property (nonatomic, readonly, nullable) SBMRelayRetransmitImport *relayRetransmit;

/**
 Creates and sets networkTransmit with passed arguments
 @param count value which will be set for new created object
 @param interval value which will be set for new created object
 @return returns new created object
 */
- (SBMNetworkTransmitImport*)createNetworkTransmitWithCount:(NSInteger)count interval:(NSInteger)interval;

/**
 Creates and sets relayRetransmit with passed arguments
 @param count value which will be set for new created object
 @param interval value which will be set for new created object
 @return returns new created object
 */
- (SBMRelayRetransmitImport*)createRelayRetransmitWithCount:(NSInteger)count interval:(NSInteger)interval;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
