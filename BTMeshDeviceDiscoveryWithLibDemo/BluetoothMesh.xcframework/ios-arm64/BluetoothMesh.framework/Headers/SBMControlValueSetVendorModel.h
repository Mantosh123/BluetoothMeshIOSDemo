//
//  SBMControlValueSetVendorModel.h
//  BluetoothMesh
//
//  Created by Piotr Sarna on 04/12/2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMVendorModel.h"
#import "SBMLocalVendorModel.h"
#import "SBMBluetoothMeshMacros.h"

/**
 Possible vendor model message flags.
 */
typedef NS_ENUM(UInt8, SBMControlValueSetVendorModelFlag) {
    /** Reply. */
    SBMControlValueSetVendorModelFlagReply          = 1 << 0,
    /** Multicast reply. */
    SBMControlValueSetVendorModelFlagMulticastReply = 1 << 1,
    /** Non-relayed message. */
    SBMControlValueSetVendorModelFlagTtl0           = 1 << 2,
    /** Transport layer segmentation is forced also for short messages. */
    SBMControlValueSetVendorModelFlagSegtrans       = 1 << 4,
    /** Use friendship credentials instead of normal credentials
        when sending data; used when publishing with friendship
        credential flag on in model publish settings */
    SBMControlValueSetVendorModelFlagFriendcred     = 1 << 5,
    /** Use extended packet size instead of standard */
    SBMControlValueSetVendorModelFlagExtended       = 1 << 6,
    /** long delay needed in sending two messages in reply that need to be sent in order */
    SBMControlValueSetVendorModelFlagLongDelay      = 1 << 7,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Base functionality protocol. Any functionality that can be used to set Vendor model values should conform to this protocol.
 */
@protocol SBMControlValueSetVendorModel <NSObject>

/**
 Vendor model to control.
 */
@property (nonatomic, readonly) SBMVendorModel *vendorModel;

/**
 The application message, including opcode.
 */
@property (nonatomic, readonly) NSData *data;

/**
 Specifies vendor model message flags.
 */
@property (nonatomic, readonly) SBMControlValueSetVendorModelFlag flags;

@end

NS_ASSUME_NONNULL_END
