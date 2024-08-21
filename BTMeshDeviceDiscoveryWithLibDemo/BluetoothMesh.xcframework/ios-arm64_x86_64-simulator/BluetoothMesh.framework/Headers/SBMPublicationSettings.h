//
//  SBMPublicationSettings.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 21/11/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMNode.h"
#import "SBMGroup.h"
#import "SBMPublishPeriod.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object that represents publication settings.
 */
@interface SBMPublicationSettings : NSObject<NSCopying>

/**
 An address used for publication.
 */
@property (nonatomic, strong, readonly) SBMAddress *address;

/**
 Index of application key used to encrypt publication.
 */
@property (nonatomic, readonly) UInt16 appKeyIndex;

/**
 An integer value that determines the raw value of the publication period.
 
 @discussion The raw value of the period byte contains bits for fields step resolution (2 bits) and a number of steps (6 bits).
 Using setPeriodWith: method, the raw value of the period is calculated internally and inserted into the period property of this object depends on the given values of step resolution and number of steps.
 
 @see Method setPeriodWith: and definition of SBMPublishPeriod class.
 */
@property (nonatomic) NSInteger period;

/**
 A boolean value that determines whether model should publish using friendship credentials flag on or off.
 */
@property (nonatomic) BOOL isFriendshipCredential;

/**
 An integer value that determines publication time to live.
 Default value is 0xFF which makes publications use node's default TTL.
 */
@property (nonatomic) NSInteger ttl;

/**
 An integer value that determines retransmission count.
 */
@property (nonatomic) NSInteger retransmitCount;

/**
 An integer value that determines retransmission interval.
 */
@property (nonatomic) NSInteger retransmitIntervalSteps;

/**
 Initialize publication settings object with specified node.

 @param node Node object used for publication.
 @param appKeyIndex Index of application key used to encrypt publication.
 @return Initialized publication settings object, or nil if an object could not be created for some reason that would not result in an exception.
 */
- (instancetype)initWithNode:(SBMNode*)node appKeyIndex:(NSInteger)appKeyIndex;

/**
 Initialize publication settings object with specified group.

 @param group Group object used for publication.
 @param appKeyIndex Index of application key used to encrypt publication.
 @return Initialized publication settings object, or nil if an object could not be created for some reason that would not result in an exception.
 */
- (instancetype)initWithGroup:(SBMGroup*)group appKeyIndex:(NSInteger)appKeyIndex;

/**
 Initialize publication settings object with local address.
 
 @param appKeyIndex Index of application key used to encrypt publication.
 @return Initialized publication settings object, or nil if an object could not be created for some reason that would not result in an exception.
*/
- (instancetype)initWithLocalAddressAndAppKeyIndex:(NSInteger)appKeyIndex;

/**
 Calculates internally a raw value of period and sets the result of that calculation into the period property.
 
 @see Definition of SBMPublishPeriod class and property period from here.
 */
- (void)setPeriodWith:(SBMPublishPeriod*)publishPeriod;

/**
 Unavailable. Use initWithNode appKeyIndex, initWithGroup appKeyIndex, initWithVirtualAddress appKeyIndex or initWithLocalAddressAndAppKeyIndex instead
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Unavailable. Use initWithNode appKeyIndex, initWithGroup appKeyIndex, initWithVirtualAddress appKeyIndex or initWithLocalAddressAndAppKeyIndex instead
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
