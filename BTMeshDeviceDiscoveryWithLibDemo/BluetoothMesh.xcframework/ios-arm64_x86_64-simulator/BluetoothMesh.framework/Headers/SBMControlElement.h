//
//  SBMControlElement.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 25/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMElement.h"

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueGetWithParamsSigModel.h"
#import "SBMControlValueSetSigModel.h"
#import "SBMControlValueSetVendorModel.h"
#import "SBMControlRequestParameters.h"
#import "SBMControlValueGetSensorModel.h"
#import "SBMControlValueSetSensorSetupModel.h"
#import "SBMGenericProperty.h"
#import "SBMSensorPropertiesGet.h"
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
 Object used to get and set element states.
 */
@interface SBMControlElement : NSObject

/**
 Action invoked when element status is successfully received.

 @param controlElement Control element object for which status was received.
 @param result Object containing result of operation.
 */
typedef void (^SBMControlElementGetSuccess)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueGetSigModel> *result);

/**
 Action invoked when property status is successfully received.

 @param controlElement Control element object for which status was received.
 @param result Object containing result of operation.
 */
typedef void (^SBMControlElementGetWithParamsSuccess)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueGetWithParamsSigModel> *result);

/**
 Action invoked when element status is successfully set.

 @param controlElement Control element object for which status was set.
 @param response Object containing operation response.
 */
typedef void (^SBMControlElementSetSuccess)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueSetSigModel> * _Nullable response);

/**
 Action invoked when element status is successfully set.

 @param controlElement Control element object for which status was set.
 @param request Object containing operation request.
 */
typedef void (^SBMControlElementSetVendorSuccess)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueSetVendorModel> *request);

/**
 Action invoked when element status could not be retrieved.

 @param controlElement Control element object for which status could not be retrieved.
 @param result Object containing result of operation.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlElementGetError)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueGetSigModel> *result, NSError *error);

/**
 Action invoked when element property status could not be retrieved.

 @param controlElement Control element object for which status could not be retrieved.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlElementGetWithParamsError)(SBMControlElement *controlElement, NSError *error);

/**
 Action invoked when element status could not be set.

 @param controlElement Control element object for which status could not be set.
 @param request Object containing operation request.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlElementSetError)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueSetSigModel> *request, NSError *error);

/**
 Action invoked when element status could not be set.

 @param controlElement Control element object for which status could not be set.
 @param request Object containing operation request.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlElementSetVendorError)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueSetVendorModel> *request, NSError *error);

/**
 Action invoked when element status is successfully received.
 
 @param controlElement Control element object for which status was received.
 @param result Object containing result of operation.
 */
typedef void (^SBMControlElementSensorGetSuccess)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueGetSensorModel> *result);

/**
 Action invoked when element status could not be retrieved.
 
 @param controlElement Control element object for which status could not be retrieved.
 @param request Object containing operation request.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlElementSensorGetError)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueGetSensorModel> *request, NSError *error);

/**
 Action invoked when element status is successfully set.
 
 @param controlElement Control element object for which status was set.
 @param result Object containing result of operation.
 */
typedef void (^SBMControlElementSensorSetSuccess)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueGetSensorModel> *result);

/**
 Action invoked when element status could not be set.
 
 @param controlElement Control element object for which status could not be set.
 @param request Object containing operation request.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlElementSensorSetError)(SBMControlElement *controlElement, __kindof NSObject<SBMControlValueSetSensorSetupModel> *request, NSError *error);

/**
 Action invoked when element status is successfully received.
 
 @param controlElement Control element object for which status was retrieved.
 @param response Object containing result of operation
 */
typedef void (^SBMLightControlElementSuccessCallback)(SBMControlElement *controlElement, __kindof NSObject<SBMLightControlResponse> *response);

/**
 
  Action invoked when element status could not be retrieved.
 
 @param controlElement Control element object for which status could not be retrieved.
 @param error Error describing failure
 */
typedef void (^SBMLightControlElementErrorCallback)(SBMControlElement *controlElement, NSError *error);

/**
 Action invoked when element status is successfully received.
 
 @param controlElement Control element object for which status was set.
 @param result Object containing result of operation.
 */
typedef void (^SBMControlElementSceneGetSuccess)(SBMControlElement *controlElement, __kindof NSObject<SBMSceneResponse> * _Nullable result);

