//
//  SBMSchedulerActionStatus.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 13/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSchedulerResponse.h"
#import "SBMScheduleRegister.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Message representing entry of Schedule Register state of an element.
 Response to Scheduler Action Get and acknowledged Action Set message.
 */
@interface SBMSchedulerActionStatus : NSObject<SBMSchedulerResponse>

/**
 Index of scheduler register entry that this object represents. Valid range for this value is from 0 to 15.
*/
@property (nonatomic, readonly) UInt8 index;

/**
 Schedule register object representing entry of specified index.
 */
@property (nonatomic, readonly) SBMScheduleRegister *scheduleRegister;

@end

NS_ASSUME_NONNULL_END
