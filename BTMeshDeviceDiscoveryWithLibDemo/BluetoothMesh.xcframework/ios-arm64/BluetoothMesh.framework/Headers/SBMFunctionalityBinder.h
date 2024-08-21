//
//  SBMFunctionalityBinder.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 06/11/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMGroup.h"
#import "SBMModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Action invoked when model binding operation has succeeded.

 @param succeededModel List of Model objects that were successfully bound to application key.
 @param appKey ApplicationKey object that models were bound to.
 */
typedef void(^SBMModelBindingSuccessCallback)(SBMModel* succeededModel, SBMApplicationKey* appKey);

/**
 Action invoked when model binding operation has failed.

 @param succeededModel List of Model objects that were successfully bound to application key.
 @param appKey ApplicationKey object that models were bound to.
 @param error Error describing reason of failure.
 */
typedef void(^SBMModelBindingErrorCallback)(SBMModel* _Nullable succeededModel, SBMApplicationKey* appKey, NSError* _Nullable error);

/**
 Action invoked when model unbinding operation has succeeded.

 @param succeededModel List of Model objects that were successfully unbound from application key.
 @param appKey ApplicationKey object that models were unbound from.
 */
typedef void(^SBMModelUnbindingSuccessCallback)(SBMModel* succeededModel, SBMApplicationKey* appKey);

/**
 Action invoked when model unbinding operation has failed.

 @param succeededModel Model objects that were successfully unbound from application key.
 @param appKey ApplicationKey object that models were unbound from.
 @param error Error describing reason of failure.
 */
typedef void(^SBMModelUnbindingErrorCallback)(SBMModel* _Nullable succeededModel, SBMApplicationKey* appKey, NSError* error);

/**
 Functionality Binder object. It is used to bind models with application key.
 */
@interface SBMFunctionalityBinder : NSObject

/**
 Initialize new Functionality Binder object.

 @param appKey ApplicationKey to which models will be bound.
 @return An initialized Functionality Binder object, or nil if an object could not be created.
 */
- (instancetype)initWithAppKey:(SBMApplicationKey*)appKey;

/**
 Not available. Use initWithAppKey instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithAppKey instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Binds model to application key.

 @param model Model object which should be bound with application key.
 @param successCallback Action invoked on successfull binding operation.
 @param errorCallback Action invoked on failed binding operation.
 */
- (void)bindModel:(SBMModel *)model successCallback:(SBMModelBindingSuccessCallback)successCallback errorCallback:(SBMModelBindingErrorCallback)errorCallback;

/**
 Unbinds model from application key.

 @param model Model object which should be unbound from application key.
 @param successCallback Action invoked on successfull unbinding operation.
 @param errorCallback Action invoked on failed unbinding operation.
 */
- (void)unbindModel:(SBMModel *)model successCallback:(SBMModelUnbindingSuccessCallback)successCallback errorCallback:(SBMModelUnbindingErrorCallback)errorCallback;

@end

NS_ASSUME_NONNULL_END
