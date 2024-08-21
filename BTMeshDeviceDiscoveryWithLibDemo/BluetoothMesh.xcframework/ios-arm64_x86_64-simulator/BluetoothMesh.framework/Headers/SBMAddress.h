//
//  SBMAddress.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 03/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Class containing all the required data to address a mesh message.
 @see SBMIntegerAddress
 @see SBMVirtualAddress
 */
@interface SBMAddress : NSObject

/**
 Address value in a convenient way for UI display or logging.
 It uses format defined in the Mesh Configuration Database:
 - In case of non-virtual address, it is a hexadecimal integer value.
 - In case of virtual address, it is an UUID string.
 */
@property (nonatomic, strong, readonly) NSString *addressString;

@property (readonly) UInt16 integer;

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
