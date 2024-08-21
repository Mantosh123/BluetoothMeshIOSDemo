//
//  SBMTimeZoneGet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 18.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeGetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 
 Represents message send to Time Server in order to receive Time Zone Status
 with the following information:
 - Current Time Zone offset
 - Upcoming Time Zone offset
 - Time when upcoming Time Zone offset will be applied.
 For details see 5.2.1.4 Time Zone Get from the Mesh Model Bluetooth Specification
*/
@interface SBMTimeZoneGet : NSObject<SBMTimeGetRequest>

@end

NS_ASSUME_NONNULL_END
