//
//  SBMBluetoothMeshConfigurationLimits.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 15/03/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Object specifying configuration limits.
 */
@interface SBMBluetoothMeshConfigurationLimits : NSObject

/**
 Maximum number of network keys.
 Maximum supported value is 7.
 Default value is 4.
 */
@property (nonatomic, readwrite) UInt8 netKeys;

/**
 Maximum number of application keys that can be created.
 Maximum supported value is 8.
 Default value is 8.
 */
@property (nonatomic, readwrite) UInt8 appKeys;

/**
 Maximum number of provisioned nodes.
 Maximum supported value is 32766.
 Default value is 255.
 The value in this field is affecting the default value of rplSize.
 */
@property (nonatomic, readwrite) UInt16 nodes;

/**
 Maximum number of a node's network keys that can be stored by the provisioner.
 Maximum supported value is 7.
 Default value is 4.
 */
@property (nonatomic, readwrite) UInt8 nodeNetworks;

/**
 Maximum number of a node's application keys that can be stored by the provisioner.
 Maximum supported value is 32.
 Default value is 4.
 */
@property (nonatomic, readwrite) UInt8 nodeAppKeys;

/**
 Size of replay protection list. It specifies maximum number of nodes that can be communicated with.
 Maximum supported value is 32767.
 Default value is 4 * limit of nodes.
 */
@property (nonatomic, readwrite) UInt16 rplSize;

/**
 Maximum number of concurrent segmented messages being received.
 Default value is 4.
 */
@property (nonatomic, readwrite) UInt8 segmentedMessagesReceived;

/**
 Maximum number of concurrent segmented messages being sent.
 Default value is 4.
 */
@property (nonatomic, readwrite) UInt8 segmentedMessagesSent;

/**
 Maximum number of parallel provisioning sessions.
 Maximum supported value is 3.
 Default value is 1.
 */
@property (nonatomic, readwrite) UInt8 provisionSessions;

/**
 Maximum number of concurrent GATT connections (required for each proxy or provision session).
 Maximum supported value is 3.
 Default value is 3.
 GattConnections shall be >= ProvisionSessions.
 Each provisioning or proxy session requires a gatt connection. (Provisioning sessions + proxy sessions <= gatt connections limit)
 There is no separate property to set the proxy connections limit. The provision connections limit has additional limit defined in the provisionSessions property.
 */
@property (nonatomic, readwrite) UInt8 gattConnections;

/**
 Number of BLOB servers that can be handled during a BLOB transfer.
 Maximum supported value is 65535.
 Default value is 64.
 */
@property (nonatomic, readwrite) UInt16 blobServers;

/**
 Maximum number of virtual addresses on the node.
 Maximum supported value is 65535.
 Default value is 4.
 */

@property (nonatomic, readwrite) UInt16 virtualAddresses;

@end

NS_ASSUME_NONNULL_END
