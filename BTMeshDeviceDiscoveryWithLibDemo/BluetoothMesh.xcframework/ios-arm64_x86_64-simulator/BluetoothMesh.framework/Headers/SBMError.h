//
//  SBMError.h
//  BluetoothMesh
//
//  Created by Maciej Siciarz on 02.06.2020.
//  Copyright © 2020 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSErrorDomain const SBMStackFoundationErrorDomain;
extern NSErrorDomain const SBMStackErrorDomain;
extern NSErrorDomain const SBMErrorDomain;
extern NSErrorDomain const SBMProvisioningErrorDomain;
extern NSErrorDomain const SBMImportErrorDomain;
extern NSErrorDomain const SBMBlobErrorDomain;
extern NSErrorDomain const SBMCertificateErrorDomain;
extern NSErrorDomain const SBMRemoteProvisioningErrorDomain;

#pragma mark SBMStackFoundationError
/**
 Error type for errors that occur on foundation level of C stack.
 */
typedef NS_ERROR_ENUM(SBMStackFoundationErrorDomain, SBMStackFoundationError) {
    /** Invalid address parameter */
    SBMStackFoundationErrorInvalidAddress = 1,
    /** Invalid model parameter */
    SBMStackFoundationErrorInvalidModel = 2,
    /** Invalid application key parameter */
    SBMStackFoundationErrorInvalidAppKey = 3,
    /** Invalid network key parameter */
    SBMStackFoundationErrorInvalidNetKey = 4,
    /** Server model is out of resources */
    SBMStackFoundationErrorInsufficientResources = 5,
    /** Key already exists */
    SBMStackFoundationErrorKeyIndexExists = 6,
    /** Invalid publish parameter */
    SBMStackFoundationErrorInvalidPublishParams = 7,
    /** Model does not support subscriptions */
    SBMStackFoundationErrorNotSubscribeModel = 8,
    /** Server model could not update its state to persistent storage */
    SBMStackFoundationErrorStorageFailure = 9,
    /** Operation not supported by the server model */
    SBMStackFoundationErrorNotSupported = 10,
    /** State cannot be updated */
    SBMStackFoundationErrorCannotUpdate = 11,
    /** State cannot be removed */
    SBMStackFoundationErrorCannotRemove = 12,
    /** Model and application key cannot be bound */
    SBMStackFoundationErrorCannotBind = 13,
    /** Temporary error */
    SBMStackFoundationErrorTemporarilyUnable = 14,
    /** State cannot be set */
    SBMStackFoundationErrorCannotSet = 15,
    /** Unspecified error */
    SBMStackFoundationErrorUnspecified = 16,
    /** Invalid binding parameter */
    SBMStackFoundationErrorInvalidBinding = 17,
    /** Request timeout */
    SBMStackFoundationErrorTimeout = 254,
    /** Invalid request; do not reply */
    SBMStackFoundationErrorDropReply = 255,
};

#pragma mark SBMStackError
/**
 Error type for errors that occur in C stack.
 */
