//
//  SBMConfigurationControlSettings.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 12/06/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Global settings for requests sent via SBMConfigurationControl.
*/

@interface SBMConfigurationControlSettings : NSObject

/**
Set default timeout for Low Power node configuration requests.

@param milliseconds Default timeout in milliseconds
*/
- (void)setLpnLocalTimeout:(UInt32)milliseconds;

/**
Get default timeout for Low Power node configuration requests.
Default timeout in library: 120000ms

@return UInt32 Default timeout in milliseconds.
*/
- (UInt32)getLpnLocalTimeout;

@end

NS_ASSUME_NONNULL_END
