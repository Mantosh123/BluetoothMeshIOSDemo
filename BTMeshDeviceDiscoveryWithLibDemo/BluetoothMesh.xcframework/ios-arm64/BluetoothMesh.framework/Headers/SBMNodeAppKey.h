//
//  SBMNodeAppKey.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 02/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMApplicationKey.h"

NS_ASSUME_NONNULL_BEGIN

/**
 State of a application key distributed to a mesh node.
 */
@interface SBMNodeAppKey : NSObject

/**
 Application key index of the Node.
 */
@property (nonatomic, readonly) UInt16 appKey;

/**
 Property contains a Boolean value that is set to 'false', unless a Key Refresh procedure
 is in progress and the application key has been successfully updated.
*/
@property (nonatomic, readonly) BOOL isUpdated;

@end

NS_ASSUME_NONNULL_END
