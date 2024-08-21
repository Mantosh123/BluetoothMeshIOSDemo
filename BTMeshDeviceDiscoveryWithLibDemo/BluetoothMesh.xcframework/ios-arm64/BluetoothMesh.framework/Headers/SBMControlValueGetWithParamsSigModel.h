//
//  SBMControlValueGetWithParamsSigModel.h
//  BluetoothMesh
//
//  Created by Michal Barnas on 23/01/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import "SBMControlValueGetSigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Every request which can be used to get state of Generic Property and requires parameters must conforms to this protocol.
*/
@protocol SBMControlValueGetWithParamsSigModel <SBMControlValueGetSigModel>

@property (nonatomic, readonly) UInt16 identifier;

@end

NS_ASSUME_NONNULL_END
