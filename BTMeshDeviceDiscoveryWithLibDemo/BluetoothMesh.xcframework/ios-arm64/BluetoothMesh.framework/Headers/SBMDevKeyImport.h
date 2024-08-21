//
//  SBMDevKeyImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 It is a container for device key for Import. Each SBMNode has own device key.
 */
@interface SBMDevKeyImport : NSObject

/**
 Raw data of the key
 */
@property (nonatomic, readwrite) NSData *key;

/**
 Creates new DeviceKey for import with and key
 */
+ (instancetype)initWithKey:(NSData*)key;

/**
 Not available. Use initWithIndex:key:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithIndex:key:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
