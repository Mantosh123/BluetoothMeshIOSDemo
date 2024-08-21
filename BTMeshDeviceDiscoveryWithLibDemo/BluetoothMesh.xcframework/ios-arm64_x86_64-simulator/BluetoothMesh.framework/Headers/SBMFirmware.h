//
//  SBMFirmware.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 17/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMFirmwareId.h"
#import "SBMBlob.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Object that represents the firmware image.
 */
@interface SBMFirmware : NSObject

/**
 Identifier of the firmware image.
 */
@property (nonatomic, readonly, strong) SBMFirmwareId* identifier;

/**
 BLOB to be transferred during firmware image upload.
 */
@property (nonatomic, readonly, strong) SBMBlob* blob;

/**
 Custom data from the firmware vendor that will be used to check whether the firmware image can be updated.
 */
@property (nonatomic, readonly, strong, nullable) NSData* metadata;

/**
 Initializer for SBMFirmware class
 
 @param identifier  Identifier of the firmware image.
 @param blob  BLOB to be transferred during firmware image upload.
 @param metadata Custom data from the firmware vendor that will be used to check whether the firmware image can be updated.
 @return SBMFirmware object.
 */
- (instancetype)initWithId:(SBMFirmwareId *)identifier
                      blob:(SBMBlob *)blob
                  metadata:(NSData * _Nullable)metadata;

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
