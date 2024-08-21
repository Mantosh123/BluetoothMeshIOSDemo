//
//  SBMElement.h
//  ble_mesh-lib
//
//  Created by Lukasz Rzepka on 04.05.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMSigModel.h"
#import "SBMVendorModel.h"
#import "SBMIntegerAddress.h"
@class SBMNode;

NS_ASSUME_NONNULL_BEGIN

/**
 Each node contains one or more Elements. The element is a container for models contained by Node.
 */
@interface SBMElement : NSObject<NSCopying>



/**
 Human-readable name that can identify and element within the node
 */
@property (nonatomic, nullable) NSString* name;


/**
 Unicast Address.
 */
@property (nonatomic, readonly) SBMIntegerAddress *address;

/**
 Number from 0 to 255 representing numeric order of the element within the node.
 */
@property (nonatomic, readonly) UInt8 index;

/**
 Represents a description of the element's location (defined in the GATT Bluetooth Namespace Descriptors). 32-bit
 When value is null getDeviceCompositionData on node could be called to update this value.
 */
@property (nonatomic, readonly, nullable) NSNumber* location; //BC: - SBMElement location


/**
 Array of SIG Models contained by Element.
 */
@property (nonatomic, readonly) NSArray<SBMSigModel *> *sigModels;

/**
 Array of Vendor Models contained by Element.
 */
@property (nonatomic, readonly) NSArray<SBMVendorModel *> *vendorModels;

/**
 Element's node.
 */
@property (nonatomic, readonly, weak) SBMNode* node;

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
