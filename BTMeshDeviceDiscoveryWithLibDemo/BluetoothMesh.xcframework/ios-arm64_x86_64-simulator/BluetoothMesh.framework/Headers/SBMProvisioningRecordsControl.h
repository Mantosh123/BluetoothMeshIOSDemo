//
//  SBMProvisioningRecordsControl.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 28.1.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMProvisioningRecord.h"
#import "SBMProvisioningRecordId.h"
#import "SBMRecordId.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Provides API to fetch provisioning records
 */
@interface SBMProvisioningRecordsControl: NSObject

/**
 Callback for successful Record Data fetching.

 @param provisioningRecord Fetched ProvisioningRecord.
 */
typedef void (^SBMProvisioningRecordGetSuccessCallback)(SBMProvisioningRecord *provisioningRecord);

/**
 Callback for successful list of Provisioning Record Ids fetching.

 @param provisioningRecordIDs Fetched list of Provisioning Record IDs.
 */
typedef void (^SBMProvisioningRecordListSuccessCallback)(NSArray<SBMProvisioningRecordId*>* provisioningRecordIDs);

/**
 Callback for failed Record Data or records list fetching.

 @param error Error that specifies reason for fetching failure.
 */
typedef void (^SBMProvisioningRecordErrorCallback)(NSError * error);

/**
 Device from which Record Data is fetched
 */
@property (nonatomic, readonly, weak) id<SBMDevice> device;

/**
 Fetches a list of Provisioning Record IDs from the device.

 @param successCallback Delivers result of the fetching.
 @param errorCallback Delivers error if appears.
 */
- (void)listProvisioningRecords:(SBMProvisioningRecordListSuccessCallback)successCallback
                  errorCallback:(SBMProvisioningRecordErrorCallback)errorCallback
NS_SWIFT_NAME(listProvisioningRecords(successCallback:errorCallback:));

/**
 Fetches a Provisioning Record from the device.
 
 @param recordId 16-bit Record ID of a Provisioning Record
 @param successCallback Delivers result of the fetching.
 @param errorCallback Delivers error if one occured.
 */
- (void)getProvisioningRecordWithId:(SBMRecordId)recordId
                    successCallback:(SBMProvisioningRecordGetSuccessCallback)successCallback
                      errorCallback:(SBMProvisioningRecordErrorCallback)errorCallback;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
