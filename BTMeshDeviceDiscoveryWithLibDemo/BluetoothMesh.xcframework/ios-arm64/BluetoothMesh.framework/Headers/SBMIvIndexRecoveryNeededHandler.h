//
//  SBMIvIndexRecoveryNeededHandler.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 19/10/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 Handler the IV Index Recovery needed event.
 
 @param nodeIvIndex Current IV Index of a node.
 @param networkIvIndex Current Iv Index of a network.
 */
typedef void(^SBMIvIndexRecoveryNeededHandler)(UInt32 nodeIvIndex, UInt32 networkIvIndex);

NS_ASSUME_NONNULL_END
