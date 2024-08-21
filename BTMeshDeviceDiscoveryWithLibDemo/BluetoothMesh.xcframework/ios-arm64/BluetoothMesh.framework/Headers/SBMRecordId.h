//
//  SBMRecordId.h
//  BluetoothMesh
//
//  Created by Stefan Kwinta on 22/03/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Contains enum definitions for provisioning records
 */
typedef NS_ENUM(UInt16, SBMRecordId) {
    /**
     Certificate-Bbased Provisioning Base URI
     */
    SBMRecordIdURI = 0x0000,
    
    /**
     Device Certificate
     */
    SBMRecordIdDeviceCertificate = 0x0001,
    
    /**
     Intermediate Certificate 1
     */
    SBMRecordIdIntermediateCertificate1 = 0x0002,
    
    /**
     Intermediate Certificate 2
     */
    SBMRecordIdIntermediateCertificate2 = 0x0003,
    
    /**
     Intermediate Certificate 3
     */
    SBMRecordIdIntermediateCertificate3 = 0x0004,
    
    /**
     Intermediate Certificate 4
     */
    SBMRecordIdIntermediateCertificate4 = 0x0005,
    
    /**
     Intermediate Certificate 5
     */
    SBMRecordIdIntermediateCertificate5 = 0x0006,
    
    /**
     Intermediate Certificate 6
     */
    SBMRecordIdIntermediateCertificate6 = 0x0007,
    
    /**
     Intermediate Certificate 7
     */
    SBMRecordIdIntermediateCertificate7 = 0x0008,
    
    /**
     Intermediate Certificate 8
     */
    SBMRecordIdIntermediateCertificate8 = 0x0009,
    
    /**
     Intermediate Certificate 9
     */
    SBMRecordIdIntermediateCertificate9 = 0x000A,
    
    /**
     Intermediate Certificate 10
     */
    SBMRecordIdIntermediateCertificate10 = 0x000B,
    
    /**
     Intermediate Certificate 11
     */
    SBMRecordIdIntermediateCertificate11 = 0x000C,
    
    /**
     Intermediate Certificate 12
     */
    SBMRecordIdIntermediateCertificate12 = 0x000D,
    
    /**
     Intermediate Certificate 13
     */
    SBMRecordIdIntermediateCertificate13 = 0x000E,
    
    /**
     Intermediate Certificate 14
     */
    SBMRecordIdIntermediateCertificate14 = 0x000F,
    
    /**
     Intermediate Certificate 15
     */
    SBMRecordIdIntermediateCertificate15 = 0x0010,
    
    /**
     Complete Local Name
     */
    SBMRecordIdCompleteLocalName = 0x0011,
    
    /**
     Appearance
     */
    SBMRecordIdAppearance = 0x0012,
};

NS_ASSUME_NONNULL_END
