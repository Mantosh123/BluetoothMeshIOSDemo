//
//  SBMAdvertisementExtensionTxStatus.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 24/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMSilabsConfigurationStatusCode.h"
#import "SBMAdvertisementExtensionTxConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Advertisement Extension Configuration Status
 @see SBMAdvertisementExtensionHandler
 */
@interface SBMAdvertisementExtensionTxStatus : NSObject

/**
 Status code of the operation.
 */
@property (nonatomic, readonly) SBMSilabsConfigurationStatusCode statusCode;

/**
 Advertisement Extension configuration of the remote node.
 */
@property (nonatomic, readonly, strong) SBMAdvertisementExtensionTxConfiguration *txConfiguration;

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
