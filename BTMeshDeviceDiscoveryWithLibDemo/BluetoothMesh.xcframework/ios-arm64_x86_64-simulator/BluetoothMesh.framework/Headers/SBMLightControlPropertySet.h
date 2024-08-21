//
//  SBMLightControlPropertySet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 17.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlSetRequest.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents Property set message send to Light Control Setup Server
 (see 6.3.6.2 Light LC Property Set from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlPropertySet : NSObject<SBMLightControlSetRequest>

/**
 Property ID identifying a Light LC property
 */
@property (nonatomic) UInt16 propertyId;

/**
 Raw value of the Light LC property
 */
@property (nonatomic) NSData* propertyValue;

/**
 Not available. Use initWithFlags:propertyId:propertyValue: instead.
 */
+ (instancetype)new NS_UNAVAILABLE;
/**
 Not available. Use initWithFlags:propertyId:propertyValue: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize Light Control property set request
 @param flags message flags to be used for request
 @param propertyId Property ID identifying a Light LC property
 @param propertyValue Raw value of the Light LC property
 */
- (instancetype)initWithFlags:(SBMLightControlMessageFlags *)flags
                   propertyId:(UInt16)propertyId
                propertyValue:(NSData *)propertyValue;

@end

NS_ASSUME_NONNULL_END
