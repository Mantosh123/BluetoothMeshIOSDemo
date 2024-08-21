//
//  SBMLightControlOccupancyModeSet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 16.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlSetRequest.h"
#import "SBMLightControlOccupancyModeType.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents Occupancy Mode set message send to Light Control Server
 (see 6.3.5.2.2 Light LC OM Set from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlOccupancyModeSet : NSObject<SBMLightControlSetRequest>

/**
 The target value of the Light LC Occupancy Mode state
 */
@property (nonatomic) SBMLightControlOccupancyModeType mode;

/**
 Not available. Use initWithFlags:mode: instead.
 */
+ (instancetype)new NS_UNAVAILABLE;
/**
 Not available. Use initWithFlags:mode: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initializer of Occupancy Mode Set request.
 @param flags message flags used for request
 */
- (instancetype)initWithFlags:(SBMLightControlMessageFlags *)flags
                         mode:(SBMLightControlOccupancyModeType)mode;

@end

NS_ASSUME_NONNULL_END
