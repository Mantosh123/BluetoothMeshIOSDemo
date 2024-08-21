//
//  SBMGenericPropertyAdmin.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMGenericProperty.h"
#import "SBMControlValueGetWithParamsSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Generic PropertyAdmin functionality object. It defines a state representing a device property of an element that can be read or writted.
 */
@interface SBMGenericPropertyAdmin : SBMGenericProperty<SBMControlValueGetWithParamsSigModel, SBMControlValueSetSigModel>

/**
 Initialize new generic property object as get request.

 @param identifier Device property identifier.
 @return An initialized generic property object, or nil if an object could not be created.
*/
- (instancetype)initWithId:(UInt16)identifier;

/**
 Initialize new generic property object as set request.

 @param identifier Device property identifier.
 @param access Device property access level.
 @param buffer Device property value.
 @return An initialized generic property object, or nil if an object could not be created.
 */
- (instancetype)initWithId:(UInt16)identifier access:(UInt8)access buffer:(NSData*)buffer;

/**
 Not available. Use initWithIdentifier instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithIdentifier instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
