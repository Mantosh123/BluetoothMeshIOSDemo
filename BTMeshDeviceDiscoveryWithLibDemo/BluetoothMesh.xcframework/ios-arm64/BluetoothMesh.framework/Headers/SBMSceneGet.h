//
//  SBMSceneGet.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 09/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMSceneGetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to get the current status of a currently active scene
 */
@interface SBMSceneGet : NSObject<SBMSceneGetRequest>

@end

NS_ASSUME_NONNULL_END
