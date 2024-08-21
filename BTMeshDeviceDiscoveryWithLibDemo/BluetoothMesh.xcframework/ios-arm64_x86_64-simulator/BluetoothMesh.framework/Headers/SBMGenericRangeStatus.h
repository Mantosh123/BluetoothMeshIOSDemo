//
//  SBMGenericRangeStatus.h
//  BluetoothMesh
//
//  Created by Michal Barnas on 21/02/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 Possible results of generic range set request.
 */
typedef NS_ENUM(NSInteger, SBMGenericRangeStatus) {
    /** Command successfully processed. */
    SBMGenericRangeStatusSuccess,
    /** The provided value for range min cannot be set. */
    SBMGenericRangeStatusCannotSetMin,
    /** The provided value for range max cannot be set. */
    SBMGenericRangeStatusCannotSetMax,
    /** Reserved for future use. */
    SBMGenericRangeStatusReserved
};
