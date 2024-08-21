//
//  SBMAdvertisingDataType.h
//  BluetoothMesh
//
//  Created by Denis Lyakhov on 29/08/2022.
//  Copyright © 2022 Silicon Labs, http://www.silabs.com. All rights reserved.
//

typedef NS_ENUM(UInt8, SBMAdvertisingDataType) {
    /**
     Flags.
     */
    SBMAdvertisingDataTypeFlags = 0x01,
    /**
     Incomplete List of 16-bit Service Class UUIDs.
     */
    SBMAdvertisingDataTypeIncompleteListOf16BitServiceClassUUIDs = 0x02,
    /**
     Complete List of 16-bit Service Class UUIDs.
     */
    SBMAdvertisingDataTypeCompleteListOf16BitServiceClassUUIDs = 0x03,
    /**
     Incomplete List of 32-bit Service Class UUIDs.
     */
    SBMAdvertisingDataTypeIncompleteListOf32BitServiceClassUUIDs = 0x04,
    /**
     Complete List of 32-bit Service Class UUIDs.
     */
    SBMAdvertisingDataTypeCompleteListOf32BitServiceClassUUIDs = 0x05,
    /**
     Incomplete List of 128-bit Service Class UUIDs.
     */
    SBMAdvertisingDataTypeIncompleteListOf128BitServiceClassUUIDs = 0x06,
    /**
     Complete List of 128-bit Service Class UUIDs.
     */
    SBMAdvertisingDataTypeCompleteListOf128BitServiceClassUUIDs = 0x07,
    /**
     Shortened Local Name.
     */
    SBMAdvertisingDataTypeShortenedLocalName = 0x08,
    /**
     Complete Local Name.
     */
    SBMAdvertisingDataTypeCompleteLocalName = 0x09,
    /**
     Tx Power Level.
     */
    SBMAdvertisingDataTypeTxPowerLevel = 0x0A,
    /**
     Class of Device.
     */
    SBMAdvertisingDataTypeClassOfDevice = 0x0D,
    /**
     Simple Pairing Hash C-192.
     */
    SBMAdvertisingDataTypeSimplePairingHashC192 = 0x0E,
    /**
     Simple Pairing Randomizer R-192.
     */
    SBMAdvertisingDataTypeSimplePairingRandomizer192 = 0x0F,
    /**
     Device ID.
     */
    SBMAdvertisingDataTypeDeviceID = 0x10,
    /**
     Security Manager Out of Band Flags.
     */
    SBMAdvertisingDataTypeSecurityManagerOutOfBandFlags = 0x11,
    /**
     Slave Connection Interval Range.
     */
    SBMAdvertisingDataTypeSlaveConnectionIntervalRange = 0x12,
    /**
     List of 16-bit Service Solicitation UUIDs.
     */
    SBMAdvertisingDataTypeListOf16BitServiceSolicitationUUIDs = 0x14,
    /**
     List of 128-bit Service Solicitation UUIDs.
     */
    SBMAdvertisingDataTypeListOf128BitServiceSolicitationUUIDs = 0x15,
    /**
     Service Data - 16-bit UUID.
     */
    SBMAdvertisingDataTypeServiceData16BitUUID = 0x16,
    /**
     Public Target Address.
     */
    SBMAdvertisingDataTypePublicTargetAddress = 0x17,
    /**
     Random Target Address.
     */
    SBMAdvertisingDataTypeRandomTargetAddress = 0x18,
    /**
     Appearance.
     */
    SBMAdvertisingDataTypeAppearance = 0x19,
    /**
     Advertising Interval.
     */
    SBMAdvertisingDataAdvertisingInterval = 0x1A,
    /**
     LE Bluetooth Device Address.
     */
    SBMAdvertisingDataLEBluetoothDeviceAddress = 0x1B,
    /**
     LE Role.
     */
    SBMAdvertisingDataLERole = 0x1C,
    /**
     Simple Pairing Hash C-256.
     */
    SBMAdvertisingDataSimplePairingHashC256 = 0x1D,
    /**
     Simple Pairing Randomizer R-256.
     */
    SBMAdvertisingDataSimplePairingRandomizerR256 = 0x1E,
    /**
     List of 32-bit Service Solicitation UUIDs.
     */
    SBMAdvertisingDataListOf32BitServiceSolicitationUUIDs = 0x1F,
    /**
     Service Data - 32-bit UUID.
     */
    SBMAdvertisingDataServiceData32BitUUID = 0x20,
    /**
     Service Data - 128-bit UUID.
     */
    SBMAdvertisingDataServiceData128BitUUID = 0x21,
    /**
     LE Secure Connections Confirmation Value.
     */
    SBMAdvertisingDataLESecureConnectionsConfirmationValue = 0x22,
    /**
     LE Secure Connections Random Value.
     */
    SBMAdvertisingDataLESecureConnectionsRandomValue = 0x23,
    /**
     URI.
     */
    SBMAdvertisingDataURI = 0x24,
    /**
     Indoor Positioning.
     */
    SBMAdvertisingDataIndoorPositioning = 0x25,
    /**
     Transport Discovery Data.
     */
    SBMAdvertisingDataTransportDiscoveryData = 0x26,
    /**
     LE Supported Features.
     */
    SBMAdvertisingDataLESupportedFeatures = 0x27,
    /**
     Channel Map Update Indication.
     */
    SBMAdvertisingDataChannelMapUpdateIndication = 0x28,
    /**
     Provisioning Bearer Advertising.
     */
    SBMAdvertisingDataProvisioningBearerAdvertising = 0x29,
    /**
     Mesh Message.
     */
    SBMAdvertisingDataMeshMessage = 0x2A,
    /**
     Mesh Beacon.
     */
    SBMAdvertisingDataMeshBeacon = 0x2B,
    /**
     BIGInfo.
     */
    SBMAdvertisingDataBIGInfo = 0x2C,
    /**
     Broadcast_Code.
     */
    SBMAdvertisingDataBroadcastCode = 0x2D,
    /**
     Resolvable Set Identifier
     */
    SBMAdvertisingDataResolvableSetIdentifier = 0x2E,
    /**
     Advertising Interval - long.
     */
    SBMAdvertisingDataAdvertisingIntervalLong = 0x2F,
    /**
     Broadcast_Name.
     */
    SBMAdvertisingDataBroadcastName = 0x30,
    /**
     3D Information Data.
     */
    SBMAdvertisingData3DInformationData = 0x3D,
    /**
     Manufacturer Specific Data.
     */
    SBMAdvertisingDataManufacturerSpecificData = 0xFF
};
