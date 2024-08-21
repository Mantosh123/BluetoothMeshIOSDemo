//
//  SBMDeviceCompositionDataImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 SBMDeviceCompositionData contains information about a node, the elements it includes, and the supported models.
 */
@interface SBMDeviceCompositionDataImport : NSObject

/**
 Company identifier.
 */
@property (nonatomic, readwrite) NSInteger cid;

/**
 Vendor-assigned product identifier.
 */
@property (nonatomic, readwrite) NSInteger pid;

/**
 Vendor-assigned product version identifier.
 */
@property (nonatomic, readwrite) NSInteger vid;

/**
 Minimum number of replay protection list entries in a device.
 */
@property (nonatomic, readwrite) NSInteger crpl;

/**
 Is Relay feature supported by node.
 */
@property (nonatomic, readwrite) BOOL supportsRelay;

/**
 Is Proxy feature supported by node.
 */
@property (nonatomic, readwrite) BOOL supportsProxy;

/**
 Is Friend feature supported by node.
 */
@property (nonatomic, readwrite) BOOL supportsFriend;

/**
 Is Low Power supported by node.
 */
@property (nonatomic, readwrite) BOOL supportsLowPower;

/**
 Not available. Use SBMNodeImport createDeviceCompositionData
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMNodeImport createDeviceCompositionData
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
