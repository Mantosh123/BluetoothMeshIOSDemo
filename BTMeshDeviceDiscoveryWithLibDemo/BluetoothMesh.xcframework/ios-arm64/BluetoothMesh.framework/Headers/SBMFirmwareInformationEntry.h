//
//  SBMFirmwareInformationEntry.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 31/03/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareId.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Firmware Information Entry identifies the information for a firmware subsystem on the node from the Firmware Information List state.
 */
@interface SBMFirmwareInformationEntry : NSObject
/**
 Index of the entry in Firmware Information List
 */
@property (nonatomic, readonly) UInt8 index;
/**
 The Firmware ID identifying the firmware image associated with the given index of the entry in the Firmware Information List.
 */
@property (nonatomic, readonly) SBMFirmwareId *currentFirmwareId;
/**
 The URI link used to retrieve an updated firmware file for the node or subsystem.
 */
@property (nonatomic, readonly, nullable) NSString *updateUri;
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
