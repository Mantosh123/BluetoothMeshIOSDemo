//
//  SBMGenericProperty.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 23/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"
#import "SBMBluetoothMeshMacros.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Base class for Generic Property functionality objects.
 */
@interface SBMGenericProperty : NSObject<SBMControlValueGetSigModel, SBMControlValueSetSigModel>

/**
 Value that represents a device property. A value of 0 is prohibited.
 */
@property (nonatomic, readonly) UInt16 identifier;

/**
 Value that indicates whether the device property can be read or written as a Generic UserProperty.
 
  - A value of 0 means that this property is not a generic user property. It is also set when object is used as request.
 
  - A value of 1 means that device property can be read.
 
  - A value of 2 means that device property can be written.
 
  - A value of 3 means that device property can be read and written.
 
  - Values from range 4 - 255 are prohibited.
 */
@property (nonatomic, readonly) UInt8 access;

/**
 If object is created as status response, buffer contains property value.
 Empty object otherwise.
 */
@property (nonatomic, readonly) NSData* buffer;

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
