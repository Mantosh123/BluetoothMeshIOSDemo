//
//  SBMGenericOnOff.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 23/10/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"
#import "SBMControlValueSetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Possible states of Generic OnOff functionality.
 */
typedef NS_ENUM(NSInteger, SBMGenericOnOffState) {
    /** Value that represents off state of an element. */
    SBMGenericOnOffStateOff,
    /** Value that represents on state of an element. */
    SBMGenericOnOffStateOn,
    /** Value that represents unknown state, used when object is a set request. */
    SBMGenericOnOffStateUnknown,
};

/**
 Generic OnOff functionality object. It represents the state of an element. The meaning of the state is determined by the model.
 */
@interface SBMGenericOnOff : NSObject<SBMControlValueGetSigModel, SBMControlValueSetSigModel>

/**
 State of Generic OnOff functionality.
 */
@property (nonatomic, readonly) SBMGenericOnOffState onOffState;

/**
 Target state of Generic OnOff functionality.
 This property is valid only if remainingTime property is not nil.
 */
@property (nonatomic, readonly) SBMGenericOnOffState targetOnOffState;

/**
 Indicates the time it will take the element to complete the transition to the target state.
 This property is nil if used as set request or no transition is in progress.
 */
@property (nonatomic, readonly, nullable) NSNumber *remainingTime;

/**
 Initialize new set request for Generic OnOff functionality.

 @param onOffState OnOff state that functionality should be initialized with.
 @return An initialized Generic OnOff functionality object, or nil if an object could not be created.
 */
- (instancetype)initWithOnOffState:(SBMGenericOnOffState)onOffState;

/**
 Not available. Use initWithOnOffState instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithOnOffState instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
