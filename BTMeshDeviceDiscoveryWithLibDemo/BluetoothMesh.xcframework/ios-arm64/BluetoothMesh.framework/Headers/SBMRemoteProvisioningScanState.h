//
//  SBMRemoteProvisioningScanState.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 17/08/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

typedef NS_ENUM(NSUInteger, SBMRemoteProvisioningScanState) {
    /**
     Idle.
     */
    SBMRemoteProvisioningScanStateIdle = 0x00,
    /**
     Remote Provisioning Multiple Devices Scan.
     */
    SBMRemoteProvisioningScanStateMultipleDevicesScan = 0x01,
    /**
     Remote Provisioning Single Device Scan.
     */
    SBMRemoteProvisioningScanStateSingleDeviceScan = 0x02,
    /**
     Reserved for Future Use.
     */
    SBMRemoteProvisioningScanStateUnknown = 0xFF
};
