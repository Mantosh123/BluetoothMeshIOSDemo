//
//  SBMLightControlLightOnOffGet.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 30/08/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlGetRequest.h"

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 Represents OnOff get message send to Light Control Server
 (see 6.3.5.3.1 Light LC Light OnOff Get from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlLightOnOffGet : NSObject <SBMLightControlGetRequest>

@end

NS_ASSUME_NONNULL_END
