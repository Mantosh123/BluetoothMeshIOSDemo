//
//  SBMSceneStatusCode.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 11/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#ifndef SBMSceneStatusCode_h
#define SBMSceneStatusCode_h

#import <Foundation/Foundation.h>

/**
 Structure defined in Mesh Model Bluetooth Specification 5.2.2.11.
 */
typedef NS_ENUM(NSUInteger, SBMSceneStatusCodeType) {
    SBMSceneStatusCodeTypeSuccess,
    SBMSceneStatusCodeTypeSceneRegisterFull,
    SBMSceneStatusCodeTypeSceneNotFound
};
#endif /* SBMSceneStatusCode_h */
