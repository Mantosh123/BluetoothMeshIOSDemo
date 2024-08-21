//
//  SBMLightControlOccupancyModeGet.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 02/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlGetRequest.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents Occupancy Mode get message send to Light Control Server
 (see 6.3.5.2.1 Light LC OM Get from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlOccupancyModeGet : NSObject <SBMLightControlGetRequest>

@end

NS_ASSUME_NONNULL_END
