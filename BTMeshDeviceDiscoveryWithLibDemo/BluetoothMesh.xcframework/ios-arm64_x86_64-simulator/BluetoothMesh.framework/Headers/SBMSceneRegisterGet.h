//
//  SBMSceneRegisterGet.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 17/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMSceneGetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a message send to Scene Server in order to get the current status of the Scene Register of an element
 (see 5.2.2.7 Scene Register Get from the Mesh Model Bluetooth Specification).
 */
@interface SBMSceneRegisterGet : NSObject<SBMSceneGetRequest>

@end

NS_ASSUME_NONNULL_END
