//
//  SBMNodeAppKeyImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 State of a application key distributed to a mesh node.
 */
@interface SBMNodeAppKeyImport : NSObject

/**
 Application key index of the Node.
 */
@property (nonatomic, readonly) NSInteger index;

/**
 Property contains a Boolean value that is set to 'false', unless a Key Refresh procedure
 is in progress and the application key has been successfully updated.
 */
@property (nonatomic, readonly) BOOL updated;


/**
 Not available. Use SBMNodeSecurity createNodeAppKeyWithIndex:isUpdated:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMNodeSecurity createNodeAppKeyWithIndex:isUpdated:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
