//
//  SBMTimeRoleSet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 25.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMTimeSetRequest.h"
#import "SBMTimeRole.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Time Role Set is an acknowledged message used to set the Time Role state of an element.
 The response to the Time Role Set message is a Time Role Status message.
*/
@interface SBMTimeRoleSet : NSObject <SBMTimeSetRequest>

/**
 Time Role for the element.
 */
@property (nonatomic) SBMTimeRole timeRole;

/**
 Initializer for Time Role Set message
 @param timeRole value to initialize timeRole property
 @return object representing Time Role Set message
 */
- (instancetype)initWithTimeRole:(SBMTimeRole)timeRole;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
