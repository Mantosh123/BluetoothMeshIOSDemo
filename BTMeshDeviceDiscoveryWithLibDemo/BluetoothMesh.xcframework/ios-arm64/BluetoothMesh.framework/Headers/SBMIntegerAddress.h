//
//  SBMIntegerAddress.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 06/07/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMAddress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Class containing all the required data required to address a mesh message.
 Unicast or group integer address.
 */
@interface SBMIntegerAddress : SBMAddress

/**
 Unicast or group integer address.
 */
@property (nonatomic, readonly) UInt16 integer;

/**
 Initialization method.
 
 @param integerAddress Unicast or group integer address.
 @return initialized SBMIntegerAddress object.
 */
- (instancetype)initWithInteger:(UInt16)integerAddress;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
