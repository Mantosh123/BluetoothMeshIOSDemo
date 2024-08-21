//
//  SBMAdvertisementExtensionTxPhy.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 05/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 Physical layer transmission mode.
 */
typedef NS_ENUM(NSInteger, SBMAdvertisementExtensionTxPhy) {
    /**
     Tx-PHY: 1M PHY.
     */
    SBMAdvertisementExtensionTxPhyLe1M = 1,
    /**
     Tx-PHY: 2M PHY.
     */
    SBMAdvertisementExtensionTxPhyLe2M = 2,
    /**
     Undefined configuration.
     */
    SBMAdvertisementExtensionTxPhyUndefined
};
