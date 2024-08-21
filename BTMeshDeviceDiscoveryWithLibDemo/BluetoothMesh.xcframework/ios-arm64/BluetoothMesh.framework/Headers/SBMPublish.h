//
//  SBMPublish.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 03/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMAddress.h"
#import "SBMGroup.h"
#import "SBMRetransmit.h"
#import "SBMCredentialsType.h"
#import "SBMPublishPeriod.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Parameters that define how the messages are published by a mesh model.
 */
@interface SBMPublish : NSObject

/**
 Publication address for the model.
 */
@property (nonatomic, readonly) SBMAddress* address;

/**
 Number from 0 to 127 representing TTL value for published message or integer with
 value 255 that indicates that the node's default TTL is used for the publication.
 */


/**
 Raw value of publish period.
 
 @discussion This property is stored into database and is using in the import/export operations.
 To decode that value use property publishPeriod which returns SBMPublishPeriod object which contains values of step resolution (2 bits) and a number of steps (6 bits) that were used in the period byte.
 
 @see publishPeriod property of this object and definition of SBMPublishPeriod class.
 */
@property (nonatomic, readonly) UInt32 period;



@property (nonatomic, readonly) UInt8 TTL;

/**
 Publish period object.
 
 @discussion Stores decoded raw value of the period. It means that you can get from its - step resolution and a number of steps used to create a raw value period byte. Contains also a publish period value in milliseconds.
 
 @see Definition of SBMPublishPeriod object and period property of this object.
 */
@property (nonatomic, readonly) SBMPublishPeriod* publishPeriod;

/**
 SBMCredentialsType representing whether master security materials (0) or friendship security materials (1) are used.
 */
@property (nonatomic, readonly) SBMCredentialsType credentials;

/**
 Describes number of times a message is published and the interval between
 retransmissions of the published messages
 */
@property (nonatomic, readonly) SBMRetransmit *retransmit;

/**
  Index of application key used to encrypt publication.
 */
@property (nonatomic, readonly) UInt16 appKeyIndex;

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
