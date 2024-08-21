//
//  SBMBluetoothMeshConfiguration.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 03.12.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMLogger.h"
#import "SBMLocalVendorModel.h"
#import "SBMBluetoothMeshConfigurationLimits.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object for Mesh configuration.
 It is a place to specify which vendor models should be supported by framework.
*/
@interface SBMBluetoothMeshConfiguration : NSObject

/**
 Supported vendor models.
 */
@property (nonatomic, readonly) NSSet<SBMLocalVendorModel *> *localVendorModels;

/**
 Object specifying configuration limits.
 */
@property (nonatomic, readonly) SBMBluetoothMeshConfigurationLimits* limits;

/**
 Address to assign for provisioner. 0 means default (0x2001).
 */
@property (nonatomic, readonly) UInt16 provisionerAddress;

/**
 IV index to initially use in the network.
 */
@property (nonatomic, readonly) UInt32 ivIndex;

/**
 Not available. Use SBMBluetoothMeshConfigurationBuilder instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMBluetoothMeshConfigurationBuilder instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
