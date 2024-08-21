//
//  SBMControlGroup.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 26/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMGroup.h"
#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueGetWithParamsSigModel.h"
#import "SBMControlValueSetSigModel.h"
#import "SBMControlValueSetVendorModel.h"
#import "SBMControlRequestParameters.h"
#import "SBMSensorPropertiesGet.h"
#import "SBMControlValueGetSensorModel.h"
#import "SBMControlValueSetSensorSetupModel.h"
#import "SBMTask.h"
#import "SBMGenericProperty.h"
#import "SBMLightControlGetRequest.h"
#import "SBMLightControlResponse.h"
#import "SBMLightControlSetRequest.h"

#import "SBMSceneGetRequest.h"
#import "SBMSceneControlRequest.h"
#import "SBMSceneResponse.h"

#import "SBMTimeGetRequest.h"
#import "SBMTimeSetRequest.h"
#import "SBMTimeResponse.h"

#import "SBMSchedulerGetRequest.h"
#import "SBMSchedulerSetRequest.h"
#import "SBMSchedulerResponse.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object used to control group.
 */
@interface SBMControlGroup : NSObject

/**
 Action invoked when group property status is successfully received.

 @param functionalityControl Control group object for which status was received.
 @param result Object containing result of operation.
 @param element SBMElement state is received for this element.
 */
typedef void (^SBMControlGroupGetWithParamsSuccess)(SBMControlGroup *functionalityControl, __kindof NSObject<SBMControlValueGetWithParamsSigModel> *result, SBMElement *element);

/**
 Action invoked when group status is successfully set.

 @param functionalityControl Control group object for which status was set.
 @param request Object containing operation request.
 */
typedef void (^SBMControlGroupSetVendorSuccess)(SBMControlGroup *functionalityControl, __kindof NSObject<SBMControlValueSetVendorModel> *request);

/**
 Action invoked when group status is successfully received.
 
 @param controlGroup Control group object for which status was received.
 @param result Object containing result of operation.
 @param element SBMElement state is received for this element.
 */
typedef void (^SBMControlGroupSensorGetHandlerSuccess)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueGetSensorModel> *result, SBMElement *element);

/**
 Action invoked when element status is successfully set.
 
 @param controlGroup Control group object for which status was set.
 @param result Object containing result of operation.
 @param element SBMElement state is set for this element.
 */
typedef void (^SBMControlGroupSensorSetHandlerSuccess)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueGetSensorModel> * _Nullable result, SBMElement * _Nullable element);

/**
 Action invoked when group property status could not be retrieved.

 @param functionalityControl Control group object for which status could not be retrieved.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlGroupGetWithParamsError)(SBMControlGroup *functionalityControl, NSError *error);

/**
 Action invoked when group status could not be set.
 
 @param functionalityControl Control group object for which status could not be set.
 @param request Object containing operation request.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlGroupSetVendorError)(SBMControlGroup *functionalityControl, __kindof NSObject<SBMControlValueSetVendorModel> *request, NSError *error);

/**
 Action invoked when group status could not be retrieved.
 
 @param controlGroup Control group object for which status could not be retrieved.
 @param result Object containing result of operation.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlGroupSensorGetError)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueGetSensorModel> *result, NSError *error);

/**
 Action invoked when element status could not be set.
 
 @param controlGroup Control group object for which status could not be set.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlGroupSensorSetError)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueSetSensorSetupModel> *request, NSError *error);

/**
 Action invoked when element status could not be retrieved.
 
 @param controlGroup Control group object for which status was retrieved.
 @param response Object containing result of operation
 @param element SBMElement state is set for this element.
 */
typedef void (^SBMLightControlGroupSuccessHandler)(SBMControlGroup *controlGroup, __kindof NSObject<SBMLightControlResponse> *_Nullable response, SBMElement * _Nullable element);

/**
 @param controlGroup Control group object for which status could not be retrieved.
 @param error Error describing failure
 */
typedef void (^SBMLightControlGroupErrorHandler)(SBMControlGroup *controlGroup, NSError *error);

/**
 Action invoked when element status is successfully received.
 
 @param controlGroup Control group object for which status was set.
 @param result Object containing result of operation.
 @param element SBMElement state is set for this element.
 */
typedef void (^SBMControlGroupSceneGetSuccess)(SBMControlGroup *controlGroup, __kindof NSObject<SBMSceneResponse>  * _Nullable result, SBMElement  * _Nullable element);

/**
 Action invoked when element status could not be retrieved.
 
 @param controlGroup Control group object for which status could not be retrieved.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlGroupSceneGetError)(SBMControlGroup *controlGroup, NSError *error);

/**
 Action invoked when element status is successfully received.
 
 @param controlGroup Control group object for which status was set.
 @param result Object containing result of operation.
 @param element SBMElement state is set for this element.
 */
typedef void (^SBMControlGroupModelGetSuccess)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueGetSigModel> *result, SBMElement * _Nullable element);

