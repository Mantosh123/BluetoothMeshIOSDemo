//
//  SBMTimeRole.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 25.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Time Role is an enumeration state that defines the role of a node in propagation of time information in a mesh network.
*/
typedef NS_ENUM(NSUInteger, SBMTimeRole) {
    /**
     The element does not participate in propagation of time information
     */
    SBMTimeRoleNone = 0,
    /**
     The element publishes Time Status messages, but does not process received Time Status messages.
     */
    SBMTimeRoleTimeAuthority,
    /**
     The element processes received and publishes Time Status messages.
     */
    SBMTimeRoleTimeRelay,
    /**
     The element does not publish but processes received Time Status messages
     */
    SBMTimeRoleTimeClient
};

NS_ASSUME_NONNULL_END
