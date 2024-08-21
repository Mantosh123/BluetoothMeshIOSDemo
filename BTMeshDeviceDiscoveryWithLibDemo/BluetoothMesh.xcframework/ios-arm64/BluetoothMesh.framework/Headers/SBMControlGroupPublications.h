//
//  SBMControlGroupPublications.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 25.09.2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMGroup.h"
#import "SBMTask.h"

#import "SBMLightControlGetRequest.h"
#import "SBMLightControlResponse.h"

#import "SBMControlValueGetSensorModel.h"

#import "SBMSceneGetRequest.h"
#import "SBMSceneResponse.h"

#import "SBMTimeGetRequest.h"
#import "SBMTimeResponse.h"

#import "SBMSchedulerGetRequest.h"
#import "SBMSchedulerResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
Class responsible for subscribing to group for status changes
*/
@interface SBMControlGroupPublications : NSObject

/**
Action invoked whenever Light Control status has been successfully received.

@param element Element which published light control status
@param group Group from which publication has been received
@param status Light Control status received from element
*/
typedef void (^SBMLightControlGroupNotificationSuccessHandler)(SBMElement* element,
                                                            SBMGroup* group,
                                                            NSObject<SBMLightControlResponse>* status);

/**
Action invoked whenever Sensor status has been successfully received.

@param element Element which published sensor control status
@param group Group from which publication has been received
@param status Sensor status received from element
*/
typedef void (^SBMSensorGroupNotificationSuccessHandler)(SBMElement* element,
                                                      SBMGroup* group,
                                                      NSObject<SBMControlValueGetSensorModel>* status);

/**
Action invoked whenever Scene status has been successfully received.

@param element Element which published scene status
@param group Group from which publication has been received
@param status Scene status received from element
*/
typedef void (^SBMScenesGroupNotificationSuccessHandler)(SBMElement* element,
                                                      SBMGroup* group,
                                                      NSObject<SBMSceneResponse>* status);

/**
 Action invoked when element Generic, Light Lightness and Light CTL model status is successfully received.
 
 @param element Element which published generic model status
 @param group Group from which publication has been received
 @param result Object containing result of operation.
 */
typedef void (^SBMGroupPublicationSuccessHandler)(SBMElement *element,
                                               SBMGroup *group,
                                               NSObject<SBMControlValueGetSigModel> *result);

/**
 Action invoked whenever Time status has been successfully received.
 
 @param element Element which published time status
 @param group Group from which publication has been received
 @param status Time status received from element
 */
typedef void (^SBMTimeGroupNotificationSuccessHandler)(SBMElement *element,
                                                    SBMGroup *group,
                                                    NSObject<SBMTimeResponse> *status);

/**
 Action invoked whenever Scheduler status has been successfully received.

 @param element Element which published scheduler status
 @param group Group from which publication has been received
 @param status Scheduler status received from element
*/
typedef void (^SBMSchedulerGroupNotificationSuccessHandler)(SBMElement* element,
                                                         SBMGroup* group,
                                                         NSObject<SBMSchedulerResponse>* status);

/**
 Action invoked when subscription could not be set.
 
 @param group Group for which operation has failed.
 @param error Error object containing information about error.
 */
typedef void (^SBMGroupNotificationErrorHandler)(SBMGroup *group,
                                                  NSError *error);

/**
Group for which we want to control publications
*/
@property (nonatomic, readonly) SBMGroup* group;

/**
Application key for which we want to control publications
*/
@property (nonatomic, readonly) SBMApplicationKey* appKey;

/**
Initialize new control group publications object

 @param group Element's group
 @param appKey Element's appKey
@return An initialized control group publications object, or nil if an object could not be created.
*/
- (instancetype)initWithGroup:(SBMGroup *)group appKey:(nonnull SBMApplicationKey *)appKey;

/**
Unavailable. Use initWithGroup: appKey: instead
*/
+ (instancetype)new NS_UNAVAILABLE;

/**
Unavailable. Use initWithGroup: appKey: instead
*/
- (instancetype)init NS_UNAVAILABLE;

/**
Subscribe to light control group status

@param request For this request we will receive published statuses
@param successHandler Action invoked on received publication
@param errorHandler Action invoked when subscribe opration has failed
@return Task used to cancel subscription
*/
- (SBMTask *)subscribeToLightControlStatus:(NSObject<SBMLightControlGetRequest> *)request
                                     successHandler:(SBMLightControlGroupNotificationSuccessHandler)successHandler
                                       errorHandler:(SBMGroupNotificationErrorHandler)errorHandler;

/**
 Subscribe to sensor group status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
*/
- (SBMTask *)subscribeToSensorStatus:(Class<SBMControlValueGetSensorModel>)request
                               successHandler:(SBMSensorGroupNotificationSuccessHandler)successHandler
                                 errorHandler:(SBMGroupNotificationErrorHandler)errorHandler;

/**
 Subscribe to scene group status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
*/
- (SBMTask *)subscribeToSceneStatus:(NSObject<SBMSceneGetRequest> *)request
                              successHandler:(SBMScenesGroupNotificationSuccessHandler)successHandler
                                errorHandler:(SBMGroupNotificationErrorHandler)errorHandler;

/**
 Method used to subscribe to Generic, Light Lightness and Light CTL model status.
 
 @param subStatusClass Class of functionality which status should be subscribed to. Needs to impelemnt SBMControlValueGetSigModel protocol.
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToStatus:(Class<SBMControlValueGetSigModel>)subStatusClass
                successHandler:(SBMGroupPublicationSuccessHandler)successHandler
                  errorHandler:(SBMGroupNotificationErrorHandler)errorHandler;

/**
 Subscribe to time group status
 
 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe operation failed.
 @return Task used to cancel subscription
 */
- (SBMTask *)subscribeToTimeStatus:(NSObject<SBMTimeGetGroupRequest> *)request
                             successHandler:(SBMTimeGroupNotificationSuccessHandler)successHandler
                               errorHandler:(SBMGroupNotificationErrorHandler)errorHandler;

/**
 Subscribe to scheduler group status

 @param request For this request we will receive published statuses
 @param successHandler Action invoked on received publication
 @param errorHandler Action invoked when subscribe opration has failed
 @return Task used to cancel subscription
*/
- (SBMTask *)subscribeToScheduleRegister:(__kindof NSObject<SBMSchedulerGetRequest> *)request
                                  successHandler:(SBMSchedulerGroupNotificationSuccessHandler)successHandler
                                    errorHandler:(SBMGroupNotificationErrorHandler)errorHandler;

@end

NS_ASSUME_NONNULL_END
