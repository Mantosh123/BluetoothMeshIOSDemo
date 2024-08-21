//
//  SBMIvIndexControl.h
//  BluetoothMesh
//
//  Created by Kamil Czajka on 19/10/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMIvUpdateHandler.h"
#import "SBMIvIndexRecoveryNeededHandler.h"

NS_ASSUME_NONNULL_BEGIN

/**
  Controller for IV Index.
*/
@interface SBMIvIndexControl: NSObject

/**
  Creates IV Index Controller
*/
- (instancetype)init;

/**
 Sets IV Index recovery mode state.
 
 Requests an IV Index recovery procedure from the stack or cancels a request. The procedure can be used when device has not been connected to the network for some time and it may have missed IV Index updates.
 After the recovery mode is enabled, it is automatically disabled once a successful IV Index recovery is completed.

 @param enabled IV Index recovery mode state to switch to.
 @param error Error from the Bluetooth Mesh stack which occurred during enabling/disabling recovery mode.
 @return Whether the request was successful.
 */
- (BOOL)setRecoveryModeEnabled:(BOOL)enabled error:(NSError * _Nullable *)error;

/**
 Gets IV Index recovery mode state.

 @return Whether IV Index recovery mode is enabled.
 @see setRecoveryModeEnabled:error:
 */
- (BOOL)isRecoveryModeEnabled;

/**
 Sets the current IV Index of the network.

 @param ivIndex IV Index value to use.
 @param error Error from the Bluetooth Mesh stack which occured during setting value.
 @return Whether the request was successful.
 */
- (BOOL)setValue:(UInt32)ivIndex error:(NSError* _Nullable *)error;

/**
  Gets the current IV index of the network.

  @return IV index value.
*/
- (UInt32)getValue;

/**
  Sets IV Index update test mode state.

  @discussion The test mode removes the 96-hour limit for changing the IV Update procedure state and leaves all other behavior of the device unchanged.

  @param enabled IV Index upate test mode state to switch to.
  @param error Error from the Bluetooth Mesh stack which occured during enabling/disabling test mode.
  @return Whether the request was successful.
*/
- (BOOL)setUpdateTestModeEnabled:(BOOL)enabled error:(NSError * _Nullable *)error;

/**
 Gets IV Index update test mode state.

 @return Whether the test mode is enabled.
 @see setUpdateTestModeEnabled:error:
 */
- (BOOL)isUpdateTestModeEnabled;

/**
 Requests an IV index update in the network.
 The request may fail for the following reasons:
    - IV index update is already ongoing
    - not enough time has passed since the previous update
    - a node is not a member of the primary subnet (subnet with NetKey at index 0x000)
    - a node is not sending secure network beacons
 To receive the state of the IV Update procedures, the handler must be set with setUpdateHandler.

 @param error Error from the Bluetooth Mesh stack which occurred during requesting update.
 @return Whether the request was successful.
 */
- (BOOL)requestUpdate:(NSError * _Nullable *)error;

/**
   Changes the handler for IV Update event.
   By default, the handler does nothing.

   @param handler Action that will occure when IV Update procedure transitions to a new state.
*/
- (void)setUpdateHandler:(nullable SBMIvUpdateHandler)handler;

/**
 Changes the handler for IV Index Recovery needed event.
 This handler is called when IV Index network is too far from the expected value, which may
 happen if the device has been powered off or away from the network for a long period of time.
 By default, the handler enables recovery mode with setRecoveryModeEnabled.

 @param handler Action that will occure when it is reported that IV Index recovery is needed.
 */
- (void)setRecoveryNeededHandler:(nullable SBMIvIndexRecoveryNeededHandler)handler;

/**
 Not available..
*/
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