/**
 Action invoked when element status could not be get.
 
 @param controlGroup Control group object for which status could not be retrieved.
 @param result Object containing result of operation.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlGroupModelGetError)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueGetSigModel> *result, NSError *error);

/**
 Action invoked when response from element is successfully received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 
 @param controlGroup Control group object for which status was set.
 @param result Object containing result of operation.
 @param element SBMElement state is set for this element.
 */
typedef void (^SBMControlGroupModelSetSuccess)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueSetSigModel> * _Nullable result, SBMElement * _Nullable element);

/**
 Action invoked when element status could not be set.
 
 @param controlGroup Control group object for which status could not be retrieved.
 @param request Object containing operation request.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlGroupModelSetError)(SBMControlGroup *controlGroup, __kindof NSObject<SBMControlValueSetSigModel> *request, NSError *error);

/**
 Action invoked when response from element is successfully received.
 
 @param controlGroup Control group object for which status was received.
 @param status Object representing received status.
 @param element Element for which status was received.
 */
typedef void (^SBMTimeControlGroupSuccessHandler)(SBMControlGroup *controlGroup, __kindof NSObject<SBMTimeResponse> *status, SBMElement *element);

/**
 Action invoked when failure has occurred for status retrieval.
 
 @param controlGroup Control group object for which failure has occurred.
 @param error Error describing reason for failure.
 */
typedef void (^SBMTimeControlGroupErrorHandler)(SBMControlGroup *controlGroup, NSError *error);

/**
 Action invoked every time the response from element is successfully received.

 @param controlGroup Control group object for which status was received.
 @param response Object representing received status.
 @param element Element for which status was received.
*/
typedef void (^SBMSchedulerControlGroupSuccessHandler)(SBMControlGroup *controlGroup, __kindof NSObject<SBMSchedulerResponse> * _Nullable response, SBMElement * _Nullable element);

/**
 Action invoked when element status could not be retrieved.

 @param controlGroup Control group object for which failure has occurred.
 @param error Error describing reason for failure.
*/
typedef void (^SBMSchedulerControlGroupErrorCallback)(SBMControlGroup *controlGroup, NSError *error);

/**
 The group destination of the control messages.
 */
@property (nonatomic, readonly) SBMGroup *group;

/**
 The application key used to encrypt the control messages.
 */
@property (nonatomic, readonly) SBMApplicationKey *appKey;

/**
 Initialize new control group object.

 @param group Group which should be controlled.
 @return An initialized control group object, or nil if an object could not be created.
 */
- (instancetype)initWithGroup:(SBMGroup * const)group appKey:(SBMApplicationKey *)appKey;

/**
 Not available. Use initWithGroup instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithGroup instead.
 */
- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Get requests

/**
 Method used to retrieve Generic, Light Lightness and Light CTL model status.
 
 @param getStatusClass Class of functionality which status should be retrieved.
 @param successHandler Action invoked on success. Handler will be called for every response received form each SBMNode from the SBMGroup. To stop receiving callbacks call cancel() from the SBMTask.
 @param errorCallback Action invoked on failure.
 @return SBMTask task cancel request.
 */
- (SBMTask *)getStatus:(Class)getStatusClass
        successHandler:(SBMControlGroupModelGetSuccess)successHandler
         errorCallback:(SBMControlGroupModelGetError)errorCallback;

/**
 Method used to send parameterised request to group for Generic Property SIG model status.

 @param propertyRequest Object describing which property ID is requested from model.
 @param successHandler Action invoked on success.
 @param errorCallback Action invoked on failure.
*/
- (SBMTask *)getPropertyStatus:(__kindof NSObject<SBMControlValueGetWithParamsSigModel> *)propertyRequest
                successHandler:(nullable SBMControlGroupGetWithParamsSuccess)successHandler
                 errorCallback:(nullable SBMControlGroupGetWithParamsError)errorCallback;

/**
 Method used to retrieve group status.
 
 SBMSensorDescriptors and SBMSensorStatus are available.
 
 @param getSensorStatusClass Class which status should be retrieved.
 @param properties Object specifying request properties.
 @param successHandler Action invoked on success. Handler will be called for every response received form each SBMNode from the SBMGroup. To stop receiving callbacks call cancel() from the SBMTask.
 @param errorHandler Action invoked on failure.
 @return SBMTask task cancel request.
 */
- (SBMTask *)getSensorStatus:(Class)getSensorStatusClass
                  properties:(SBMSensorPropertiesGet *)properties
              successHandler:(nullable SBMControlGroupSensorGetHandlerSuccess)successHandler
                errorHandler:(nullable SBMControlGroupSensorGetError)errorHandler;

/**
 Method used to retrieve Light Control model status.
 
 @param request Request object for which status should be retrieved.
 @param successHandler Action invoked on success. Handler will be called for every response received form each SBMNode from the SBMGroup. To stop receiving callbacks call cancel() from the SBMTask.
 @param errorHandler Action invoked on failure.
 @return SBMTask task cancel request.
 */
