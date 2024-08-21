//
//  SBMBlobServerState.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 14/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 Status of a BLOB transfer to a specific BLOB Server.
 */
typedef NS_ENUM(NSUInteger, SBMBlobServerState) {
    /**
     Current procedure is done.
     */
    SBMBlobServerStateProcedureDone = 0,
    /**
     Current procedure is in progress.
     */
    SBMBlobServerStateProcedureInProgress = 1,
    /**
     Transfer has failed.
     */
    SBMBlobServerStateError = 2,
    /**
     Transfer has been completed successfully.
     */
    SBMBlobServerStateSuccess = 3,
    /**
     The server is in an unspecified state.
     */
    SBMBlobServerStateNotDefined
};
