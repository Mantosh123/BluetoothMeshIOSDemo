//
//  SBMSchedulerActionSet.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 18/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSchedulerSetRequest.h"
#import "SBMScheduleRegister.h"
#import "SBMSchedulerMessageFlags.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to set the action defined by the entry of scheduler register state.
 The response to the Scheduler Action Set message is a Scheduler Action Status message if message is acknowledged.
*/
@interface SBMSchedulerActionSet : NSObject<SBMSchedulerSetRequest>

/**
 Object containing information if request should be acknowledged.
 */
@property (nonatomic, readonly) SBMSchedulerMessageFlags *flags;

/**
 Index of schedule register entry that this request should modify.
 Range of this value is 0-15 because schedule register have only 16 entries, zero-based.
 */
@property (nonatomic, readonly) UInt8 index;

/**
 Object containing information that this request should set to entry of schedule register at specified index.
 */
@property (nonatomic, readonly) SBMScheduleRegister* scheduleRegister;

/**
 Initializes request with specified flags, index and schedule register entry.
 @param flags flags specifying if request should be acknowledged
 @param index index of entry that should be received from scheduler register state. Value must be between 0-15, because schedule register has only 16 entries.
 @param scheduleRegister object containing information that this request should set to schedule register at specified index
 @return object representing Scheduler Action Get message
*/
- (instancetype)initWithFlags:(SBMSchedulerMessageFlags *)flags
                        index:(UInt8)index
             scheduleRegister:(SBMScheduleRegister*)scheduleRegister;

@end

NS_ASSUME_NONNULL_END
