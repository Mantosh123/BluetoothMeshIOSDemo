//
//  SBMSubnetSecurityImport+Private.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import "SBMSubnetSecurityImport.h"
#import "SBMImportObject.h"
@class SBMSubnet;

NS_ASSUME_NONNULL_BEGIN

@interface SBMSubnetSecurityImport (Private) <SBMImportObject>

- (instancetype)initWithKeyPhase:(UInt8)keyPhase andTimestamp:(NSInteger)timestamp;
- (BOOL)importToSubnet:(SBMSubnet*)subnet error:(NSError**)error;

@end

NS_ASSUME_NONNULL_END
