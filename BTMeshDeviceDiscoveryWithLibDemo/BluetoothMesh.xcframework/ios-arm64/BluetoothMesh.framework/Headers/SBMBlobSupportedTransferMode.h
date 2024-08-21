//
//  SBMBlobSupportedTransferMode.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 15/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents BLOB Supported Transfer mode.
 */
typedef NS_ENUM(NSInteger, SBMBlobSupportedTransferMode)
{
    /**
     Neither of the modes is supported.
     */
    SBMBlobSupportedTransferModeNone = 0,
    /**
     Push Mode (client-driven)
     */
    SBMBlobSupportedTransferModePush = 1,
    /**
     Pull Mode (server-driven)
     */
    SBMBlobSupportedTransferModePull = 2,
    /**
     Both modes are supported
     */
    SBMBlobSupportedTransferModeBoth = 3,
};

