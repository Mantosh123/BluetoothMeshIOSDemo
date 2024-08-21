//
//  SBMBluetoothMeshConfigurationBuilder.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 17/03/2023.
//  Copyright © 2023 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMBluetoothMeshConfiguration.h"
#import "SBMLocalVendorModel.h"
#import "SBMBluetoothMeshConfigurationLimits.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object for building Mesh configuration.
*/
@interface SBMBluetoothMeshConfigurationBuilder : NSObject

/**
 Builds SBMBluetoothMeshConfiguration object.
 */
- (SBMBluetoothMeshConfiguration *)build;

/**
 Set value for supported vendor models in being built SBMBluetoothMeshConfiguration.
 */
- (SBMBluetoothMeshConfigurationBuilder *)localVendorModels:(NSSet<SBMLocalVendorModel *> *)localVendorModels;

/**
 Set value for object specifying configuration limits in being built SBMBluetoothMeshConfiguration.
 */
- (SBMBluetoothMeshConfigurationBuilder *)limits:(SBMBluetoothMeshConfigurationLimits *)limits;

/**
 Set value for UInt16 specifying provisioner address in being built SBMBluetoothMeshConfiguration.
 */
- (SBMBluetoothMeshConfigurationBuilder *)provisionerAddress:(UInt16)provisionerAddress;

/**
 Set value for UInt32 specifying IV index in being built SBMBluetoothMeshConfiguration.
 */
- (SBMBluetoothMeshConfigurationBuilder *)ivIndex:(UInt32)ivIndex;


/**
 Not available. Use init instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
