//
//  SBMScheduleRegisterScene.h
//  BluetoothMesh
//
//  Created by Michał Barnaś on 21/05/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enum that defines scene number to recall on occurence of event.
 Value of SBMScheduleRegisterSceneNone means no scene is set or other action than scene recall was set.
 Otherwise, value of specific scene number must be set.
*/
typedef NS_ENUM(UInt16, SBMScheduleRegisterSceneEnum) {
    SBMScheduleRegisterSceneNone = 0x00,
    SBMScheduleRegisterSceneSpecific = 0x01
};

NS_ASSUME_NONNULL_BEGIN

/**
 Object encapsulating scene property in schedule register
*/
@interface SBMScheduleRegisterScene : NSObject

/**
 Raw value as specified in Bluetooth Mesh specification
*/
@property (nonatomic, readonly) UInt16 rawValue;

/**
 Initializes object with specific scene number.
 @param scene specific scene number
 @return initialized object
*/
- (instancetype)initWithSpecific:(UInt16)scene;

/**
 Initializes object with predefined scene value
 @param scene predefined value. predefined value from SBMScheduleRegisterSceneEnum. To set specific scene number, initWithSpecific should be used.
        Using SBMScheduleRegisterSceneSpecific in this init will result in the same behaviour as passing value of 1 to initWithSpecific. This means using scene with number of 1.
 @return initialized object
*/
- (instancetype)initWith:(SBMScheduleRegisterSceneEnum)scene;

/**
 Function that returns interpreted raw value.
 Based on raw value, this function returns enum that informs if specific scene number or no scene is set.
*/
- (SBMScheduleRegisterSceneEnum)getEnum;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
