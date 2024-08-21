//
//  SBMProvisionerOOBEnums.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 23/11/2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Possible results of OOB operations.
 */
typedef NS_ENUM(NSUInteger, SBMProvisionerOOBResult) {
    /** OOB operation finished with success. */
    SBMProvisionerOOBResultSuccess = 0,
    /** OOB operation finished with error. */
    SBMProvisionerOOBResultError,
};