/**
 Action invoked when element status could not be retrieved.
 
 @param controlElement Control element object for which status could not be retrieved.
 @param error Error describing reason of failure.
 */
typedef void (^SBMControlElementSceneGetError)(SBMControlElement *controlElement, NSError *error);

/**
 Action invoked when element status is successfully received.

 @param controlElement Control element object for which status was set.
 @param response Object containing result of operation.
*/
typedef void (^SBMTimeControlElementSuccessCallback)(SBMControlElement *controlElement, __kindof NSObject<SBMTimeResponse> *response);

/**
 Action invoked when element status could not be retrieved.

 @param controlElement Control element object for which status could not be retrieved.
 @param error Error describing reason of failure.
*/
typedef void (^SBMTimeControlElementErrorCallback)(SBMControlElement *controlElement, NSError *error);

/**
 Action invoked when element status is successfully received.

 @param controlElement Control element object for which status was received.
 @param response Object representing received status.
*/
typedef void (^SBMSchedulerControlElementSuccessCallback)(SBMControlElement *controlElement, __kindof NSObject<SBMSchedulerResponse> *response);

/**
 Action invoked when element status could not be retrieved.

 @param controlElement Control element object for which status could not be retrieved.
 @param error Error describing reason of failure.
*/
typedef void (^SBMSchedulerControlElementErrorCallback)(SBMControlElement *controlElement, NSError *error);

/**
 Controlled element.
 */
@property (nonatomic, readonly) SBMElement *element;

/**
 The application key used to encrypt the control message.
 */
@property (nonatomic, readonly) SBMApplicationKey *appKey;

/**
 Initialize new control element object.

 @param element Element which should be controlled.
 @param appKey Application key used to encrypt the control message.
 @return An initialized control element object, or nil if an object could not be created.
 */
- (instancetype)initWithElement:(SBMElement *)element appKey:(SBMApplicationKey *)appKey;

/**
 Not available. Use initWithElement instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithElement instead.
 */
- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Get requests

/**
 Method used to retrieve Generic, Light Lightness and Light CTL model status.
 
 For example getStatusClass can be set as SBMLightingCTLTemperature.class in ObjC
 or SBMLightingCTLTemperature.self in Swift.
 getStatusClass must implement SBMControlValueGetSigModel.

 @param getStatusClass Class of functionality which status should be retrieved.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)getStatus:(Class)getStatusClass
  successCallback:(nullable SBMControlElementGetSuccess)successCallback
    errorCallback:(nullable SBMControlElementGetError)errorCallback;

/**
 Method used to send parameterised request to element for Generic Property SIG model status.

 @param propertyRequest Object describing which property ID is requested from model.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
*/
- (void)getPropertyStatus:(__kindof NSObject<SBMControlValueGetWithParamsSigModel> *)propertyRequest
          successCallback:(nullable SBMControlElementGetWithParamsSuccess)successCallback
            errorCallback:(nullable SBMControlElementGetWithParamsError)errorCallback;

/**
 Method used to retrieve Sensor model status.
 
 SBMSensorDescriptors and SBMSensorStatus are available.
 
 @param getStatusClass Class which status should be retrieved.
 @param properties Object specifying request properties.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)getSensorStatus:(Class)getStatusClass
             properties:(SBMSensorPropertiesGet *)properties
        successCallback:(nullable SBMControlElementSensorGetSuccess)successCallback
          errorCallback:(nullable SBMControlElementSensorGetError)errorCallback;

/**
 Method used to retrieve Light Control model status.
 
 @param request Request object for which status should be retrieved.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)getLightControlResponse:(__kindof NSObject<SBMLightControlGetRequest> *)request
                successCallback:(nullable SBMLightControlElementSuccessCallback)successCallback
                  errorCallback:(nullable SBMLightControlElementErrorCallback)errorCallback;

/**
 Method used to retrieve Scene model status.
 
 @param request Object request. SBMSceneGet and SBMSceneRegisterGet are available.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
-(void)getSceneValue:(__kindof NSObject<SBMSceneGetRequest> *)request
     successCallback:(SBMControlElementSceneGetSuccess) successCallback
       errorCallback:(SBMControlElementSceneGetError) errorCallback;

/**
 Method used to retrieve Time model status.
 
 @param request Message sent to Time Control Client, Server or Setup Server
 @param successCallback Action invoked when response is received
 @param errorCallback Action invoked in case of failure
 */