- (SBMTask *)getLightControlResponse:(__kindof NSObject<SBMLightControlGetRequest> *)request
                      successHandler:(nullable SBMLightControlGroupSuccessHandler)successHandler
                        errorHandler:(nullable SBMLightControlGroupErrorHandler)errorHandler;

/**
 Method used to retrieve Scene model status.
 
 @param request Object request. SBMSceneGet and SBMSceneRegisterGet are available.
 @param successHandler Action invoked on success. Handler will be called for every response received form each SBMNode from the SBMGroup. To stop receiving callbacks call cancel() from the SBMTask.
 @param errorCallback Action invoked on failure.
 @return SBMTask task cancel request.
 */
- (SBMTask *)getSceneValue:(__kindof NSObject<SBMSceneGetRequest> *)request
            successHandler:(SBMControlGroupSceneGetSuccess) successHandler
             errorCallback:(SBMControlGroupSceneGetError) errorCallback;

/**
 Method used to retrieve Time model status.
 
 @param request Message sent to Time Control Server
 @param successHandler Action invoked when response is received
 @param errorHandler Action invoked in case of failure
 */
- (SBMTask *)getTimeControlResponse:(__kindof NSObject<SBMTimeGetGroupRequest> *)request
                     successHandler:(SBMTimeControlGroupSuccessHandler)successHandler
                       errorHandler:(SBMTimeControlGroupErrorHandler)errorHandler;

/**
 Method used to retrieve Scheduler model status.
 
 @param request Message sent to Scheduler Server
 @param successHandler Action invoked on success. Handler will be called for every response received form each SBMNode from the SBMGroup. To stop receiving callbacks call cancel on SBMTask object.
 @param errorCallback Action invoked in case of failure
 */
- (SBMTask *)getScheduleRegister:(__kindof NSObject<SBMSchedulerGetRequest> *)request
                  successHandler:(nullable SBMSchedulerControlGroupSuccessHandler)successHandler
                   errorCallback:(nullable SBMSchedulerControlGroupErrorCallback)errorCallback;

#pragma mark - Set requests

/**
 Method used to set Generic, Light Lightness and Light CTL model status.
 
 @param status Object specifying status to set.
 @param params Object specifying request parameters.
 @param successHandler Called when a response from element is successfully received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 @param errorCallback Action invoked on failure.
 @return SBMTask task cancel request.
 */
- (SBMTask *)setStatus:(__kindof NSObject<SBMControlValueSetSigModel> *)status
            parameters:(SBMControlRequestParameters *)params
        successHandler:(SBMControlGroupModelSetSuccess)successHandler
         errorCallback:(SBMControlGroupModelSetError)errorCallback;

/**
 Method used to set group status.

 @param status Object specifying status to set.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)setStatus:(__kindof NSObject<SBMControlValueSetVendorModel> *)status
  successCallback:(nullable SBMControlGroupSetVendorSuccess)successCallback
    errorCallback:(nullable SBMControlGroupSetVendorError)errorCallback;

/**
 Method used to set Sensor model group status.

 @param status Object specifying status to set.
 @param successHandler Called when a response from element is successfully received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 @param errorCallback Action invoked on failure.
 @return SBMTask task cancel request.
 */
- (SBMTask *)setSensorSetupStatus:(__kindof NSObject<SBMControlValueSetSensorSetupModel> *)status
                   successHandler:(nullable SBMControlGroupSensorSetHandlerSuccess)successHandler
                    errorCallback:(nullable SBMControlGroupSensorSetError)errorCallback;

/**
 Method used to set Light Control model values
 @param request Message sent to Light Control Server or Setup Server
 @param successHandler Called when a response from element is successfully received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 @param errorHandler Called when a response from element could not be received (for acknowledged messages) or when error occurred when sending message
 */
- (SBMTask *)setLightControlValue:(__kindof NSObject<SBMLightControlSetRequest> *)request
                   successHandler:(nullable SBMLightControlGroupSuccessHandler)successHandler
                     errorHandler:(nullable SBMLightControlGroupErrorHandler)errorHandler;

/**
 Method used to set Scene model status.
 
 @param request Object request. SBMSceneStore, SBMSceneRecall and SBMSceneDelete are available.
 @param successHandler Called when a response from element is successfully received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 @param errorCallback Action invoked on failure.
 @return SBMTask task cancel request.
 */
- (SBMTask *)changeSceneRegister:(__kindof NSObject<SBMSceneControlRequest> *)request
                  successHandler:(nullable SBMControlGroupSceneGetSuccess)successHandler
                   errorCallback:(nullable SBMControlGroupSceneGetError)errorCallback;

/**
 Method used to set Scheduler model status.

 @param request Message sent to Scheduler Setup Server
 @param successHandler Called every time a response from an element is received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 @param errorCallback Action invoked in case of failure
*/
- (SBMTask *)setScheduleRegister:(__kindof NSObject<SBMSchedulerSetRequest> *)request
                  successHandler:(nullable SBMSchedulerControlGroupSuccessHandler)successHandler
                   errorCallback:(nullable SBMSchedulerControlGroupErrorCallback)errorCallback;

@end

NS_ASSUME_NONNULL_END
