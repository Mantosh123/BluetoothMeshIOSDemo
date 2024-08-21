//
//  SBMSceneRecall.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 12/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMSceneControlRequest.h"
#import "SBMSceneMessageFlags.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Message used to recall the current state of an element from a previously stored scene.
 */
@interface SBMSceneRecall : NSObject<SBMSceneControlRequest>

/**
 Scene to be recalled for node.
 */
@property (nonatomic) UInt16 sceneNumber;

/**
 Transaction Identifier.
 */
@property (nonatomic) UInt8 transactionId;

/**
 Transition Time, 32-bit value (optional).
 Amount of time (in milliseconds) allotted for the transition to take place.
 */
@property (nonatomic, nullable) NSNumber *transitionTime;

/**
 Message execution delay in milliseconds, 32-bit value. It shall be set if Transition Time is set. Otherwise shall not.
 */
@property (nonatomic, nullable) NSNumber *delay;

/**
 Not available.
 Use initWithFlags:sceneNumber:transactionId:transitionTime:delay: or initWithFlags:scene:transactionId: instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available.
 Use initWithFlags:sceneNumber:transactionId:transitionTime:delay: or initWithFlags:scene:transactionId: instead.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize new Scene recall request object.
 
 @param flags Message flags to be used for this message
 @param scene Scene to be recalled for node.
 @param transactionId Transaction Identifier value
 */
- (instancetype)initWithFlags:(SBMSceneMessageFlags *)flags
                        scene:(UInt16)scene
                transactionId:(UInt8)transactionId;

/**
 Initialize new Scene recall request object.
 
 @param flags Message flags to be used for this message
 @param scene Scene to be recalled for node. To create SBMScene use createSceneWithName method from SBMNetwork. Already creaded scenes can be found in the array of scenes in the SBMNetwork.
 @param transactionId Transaction Identifier value
 @param transitionTime Transition Time value
 @param delay Message execution delay in 5 millisecond steps value
 */
- (instancetype)initWithFlags:(SBMSceneMessageFlags *)flags
                        scene:(UInt16)scene
                transactionId:(UInt8)transactionId
               transitionTime:(UInt32)transitionTime
                        delay:(UInt32)delay;

@end
NS_ASSUME_NONNULL_END
