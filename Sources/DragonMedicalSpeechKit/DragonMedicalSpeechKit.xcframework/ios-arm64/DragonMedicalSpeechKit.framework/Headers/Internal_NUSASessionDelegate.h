//
//  Internal_NUSASessionDelegate.h
//  Dragon Medical SpeechKit
//
//  Copyright (c) 2014 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 0.0.0.0
//
#import <DragonMedicalSpeechKit/NUSASessionDelegate.h>
#import <DragonMedicalSpeechKit/Internal_NUSATypes.h>
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief NUSASessionDelegateInternal delegate messages.
 
	@xmlonly<nmFramework>NuanceSpeechAnywhere</nmFramework>@endxmlonly
	@since 1.6 SR9
 
	Delegate messages sent by the Internal_NUSASession class to its delegate receiver. All messages
	provided by the protocol are optional and can be implemented by the receiver.
 */
@protocol Internal_NUSASessionDelegate <NUSASessionDelegate>
@optional

/** @brief Sent when signal level changes.
 @since 1.6 SR9
 
 Sent to the delegate whenever the signal level changes.
 
 @param signalLevel Ranges from 0.0 to 1.0.
 @param quality The audio quality, see Internal_NUSATypes.h for possible values
 */
- (void) sessionUpdateSignalLevel: (Float32) signalLevel quality: (Internal_NUSAAudioQuality) quality;

/** @brief Sent when the WCIS/help/... starts being loaded to the custom webview.
	@since 1.6 SR13
 
 This message is sent in response to Internal_NUSASession's showView: or when the user speaks a command that triggers the display of WCIS view
 
 @param content content that is being displayed, see Internal_NUSATypes.h for possible values
 */
- (void) sessionDidReceiveShowView: (NSString*) content;

/** @brief Hide WCIS/help/... view.
	@since 1.6 SR13

 This message is sent in response to Internal_NUSASession's hideView or when the user speaks a command that triggers closing of WCIS view
 
 */
- (void) sessionDidReceiveHideView;

/** @brief
 This message is sent in response to Internal_NUSASession's configuration retrieval.
 
 @param identifier share with different client for configuration retrieval.
 @param expiry is the expire date and time of identifier.
 @param username will be available after start sharing identifier from other client.
 @param accountToken will be available after start sharing identifier from other client.
 */
- (void) onConfigRetrievalOutcomeChangedWithId:(NSString*)identifier expiry:(NSDate*)expiry user:(NSString*)username token:(NSString*)accountToken organization:(NSString*)organizationName;

/** @brief
 This message is sent in response to Internal_NUSASession's on shared configuration.
 
 @param status of sharing configuration.
 */
- (void) sessionSharedConfiguration:(BOOL)status;

/** @brief
 This message is sent when running in theia mode, and separated clients are now connected and ready for inter communication.
 */
- (void) onSessionReady;

/** @brief
 This message is sent when running in theia mode, and separated clients become disconnected.
 */
- (void) onCloseSession:(BOOL)audioDeleted;

@end
