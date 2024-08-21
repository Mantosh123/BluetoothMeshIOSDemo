//
//  SBMSensorMessageFlags.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 09/07/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message flags used to indicate specific behavior for sensor control messages.
 */
@interface SBMSensorMessageFlags : NSObject

/**
 Boolean value specifying whether or not message should be acknowledged.
 */
@property (nonatomic, assign) BOOL isAcknowledgedRequired;

@end

NS_ASSUME_NONNULL_END
