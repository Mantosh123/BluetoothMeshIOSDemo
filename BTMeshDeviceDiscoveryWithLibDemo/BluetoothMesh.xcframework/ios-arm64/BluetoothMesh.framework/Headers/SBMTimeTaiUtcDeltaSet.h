//
//  SBMTimeTaiUtcDeltaSet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 23.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeSetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 TAI-UTC Delta Set is an acknowledged message used to set the TAI-UTC Delta New state and the TAI of Delta Change state.
*/
@interface SBMTimeTaiUtcDeltaSet : NSObject <SBMTimeSetRequest>

/**
 Upcoming difference between TAI and UTC in seconds.
 */
@property (nonatomic) SInt32 taiUtcDeltaNew;

/**
 TAI Seconds time of the upcoming TAI-UTC Delta change.
 */
@property (nonatomic) UInt64 taiOfDeltaChange;

/**
 Initializer of Time TAI-UTC Delta Set message
 @param taiUtcDeltaNew value to initialize taiUtcDeltaNew property
 @param taiOfDeltaChange value to initialize taiOfDeltaChange property
 @return object representing Time TAI-UTC Delta set message
 */
- (instancetype)initWithTaiUtcDeltaNew:(SInt32)taiUtcDeltaNew
                      taiOfDeltaChange:(UInt64)taiOfDeltaChange;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
