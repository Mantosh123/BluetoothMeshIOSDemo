//
//  SBMProvisioningRecord.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 28.1.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMDevice.h"
#import "SBMProvisioningRecordId.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a Provisioning Record containing Record ID, Record Data and device.
 */
@interface SBMProvisioningRecord : NSObject

/**
 Device from which Record Data is fetched.
 */
@property (nonatomic, readonly, weak) id<SBMDevice> fromDevice;

/**
 Record ID wrapper identifying Provisioning Record.
 */
@property (nonatomic, readonly) SBMProvisioningRecordId* recordID;

/**
 Record Length.
 */
@property (nonatomic, readonly) UInt16 length;

/**
 Data of provisioning record.
 */
@property (nullable, nonatomic, readonly) NSData* data;

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
