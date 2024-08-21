//
//  SBMGroupImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A SBMGroupImport object contains informations used to import
 */
@interface SBMGroupImport : NSObject

/**
 Group name.
 */
@property (nonatomic, readwrite, nullable) NSString *name;

/**
 Group address.
 */
@property (nonatomic, readwrite) UInt16 address;

///**
// Virtual address of group. UUID
// */
//@property (nonatomic, readwrite, nullable) NSData *virtualAddress;
//
///**
// Parent of this group.
// */
//@property (nonatomic, readwrite, nullable) SBMGroupImport *parentGroup;
//

+ (instancetype) initWithAddress:(UInt16)address;

/**
 Not available. Use SBMSubnetImport addGroupWithAddress:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMSubnetImport addGroupWithAddress:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
