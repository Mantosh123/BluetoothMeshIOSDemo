//
//  SBMTimeRoleStatus.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 24.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeResponse.h"
#import "SBMTimeRole.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Response to Time Role Get or Time Role Set message.
*/
@interface SBMTimeRoleStatus : NSObject <SBMTimeResponse>

/**
 The Time Role for the element.
 */
@property (nonatomic, readonly) SBMTimeRole timeRole;

@end

NS_ASSUME_NONNULL_END
