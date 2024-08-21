//
//  SBMTimeGetRequest.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 02.03.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents request objects that can be used to get state of Time Model for element
 */
@protocol SBMTimeGetElementRequest <NSObject>

@end

/**
 Represents request objects that can be used to get state of Time Model for group
 */
@protocol SBMTimeGetGroupRequest <NSObject>

@end

/**
 Represents request objects that can be used to get state of Time Model
 */
@protocol SBMTimeGetRequest <SBMTimeGetElementRequest, SBMTimeGetGroupRequest>

@end

NS_ASSUME_NONNULL_END