typedef NS_ERROR_ENUM(SBMStackErrorDomain, SBMStackError) {
    SBMStackErrorHardwarePsStoreFull = 1051,
    SBMStackErrorHardwarePsKeyNotFound = 1052,
    SBMStackErrorInvalidConnHandle = 37,
    SBMStackErrorWaitingResponse = 5,
    SBMStackErrorInvalidParam = 33,
    SBMStackErrorWrongState = 2,
    SBMStackErrorOutOfMemory = 26,
    SBMStackErrorNotImplemented = 15,
    SBMStackErrorInvalidCommand = 72,
    SBMStackErrorTimeout = 7,
    SBMStackErrorGattConnectionTimeout = 7,
    SBMStackErrorAlreadyExists = 46,
    SBMStackErrorInvalidKey = 41,
    SBMStackErrorCommandTooLong = 73,
    SBMStackErrorOutOfBonds = 1026,
    SBMStackErrorUnspecified = 1027,
    SBMStackErrorHardware = 1028,
    SBMStackErrorBuffersFull = 28,
    SBMStackErrorNotSupported = 15,
    SBMStackErrorNoBonding = 1030,
    SBMStackErrorCrypto = 1031,
    SBMStackErrorDataCorrupted = 1032,
    SBMStackErrorCommandIncomplete = 74,
    SBMStackErrorNotInitialized = 17,
    SBMStackErrorInvalidSyncHandle = 1034,
    SBMStackErrorInvalidModuleAction = 1035,
    SBMStackErrorRadio = 1036,
    SBMStackErrorApplicationMismatchedOrInsufficientSecurity = 1053,
    SBMStackErrorApplicationEncryptionDecryptionError = 1054,
    SBMStackErrorSmpPasskeyEntryFailed = 4609,
    SBMStackErrorSmpOobNotAvailable = 4610,
    SBMStackErrorSmpAuthenticationRequirements = 4611,
    SBMStackErrorSmpConfirmValueFailed = 4612,
    SBMStackErrorSmpPairingNotSupported = 4613,
    SBMStackErrorSmpEncryptionKeySize = 4614,
    SBMStackErrorSmpCommandNotSupported = 4615,
    SBMStackErrorSmpUnspecifiedReason = 4616,
    SBMStackErrorSmpRepeatedAttempts = 4617,
    SBMStackErrorSmpInvalidParameters = 4618,
    SBMStackErrorSmpDhkeyCheckFailed = 4619,
    SBMStackErrorSmpNumericComparisonFailed = 4620,
    SBMStackErrorSmpBredrPairingInProgress = 4621,
    SBMStackErrorSmpCrossTransportKeyDerivationGenerationNotAllowed = 4622,
    SBMStackErrorSmpKeyRejected = 4623,
    SBMStackErrorBtUnknownConnectionIdentifier = 4098,
    SBMStackErrorBtAuthenticationFailure = 4101,
    SBMStackErrorBtPinOrKeyMissing = 4102,
    SBMStackErrorBtMemoryCapacityExceeded = 4103,
    SBMStackErrorBtConnectionTimeout = 4104,
    SBMStackErrorBtConnectionLimitExceeded = 4105,
    SBMStackErrorBtAclConnectionAlreadyExists = 4107,
    SBMStackErrorBtCommandDisallowed = 4108,
    SBMStackErrorBtConnectionRejectedDueToLimitedResources = 4109,
    SBMStackErrorBtConnectionRejectedDueToSecurityReasons = 4110,
    SBMStackErrorBtConnectionRejectedDueToUnacceptableBdAddr = 4111,
    SBMStackErrorBtConnectionAcceptTimeoutExceeded = 4112,
    SBMStackErrorBtUnsupportedFeatureOrParameterValue = 4113,
    SBMStackErrorBtInvalidCommandParameters = 4114,
    SBMStackErrorBtRemoteUserTerminated = 4115,
    SBMStackErrorBtRemoteDeviceTerminatedConnectionDueToLowResources = 4116,
    SBMStackErrorBtRemotePoweringOff = 4117,
    SBMStackErrorBtConnectionTerminatedByLocalHost = 4118,
    SBMStackErrorBtRepeatedAttempts = 4119,
    SBMStackErrorBtPairingNotAllowed = 4120,
    SBMStackErrorBtUnsupportedRemoteFeature = 4122,
    SBMStackErrorBtUnspecifiedError = 4127,
    SBMStackErrorBtLlResponseTimeout = 4130,
    SBMStackErrorBtLlProcedureCollision = 4131,
    SBMStackErrorBtEncryptionModeNotAcceptable = 4133,
    SBMStackErrorBtLinkKeyCannotBeChanged = 4134,
    SBMStackErrorBtInstantPassed = 4136,
    SBMStackErrorBtPairingWithUnitKeyNotSupported = 4137,
    SBMStackErrorBtDifferentTransactionCollision = 4138,
    SBMStackErrorBtChannelAssessmentNotSupported = 4142,
    SBMStackErrorBtInsufficientSecurity = 4143,
    SBMStackErrorBtParameterOutOfMandatoryRange = 4144,
    SBMStackErrorBtSimplePairingNotSupportedByHost = 4151,
    SBMStackErrorBtHostBusyPairing = 4152,
    SBMStackErrorBtConnectionRejectedDueToNoSuitableChannelFound = 4153,
    SBMStackErrorBtControllerBusy = 4154,
    SBMStackErrorBtUnacceptableConnectionInterval = 4155,
    SBMStackErrorBtAdvertisingTimeout = 4156,
    SBMStackErrorBtConnectionTerminatedDueToMicFailure = 4157,
    SBMStackErrorBtConnectionFailedToBeEstablished = 4158,
    SBMStackErrorBtMacConnectionFailed = 4159,
    SBMStackErrorBtCoarseClockAdjustmentRejectedButWillTryToAdjustUsingClockDragging = 4160,
    SBMStackErrorBtUnknownAdvertisingIdentifier = 4162,
    SBMStackErrorBtLimitReached = 4163,
    SBMStackErrorBtOperationCancelledByHost = 4164,
    SBMStackErrorBtPacketTooLong = 4165,
    SBMStackErrorAttInvalidHandle = 4353,
    SBMStackErrorAttReadNotPermitted = 4354,
    SBMStackErrorAttWriteNotPermitted = 4355,
    SBMStackErrorAttInvalidPdu = 4356,
    SBMStackErrorAttInsufficientAuthentication = 4357,
    SBMStackErrorAttRequestNotSupported = 4358,
    SBMStackErrorAttInvalidOffset = 4359,
    SBMStackErrorAttInsufficientAuthorization = 4360,
    SBMStackErrorAttPrepareQueueFull = 4361,
    SBMStackErrorAttAttNotFound = 4362,
    SBMStackErrorAttAttNotLong = 4363,
    SBMStackErrorAttInsufficientEncKeySize = 4364,
    SBMStackErrorAttInvalidAttLength = 4365,
    SBMStackErrorAttUnlikelyError = 4366,
    SBMStackErrorAttInsufficientEncryption = 4367,
    SBMStackErrorAttUnsupportedGroupType = 4368,
    SBMStackErrorAttInsufficientResources = 4369,
    SBMStackErrorAttOutOfSync = 4370,
    SBMStackErrorAttValueNotAllowed = 4371,
    SBMStackErrorAttApplication = 4480,
    SBMStackErrorMeshAlreadyExists = 1281,
    SBMStackErrorMeshDoesNotExist = 1282,
    SBMStackErrorMeshLimitReached = 1283,
    SBMStackErrorMeshInvalidAddress = 1284,
    SBMStackErrorMeshMalformedData = 1285,
    SBMStackErrorMeshAlreadyInitialized = 1286,
    SBMStackErrorMeshNotInitialized = 1287,
    SBMStackErrorMeshNoFriendOffer = 1288,
    SBMStackErrorMeshProvLinkClosed = 1289,
    SBMStackErrorMeshProvInvalidPdu = 1290,
    SBMStackErrorMeshProvInvalidPduFormat = 1291,
    SBMStackErrorMeshProvUnexpectedPdu = 1292,
    SBMStackErrorMeshProvConfirmationFailed = 1293,
    SBMStackErrorMeshProvOutOfResources = 1294,
    SBMStackErrorMeshProvDecryptionFailed = 1295,
    SBMStackErrorMeshProvUnexpectedError = 1296,
    SBMStackErrorMeshProvCannotAssignAddr = 1297,
    SBMStackErrorMeshAddressTemporarilyUnavailable = 1298,
    SBMStackErrorMeshAddressAlreadyUsed = 1299,
    SBMStackErrorMeshPublishNotConfigured = 1300,
    SBMStackErrorMeshAppKeyNotBound = 1301,
    SBMStackErrorMeshNoDataAvailable = 27,
    SBMStackErrorMeshFoundationInvalidAddress = 4865,
    SBMStackErrorMeshFoundationInvalidModel = 4866,
    SBMStackErrorMeshFoundationInvalidAppKey = 4867,
    SBMStackErrorMeshFoundationInvalidNetKey = 4868,
    SBMStackErrorMeshFoundationInsufficientResources = 4869,
    SBMStackErrorMeshFoundationKeyIndexExists = 4870,
    SBMStackErrorMeshFoundationInvalidPublishParams = 4871,
    SBMStackErrorMeshFoundationNotSubscribeModel = 4872,
    SBMStackErrorMeshFoundationStorageFailure = 4873,
    SBMStackErrorMeshFoundationNotSupported = 4874,
    SBMStackErrorMeshFoundationCannotUpdate = 4875,
    SBMStackErrorMeshFoundationCannotRemove = 4876,
    SBMStackErrorMeshFoundationCannotBind = 4877,
    SBMStackErrorMeshFoundationTemporarilyUnable = 4878,
    SBMStackErrorMeshFoundationCannotSet = 4879,
    SBMStackErrorMeshFoundationUnspecified = 4880,
    SBMStackErrorMeshFoundationInvalidBinding = 4881,
    SBMStackErrorFilesystemFileNotFound = 45,
    SBMStackErrorL2capRemoteDisconnected = 1037,
    SBMStackErrorL2capLocalDisconnected = 1038,
    SBMStackErrorL2capCidNotExist = 1039,
    SBMStackErrorL2capLeDisconnected = 1040,
    SBMStackErrorL2capFlowControlViolated = 1042,
    SBMStackErrorL2capFlowControlCreditOverflowed = 1043,
    SBMStackErrorL2capNoFlowControlCredit = 1044,
    SBMStackErrorL2capConnectionRequestTimeout = 1045,
    SBMStackErrorL2capInvalidCid = 1046,
    SBMStackErrorL2capWrongState = 1047,
    SBMStackErrorSecurityImageChecksumError = 70,
};

