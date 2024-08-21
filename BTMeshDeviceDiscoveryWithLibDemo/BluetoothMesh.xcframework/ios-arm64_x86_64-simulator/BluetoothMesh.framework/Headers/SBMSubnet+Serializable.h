//
//  SBMSubnet+Serializable.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 03.12.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMJSONSerializable.h"
#import "SBMMeshIdentifiable.h"
#import "SBMSubnet.h"

NS_ASSUME_NONNULL_BEGIN

@interface SBMSubnet(Serializable) <SBMJSONSerializable, SBMMeshIdentifiable>

- (instancetype)initWithNetwork:(SBMNetwork *)network andJSONDictionary:(NSDictionary*)dictionary;
- (NSDictionary*)toJSONDictionary;

@end

NS_ASSUME_NONNULL_END
