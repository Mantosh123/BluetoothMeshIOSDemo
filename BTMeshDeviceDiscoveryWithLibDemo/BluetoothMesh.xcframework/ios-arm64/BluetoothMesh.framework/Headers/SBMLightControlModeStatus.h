//
//  SBMLightControlModeStatus.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 30.08.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlMode.h"
#import "SBMLightControlResponse.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a status message received as a response after Mode get or set request send to Light Control Server
 (see 6.3.5.1.4 Light LC Mode Status from the Mesh Model Bluetooth Specification).
 */
@interface SBMLightControlModeStatus : NSObject<SBMLightControlResponse>

/**
 LightControlMode value.
 */
@property (nonatomic, readonly) SBMLightControlMode mode;

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
