//
//  SBMOobInformation.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 13/10/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

/*
 Out-of-band information advertised by an unprovisioned device.
 */
typedef NS_OPTIONS(UInt16, SBMOobInformation) {
    /**
     Other.
     */
    SBMOobInformationOther =  1 << 0,
    /**
     Uri.
     */
    SBMOobInformationUri =  1 << 1,
    /**
     Two Dimensional Code.
     */
    SBMOobInformationTwoDimensionalCode =  1 << 2,
    /**
     Bar Code.
     */
    SBMOobInformationBarCode = 1 << 3,
    /**
     Nfc.
     */
    SBMOobInformationNfc = 1 << 4,
    /**
     Number.
     */
    SBMOobInformationNumber = 1 << 5,
    /**
     String.
     */
    SBMOobInformationString = 1 << 6,
    /**
     Certificate Based Provisioning.
     */
    SBMOobInformationCertificateBasedProvisioning = 1 << 7,
    /**
     ProvisioningRecords.
     */
    SBMOobInformationProvisioningRecords = 1 << 8,
    /**
     On Box.
     */
    SBMOobInformationOnBox = 1 << 11,
    /**
     Inside Box.
     */
    SBMOobInformationInsideBox = 1 << 12,
    /**
     On Paper.
     */
    SBMOobInformationOnPaper = 1 << 13,
    /**
     Inside Manual.
     */
    SBMOobInformationInsideManual = 1 << 14,
    /**
     On Device.
     */
    SBMOobInformationOnDevice = 1 << 15
};
