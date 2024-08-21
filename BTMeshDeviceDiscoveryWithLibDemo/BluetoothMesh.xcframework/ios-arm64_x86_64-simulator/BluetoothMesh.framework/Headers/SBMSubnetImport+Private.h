//
//  SBMSubnetImport+Private.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import "SBMImportObject.h"
#import "SBMSubnetImport.h"
@class SBMNetwork;
@class SBMSubnet;
@class SBMNetKeyImport;

NS_ASSUME_NONNULL_BEGIN

@interface SBMSubnetImport (Private) <SBMImportObject>

@property (nonatomic, readonly, nullable) SBMSubnet *subnet;

- (instancetype)initWithNetKey:(SBMNetKeyImport *)netKey;
- (BOOL)importToNetwork:(SBMNetwork *)network error:(NSError* _Nullable*)error;

@end

NS_ASSUME_NONNULL_END
