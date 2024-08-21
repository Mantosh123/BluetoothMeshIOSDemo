//
//  SBMImporter.h
//  BluetoothMesh
//
//  Created by Subhojit Mandal on 14/02/24.
//  Copyright © 2024 Silicon Labs, http://www.silabs.com. All rights reserved.
//


#import "SBMNetworkImport.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 Class used to import Mesh structure
 */
@interface SBMImporter : NSObject

/**
 Validate created structure and perform import.
 @param error out parameter. Set if validation or import failed
 @return Return YES if success NO if failed
 */
- (BOOL)performImport:(NSError**)error;


/**
 Creates new network for import with UUID
 @return SBMNetworkImport created object
 */
- (SBMNetworkImport*)createNetwork:(NSData*)uuid;

@end

NS_ASSUME_NONNULL_END
