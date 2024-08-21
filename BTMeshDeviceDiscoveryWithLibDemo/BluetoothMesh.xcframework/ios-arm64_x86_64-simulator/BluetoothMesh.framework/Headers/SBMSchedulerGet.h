//
//  SBMSchedulerGet.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 17/04/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSchedulerGetRequest.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to get the current Schedule Register state of an element.
 The response to the Scheduler Get message is a Scheduler Status message.
 */
@interface SBMSchedulerGet : NSObject<SBMSchedulerGetRequest>

@end

NS_ASSUME_NONNULL_END
