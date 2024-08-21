//
//  SBMControlElementPublications.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 25.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMElement.h"
#import "SBMTask.h"

#import "SBMControlValueGetSigModel.h"

#import "SBMLightControlGetRequest.h"
#import "SBMLightControlResponse.h"

#import "SBMControlValueGetSensorModel.h"
#import "SBMSensorPropertiesGet.h"

#import "SBMSceneGetRequest.h"
#import "SBMSceneResponse.h"

#import "SBMTimeGetRequest.h"
#import "SBMTimeResponse.h"

#import "SBMSchedulerGetRequest.h"
#import "SBMSchedulerResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Class responsible for subscribing to given element for status changes encrypted with a given application key.
 */
@interface SBMControlElementPublications : NSObject

/**
 Action invoked whenever Light Control status has been successfully received.
 
 @param element Element which published light control status
 @param appKey Application key used to encrypt the status messages.
 @param status Light Control status received from element
 */
typedef void (^SBMLightControlElementPublicationSuccessHandler)(SBMElement* element,
                                                                SBMApplicationKey* appKey,
                                                                NSObject<SBMLightControlResponse>* status);

/**
 Action invoked whenever Sensor status has been successfully received.
 
 @param element Element which published sensor status
 @param group Group from which publication has been received
 @param status Sensor status received from element
 */
typedef void (^SBMSensorElementPublicationSuccessHandler)(SBMElement* element,
                                                          SBMApplicationKey* group,
                                                          NSObject<SBMControlValueGetSensorModel>* status);

/**
 Action invoked whenever Scene status has been successfully received.
 
 @param element Element which published light control status
 @param appKey Application key used to encrypt the status messages.
 @param status Scene status received from element
 */
typedef void (^SBMScenesElementPublicationSuccessHandler)(SBMElement* _Nullable element,
                                                          SBMApplicationKey* _Nullable appKey,
                                                          NSObject<SBMSceneResponse>* _Nullable status);

/**
 Action invoked when element Generic, Light Lightness and Light CTL model status is successfully received.
 
 @param element Element which published generic model status
 @param appKey Application key used to encrypt the status messages.
 @param result Object containing result of operation.
 */
typedef void (^SBMElementPublicationSuccessHandler)(SBMElement* element,
                                                    SBMApplicationKey* appKey,
                                                    NSObject<SBMControlValueGetSigModel> *result);

/**
 Action invoked when element status is successfully received.
 
 @param element Element which published time status
 @param appKey Application key used to encrypt the status messages.
 @param response Time status received from element
 */
typedef void (^SBMTimeControlElementSuccessHandler)(SBMElement * _Nullable element,
                                                    SBMApplicationKey* _Nullable appKey,
                                                    __kindof NSObject<SBMTimeResponse> * _Nullable response);

/**
 Action invoked when element status is successfully received.
 
 @param element Element which published scheduler status
 @param appKey Application key used to encrypt the status messages.
 @param response Scheduler status received from element
 */
typedef void (^SBMSchedulerElementPublicationSuccessHandler)(SBMElement * _Nullable element,
                                                             SBMApplicationKey* _Nullable appKey,
                                                             __kindof NSObject<SBMSchedulerResponse> * _Nullable response);

/**
 Action invoked when subscription could not be set.
 
 @param error Error object containing information about error
 */
typedef void (^SBMElementPublicationErrorHandler)(NSError* error);

/**
 Subscribe to light control element status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToLightControlStatus:(NSObject<SBMLightControlGetRequest> *)request
                                     successHandler:(SBMLightControlElementPublicationSuccessHandler)successHandler
                                       errorHandler:(SBMElementPublicationErrorHandler)errorHandler;

/**
 Subscribe to sensor element status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToSensorStatus:(Class<SBMControlValueGetSensorModel>)request
                               successHandler:(SBMSensorElementPublicationSuccessHandler)successHandler
                                 errorHandler:(SBMElementPublicationErrorHandler)errorHandler;

/**
 Subscribe to scene element status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToSceneStatus:(NSObject<SBMSceneGetRequest> *)request
                              successHandler:(SBMScenesElementPublicationSuccessHandler)successHandler
                                errorHandler:(SBMElementPublicationErrorHandler)errorHandler;

/**
 Method used to subscribe to Generic, Light Lightness and Light CTL model status.
 
 @param subStatusClass Class of functionality which status should be subscribed to. Needs to impelemnt SBMControlValueGetSigModel protocol.
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToStatus:(Class<SBMControlValueGetSigModel>)subStatusClass
                successHandler:(SBMElementPublicationSuccessHandler)successHandler
                  errorHandler:(SBMElementPublicationErrorHandler)errorHandler;

/**
 Subscribe to time element status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToTimeStatus:(__kindof NSObject<SBMTimeGetElementRequest> *)request
                             successHandler:(SBMTimeControlElementSuccessHandler)successHandler
                               errorHandler:(SBMElementPublicationErrorHandler)errorHandler;

/**
 Subscribe to scheduler element status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToScheduleRegister:(__kindof NSObject<SBMSchedulerGetRequest> *)request
                                  successHandler:(SBMSchedulerElementPublicationSuccessHandler)successHandler
                                    errorHandler:(SBMElementPublicationErrorHandler)errorHandler;

@end

NS_ASSUME_NONNULL_END
