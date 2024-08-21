//
//  SBMLightControlLightOnOff.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 10.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#ifndef SBMLightControlLightOnOff_h
#define SBMLightControlLightOnOff_h

/**
 Represents the state of a Light Lightness controller (see 6.2.3.3 Light LC Light OnOff from the Mesh Model Bluetooth Specification).
 */
typedef NS_ENUM (NSUInteger, SBMLightControlLightOnOffType) {
    /**
     State is equal to Off or equal to Standby.
     */
    SBMLightControlLightOnOffTypeOffOrStandby = 0,
    
    /**
     State is not equal to Off and not equal to Standby.
     */
    SBMLightControlLightOnOffTypeNotOffAndNotStandby = 1,
};

#endif /* SBMLightControlLightOnOff_h */