#pragma mark SBMError
/**
 Error type for generic errors that occur in library.
 */
typedef NS_ERROR_ENUM(SBMErrorDomain, SBMError) {
    /** Operation has timed out and should probably be retried. */
    SBMErrorTimeout = 4000,
    /**
     Creating request failed.
     This can happen if model was not found in element or group to which request is to be sent.
     */
    SBMErrorRequestCreationFailed = 4001,
    /**
     Not all nodes in subnet could successfuly be factory reset.
     Factory reset is considered as successful if we receive response,
     but even if we do not receive response it is possible that node has been reset.
     */
    SBMErrorSubnetRemovalFailed = 4002,
    /** Not all nodes in group could successfully be unbound. */
    SBMErrorGroupRemovalFailed = 4003,
    /** Local vendor model could not be found. */
    SBMErrorLocalVendorModelNotFound = 4004,
    /** Proxy connection could not be estabilished */
    SBMErrorProxyEstabilishmentFailure = 4005,
    /** No available address could be found for group */
    SBMErrorNoAvailableGroupAddress = 4008,
    /** Group address is incorrect */
    SBMErrorIncorrectGroupAddress = 4009,
    /** Given group address is already in use */
    SBMErrorGroupAddressInUse = 4010,
    /** This error can occur when callback was not found when cancelling SBMTask*/
    SBMErrorCallbackNotFound = 4011,
    /** Task has been cancelled */
    SBMErrorTaskCancelled = 4012,
    /** Invalid value for Secure Network Beacon status received from stack */
    SBMErrorInvalidSNBValue = 4013,
    /** Scene number 0x0 is invalid */
    SBMErrorProhibitedSceneNumber = 4014,
    /** Attempt to create scene with already used number was made */
    SBMErrorSceneNumberAlreadyUsed = 4015,
    /** Connection with device has been interrupted. Device needs to be reconnected for further usage. */
    SBMErrorInterruptedConnection = 4016,
    /** Subnet could not be created due to a maximum number of network keys exceeded */
    SBMErrorNetKeyMaxExceeded = 4017,
    /** Group could not be created due to a maximum number of application keys exceeded*/
    SBMErrorAppKeyMaxExceeded = 4018,
    /** Subnet could not be created due to provided netKey already exists */
    SBMErrorNetKeyAlreadyExists = 4019,
};

