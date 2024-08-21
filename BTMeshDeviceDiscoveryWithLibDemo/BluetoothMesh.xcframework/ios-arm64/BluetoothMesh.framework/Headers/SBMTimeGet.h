//
//  SBMTimeGet.h
//  BluetoothMesh
//
//  Created by Michal Barnas on 24/02/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeGetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to get the Time state of neighbor nodes.
 The response to the Time Get message is a Time Status message.
 */
@interface SBMTimeGet : NSObject <SBMTimeGetRequest>

@end

NS_ASSUME_NONNULL_END
