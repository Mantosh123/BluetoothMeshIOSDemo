//
//  SBMTransmitImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SBMTransmitImport : NSObject

@property (nonatomic, readonly) NSInteger count;
@property (nonatomic, readonly) NSInteger interval;

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
