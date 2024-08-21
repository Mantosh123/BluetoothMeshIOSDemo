//
//  SBMBlobClientState.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 22/04/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 BLOB Client State.
 */
typedef NS_ENUM(NSUInteger, SBMBlobClientState) {
    /**
     No transfer has been setup.
     */
    SBMBlobClientStateInactive,
    /**
     State Machine initial state.
     */
    SBMBlobClientStateStart,
    /**
     The client is querying the servers with an Information Get message.
     */
    SBMBlobClientStateCollectInfo,
    /**
     Information Get procedure has benn completed.
     */
    SBMBlobClientStateCollectInfoDone,
    /**
     The client is notifying the servers with a Transfer Start message.
     */
    SBMBlobClientStateStartTransfer,
    /**
     Sending Transfer Start messages procedure has been completed.
     */
    SBMBlobClientStateStartTransferDone,
    /**
     The client is notifying the servers with a Block Start message.
     */
    SBMBlobClientStateStartBlock,
    /**
     Sending Block Start messages procedure has been completed.
     */
    SBMBlobClientStateStartBlockDone,
    /**
     The client is sending BLOB chunks to the servers.
     */
    SBMBlobClientStateSendChunks,
    /**
     The client is querying the servers with a Block Get message.
     */
    SBMBlobClientStateQueryChunks,
    /**
     The transfer is complete, either successfully or unsuccessfully.
     */
    SBMBlobClientStateComplete,
    /**
     The transfer is canceling, client is sending Transfer Cancel messages to the servers.
     */
    SBMBlobClientStateCanceling,
    /**
     The transfer is suspended, client is doing nothing until it is ordered to resume.
     */
    SBMBlobClientStateSuspended
};
