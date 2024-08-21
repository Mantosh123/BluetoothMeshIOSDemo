//
//  SBMIvUpdateState.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 19/10/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 Possible states of IV Index Update Procedure.
 */
typedef NS_ENUM(NSUInteger, SBMIvUpdateState) {
    /** Normal Operation. */
    SBMIvUpdateNormal = 0,
    /** IV Index Update is in progress. */
    SBMIvUpdateInProgress = 1,
};

NS_ASSUME_NONNULL_END
