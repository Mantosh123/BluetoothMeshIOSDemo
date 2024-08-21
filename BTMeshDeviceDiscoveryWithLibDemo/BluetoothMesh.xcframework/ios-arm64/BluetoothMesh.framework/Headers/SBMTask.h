//
//  SBMTask.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 10/06/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Generic Mesh Task to cancel requests.
 */
@interface SBMTask : NSObject

/**
 Task identificator
 */
@property (nonatomic, readonly) UInt64 identificator;

/**
 Call to cancel the task. Callbacks will NOT stop comming without call cancel method.
 VERY IMPORTANT
 */
- (void)cancel;

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
