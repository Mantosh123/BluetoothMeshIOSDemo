//
//  SBMAdvertisementExtensionNetworkPduStatus.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 21/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMSilabsConfigurationStatusCode.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Advertisement Extension Network PDU Status
 @see SBMAdvertisementExtensionHandler
 */
@interface SBMAdvertisementExtensionNetworkPduStatus : NSObject

/**
 Status code of the operation.
 */
@property (nonatomic, readonly) SBMSilabsConfigurationStatusCode statusCode;

/**
 Current maximum Network PDU size of the remote node.
 */
@property (nonatomic, readonly) UInt16 maxSize;

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
