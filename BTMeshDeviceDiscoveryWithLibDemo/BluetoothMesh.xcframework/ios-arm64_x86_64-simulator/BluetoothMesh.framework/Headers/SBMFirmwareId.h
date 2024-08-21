//
//  SBMFirmwareId.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 31/03/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 Identifier of the firmware image.
 */
@interface SBMFirmwareId : NSObject

/**
 A 16-bit Company ID that identifies the firmware vendor.
 */
@property (nonatomic, readonly) UInt16 companyId;

/**
 Vendor-specific information describing the firmware binary package.
 */
@property (nonatomic, readonly) NSData *versionInformation;

/**
 Initializer for SBMFirmwareId class
 
 @param companyId A 16-bit Company ID that identifies the firmware vendor.
 @param versionInformation Vendor-specific information describing the firmware binary package.
 @return Return instance of an object. 
 */
-(instancetype)initWithCompanyId:(UInt16)companyId versionInformation:(NSData *)versionInformation;

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
