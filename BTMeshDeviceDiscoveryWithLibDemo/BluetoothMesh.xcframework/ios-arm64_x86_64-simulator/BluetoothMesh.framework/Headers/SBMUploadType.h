//
//  SBMUploadType.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 07/10/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 The type of an upload to a node with Firmware Distribution Server.
 */
typedef NS_ENUM(UInt8, SBMUploadType)
{
    /**
     The firmware upload is executed in-band.
     */
    SBMUploadTypeInBand = 0,
    /**
     The firmware upload is executed out-of-band.
     */
    SBMUploadTypeOutOfBand = 1,
    /**
     No upload is in progress.
     */
    SBMUploadTypeNone = 2,
    /**
     Value not defined.
     */
    SBMUploadTypeNotDefined
};
