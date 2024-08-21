//
//  SBMLightControlMode.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 03.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef SBMLightControlMode_h
#define SBMLightControlMode_h

/**
 Determines the mode of operation of the controller (see 6.2.3.1 Light LC Mode from the Mesh Model Bluetooth Specification).
 */
typedef NS_ENUM(NSUInteger, SBMLightControlMode) {
    /**
     The controller is turned off. The binding with the Light Lightness state is disabled.
     */
    SBMLightControlModeOff,

    /**
     The controller is turned on. The binding with the Light Lightness state is enabled.
     */
    SBMLightControlModeOn,
};

#endif /* SBMLightControlMode_h */
