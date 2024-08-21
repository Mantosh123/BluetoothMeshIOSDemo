//
//  SBMElementImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMModelImport.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Each node contains one or more Elements. Element is a container for a Models contained by Node.
 */
@interface SBMElementImport : NSObject

/**
 Human-readable name that can identify and element within the node
 */
@property (nonatomic, readwrite, nullable) NSString *name;

/**
 Number from 0 to 255 representing numeric order of the element within the node.
 */
@property (nonatomic, readwrite) UInt8 index;

/**
 Represents a description of the element's location (defined in the GATT Bluetooth Namespace Descriptors).
 */
@property (nonatomic, readwrite) UInt32 location;

/**
 Array of Models contained by Element to import.
 To add new element use createModel:
 */
@property (nonatomic, readonly) NSArray<SBMModelImport*> *models;

/**
 Creates and adds new model with provided identifier
 @param identifier of new created model (16bit if it's SIG model 32bit if it's Vendor model)
 @return returns created object for configuration
 */
- (SBMModelImport*)createModel:(NSInteger) identifier;

/**
 Not available. Use SBMNodeImport addElementWithIndex:andLocation:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMNodeImport addElementWithIndex:andLocation:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
