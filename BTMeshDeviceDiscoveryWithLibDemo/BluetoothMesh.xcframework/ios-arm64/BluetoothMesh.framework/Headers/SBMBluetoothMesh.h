//
//  SBMBluetoothMesh.h
//  ble_mesh-lib
//
//  Created by Lukasz Rzepka on 10.04.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMNetwork.h"
#import "SBMBluetoothMeshConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/**
 It is the main object of the Bluetooth Mesh iOS API. 
 */
@interface SBMBluetoothMesh : NSObject

/**
 Object containing informations about the Bluetooth Mesh Network.
 Initialized during the Mesh Stack initialization.
 */
@property (nonatomic, strong, nullable) SBMNetwork *network;

/**
 SBMBluetoothMesh is a singleton object. Before first usage call initialize method with configuration.
 */
+ (SBMBluetoothMesh *)sharedInstance;

/**
 Boolean value that determines whether BluetoothMesh stack was properly initialized.
 */
@property (nonatomic, readwrite) BOOL isInitialized;

/**
 Not available. Use sharedInstance instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use sharedInstance instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize of BluetoothMesh stack.
 It is needed to provide configuration of BluetoothMesh before useage of framework.
 
 @param configuration SBMBluetoothMeshConfiguration.
 @param error Error describing reason of failure.
 
 @return Return YES if success NO if failed
 */
- (BOOL)initialize:(SBMBluetoothMeshConfiguration *)configuration error:(NSError**)error;

/**
 Get initialized mesh configuration.
 
 @return SBMBluetoothMeshConfiguration mesh configuration.
 */
- (nullable SBMBluetoothMeshConfiguration *)configuration;


/**
 Creates SBMNetwork object. It is a main container for Mesh objects.
 
 @discussion Currently it is possible to create more than one Network instance, but it is not recommended, since every Network instance will work on the same database. More information on handling multliple networks can be found in the AN1200 document, in section 10.
 
 @param name Name of Network.
 @param error Error describing reason of failure.
 @return Created network, or nil if network could not be created.
 */
- (nullable SBMNetwork *)createNetworkWith:(NSString *)name error:(NSError **)error;


/**
 Gets from the local mesh stack the amount of sequence numbers before wraparound.
 Checks how many network PDUs can be sent before the sequence number will wrap around. Before the
 wraparound happens, a device must request an IV index update as it is prohibited to use the same
 sequence number and IV index twice.

 @return Amount of sequence number available before wraparound happens.
 @see getSequenceNumber
 @see SBMIvIndexControl.requestUpdate
 */
- (UInt32)getSequenceNumberWrapCount;

/**
 Gets from the local mesh stack current sequence number, a 24-bit value that is used in
 Network PDU when sending messages. Before the sequence number approaches the maximum value
 (0xFFFFFF), the element shall update the IV Index.
 
 @param error Error describing reason of failure.
 @return Current sequence number.
 
 */
- (nullable NSNumber*)sequenceNumberWithError:(NSError **)error;

/**
 Changes a value of the sequence number in the local mesh stack.
 @see sequenceNumberWithError

 @param sequenceNumber New 24-bit value of sequence number (0x000000–0xFFFFFF).
 @param error Error describing reason of failure.
*/
 
- (void)setSequenceNumber:(UInt32)sequenceNumber error:(NSError **)error __attribute__((swift_error(nonnull_error)));

/**
 Clear local Mesh structure.
 Clears the entire local Mesh structure, but any procedure that running isn't finished at the moment when this method is called.
 
 @return error NSError return nil if BluetoothMesh stack was initialized successfully.
 */
- (nullable NSError *)clearDatabase;


//Added for Import

- (nullable NSError *)clearDatabaseForImport;

- (nullable NSError *)reInitialized;

/**
 Returns provisioner's address provided during network initialization.
 @see initializeNetwork
 */
- (SBMIntegerAddress *)provisionerAddress;


/**
 Method used to get existing networks.

 @return Array of existing networks.
 */
- (NSArray<SBMNetwork *> *)networks; //Added BC:

/**
 Initializate Network with specified address and ivIndex.
 
 @param network Network to initialize
 @param address Address to assign for provisioner. 0 means default (0x2001).
 @param ivIndex IV index to initially use in the network.
 @param error Error describing reason of failure.
 */
- (void)initializeNetwork:(SBMNetwork *)network address:(UInt16)address ivIndex:(UInt32)ivIndex error:(NSError**)error __attribute__((swift_error(nonnull_error))); //Added BC:


@end

NS_ASSUME_NONNULL_END
