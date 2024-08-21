//
//  SBMBlob.h
//  BluetoothMesh
//
//  Created by Vasyl Haievyi on 12/01/2021.
//  Copyright © 2021 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Class representing Blob to be transferred.
 */
@interface SBMBlob : NSObject

/**
 Unique Blob identifier.
 */
@property (nonatomic, readwrite) NSData *identifier;

/**
 Data that will be transferred during the Blob transfer procedure.
 */
@property (nonatomic, readonly) NSData *data;

/**
 Initializer method for SBMBlob.
 Unique Blob identifier is generated automatically.
 
 @param data Data that will be transferred during the Blob transfer procedure.
 @return initialized SBMBlob object.
 */
- (instancetype)initWithData:(NSData *)data;

/**
 Generate new random identifier for this object.
 */
- (void)updateIdentifier;

/**
 Not available. Use initWithIdentifier:data instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithIdentifier:data instead.
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
