//
//  SBMScheduleRegisterAction.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 09/06/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines action that should be taken at occurence of specified event.
 */
typedef NS_ENUM(NSUInteger, SBMScheduleRegisterAction) {
    SBMScheduleRegisterActionTurnOff = 0x0,
    SBMScheduleRegisterActionTurnOn = 0x1,
    SBMScheduleRegisterActionSceneRecall = 0x2,
    SBMScheduleRegisterActionNoAction = 0xF
};
