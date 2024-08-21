//
//  SBMModelTransmissionControl.h
//  BluetoothMesh
//
//  Created by Arkadiusz Marszałek on 05/06/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMLocalVendorModel.h"
#import "SBMModelIdentifier.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Model Transmission Control object used to set transmission options specific to model.
 */
@interface SBMModelTransmissionControl : NSObject

/**
 Sets transmission options for a local vendor model.

 @param enable Extended packets setting that should be set for a local vendor model.
 @param localVendorModel Local vendor model for which the options should be set.
 @return Error that specifies resason of failure when setting options. Can be nil if operation was successful.
 
 Example usage:
 @code
 let transmissionControl = SBMModelTransmissionControl()
 
 // go through all local vendor models that were configured during initialization
 // and set transmission options for them
 SBMBluetoothMesh.sharedInstance().configuration()?.localVendorModels.forEach { localVendorModel in
     transmissionControl.useExtendedPackets(true, localVendorModel: localVendorModel)
 }
 @endcode
 */
- (NSError *)useExtendedPackets:(BOOL)enable localVendorModel:(SBMLocalVendorModel*)localVendorModel;
/**
 Sets transmission options for a local sig model.

 @param enable Extended packets setting that should be set for a sig model.
 @param sigModelIdentifier Identifier of a sig model for which the options should be set.
 @return Error that specifies resason of failure when setting options. Can be nil if operation was successful.
 
 Example usage:
 @code
 let options = SBMModelTransmissionOptions(extendedPacketSize: true)
 //Device sig model client identifiers
 let sigModelsIdentifiers: [SBMModelIdentifier] = [.sceneClient, .schedulerClient]
 let transmissionControl = SBMModelTransmissionControl()
 
 // go through all sig model client identifiers that device supports
 // and set transmission options for them
 sigModelIdentifiers.forEach { sigModelIdentifier in
     transmissionControl.useExtendedPackets(true, sigModelIdentifier: sigModelIdentifier)
 }
 @endcode
 */
- (NSError *)useExtendedPackets:(BOOL)enable sigModelIdentifier:(SBMModelIdentifier)sigModelIdentifier;

/**
 Gets transmission options for a local vendor model.

 @param localVendorModel Local vendor model for which the options should be fetched.
 @return BOOL value if succeeded.
 */
- (nullable NSNumber *)isUsingExtendedPacketsForLocalVendorModel:(SBMLocalVendorModel*)localVendorModel error:(NSError **)error NS_SWIFT_NAME(isUsingExtendedPackets(localVendorModel:));

/**
 Gets transmission options for a local sig model.

 @param sigModelIdentifier Identifier of a sig model for which the options should be fetched.
 @return BOOL value if succeeded.
 */
- (nullable NSNumber *)isUsingExtendedPacketsForSigModelIdentifier:(SBMModelIdentifier)sigModelIdentifier error:(NSError **)error NS_SWIFT_NAME(isUsingExtendedPackets(sigModelIdentifier:));

/**
 Sets global PDU max size setting for local models with Advertisement Extension feature enabled.
 
 @param size Maximum Network PDU size. Valid range: 29 - 253.
 */
- (void)setLocalPduMaxSize:(UInt16)size;

/**
 Maximum Network PDU size.
 Global setting that affects local models with Advertisement Extension feature enabled.
 Default value is the max size defined by the spec. (29 bytes)
 
 @return Current global setting for PDU max size.
 */
- (UInt16)localPduMaxSize;

@end

NS_ASSUME_NONNULL_END
