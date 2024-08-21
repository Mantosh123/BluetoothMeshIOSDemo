//
//  SBMSubnetSecurity+Serializable.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 25/09/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#ifndef SBMSubnetSecurity_Serializable_h
#define SBMSubnetSecurity_Serializable_h
#import "SBMJSONSerializable.h"

@interface SBMSubnetSecurity(Serializable) <SBMJSONSerializable>

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end
#endif /* SBMSubnetSecurity_Serializable_h */
