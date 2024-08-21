//
//  SBMTimeTaiUtcDeltaStatus.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 23.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Response to TAI-UTC Delta Get or TAI-UTC Delta Set message.
*/
@interface SBMTimeTaiUtcDeltaStatus : NSObject <SBMTimeResponse>

/**
 Current difference between TAI and UTC in seconds.
 */
@property (nonatomic, readonly) SInt32 taiUtcDeltaCurrent;

/**
 Upcoming difference between TAI and UTC in seconds.
 */
@property (nonatomic, readonly) SInt32 taiUtcDeltaNew;

/**
 TAI Seconds time of the upcoming TAI-UTC Delta change.
 */
@property (nonatomic, readonly) UInt64 taiOfDeltaChange;

@end

NS_ASSUME_NONNULL_END
