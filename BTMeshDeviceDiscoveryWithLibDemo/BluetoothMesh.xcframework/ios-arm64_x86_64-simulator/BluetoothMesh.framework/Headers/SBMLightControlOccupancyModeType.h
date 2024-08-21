//
//  SBMLightControlOccupancyModeType.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 16.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#ifndef SBMLightControlOccupancyModeType_h
#define SBMLightControlOccupancyModeType_h

/**
 Determines if a controller transitions from a standby state when an occupancy sensor reports occupancy
 (see 6.2.3.2 Light LC Occupancy Mode from the Mesh Model Bluetooth Specification).
 */
typedef NS_ENUM (NSUInteger, SBMLightControlOccupancyModeType) {
    /**
     The controller does not transition from a standby state when occupancy is reported.
     */
    
    SBMLightControlOccupancyModeTypeStandbyTransitionDisabled = 0,
    /**
     The controller may transition from a standby state when occupancy is reported.
     */
    SBMLightControlOccupancyModeTypeStandbyTransitionEnabled = 1,
};

#endif /* SBMLightControlOccupancyModeType_h */
