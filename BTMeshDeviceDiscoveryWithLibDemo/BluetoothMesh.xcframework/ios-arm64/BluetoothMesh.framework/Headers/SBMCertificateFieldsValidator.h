//
//  SBMCertificateFieldsValidator.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 15/02/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Object used but not mandatory for Certificate-Based Provisioning.
 */
@interface SBMCertificateFieldsValidator : NSObject

/**
 Method used to check validity of device certificate's fields in accordance to Certificate-Based Provisioning.

 @param certificate Device certificate meant for Certificate-Based Provisioning.
 @param device Device associated with the parsed certificate,
 @return Set of Errors describing all invalid fields encountered in the device certificate.
 */
- (NSSet<NSError *> *)parse:(NSData *)certificate from:(id<SBMDevice>)device;

@end

NS_ASSUME_NONNULL_END
