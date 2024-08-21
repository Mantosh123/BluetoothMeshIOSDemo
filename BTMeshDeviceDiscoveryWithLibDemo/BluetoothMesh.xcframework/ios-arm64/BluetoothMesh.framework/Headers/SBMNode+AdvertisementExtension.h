//
//  SBMNode+AdvertisementExtension.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 16/11/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMNode.h"

@class SBMVendorModel;

NS_ASSUME_NONNULL_BEGIN

@interface SBMNode(AdvertisementExtension)

/**
 Silabs Confiugration Server Model instance used for configuring e.g. Advertisement Extension feature on the node.
 If present, it shall be located on the primary element of the node.
 @see SBMAdvertisementExtension
 */
@property (nonatomic, readonly, nullable) SBMVendorModel *silabsConfigurationServerModel;

@end

NS_ASSUME_NONNULL_END
