//
//  SBMNetKeyImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 SBMNetKeyImport it's object which contain information used to import Network Key
 */
@interface SBMNetKeyImport : NSObject

/**
 Raw data of current value of the key
 */
@property (nonatomic, readwrite) NSData * key;

/**
 Raw data of old value of the key
 */
@property (nonatomic, readwrite, nullable) NSData * oldKey;

/**
 Index of the key
 */
@property (nonatomic, readwrite) NSInteger index;

/**
 Creates new SBMNetKeyImport with passed properties
 @param index index of the key
 @param key raw data of the key
 @param oldKey raw data of the old key
 @return new created object
 */
+ (instancetype)initWithIndex:(NSInteger)index key:(NSData*)key oldKey:(NSData* _Nullable)oldKey;

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
