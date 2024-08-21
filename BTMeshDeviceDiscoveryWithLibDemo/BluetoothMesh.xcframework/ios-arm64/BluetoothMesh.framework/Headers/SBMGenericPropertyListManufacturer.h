//
//  SBMGenericPropertyListManufacturer.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMGenericPropertyList.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Generic PropertyListManufacturer functionality object. It defines a list of states representing a device property of an element that is programmed by a manufacturer and can be read.
 */
@interface SBMGenericPropertyListManufacturer : SBMGenericPropertyList <SBMControlValueGetSigModel>

/**
 Initialize object to use as get request.

 @return An initialized generic property list object, or nil if an object could not be created.
*/
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
