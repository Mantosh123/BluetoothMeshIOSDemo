//
//  SBMProvisioningRecordId.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 28.1.2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMRecordId.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents Record ID wrapper containing actual ID
 */
@interface SBMProvisioningRecordId: NSObject

/**
 16-bit Record ID identifying a Provisioning Record
 */
@property (nonatomic, readonly) SBMRecordId recordId;

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
