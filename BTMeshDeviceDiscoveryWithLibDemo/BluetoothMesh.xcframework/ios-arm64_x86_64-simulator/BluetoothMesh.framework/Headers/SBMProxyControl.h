//
//  SBMProxyControl.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 18/04/2019.
//  Copyright © 2019 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMProxyConnection.h"
#import "SBMSubnet.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Proxy filter list type of the Proxy Server.
 */
typedef NS_ENUM(NSUInteger, SBMProxyControlFilterType) {
    /** On the list are addresses from which the Proxy Client wants to receive messages.
        If the address is not on the list then the client will not receive messages from this address.  */
    SBMProxyControlFilterTypeAcceptList = 0,
    /** On the list are addresses from which the Proxy Client does not want to receive the message.
        If the address is not on the list then the client will receive from this address messages.  */
    SBMProxyControlFilterTypeRejectList = 1,
};

/**
 Called when `SBMProxyControl.acceptPackets` or `SBMProxyControl.rejectPackets` ends with success.
 
 @param address The address which was accepted/rejected on the Proxy Server.
 */
typedef void(^SBMProxyControlSuccessCallback)(SBMAddress *address);

/**
 Called when `SBMProxyControl.acceptPackets` or `SBMProxyControl.rejectPackets` ends with error.
 
 @param address The address which was trying to aceepted/rejected on the Proxy Server.
 @param error The failure reason.
 */
typedef void(^SBMProxyControlErrorCallback)(SBMAddress *address, NSError *error);

/**
 Called when `SBMProxyControl.setFilterType` ends with success.
  
 @param filterType The filter type which was set on the Proxy Server.
 */
typedef void(^SBMProxyControlSetFilterTypeSuccessCallback)(SBMProxyControlFilterType filterType);

/**
 Called when `SBMProxyControl.setFilterType` ends with error.
 
 @param filterType The filter type which setting failed.
 @param error The failure reason.
 */
typedef void(^SBMProxyControlSetFilterTypeErrorCallback)(SBMProxyControlFilterType filterType, NSError *error);

/**
 Called when `SBMProxyControl.getFilterStatus` ends with success.
  
 For accept list, entryCount value means that `entryCount` addresses are accepted on the Proxy Server.
 For reject list, entryCount value means that `entryCount` addresses are rejected on the Proxy Server.
 
 @param filterType The filter type which is currently set on the Proxy Server.
 @param entryCount A number of addresses on the proxy filter list.
 */
typedef void(^SBMProxyControlGetFilterStatusSuccessCallback)(SBMProxyControlFilterType filterType, NSUInteger entryCount);

/**
 Called when `SBMProxyControl.getFilterStatus` ends with error.
 
 @param error The failure reason.
 */
typedef void(^SBMProxyControlGetFilterStatusErrorCallback)(NSError *error);

/**
 Controls the Proxy Server filter list.
  
 After establishing a proxy connection using `SBMProxyConnection.connect(toProxy:errorCallback:)`
 the Proxy Server creates a filter list, which can be used to reduce the number
 of packets exchanged with the proxy node.
 
 This can be done using `SMBProxyControl.accept(:in:success:error:)`
 and `SBMProxyControl.reject(:in:success:error:)`, which add or remove
 an address to or from the proxy filter list, depending on the list type.
 
 The filter list can be either an accept list or a reject list (a white list or a black list according
 to Mesh Profile Specification v1.0.1).
 An accept list is a list of destination addresses of the packets which the Proxy Server
 passes through to the Client, other packets will not be received.
 A reject list is a list of destination addresses of the packets which the Proxy Server
 shall not pass through to the Client, all other packets will be received.
 
 By default, the Proxy Server always initiates the filter as an empty accept list.
 The type of list can be changed using `SBMProxyControl.setFilterType:inSubnet:success:error:)'
 
 Whenever the Proxy Client sends a message to the Network, the source address
 is added to its accept list or removed from its reject list, to let the Client receive a response.
 
 For a detailed explanation see Mesh Profile Spec v1.0.1 chapter 6.4 and the following.
 */
@interface SBMProxyControl : NSObject

/**
 Represents a connection to the Proxy Server which this object controls.
 */
@property (nonatomic, strong, readonly) SBMProxyConnection *connection;

/**
 Initializes a proxy control object.
 
 @param connection  The connection to the Proxy Server which this object controls.
 */
- (instancetype)initWithProxyConnection:(SBMProxyConnection *)connection;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 Accepts packets with a destination address to be passed to the Proxy Client.
 
 An address is accepted for each subnet in which a proxy node resides.
 
 If the Proxy Server uses an accept list, a destination address is added to the list.
 If the Proxy Server uses a reject list, a destination address is removed from the list.
 
 If the Proxy Server runs out of space on the filter list, an address is not added
 and success callback will be called.
 The responsibility of knowing this limit and handling it belongs to clients of this class.
 
 @param address A destination address to be accepted
 @param success The success callback called when the operation succeeds
 @param error The failure reason.
 */
- (void)accept:(SBMAddress *)address
       success:(SBMProxyControlSuccessCallback)success
         error:(SBMProxyControlErrorCallback)error;

/**
 Rejects packets with a destination address from being passed to Proxy Client.
 
 An address is denied for each subnet in which a proxy node resides.
 
 If the Proxy server uses accept list, a destination address is removed from the list.
 If the Proxy server uses reject list, a destination address is added to list.
 
 If the Proxy server runs out of space on the filter list, an address will not be added
 and success callback will be called.
 The responsibility of knowing this limit and handling it belongs to clients of this class.
  
 @param address A destination address to be denied.
 @param success The success callback called when the operation succeeds.
 @param error The failure reason.
 */
- (void)reject:(SBMAddress *)address
       success:(SBMProxyControlSuccessCallback)success
         error:(SBMProxyControlErrorCallback)error;

/**
 Sets a filter list type on the Proxy Server.

 Note that each call of this method causing clearing entries of the list on the proxy node.
 Especially in the situation when the desired filter type is already set and this method is called with the same value of a parameter of 'filterType' as is currently set, then the entire list will be cleared.
 Calling this method is clearing filter lists and setting a given filter type for each subnet in which node resides.
 
 @param filterType The filter type to set.
 @param success The success callback called when the operation succeeds.
 @param error The failure reason.
 */
- (void)setFilterType:(SBMProxyControlFilterType)filterType
              success:(SBMProxyControlSetFilterTypeSuccessCallback)success
                error:(SBMProxyControlSetFilterTypeErrorCallback)error;

/**
 Gets filter status on the Proxy Server.
 
 The success callback returns the status of the Proxy Server filter list.
 
 @param success The success callback called when the operation succeeds.
 @param error The failure reason.
 */
- (void)getFilterStatusWithSuccess:(SBMProxyControlGetFilterStatusSuccessCallback)success
                             error:(SBMProxyControlGetFilterStatusErrorCallback)error;

@end

NS_ASSUME_NONNULL_END