#pragma mark SBMProvisioningError
/**
 Error type for errors specific to Provisioning process.
 */
typedef NS_ERROR_ENUM(SBMProvisioningErrorDomain, SBMProvisioningError) {
    /** Another provisioning procedure is in progress */
    SBMProvisioningErrorProvisioningInProgress = 4102,
    /** Connection with device could not be estabilished */
    SBMProvisioningErrorCouldNotConnect = 4103,
    /**
     Failure occurred when setting OOB requirements.
     Error causing this failure should be avaialble under NSUnderlyingErrorKey in userInfo dictionary.
     */
    SBMProvisioningErrorOOBRequirementsFailure = 4104,
    /**
     Provisioning of device failed.
     Error causing this failure should be avaialble under NSUnderlyingErrorKey in userInfo dictionary.
     */
    SBMProvisioningErrorProvisioningFailure = 4105,
    /**
     Proxy connection to the node could not be estabilished.
     Error causing this failure should be avaialble under NSUnderlyingErrorKey in userInfo dictionary.
     */
    SBMProvisioningErrorProxyConnectionFailure = 4106,
    /**
     Failure ocurred when retrieving Device Composition Data.
     Error causing this failure should be avaialble under NSUnderlyingErrorKey in userInfo dictionary.
     */
    SBMProvisioningErrorDCDRetrievalFailure = 4107,
    /**
     Failure ocurred when setting proxy.
     Error causing this failure may be avaialble under NSUnderlyingErrorKey in userInfo dictionary.
     */
    SBMProvisioningErrorSetProxyFailure = 4109,
    /**
     Failure ocurred when setting node identity.
     Error causing this failure may be avaialble under NSUnderlyingErrorKey in userInfo dictionary.
     */
    SBMProvisioningErrorSetNodeIdentityFailure = 4110,
    /** Out of band alphanumeric AuthData has invalid format */
    SBMProvisioningErrorOOBInvalidAuthDataFormat = 4112,
};

