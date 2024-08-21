//
//  SBMRetransmitImport.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SBMRetransmitImport : NSObject

/**
 Number of retransmissions. Could be from 0 to 7
 */
@property (nonatomic, readonly) NSInteger count;

/**
 Represents the interval in miliseconds between retransmissions. Could be from 50 to 1600
 */
@property (nonatomic, readonly) NSInteger interval;

/**
 Not available. Use SBMPublishImport createRetransmit
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use SBMPublishImport createRetransmit
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
