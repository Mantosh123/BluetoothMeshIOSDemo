//
//  SBMLightControlPropertyStatus.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 28/08/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a status message received as a response after Property get or set request send to Light Control Server
 * (see 6.3.6.4 Light LC Property Status from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlPropertyStatus : NSObject<SBMLightControlResponse>

/**
 Property ID identifying a Light LC Property
 */
@property (nonatomic, readonly) UInt16 propertyID;

/**
 Value of the Light LC Property
 */
@property (nonatomic, readonly, nullable) NSData *propertyValue;

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
