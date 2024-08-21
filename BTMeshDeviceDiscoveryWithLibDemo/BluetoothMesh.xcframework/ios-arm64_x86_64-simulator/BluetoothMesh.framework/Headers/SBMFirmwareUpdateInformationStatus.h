//
//  SBMFirmwareInformationStatus.h
//  BluetoothMesh
//
//  Created by Hubert Drogosz on 31/03/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMFirmwareInformationEntry.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Response sent by a Firmware Update server.
 @see SBMFirmwareUpdate
 @see SBMFirmwareUpdateHandler
 
 Reports information about firmware images installed on a node.
 */
@interface SBMFirmwareUpdateInformationStatus : NSObject

/**
 Total number of firmwares installed on the node, size of the Firmware Information List.
 */
@property (nonatomic, readonly) UInt8 totalCount;

/**
 Reported entries from the Firmware Information List state.
 */
@property (nonatomic, readonly) NSArray<SBMFirmwareInformationEntry *> *reportedEntries;

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
