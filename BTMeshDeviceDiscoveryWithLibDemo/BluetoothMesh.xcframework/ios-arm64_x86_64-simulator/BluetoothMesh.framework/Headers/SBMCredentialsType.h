//
//  SBMCredentialsType.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 08/11/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 Type of security materials.
 */
typedef NS_ENUM (NSUInteger, SBMCredentialsType) {
    
    /**
     Master Security materials are used
     */
    SBMCredentialsTypeMasterSecurityMaterials,
    
    /**
     Friendship Security materials are used
     */
    SBMCredentialsTypeFriendshipSecurityMaterials,
    
    /**
     Security materials not defined
     */
    SBMCredentialsTypeNotDefined
};

