//
//  SBMSilabsConfigurationStatusCode.h
//  BluetoothMesh
//
//  Created by Krystian Kokoszka on 19/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/**
 Status codes for responses of the Silabs Configuration Server vendor model.
 @see SBMAdvertisementExtension
 */
typedef NS_ENUM(NSInteger, SBMSilabsConfigurationStatusCode) {
    /**
     The message was processed successfully.
     */
    SBMSilabsConfigurationStatusCodeSuccess,
    /**
     Internal use only. Should not be encountered.
     */
    SBMSilabsConfigurationStatusCodeUnknownCommand,
    /**
     The server received an invalid parameter.
     */
    SBMSilabsConfigurationStatusCodeInvalidParameter,
    /**
     An object (e.g. model) does not exist on the target.
     */
    SBMSilabsConfigurationStatusCodeDoesNotExist
};
