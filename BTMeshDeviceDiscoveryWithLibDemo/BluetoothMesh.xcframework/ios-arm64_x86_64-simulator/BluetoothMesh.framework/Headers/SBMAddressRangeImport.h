//
//  SBMAddressRangeImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A range of addresses used to import.
 */
@interface SBMAddressRangeImport : NSObject

/**
 The lowest possible address.
 */
@property (nonatomic, readwrite) UInt16 lowAddress;

/**
 The highest possible address.
 */
@property (nonatomic, readwrite) UInt16 highAddress;

/**
 Not available. Use SBMProvisionerImport addUnicastRange/addGroupRange/addSceneRange
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
Not available. Use SBMProvisionerImport addUnicastRange/addGroupRange/addSceneRange
*/
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
