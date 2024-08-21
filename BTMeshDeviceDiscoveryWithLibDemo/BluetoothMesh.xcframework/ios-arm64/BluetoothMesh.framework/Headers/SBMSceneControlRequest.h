//
//  SBMSceneControlRequest.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 29/08/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMSceneMessageFlags.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents requests from Scene Client that can control the Scene Register state
 */
@protocol SBMSceneControlRequest <NSObject>

/**
Scene message flags used to set additional request properties.
*/
@property (nonatomic, strong) SBMSceneMessageFlags *flags;

@end

NS_ASSUME_NONNULL_END
