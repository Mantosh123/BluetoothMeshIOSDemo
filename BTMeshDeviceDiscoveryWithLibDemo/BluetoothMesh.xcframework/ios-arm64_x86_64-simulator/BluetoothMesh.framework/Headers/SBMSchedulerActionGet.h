//
//  SBMSchedulerActionGet.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 29/04/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSchedulerGetRequest.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to get the action defined by the entry of scheduler register state.
 The response to the Scheduler Action Get message is a Scheduler Action Status message.
*/
@interface SBMSchedulerActionGet : NSObject<SBMSchedulerGetRequest>

/**
 Index of schedule register entry to receive. Valid range for this value is from 0 to 15.
 */
@property (nonatomic, readonly) UInt8 index;

/**
 Initializes request with specified entry index
 @param index index of entry that should be received from scheduler register state. Valid range for this parameter is from 0 to 15.
 @return object representing Scheduler Action Get message
 */
- (instancetype)initWithIndex:(UInt8)index;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
