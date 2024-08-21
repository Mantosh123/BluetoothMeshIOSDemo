//
//  SBMFixedGroupAddress.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 04/05/2023.
//  Copyright © 2023 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 Addresses of fixed groups.
*/
typedef NS_ENUM(UInt16, SBMFixedGroupAddress) {
    /** All nodes that have the proxy functionality enabled */
    SBMFixedGroupAddressAllProxies = 0xFFFC,
    /** All nodes that have the friend functionality enabled */
    SBMFixedGroupAddressAllFriends = 0xFFFD,
    /** All nodes that have the relay functionality enabled */
    SBMFixedGroupAddressAllRelays = 0xFFFE,
    /** All nodes in the subnet */
    SBMFixedGroupAddressAllNodes = 0xFFFF
};