- (void)getTimeControlResponse:(__kindof NSObject<SBMTimeGetElementRequest> *)request
               successCallback:(nullable SBMTimeControlElementSuccessCallback)successCallback
                 errorCallback:(nullable SBMTimeControlElementErrorCallback)errorCallback;

/**
 Method used to retrieve Scheduler model status.
 
 @param request Message sent to Scheduler Server
 @param successCallback Action invoked when response is received
 @param errorCallback Action invoked in case of failure
 */
- (void)getScheduleRegister:(__kindof NSObject<SBMSchedulerGetRequest> *)request
            successCallback:(nullable SBMSchedulerControlElementSuccessCallback)successCallback
              errorCallback:(nullable SBMSchedulerControlElementErrorCallback)errorCallback;

#pragma mark - Set requests

/**
 Method used to set Generic, Light Lightness and Light CTL model status.
 
 For example use SBMLightingCTLSet object.

 @param status Object specifying status to set.
 @param params Object specifying request parameters.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)setStatus:(__kindof NSObject<SBMControlValueSetSigModel> *)status
       parameters:(SBMControlRequestParameters *)params
  successCallback:(nullable SBMControlElementSetSuccess)successCallback
    errorCallback:(nullable SBMControlElementSetError)errorCallback;

/**
 Method used to set Vendor model/functionality status.
 
 It is needed to provide implementation by application developer
 for SBMControlValueSetVendorModel to use this functionality.

 @param status Object specifying status to set.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)setStatus:(__kindof NSObject<SBMControlValueSetVendorModel> *)status
  successCallback:(nullable SBMControlElementSetVendorSuccess)successCallback
    errorCallback:(nullable SBMControlElementSetVendorError)errorCallback;

/**
 Method used to set Sensor model status.
 
 @param status Object specifying status to set.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)setSensorSetupStatus:(__kindof NSObject<SBMControlValueSetSensorSetupModel> *)status
             successCallback:(nullable SBMControlElementSensorSetSuccess)successCallback
               errorCallback:(nullable SBMControlElementSensorSetError)errorCallback;

/**
 Method used to set Light Control model values
 @param request Message sent to Light Control Server or Setup Server
 @param successCallback Called when a response from element is successfully received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 @param errorCallback Called when a response from element could not be received (for acknowledged messages) or when error occurred when sending message
 */
- (void)setLightControlValue:(__kindof NSObject<SBMLightControlSetRequest> *)request
             successCallback:(nullable SBMLightControlElementSuccessCallback)successCallback
               errorCallback:(nullable SBMLightControlElementErrorCallback)errorCallback;

/**
 Method used to set Scene model status.
 
 @param request Object request. SBMSceneStore, SBMSceneRecall and SBMSceneDelete are available.
 @param successCallback Action invoked on success.
 @param errorCallback Action invoked on failure.
 */
- (void)changeSceneRegister:(__kindof NSObject<SBMSceneControlRequest> *)request
            successCallback:(nullable SBMControlElementSceneGetSuccess)successCallback
              errorCallback:(nullable SBMControlElementSceneGetError)errorCallback;

/**
Method used to set Time model status.

@param request Message sent to Time Control Client or Setup Server
@param successCallback Action invoked when response is received
@param errorCallback Action invoked in case of failure
*/
- (void)setTimeControlValue:(__kindof NSObject<SBMTimeSetRequest> *)request
            successCallback:(nullable SBMTimeControlElementSuccessCallback)successCallback
              errorCallback:(nullable SBMTimeControlElementErrorCallback)errorCallback;

/**
 Method used to set Scheduler model status.

 @param request Message sent to Scheduler Setup Server
 @param successCallback Action invoked when response is received (for acknowledged messages) or after successfully sending request (unacknowledged messages)
 @param errorCallback Action invoked in case of failure
*/
- (void)setScheduleRegister:(__kindof NSObject<SBMSchedulerSetRequest> *)request
            successCallback:(nullable SBMSchedulerControlElementSuccessCallback)successCallback
              errorCallback:(nullable SBMSchedulerControlElementErrorCallback)errorCallback;

@end

NS_ASSUME_NONNULL_END
