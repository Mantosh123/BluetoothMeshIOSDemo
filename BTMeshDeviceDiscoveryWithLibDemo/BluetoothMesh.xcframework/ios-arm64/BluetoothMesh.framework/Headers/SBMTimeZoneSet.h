//
//  SBMTimeZoneSet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 20.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeSetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents message send to TimeSetupServer in order to set the following values:
 - Upcoming Time Zone offset
 - Time when upcoming Time Zone offset will be applied.
 Response will be Time Zone status message.
 For details see 5.2.1.5 Time Zone Set from the Mesh Model Bluetooth Specification
*/
@interface SBMTimeZoneSet : NSObject <SBMTimeSetRequest>

/**
 The new (i.e. upcoming Time Zone change) zone offset in 15-minute increments.
 Positive numbers are eastwards from UTC.
 This variable can take values from -64 to 191
 (which converts to range from -16 to 47.75 hours).
*/
@property (nonatomic) SInt16 timeZoneOffsetNew;

/**
 The time (in TAI Seconds format) which indicates when
 new Time Zone offset will be applied.

 Value 0 means that TimeSetupServer won't contain this information.
*/
@property (nonatomic) UInt64 taiOfZoneChange;

/**
 Initializer for Time Zone set message
 @param timeZoneOffsetNew value to initialize timeZoneOffsetNew property
 @param taiOfZoneChange value to initialize taiOfZoneChange property
 @return object reperesenting Time Zone Set message
 */
- (instancetype)initWithTimeZoneOffSetNew:(SInt16)timeZoneOffsetNew
                          taiOfZoneChange:(UInt64)taiOfZoneChange;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
