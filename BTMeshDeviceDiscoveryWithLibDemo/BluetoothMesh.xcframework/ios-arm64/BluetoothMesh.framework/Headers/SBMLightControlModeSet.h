//
//  SBMLightControlModeSet.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 03.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlSetRequest.h"
#import "SBMLightControlMode.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents Mode set message send to Light Control Server
 (see 6.3.5.1.2 Light LC Mode Set from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlModeSet : NSObject<SBMLightControlSetRequest>

/**
 Light Control Mode value to be set.
 */
@property (nonatomic) SBMLightControlMode mode;

/**
 Not available. Use initWithFlags:mode: instead.
 */
+ (instancetype)new NS_UNAVAILABLE;
/**
 Not available. Use initWithFlags:mode: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize new Light Control Mode Set request object.

 @param flags Message flags to be used for this message
 @param mode Light Control Mode value to be set
 */
- (instancetype)initWithFlags:(SBMLightControlMessageFlags *)flags
                         mode:(SBMLightControlMode)mode;

@end

NS_ASSUME_NONNULL_END
