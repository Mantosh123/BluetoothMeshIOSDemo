//
//  SBMFirmwareUpdateAdditionalInformation.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 25/03/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Additional information for Firmware Update.
 */
typedef NS_ENUM(NSInteger, SBMFirmwareUpdateAdditionalInformation)
{
    /**
     No changes to node composition data.
     */
    SBMFirmwareUpdateAdditionalInformationNone = 0,
    /**
     Node composition data changed. The node does not support remote provisioning.
     */
    SBMFirmwareUpdateAdditionalInformationDcdChangeNoResponse = 1,
    /**
     Node composition data changed, and remote provisioning is supported. The node supports remote provisioning and composition data page 0x80. Page 0x80 contains different composition data than page 0x0.
     */
    SBMFirmwareUpdateAdditionalInformationDcdChangeResponseSupported = 2,
    /**
     Node unprovisioned. The node is unprovisioned after successful application of a verified firmware image.
     */
    SBMFirmwareUpdateAdditionalInformationUnprovisionedAfterUpdate = 3,
    /**
     Value not defined.
     */
    SBMFirmwareUpdateAdditionalInformationNotDefined
};
