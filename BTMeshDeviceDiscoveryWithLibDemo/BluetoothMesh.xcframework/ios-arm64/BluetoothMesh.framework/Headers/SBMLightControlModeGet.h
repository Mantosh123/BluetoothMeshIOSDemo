//
//  SBMLightControlModeGet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 26.08.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMLightControlGetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents Mode get message send to Light Control Server
 (see 6.3.5.1.1 Light LC Mode Get from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlModeGet : NSObject <SBMLightControlGetRequest>

@end

NS_ASSUME_NONNULL_END
