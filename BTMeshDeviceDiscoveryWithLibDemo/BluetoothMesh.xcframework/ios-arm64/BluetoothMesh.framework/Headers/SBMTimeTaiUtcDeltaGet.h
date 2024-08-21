//
//  SBMTimeTaiUtcDeltaGet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 23.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeGetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 TAI-UTC Delta Get is an acknowledged message used to get a TAI-UTC Delta Status message.
*/
@interface SBMTimeTaiUtcDeltaGet : NSObject <SBMTimeGetRequest>

@end

NS_ASSUME_NONNULL_END
