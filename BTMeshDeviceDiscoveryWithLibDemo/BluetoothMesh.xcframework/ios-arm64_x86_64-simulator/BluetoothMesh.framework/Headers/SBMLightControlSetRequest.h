//
//  SBMLightControlSetRequest.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 03.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMLightControlMessageFlags.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Every class which represents a set massage send to Light Control Server and Settings Server implements this protocol.
 */
@protocol SBMLightControlSetRequest <NSObject>

/**
 Light Control message flags used to set additional request properties.
 */
@property (nonatomic) SBMLightControlMessageFlags *flags;

@end

NS_ASSUME_NONNULL_END
