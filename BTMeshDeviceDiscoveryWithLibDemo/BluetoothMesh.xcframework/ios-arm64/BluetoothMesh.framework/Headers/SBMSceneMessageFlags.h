//
//  SBMSceneMessageFlags.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 29/08/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message flags used to indicate specific behavior for scene control messages.
 */
@interface SBMSceneMessageFlags : NSObject

/**
 Boolean value specifying whether or not message should be acknowledged.
 */
@property (nonatomic, assign) BOOL isAcknowledgedRequired;

@end

NS_ASSUME_NONNULL_END