#pragma mark SBMImportError
/**
 Error type for errors specific to Import process.
 */
typedef NS_ERROR_ENUM(SBMImportErrorDomain, SBMImportError) {
    /** Error occurs when property is detected as null, when it should not be. */
    SBMImportErrorNullProperty = 4201,
    /** Valitaed value is too low */
    SBMImportErrorValueTooLow = 4202,
    /** Validated value is too high */
    SBMImportErrorValueTooHigh = 4203,
    /** Occurs if lowAddress is higher than highAddress */
    SBMImportErrorInvalidAddressRange = 4204,
    /** Property has invalid data length */
    SBMImportErrorInvalidDataLength = 4205,
    /** Property is not of NSData type */
    SBMImportErrorInvalidDataType = 4206,
    /** Device key is used more than one time */
    SBMImportErrorDeviceKeyUsedTooManyTimes = 4207,
    /** Node is being used before being imported (eg when importing scene) */
    SBMImportErrorNodeNotImported = 4208,
    /** Group is being used before being imported (eg when importing model) */
    SBMImportErrorGroupNotImported = 4209,
    /** Application key could not be created. */
    SBMImportErrorNetworkKeyInitFailure = 4210,
    /** Error occurs if node net keys are not the same as net keys in node security */
    SBMImportErrorInvalidNetKeys = 4211,
    /** Application key could not be created. */
    SBMImportErrorApplicationKeyInitFailure = 4212,
    /** Error occurs if node app keys are not the same as app keys in node security */
    SBMImportErrorInvalidAppKeys = 4213,
    /** Node security has to be of defined type. */
    SBMImportErrorUndefinedSecurity = 4214,
    /** Publish object has to have defined credentials */
    SBMImportErrorUndefinedCredentials = 4215,
    /** Key refresh phase has invalid value */
    SBMImportErrorInvalidKeyRefreshPhase = 4216,
};

#pragma mark SBMBlobError
/**
 Error type for errors specific to BLOB transfer process.
 */
typedef NS_ERROR_ENUM(SBMBlobErrorDomain, SBMBlobError) {
    /** The BLOB transfer process has timed out. */
    SBMBlobErrorTimeout = 4300,
    /** The Block number is higher than the total number of blocks indicates */
    SBMBlobErrorInvalidBlockNumber = 4301,
    /** The Block Size is outside of the boundaries specified by the Server's Min and Max Block Size Log capabilities */
    SBMBlobErrorWrongBlockSize = 4302,
    /**
     The chunk size exceeds the size indicated by the Max Chunk Size state, or the number of chunks exceeds the number specified by the Max Total Chunks state.
     */
    SBMBlobErrorWrongChunkSize = 4303,
    /** The operation cannot be performed while the server is in the current phase. */
    SBMBlobErrorInvalidState = 4304,
    /** A parameter in the message is outside of its valid range */
    SBMBlobErrorInvalidParameter = 4305,
    /** The message contains a BLOB ID value that is not expected. */
    SBMBlobErrorWrongObjectId = 4306,
    /** There is not enough space available in memory to receive the BLOB. */
    SBMBlobErrorBlobTooLarge = 4307,
    /** The transfer mode is not supported by the BLOB Transfer Server model. */
    SBMBlobErrorUnsupportedTransferMode = 4308,
    /** An internal error occurred on the node. */
    SBMBlobErrorInternalError = 4309,
    /**
     The requested information cannot be provided while the server is in the current phase.
     Only used in DFU to denote that no MBT status code has been received yet.
     */
    SBMBlobErrorInformationUnavailable = 4310,
    /** A malformed message was received. */
    SBMBlobErrorMalformedMessage = 4311,
    /** An unspecified error occured. */
    SBMBlobErrorNotDefined = 4312,
};

