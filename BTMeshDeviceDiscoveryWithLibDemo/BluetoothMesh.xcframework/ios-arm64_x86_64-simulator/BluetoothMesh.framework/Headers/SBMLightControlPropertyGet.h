//
//  SBMLightControlPropertyGet.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 27/08/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBMLightControlGetRequest.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Represents Property get message send to Light Control Server
 (see 6.3.6.1 Light LC Property Get from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlPropertyGet : NSObject <SBMLightControlGetRequest>

/**
 Property ID identifying a Light LC Property
 */
@property (nonatomic, readonly) UInt16 propertyID;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize new Property Get Light Control Object.
 
 @param propertyID propertyID that functionality should be initialized with.
 @return An initialized PropertyGet object, or nil if an object could not be created.
 */
- (instancetype)initWithPropertyID:(UInt16)propertyID;

@end

NS_ASSUME_NONNULL_END
