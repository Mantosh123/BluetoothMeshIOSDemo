//
//  SBMFirmwareUpdatePolicy.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 15/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
  Describes Firmware Update Policy modes.
 */
typedef NS_ENUM(NSInteger, SBMFirmwareUpdatePolicy)
{
    /**
     The Target Nodes will only verify the received firmware image.
     The firmware distribution process will need to be followed by a Firmware Distribution Apply message.
     */
    SBMFirmwareUpdatePolicyVerifyOnly = 0,
    /**
     The firmware image will be installed immediately after the verification on the Updating Node succeeds.
     When this policy is active, Firmware Distribution Client shall not send Firmware Distribution Apply message.
     */
    SBMFirmwareUpdatePolicyVerifyAndApply = 1,
    /**
     Value not defined.
     */
    SBMFirmwareUpdatePolicyNotDefined
};
