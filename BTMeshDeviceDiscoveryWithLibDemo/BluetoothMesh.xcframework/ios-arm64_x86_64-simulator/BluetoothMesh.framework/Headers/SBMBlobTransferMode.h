//
//  SBMBlobTransferMode.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 09/10/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 Transfer Mode used during current BLOB transfer.
 */
typedef NS_ENUM(NSUInteger, SBMBlobTransferMode) {
    /**
     No transfer is active now.
     */
    SBMBlobTransferModeNoActiveTransfer = 0x0,
    /**
     Push Mode (Provisioner-driven transfer).
     */
    SBMBlobTransferModePush = 0x1,
    /**
     Pull Mode (Node-driven transfer).
     */
    SBMBlobTransferModePull = 0x2,
    /**
     Unspecified mode.
     */
    SBMBlobTransferModeNotDefined
};