#pragma mark SBMCertificateFieldsValidator
/**
 Error type for errors specific to Certificate Validation process.
 */
typedef NS_ERROR_ENUM(SBMCertificateErrorDomain, SBMCertificateError) {
    /** Provided certificate data could not be parsed */
    SBMCertificateErrorInvalidData = 4401,
    /** Wrong algorithm of signature's public key */
    SBMCertificateErrorSignaturePKAlgorithm = 4402,
    /** Wrong certificate version */
    SBMCertificateErrorVersion = 4403,
    /** Certificate's subject common name does not match device UUID */
    SBMCertificateErrorCommonName = 4404,
    /** Wrong algorithm of subject's public key */
    SBMCertificateErrorSubjectPKAlgorithm = 4405,
    /** Wrong curve of subject's public key */
    SBMCertificateErrorSubjectPKCurve = 4406,
    /** Issuer unique ID should not be present */
    SBMCertificateErrorIssuerUniqueId = 4407,
    /** Subject unique ID should not be present */
    SBMCertificateErrorSubjectUniqueId = 4408,
    /** Key Agreement is not enabled */
    SBMCertificateErrorKeyAgreement = 4409,
    /** Certificate contains forbidden extension types */
    SBMCertificateErrorForbiddenExtensionTypes = 4410,
    /** Basic constraints extension shall be present */
    SBMCertificateErrorBasicConstraints = 4411,
    /** Wrong value of Basic Constraints' CA field */
    SBMCertificateErrorBasicConstraintsCA = 4412,
    /** Basic Constraints' PathLen shall not be present */
    SBMCertificateErrorBasicConstraintsPathLen = 4413,
    /** Signature's message digest is wrong */
    SBMCertificateErrorSignatureMessageDigest = 4414,
};

#pragma mark SBMRemoteProvisioningError
/**
 Error type for errors specific to Remote Provisioning process.
 */
typedef NS_ERROR_ENUM(SBMRemoteProvisioningErrorDomain, SBMRemoteProvisioningError) {
    /**
     Scanning cannot start.
     */
    SBMRemoteProvisioningErrorScanningCannotStart = 4500,
    /**
     Invalid state.
     */
    SBMRemoteProvisioningErrorInvalidState = 4501,
    /**
     Limited resources.
     */
    SBMRemoteProvisioningErrorLimitedResources = 4502,
    /**
     Link cannot open.
     */
    SBMRemoteProvisioningErrorLinkCannotOpen = 4503,
    /**
     Link open failed.
     */
    SBMRemoteProvisioningErrorLinkOpenFailed = 4504,
    /**
     Link closed by Device.
     */
    SBMRemoteProvisioningErrorLinkClosedByDevice = 4505,
    /**
     Link closed by Server.
     */
    SBMRemoteProvisioningErrorLinkClosedbyServer = 4506,
    /**
     Link closed by Client.
     */
    SBMRemoteProvisioningErrorLinkClosedByClient = 4507,
    /**
     Link closed as cannot receive PDU.
     */
    SBMRemoteProvisioningErrorLinkClosedAsCannotReceivePDU = 4508,
    /**
     Link closed as cannot send PDU.
     */
    SBMRemoteProvisioningErrorLinkClosedAsCannotSendPDU = 4509,
    /**
     Link closed as cannot deliver PDU Report.
     */
    SBMRemoteProvisioningErrorLinkClosedAdDeliverPDUReport = 4510,
    /**
     Reserved for future use.
     */
    SBMRemoteProvisioningErrorUndefined = 4511
};
