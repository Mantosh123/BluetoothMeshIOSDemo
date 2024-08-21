//
//  SBMTimeRoleGet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 24.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeGetRequest.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Time Role Get is an acknowledged message used to get the Time Role state of an element.
 The response to the Time Role Get message is a Time Role Status message.
*/
@interface SBMTimeRoleGet : NSObject <SBMTimeGetElementRequest>

@end

NS_ASSUME_NONNULL_END
