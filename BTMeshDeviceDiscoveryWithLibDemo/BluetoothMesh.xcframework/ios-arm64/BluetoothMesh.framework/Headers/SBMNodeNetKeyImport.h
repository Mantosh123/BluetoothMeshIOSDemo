//
//  SBMNodeNetKeyImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * State of a network key distributed to a mesh node.
 */
@interface SBMNodeNetKeyImport : NSObject

/**
 Network key index of the Node.
 */
@property (nonatomic, readonly) NSInteger index;

/**
 Property contains a BOOL value that is set to 'false', unless a Key Refresh procedure
 is in progress and the network key has been successfully updated.
 */
@property (nonatomic, readonly) BOOL updated;

/**
 Not available. Use SBMNodeSecurity createNodeNetKeyWithIndex:isUpdated:
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMNodeSecurity createNodeNetKeyWithIndex:isUpdated:
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
