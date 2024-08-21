//
//  SBMFirmwareDistributionCapabilitiesStatus.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/02/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Response sent by a Firmware Distribution server.
 @see SBMFirmwareDistribution
 @see SBMFirmwareDistributionHandler
 
 Reports Distributor capabilities.
 */
@interface SBMFirmwareDistributionCapabilitiesStatus : NSObject

/**
 Maximum number of entries in the Distribution Receivers List state.
 */
@property (nonatomic, readonly) UInt16 maxReceiversListSize;

/**
 Maximum number of entries in the Firmware List state.
 */
@property (nonatomic, readonly) UInt16 maxFirmwareListSize;

/**
 Maximum size of one firmware image.
 */
@property (nonatomic, readonly) UInt32 maxFirmwareSize;

/**
 Total size of storage dedicated for firmware images.
 */
@property (nonatomic, readonly) UInt32 maxUploadSpace;

/**
 Currently available size in the storage dedicated for firmware images.
 */
@property (nonatomic, readonly) UInt32 remainingUploadSpace;

/**
 Value of the Out-of-Band Retrieval Supported state.
 */
@property (nonatomic, readonly) BOOL oobRetrievalSupported;

/**
 Value of the Supported URI Scheme Names state.
 Is present only when OOB retrieval is Supported. (Optional)
 */
@property (nonatomic, readonly, strong, nullable) NSData *supportedURISchemeNames;

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
