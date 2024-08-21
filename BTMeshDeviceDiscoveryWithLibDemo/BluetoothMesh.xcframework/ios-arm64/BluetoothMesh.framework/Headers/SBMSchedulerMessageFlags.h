//
//  SBMSchedulerMessageFlags.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 19/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Object containing flags used when sending set requests to scheduler model
 */
@interface SBMSchedulerMessageFlags : NSObject

/**
 Property defining if request should be acknowledged
 */
@property (nonatomic, assign) BOOL isAcknowledgedRequired;

@end

NS_ASSUME_NONNULL_END
