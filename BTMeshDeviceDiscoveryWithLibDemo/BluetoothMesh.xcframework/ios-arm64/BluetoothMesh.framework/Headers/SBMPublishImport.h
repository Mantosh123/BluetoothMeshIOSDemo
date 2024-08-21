//
//  SBMPublishImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SBMAddressImport.h"
#import "SBMRetransmitImport.h"
#import "SBMCredentialsType.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Parameters that define how the messages are published by a mesh model.
 */
@interface SBMPublishImport : NSObject

/**
 Publication address for the model.
 */
@property (nonatomic, readonly) SBMAddressImport* address;

/**
 Number from 0 to 127 representing TTL value for published message or integer with
 value 255 that indicates that the node's default TTL is used for the publication.
 */
@property (nonatomic, readwrite) UInt8 TTL;

/**
 Interval between subsequent publications in milliseconds. 0 means that periodic publication is disabled.
 */
@property (nonatomic, readwrite) UInt32 period;

/**
 SBMCredentialsType representing whether master security materials (0) or friendship security materials (1) are used.
 */
@property (nonatomic, readwrite) SBMCredentialsType credentials;

/**
 Describes number of times a message is published and the interval between
 retransmissions of the published messages
 */
@property (nonatomic, readonly) SBMRetransmitImport *retransmit;

/**
 Index of application key used to encrypt publication.
*/
@property (nonatomic, readonly) UInt16 appKeyIndex;

/**
 Creates and sets Retransmit object with count and interval
 @param count Count of created interval
 @param interval Interval of created interval
 @return Created object
 */
- (SBMRetransmitImport*)createRetransmitWithCount:(NSInteger)count interval:(NSInteger)interval;

/**
 Creates and sets address with provided address value
 @param address Address value of created object
 @return Created object
 */
- (SBMAddressImport*)createAddress:(UInt32)address;

/**
 Created and sets address with provided virtual address value
 @param virtualAddress Virtual address value of created object
 @return Created object
 */
- (SBMAddressImport*)createAddressWithVirtualAddress:(NSData*)virtualAddress;

/**
 Not available.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
