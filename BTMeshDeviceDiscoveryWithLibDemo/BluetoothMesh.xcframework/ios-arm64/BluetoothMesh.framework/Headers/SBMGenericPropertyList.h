//
//  SBMGenericPropertyList.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Base class for Generic PropertyList functionality objects.
 */
@interface SBMGenericPropertyList : NSObject<SBMControlValueGetSigModel>

/**
 Property list buffer.
 If object is created as status response, it contains raw properties data.
 Empty object otherwise.
 */
@property (nonatomic, readonly) NSData* buffer;

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
