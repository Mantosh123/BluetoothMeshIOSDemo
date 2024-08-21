//
//  SBMAdvertisementExtensionTxStatus.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 05/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMAdvertisementExtensionTxPhy.h"
#import "SBMAdvertisementExtensionTxOptionsBitmapType.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Advertisement Extension Configuration.
 This is a node wide configuration.
 */
@interface SBMAdvertisementExtensionTxConfiguration : NSObject

/**
 Physical layer transmission mode.
 */
@property (nonatomic, readonly) SBMAdvertisementExtensionTxPhy txPhyConfigType;

/**
 Additional setting flags for the Advertisement Extension Configuration.
 */
@property (nonatomic, readonly) SBMAdvertisementExtensionTxOptionsBitmapType txOptionsBitmapType;

/**
 Initialization method.
 
 @param txPhyConfigType Physical layer transmission mode.
 @param txOptionsBitmapType Additional setting flags for the Advertisement Extension Configuration.
 */
- (instancetype)initWith:(SBMAdvertisementExtensionTxPhy)txPhyConfigType
     txOptionsBitmapType:(SBMAdvertisementExtensionTxOptionsBitmapType)txOptionsBitmapType;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
