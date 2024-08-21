//
//  SBMAdvertisementExtensionModelStatus.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMSilabsConfigurationStatusCode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Advertisement Extension Model Status
 @see SBMAdvertisementExtensionHandler
 */
@interface SBMAdvertisementExtensionModelStatus : NSObject

/**
 Status code of the operation.
 */
@property (nonatomic, readonly) SBMSilabsConfigurationStatusCode statusCode;

/**
 Advertisement Extension transmission enablement setting of the given model.
 */
@property (nonatomic, readonly) BOOL isModelTxEnabled;

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
