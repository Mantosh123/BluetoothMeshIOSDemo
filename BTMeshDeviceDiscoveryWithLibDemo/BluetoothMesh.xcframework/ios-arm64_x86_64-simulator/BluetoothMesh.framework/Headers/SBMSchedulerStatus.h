//
//  SBMSchedulerStatus.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 20/04/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSchedulerResponse.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message representing Scheduler state of an element.
 Response to Scheduler Get message.
 */
@interface SBMSchedulerStatus : NSObject<SBMSchedulerResponse>

/**
 Represents state of schedule register.
 This array contains 16 NSNumber* objects with boolean values.
 Boolean value of false represents empty entry in schedule register, value of true represents used entry.
 */
@property NSArray<NSNumber*>* schedules;

@end

NS_ASSUME_NONNULL_END
