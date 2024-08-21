//
//  SBMModelSettings.h
//  BluetoothMesh
//
//  Created by Marek Szkowron on 03/10/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMAddress.h"
#import "SBMPublish.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Contains publication and subscriptions settings for the Model.
 */
@interface SBMModelSettings : NSObject

/**
 addresses that are subscribed to the Model.
 */
@property (nonatomic, readonly) NSArray<SBMAddress *> *subscriptions;

/**
 Publish object describing the configuration of the Model's publication.
 */
@property (nonatomic, readonly, nullable) SBMPublish* publish;

@end

NS_ASSUME_NONNULL_END
