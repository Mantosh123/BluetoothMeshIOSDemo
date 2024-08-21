//
//  SBMLightControlMessageFlags.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 02.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Light Control message flags used to set additional request properties.
 */
@interface SBMLightControlMessageFlags : NSObject

/**
 Acknowledgement flag for Light LC message.
 Light Control Model will be received in response if acknowledge is enabled.
 */
@property (nonatomic) BOOL acknowledgeRequired;

@end

NS_ASSUME_NONNULL_END
