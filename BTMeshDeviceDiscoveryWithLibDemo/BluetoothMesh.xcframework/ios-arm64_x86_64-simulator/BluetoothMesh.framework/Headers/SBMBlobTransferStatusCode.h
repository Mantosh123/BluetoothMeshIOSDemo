//
//  SBMBlobTransferStatusCode.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 09/10/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Status codes used by the BLOB Transfer Server and the BLOB Transfer Client models.
 */
typedef NS_ENUM(NSUInteger, SBMBlobTransferStatusCode)
{
    /**
     The message was processed successfully.
     */
    SBMBlobTransferStatusCodeSuccess = 0x0,

    /**
     The Block number is higher than the total number of blocks indicates.
     */
    SBMBlobTransferStatusCodeInvalidBlockNumber = 0x1,

    /**
     The Block Size is outside of the boundaries specified by the Server's Min and Max Block Size Log capabilities.
     */
    SBMBlobTransferStatusCodeInvalidBlockSize = 0x2,

    /**
     The Chunk Size is too large for the Server to accept, or so small that the Block's total chunks number would exceed the Server's Max Chunks capability.
     */
    SBMBlobTransferStatusCodeInvalidChunkSize = 0x3,

    /**
     The Server is in a state where it cannot process the message.
     */
    SBMBlobTransferStatusCodeWrongPhase = 0x4,

    /**
     A parameter in the message is outside of its valid range.
     */
    SBMBlobTransferStatusCodeInvalidParameter = 0x5,

    /**
     The Server is not expecting to receive this Object ID.
     */
    SBMBlobTransferStatusCodeWrongBlobID = 0x6,

    /**
     There is not enough space available in memory to receive the BLOB.
     */
    SBMBlobTransferStatusCodeBlobTooLarge = 0x7,

    /**
     The transfer mode is not supported by the BLOB Transfer Server model.
     */
    SBMBlobTransferStatusCodeUnsupportedTransferMode = 0x8,

    /**
     An internal error occurred on the node
     */
    SBMBlobTransferStatusCodeInternalError = 0x9,

    /**
     The requested information cannot be provided while the server is in the current phase.
     */
    SBMBlobTransferStatusCodeInformationUnavailable = 0xA
};
