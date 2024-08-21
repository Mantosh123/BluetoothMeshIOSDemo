//
//  SBMVirtualAddress.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 06/07/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMAddress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Class containing all the required data required to address a mesh message.
 UUID of the virtual address.
 */
@interface SBMVirtualAddress : SBMAddress

/**
 UUID of the virtual address.
 */
@property (nonatomic, readonly) NSUUID *uuid;

/**
 Initialization method.
 
 @param virtualAddress UUID of the virtual address.
 @return initialized SBMVirtualAddress object.
 */
- (instancetype)initWithUuid:(NSUUID *)virtualAddress;

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
