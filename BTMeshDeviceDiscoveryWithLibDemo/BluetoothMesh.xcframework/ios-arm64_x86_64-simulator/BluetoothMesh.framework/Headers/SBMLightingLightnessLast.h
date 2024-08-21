//
//  SBMLightingLightnessLast.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Lighting LightnessLast functionality object. It represents the last known non-zero value of Lighting LightnessActual.
 */
@interface SBMLightingLightnessLast : NSObject<SBMControlValueGetSigModel>

/**
 Value of Lighting LightnessLast functionality.
 */
@property (nonatomic, readonly) UInt16 lightness;

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
