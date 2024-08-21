//
//  SBMIvUpdateHandler.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 19/10/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMIvUpdateState.h"

/**
 Handler the event of IV Update procedure transitioning to a new state.

 @param ivIndex Current IV Index.
 @param state New state of the update procedure.
 */
typedef void(^SBMIvUpdateHandler)(UInt32 ivIndex, SBMIvUpdateState state);
