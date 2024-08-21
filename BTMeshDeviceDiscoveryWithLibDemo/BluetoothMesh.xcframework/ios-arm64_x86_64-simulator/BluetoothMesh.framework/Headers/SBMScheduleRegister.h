//
//  SBMScheduleRegister.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 13/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMScheduleRegisterAction.h"

#import "SBMScheduleRegisterYear.h"
#import "SBMScheduleRegisterMonth.h"
#import "SBMScheduleRegisterDay.h"
#import "SBMScheduleRegisterDayOfWeek.h"

#import "SBMScheduleRegisterHour.h"
#import "SBMScheduleRegisterMinute.h"
#import "SBMScheduleRegisterSecond.h"

#import "SBMScheduleRegisterScene.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Class representing entry of schedule register
 */
@interface SBMScheduleRegister : NSObject

/**
 Year of occurence of specified event.
 Object encapsulates 2 least significant digits of the year or value of SBMScheduleRegisterYearAny if event should occur every year.
 */
@property (nonatomic, readonly) SBMScheduleRegisterYear *year;

/**
 Array of SBMScheduleRegisterMonth objects which encapsulate values of SBMScheduleRegisterMonth enum.
 */
@property (nonatomic, readonly) NSArray<SBMScheduleRegisterMonth*> *months;

/**
 Day of occurence of specified event.
 Object encapsulates day or value of SBMScheduleRegisterDayAny if event should occur at any day.
 */
@property (nonatomic, readonly) SBMScheduleRegisterDay *day;

/**
 Hour of occurence of specified event.
 Object encapsulates specific hour or value of SBMScheduleRegisterHour enum.
*/
@property (nonatomic, readonly) SBMScheduleRegisterHour *hour;

/**
 Minute of occurence of specified event.
 Object encapsulates specific minute or value of SBMScheduleRegisterMinute enum.
*/
@property (nonatomic, readonly) SBMScheduleRegisterMinute *minute;

/**
 Second of occurence of specified event.
 Object encapsulates specific second or value of SBMScheduleRegisterSecond enum.
*/
@property (nonatomic, readonly) SBMScheduleRegisterSecond *second;

/**
 Array of SBMScheduleRegisterDayOfWeek objects which encapsulates values of SBMScheduleRegisterDayOfWeek enum.
 */
@property (nonatomic, readonly) NSArray<SBMScheduleRegisterDayOfWeek*> *daysOfWeek;

/**
 Action which should be taken when specified date and time took place.
 Value must be of type SBMScheduleRegisterAction.
 */
@property (nonatomic, readonly) SBMScheduleRegisterAction action;

/**
 Amount of time (in milliseconds) allotted for the transition to take place.
 */
@property (nonatomic, readonly) UInt32 transitionTime;

/**
 If action to perform is scene recall, this object encapsulates number of scene to recall.
 If other action is set, this object should be created with enum SBMScheduleRegisterSceneNone.
 */
@property (nonatomic, readonly) SBMScheduleRegisterScene *scene;

/**
 Initializer of Schedule Register object for action other than scene recall
 @param year value to initialize year property
 @param months value to initialize months property
 @param day value to initialize day property
 @param hour value to initialize hour property
 @param minute value to initialize minute property
 @param second value to initialize second property
 @param daysOfWeek value to initialize daysOfWeek property
 @param action value to initialize action property
 @param transitionTime value to initialize transitionTime property
 @return object representing Schedule Register
 */
- (instancetype)initWithYear:(SBMScheduleRegisterYear*)year
                      months:(NSArray<SBMScheduleRegisterMonth*>*)months
                         day:(SBMScheduleRegisterDay*)day
                        hour:(SBMScheduleRegisterHour*)hour
                      minute:(SBMScheduleRegisterMinute*)minute
                      second:(SBMScheduleRegisterSecond*)second
                  daysOfWeek:(NSArray<SBMScheduleRegisterDayOfWeek*>*)daysOfWeek
                      action:(SBMScheduleRegisterAction)action
              transitionTime:(UInt32)transitionTime;

/**
 Initializer of Schedule Register object for scene recall action
 @param year value to initialize year property
 @param months value to initialize months property
 @param day value to initialize day property
 @param hour value to initialize hour property
 @param minute value to initialize minute property
 @param second value to initialize second property
 @param daysOfWeek value to initialize daysOfWeek property
 @param action value to initialize action property
 @param transitionTime value to initialize transitionTime property
 @param scene value to initialize scene property
 @return object representing Schedule Register
*/
- (instancetype)initWithYear:(SBMScheduleRegisterYear*)year
                      months:(NSArray<SBMScheduleRegisterMonth*>*)months
                         day:(SBMScheduleRegisterDay*)day
                        hour:(SBMScheduleRegisterHour*)hour
                      minute:(SBMScheduleRegisterMinute*)minute
                      second:(SBMScheduleRegisterSecond*)second
                  daysOfWeek:(NSArray<SBMScheduleRegisterDayOfWeek*>*)daysOfWeek
                      action:(SBMScheduleRegisterAction)action
              transitionTime:(UInt32)transitionTime
                       scene:(SBMScheduleRegisterScene*)scene;

@end

NS_ASSUME_NONNULL_END
