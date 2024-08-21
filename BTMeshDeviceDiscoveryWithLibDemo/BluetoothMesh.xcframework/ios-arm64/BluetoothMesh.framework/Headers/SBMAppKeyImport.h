//
//  SBMAppKeyImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A SBMAppKeyImport object contains informations used to import
 */
@interface SBMAppKeyImport : NSObject

/**
 ApplicationKey name.
 */
@property (nonatomic, readwrite, nullable) NSString *name;

/**
 ApplicationKey index.
 */
@property (nonatomic, readwrite) NSInteger index;

/**
 Application key data.
 */
@property (nonatomic, readwrite) NSData *key;

/**
 Old value of application key data.
 */
@property (nonatomic, readwrite, nullable) NSData *oldKey;

/**
 Creates new application key for import.
 @param index Application key index
 @param key 16 bytes of application key data.
 @param oldKey old key value. 16 byes of application key data
 @return Created application key import to create import structure
 */
+ (instancetype)initWithIndex:(NSInteger)index key:(NSData *)key oldKey:(nullable NSData*)oldKey;

/**
 Not available. Use initWithIndex:key:oldKey:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithIndex:key:oldKey:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
