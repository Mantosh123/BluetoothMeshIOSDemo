//
//  SBMConfigurationControl.h
//  BluetoothMesh
//
//  Created by Łukasz Rzepka on 07.11.2018.
//  Copyright © 2018 Silicon Labs, http://www.silabs.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBMNode.h"
#import "SBMSubnet.h"
#import "SBMDeviceCompositionData.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark SBMConfigurationControl

/**
 SBMConfigurationControl methods are for configuring a node over the mesh network by sending configuration model messages. Note that the API is asynchronous; unless there is an immediate local failure.
 Important: It is not needed to keep object by application. Framework will do it.
*/

@interface SBMConfigurationControl : NSObject

#pragma mark - Get callbacks

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for whether proxy is enabled or not.
 */
typedef void(^SBMCheckNodeProxySuccess)(SBMNode* node, BOOL enabled);

/**
 @param node SBMNode to which the message was sent.
 @param error NSError error received during check proxy state.
 */
typedef void(^SBMCheckNodeProxyError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for whether relay is enabled or not.
 @param retransmissionCount UInt8 parameter for relay retransmission count.
 @param retransmissionInterval UInt8 parameter for relay retransmission interval. Number of 10 millisecond steps that controls the interval between message retransmissions originating from the node. Actual retransmission  interval is equal to  (the value of this parameter + 1) * 10 milliseconds.
 */
typedef void(^SBMCheckNodeRelaySuccess)(SBMNode* node, BOOL enabled, UInt8 retransmissionCount, UInt8 retransmissionInterval);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during check relay state.
 */
typedef void(^SBMCheckNodeRelayError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for whether friend is enabled or not.
 */
typedef void(^SBMCheckNodeFriendSuccess)(SBMNode* node, BOOL enabled);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during check friend state.
 */
typedef void(^SBMCheckNodeFriendError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for whether node identity is enabled or not.
 @param subnet SBMSubnet checked subnet. Node identity can be set only for one subnet.
 */
typedef void(^SBMCheckNodeIdentitySuccess)(SBMNode* node, BOOL enabled, SBMSubnet* subnet);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during check node identity state.
 */
typedef void(^SBMCheckNodeIdentityError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param publicationAddress Heartbeat publication address.
 @param publishCountLogarithm Heartbeat publish count 2's logarithm value.
 @param publishPeriodLogarithm Heartbeat publish period 2's logarithm value.
 @param timeToLive Heartbeat time to live.
 @param features Feature bitmask for heartbeat triggering.
 @param publishCryptoSubnetKeyIndex Network key index of the key used to encrypt the published messages.
 */
typedef void(^SBMCheckNodeHeartbeatPublicationSuccess)(SBMNode* node, UInt16 publicationAddress, UInt8 publishCountLogarithm, UInt8 publishPeriodLogarithm, UInt8 timeToLive, UInt16 features, UInt16 publishCryptoSubnetKeyIndex);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during check heartbeat publication.
 */
typedef void(^SBMCheckNodeHeartbeatPublicationError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param sourceAddress Heartbeat source address.
 @param destinationAddress Heartbeat destination address.
 @param subscribeCountLogarithm Heartbeat subscribe count 2's logarithm value.
 @param subscribePeriodLogarithm Heartbeat subscribe period 2's logarithm value.
 @param hopMinimum Minimum hops value registered when receiving Heartbeat messages.
 @param hopMaximum Maximum hops value registered when receiving Heartbeat messages.
 */
typedef void(^SBMCheckNodeHeartbeatSubscriptionSuccess)(SBMNode* node, UInt16 sourceAddress, UInt16 destinationAddress, UInt8 subscribeCountLogarithm, UInt8 subscribePeriodLogarithm, UInt8 hopMinimum, UInt8 hopMaximum);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during check heartbeat subscription.
 */
typedef void(^SBMCheckNodeHeartbeatSubscriptionError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param retransmissionCount Network retransmission count. Use 0 to turn retransmissions off.
 @param retransmissionInterval Network retransmission interval. Number of 10 millisecond steps that controls the interval between message retransmissions originating from the node. Actual retransmission  interval is equal to  (the value of this parameter + 1) * 10 milliseconds.
 */
typedef void(^SBMCheckNodeRetransmissionConfigurationSuccess)(SBMNode* node, UInt8 retransmissionCount, UInt8 retransmissionInterval);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during check retransmission configuration.
 */
typedef void(^SBMCheckNodeRetransmissionConfigurationError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param defaultTTL Default TTL value for node.
 */
typedef void (^SBMCheckNodeDefaultTTLSuccess)(SBMNode *node, UInt8 defaultTTL);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during check default TTL.
 */
typedef void (^SBMCheckNodeDefaultTTLError)(SBMNode *node, NSError *error);

/**
 @param configurationControl SBMConfigurationControl reference to configuration control.
 @param dcd Raw representation of device composition data of node.
 */
typedef void(^SBMGetDeviceCompositionDataSuccess)(SBMConfigurationControl *configurationControl, NSData* _Nullable dcd);

/**
 @param configurationControl SBMConfigurationControl reference to configuration control.
 @param error NSError received error.
 */
typedef void(^SBMGetDeviceCompositionDataError)(SBMConfigurationControl *configurationControl, NSError* error);

/**
 @param node The node that the callback applies to.
 @param enabled The result status of the check.
 */
typedef void(^SBMSecureNetworkBeaconSuccessCallback)(SBMNode *node, BOOL enabled);

/**
 @param node The node that the callback applies to.
 @param error Error that ocurred during
 */
typedef void(^SBMSecureNetworkBeaconErrorCallback)(SBMNode *node, NSError *error);

/**
 @param friendNode The friend node that the callback applies to.
 @param lowPowerNode The low power node.
 @param pollTimeout The current value of the PollTimeout timer of the Low Power node, or value 0 if the node is not a Friend node for the Low Power node.
 */
typedef void(^SBMLpnPollTimeoutSuccessCallback)(SBMNode *friendNode, SBMNode *lowPowerNode, UInt32 pollTimeout);

/**
 @param friendNode The friend node that the callback applies to.
 @param lowPowerNode The low power node.
 @param error Error that ocurred during
 */
typedef void(^SBMLpnPollTimeoutErrorCallback)(SBMNode *friendNode, SBMNode *lowPowerNode, NSError *error);

#pragma mark - Set callbacks

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for changed proxy state.
 */
typedef void(^SBMSetNodeProxySuccess)(SBMNode* node, BOOL enabled);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during change proxy state.
 */
typedef void(^SBMSetNodeProxyError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for changed proxy state.
 @param retransmissionCount UInt8 parameter for changed relay retransmission count.
 @param retransmissionInterval UInt8 parameter for changed relay retransmission interval. Number of 10 millisecond steps that controls the interval between message retransmissions originating from the node. Actual retransmission  interval is equal to  (the value of this parameter + 1) * 10 milliseconds.
 */
typedef void(^SBMSetNodeRelaySuccess)(SBMNode* node, BOOL enabled, UInt8 retransmissionCount, UInt8 retransmissionInterval);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during change relay state.
 */
typedef void(^SBMSetNodeRelayError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for changed friend state.
 */
typedef void(^SBMSetNodeFriendSuccess)(SBMNode* node, BOOL enabled);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during change friend state.
 */
typedef void(^SBMSetNodeFriendError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param enabled BOOL parameter for changed node identity state.
 @param subnet SBMSubnet subnet for which the node identity has been changed.
 */
typedef void(^SBMSetNodeIdentitySuccess)(SBMNode* node, BOOL enabled, SBMSubnet* subnet);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during change node identity state.
 */
typedef void(^SBMSetNodeIdentityError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param defaultTTL Default TTL value for node. Accepted values are 0 and 2..127. 0 means message has not been relayed and will not be relayed.
 */
typedef void (^SBMSetNodeDefaultTTLSuccess)(SBMNode *node, UInt8 defaultTTL);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during change node default TTL.
 */
typedef void (^SBMSetNodeDefaultTTLError)(SBMNode *node, NSError *error);

/**
 @param node SBMNode node to which the message was sent.
 @param publicationAddress Heartbeat publication address.
 @param publishCountLogarithm Heartbeat publish count 2's logarithm value.
 @param publishPeriodLogarithm Heartbeat publish period 2's logarithm value.
 @param timeToLive Heartbeat time to live.
 @param features Feature bitmask for heartbeat triggering.
 @param publishCryptoSubnetKeyIndex Network key index of the key used to encrypt the published messages.
 */
typedef void(^SBMSetNodeHeartbeatPublicationSuccess)(SBMNode* node,
                                                     SBMIntegerAddress *publicationAddress,
                                                     UInt8 publishCountLogarithm,
                                                     UInt8 publishPeriodLogarithm,
                                                     UInt8 timeToLive,
                                                     UInt16 features,
                                                     UInt16 publishCryptoSubnetKeyIndex);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during set heartbeat publication.
 */
typedef void(^SBMSetNodeHeartbeatPublicationError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 @param sourceAddress Heartbeat source address.
 @param destinationAddress Heartbeat destination address.
 @param subscribeCountLogarithm Heartbeat subscribe count 2's logarithm value.
 @param subscribePeriodLogarithm Heartbeat subscribe period 2's logarithm value.
 @param hopMinimum Minimum hops value registered when receiving Heartbeat messages.
 @param hopMaximum Maximum hops value registered when receiving Heartbeat messages.
 */
typedef void(^SBMSetNodeHeartbeatSubscriptionSuccess)(SBMNode *node,
                                                      SBMElement  * _Nullable sourceAddress,
                                                      SBMIntegerAddress *destinationAddress,
                                                      UInt8 subscribeCountLogarithm,
                                                      UInt8 subscribePeriodLogarithm,
                                                      UInt8 hopMinimum,
                                                      UInt8 hopMaximum);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during set heartbeat subscription.
 */
typedef void(^SBMSetNodeHeartbeatSubscriptionError)(SBMNode* node, NSError* error);


/**
 @param node SBMNode node to which the message was sent.
 @param retransmissionCount Network retransmission count.
 @param retransmissionInterval Network retransmission interval. Number of 10 millisecond steps that controls the interval between message retransmissions originating from the node. Actual retransmission  interval is equal to  (the value of this parameter + 1) * 10 milliseconds.
 */
typedef void(^SBMSetNodeRetransmissionConfigurationSuccess)(SBMNode* node, UInt8 retransmissionCount, UInt8 retransmissionInterval);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during set retransmission configuration.
 */
typedef void(^SBMSetNodeRetransmissionConfigurationError)(SBMNode* node, NSError* error);

/**
 @param node SBMNode node to which the message was sent.
 */
typedef void(^SBMFactoryResetSuccess)(SBMNode* node);

/**
 @param node SBMNode node to which the message was sent.
 @param error NSError error received during factory reset of node.
 */
typedef void(^SBMFactoryResetError)(SBMNode* node, NSError* error);

#pragma mark - Properties
/**
 Node to configure.
*/
@property (nonatomic, readonly) SBMNode* node;


#pragma mark - Init

/**
 SBMConfigurationControl initialization.
 @param node SBMNode object to configure.
*/
- (instancetype)initWithNode:(SBMNode*)node;

/**
 Not available. Use initWithNode instead.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Not available. Use initWithNode instead.
 */
- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Get methods

/**
 Check proxy state.
*/
- (void)checkProxyStatus:(SBMCheckNodeProxySuccess)successCallback
           errorCallback:(SBMCheckNodeProxyError)errorCallback;

/**
 Check relay state.
 */
- (void)checkRelayStatus:(SBMCheckNodeRelaySuccess)successCallback
           errorCallback:(SBMCheckNodeRelayError)errorCallback;

/**
 Check friend state.
 */
- (void)checkFriendStatus:(SBMCheckNodeFriendSuccess)successCallback
            errorCallback:(SBMCheckNodeFriendError)errorCallback;

/**
 Check node identity state for subnet.
 */
- (void)checkNodeIdentityStatus:(SBMSubnet*)subnet
                successCallback:(SBMCheckNodeIdentitySuccess)successCallback
                  errorCallback:(SBMCheckNodeIdentityError)errorCallback;

/**
 Check node's default TTL.
 
 @param successCallback Action invoked on successful default TTL check operation.
 @param errorCallback Action invoked on failed default TTL check operation.
 */
- (void)checkDefaultTTL:(SBMCheckNodeDefaultTTLSuccess)successCallback errorCallback:(SBMCheckNodeDefaultTTLError)errorCallback;
/**
 Gets a node's heartbeat publish parameters.

 @param successCallback Action invoked on successfull heartbeat publication check operation.
 @param errorCallback Action invoked on failed heartbeat publication check operation.
 */
- (void)checkHeartbeatPublicationStatus:(SBMCheckNodeHeartbeatPublicationSuccess)successCallback
                          errorCallback:(SBMCheckNodeHeartbeatPublicationError)errorCallback;

/**
 Gets a node's heartbeat subscription parameters.

 @param successCallback Action invoked on successfull heartbeat subscription check operation.
 @param errorCallback Action invoked on failed heartbeat subscription check operation.
 */
- (void)checkHeartbeatSubscriptionStatus:(SBMCheckNodeHeartbeatSubscriptionSuccess)successCallback
                           errorCallback:(SBMCheckNodeHeartbeatSubscriptionError)errorCallback;

/**
 Gets a node's retransmission configuration.
 
 @param successCallback Action invoked on successfull retransmission configuration check operation.
 @param errorCallback Action invoked on failed retransmission configuration check operation.
 */
- (void)checkRetransmissionConfigurationStatus:(SBMCheckNodeRetransmissionConfigurationSuccess)successCallback
                                 errorCallback:(SBMCheckNodeRetransmissionConfigurationError)errorCallback;

#pragma mark - Set methods

/**
 Set proxy state.
 */
- (void)setProxy:(BOOL)enabled
            with:(SBMSetNodeProxySuccess)successCallback
   errorCallback:(SBMSetNodeProxyError)errorCallback;

/**
 Sets a node's relay configuration.

 @param enabled Boolean value that determines whether relay should be enabled.
 @param retransmissionCount Relay retransmission count. Use 0 to turn retransmissions off.
 @param retransmissionInterval Relay retransmission interval. Number of 10 millisecond steps that controls the interval between message retransmissions originating from the node. Actual retransmission  interval is equal to  (the value of this parameter + 1) * 10 milliseconds.
 @param successCallback Action invoked on successfull relay set operation.
 @param errorCallback Action invoked on failed relay set operation.
 */
- (void)setRelay:(BOOL)enabled
     retransmissionCount:(UInt8)retransmissionCount
  retransmissionInterval:(UInt8)retransmissionInterval
                    with:(SBMSetNodeRelaySuccess)successCallback
           errorCallback:(SBMSetNodeRelayError)errorCallback;

/**
 Set friend state.
 */
- (void)setFriend:(BOOL)enabled
             with:(SBMSetNodeFriendSuccess)successCallback
    errorCallback:(SBMSetNodeFriendError)errorCallback;

/**
 Set node identity state for subnet.
 */
- (void)setNodeIdentity:(SBMSubnet*)subnet
                enabled:(BOOL)enabled
                   with:(SBMSetNodeIdentitySuccess)successCallback
          errorCallback:(SBMSetNodeIdentityError)errorCallback;

/**
 Set node's default TTL.
 
 @param defaultTTL default TTL for node. Accepted values are 0 and 2..127. 0 means message has not been relayed and will not be relayed.
 @param successCallback Action invoked on successful default TTL set operation.
 @param errorCallback Action invoked on failed default TTL set operation.
 */
- (void)setDefaultTTL:(UInt8)defaultTTL with:(SBMSetNodeDefaultTTLSuccess)successCallback errorCallback:(SBMSetNodeDefaultTTLError)errorCallback;

/**
 Sets a node's heartbeat publish parameters.

 @param publicationAddress Heartbeat publication address.
 @param publishCountLogarithm Heartbeat publish count 2's logarithm value.
 @param publishPeriodLogarithm Heartbeat publish period 2's logarithm value.
 @param timeToLive Heartbeat time to live.
 @param features Feature bitmask for heartbeat triggering.
 @param publishCryptoSubnetKeyIndex Network key index of the key used to encrypt the published messages.
 @param successCallback Action invoked on successfull heartbeat publication set operation.
 @param errorCallback Action invoked on failed heartbeat publication set operation.
 */
- (void)setHeartbeatPublication:(nullable SBMIntegerAddress *)publicationAddress
          publishCountLogarithm:(UInt8)publishCountLogarithm
         publishPeriodLogarithm:(UInt8)publishPeriodLogarithm
                     timeToLive:(UInt8)timeToLive
                       features:(UInt16)features
    publishCryptoSubnetKeyIndex:(UInt16)publishCryptoSubnetKeyIndex
                           with:(SBMSetNodeHeartbeatPublicationSuccess)successCallback
                  errorCallback:(SBMSetNodeHeartbeatPublicationError)errorCallback;

/**
 Sets a node's heartbeat subscription log parameters.
 The Destination Address parameter can be used by nodes to configure a proxy filter to allow them to receive Heartbeat messages, for example, nodes connected using a GATT bearer or in a friendship.

@param sourceAddress Heartbeat source.
@param destinationAddress Heartbeat destination address (group address or node's primary address).
@param periodLog Heartbeat subscription period logarithm-of-2 value.
@param successCallback Action invoked on successfull heartbeat subscription set operation.
@param errorCallback Action invoked on failed heartbeat subscription set operation.
*/

- (void)setHeartbeatSubscriptionLog:(nullable SBMElement *)sourceAddress
                 destinationAddress:(nullable SBMIntegerAddress *)destinationAddress
                          periodLog:(UInt8)periodLog
                               with:(SBMSetNodeHeartbeatSubscriptionSuccess)successCallback
                      errorCallback:(SBMSetNodeHeartbeatSubscriptionError)errorCallback;

/**
 Sets a node's retransmission configuration.
 
 @param retransmissionCount Network retransmission count. Use 0 to turn retransmissions off.
 @param retransmissionInterval Network retransmission interval. Number of 10 millisecond steps that controls the interval between message retransmissions originating from the node. Actual retransmission  interval is equal to (the value of this parameter + 1) * times 10 milliseconds.
 @param successCallback Action invoked on successfull retransmission configuration set operation.
 @param errorCallback Action invoked on failed retransmission configuration set operation.
 */
- (void)setRetransmissionConfiguration:(UInt8)retransmissionCount
                retransmissionInterval:(UInt8)retransmissionInterval
                                  with:(SBMSetNodeRetransmissionConfigurationSuccess)successCallback
                         errorCallback:(SBMSetNodeRetransmissionConfigurationError)errorCallback;

#pragma mark - Factory reset

/**
 @brief Send factory reset node message.
 
 @discussion It is possible for factory reset message or for response to factory reset
 message to be lost in network. In such case, library has no immediate way to tell
 if node successfully performed factory reset operation and operation will end with
 timeout error.
 When factory resetting node that is proxy to connected network, connection will be
 interrupted and even when factory reset was performed successfully, this request
 will result in error callback called with timeout as error.
 Other possible errors returned from this method are "out of memory" or "wrong state".
 In case of timeout of this request, there are 3 possibilities:
 - node wasn't factory reset and still responds to other requests. In this case, factory
  reset request should be sent again
 - node advertises as unprovisioned device. This means that node was factory reset
  and only response was lost. It's safe to remove node from local database.
 - node doesn't respond to requests and is not advertising. In this case we cannot be
  sure if request was lost or only response. Resending factory reset request may
  improve possibility that node will be factory reset, but no guarantee can be given.
 */
- (void)factoryReset:(SBMFactoryResetSuccess)successCallback
       errorCallback:(SBMFactoryResetError)errorCallback;

#pragma mark - DCD

/**
 Get device composition data state.
 */
- (void)getDeviceCompositionData:(SBMGetDeviceCompositionDataSuccess)successCallback
                   errorCallback:(SBMGetDeviceCompositionDataError)errorCallback;

#pragma mark - Secure Network Beacon

/**
 Get the node's Secure Network beacon configuration state.

 @param successCallback Called when result had been received.
 @param errorCallback Called when error has been encoutered.
 */
- (void)getSecureNetworkBeacon:(SBMSecureNetworkBeaconSuccessCallback)successCallback
                 errorCallback:(SBMSecureNetworkBeaconErrorCallback)errorCallback;

/**
 Set the node's Secure Network beacon configuration state.
 
 @param enable Boolean representing if mesh Secure Network beaconing is to be turn on or off.
 @param successCallback Called when result had been received.
 @param errorCallback Called when error has been encountered.
 */
- (void)setSecureNetworkBeacon:(BOOL)enable
               successCallback:(SBMSecureNetworkBeaconSuccessCallback)successCallback
                 errorCallback:(SBMSecureNetworkBeaconErrorCallback)errorCallback;

#pragma mark - Low power node

/**
Get the current value of PollTimeout timer of the Low Power node within a Friend Node.
 
 @param lowPowerNode object representing low power node
 @param successCallback Called when result had been received.
 @param errorCallback Called when error has been encountered.
*/
- (void)getLpnPollTimeout:(SBMNode *)lowPowerNode
          successCallback:(SBMLpnPollTimeoutSuccessCallback)successCallback
            errorCallback:(SBMLpnPollTimeoutErrorCallback)errorCallback;

@end

NS_ASSUME_NONNULL_END
