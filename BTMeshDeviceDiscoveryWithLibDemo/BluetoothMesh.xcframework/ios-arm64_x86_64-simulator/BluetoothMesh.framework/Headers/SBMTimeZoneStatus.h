//
//  SBMTimeZoneStatus.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 20.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a Time Zone Status message, response to get or set Time Zone request
 (see 5.2.1.6 Time Zone Status from the Mesh Model Bluetooth Specification).
*/
@interface SBMTimeZoneStatus : NSObject <SBMTimeResponse>

/**
  The current zone offset in 15-minute increments.
  Positive numbers are eastwards from UTC.
  This variable takes values from -64 to 191
  (which converts to range from -16 to 47.75 hours).
 */
@property (nonatomic, readonly) SInt16 timeZoneOffsetCurrent;

/**
  The new (i.e. upcoming Time Zone change) zone offset in 15-minute increments.
  Positive numbers are eastwards from UTC.
  This variable takes values from -64 to 191
  (which converts to range from -16 to 47.75 hours).
 */
@property (nonatomic, readonly) SInt16 timeZoneOffsetNew;

/**
  The time (in TAI Seconds format) which indicates when
  new Time Zone offset will be applied.
 
  Value 0 means that TimeServer does not contain this information.
 */
@property (nonatomic, readonly) UInt64 taiOfZoneChange;

@end

NS_ASSUME_NONNULL_END
