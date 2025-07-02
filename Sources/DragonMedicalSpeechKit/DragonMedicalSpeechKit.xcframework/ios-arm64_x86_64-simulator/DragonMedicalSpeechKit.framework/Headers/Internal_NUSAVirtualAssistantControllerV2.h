//
//  Internal_NUSAVirtualAssistantControllerV2.h
//  DragonMedicalSpeechKit
//
//  Copyright © 2021 Nuance Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DragonMedicalSpeechKit/NUSAVirtualAssistantControllerV2.h>
#import <UIKit/UIKit.h>

@interface Internal_NUSAVirtualAssistantControllerV2 : NUSAVirtualAssistantControllerV2

/** @brief Returns the shared instance of NUSAVirtualAssistantControllerV2 which supports the aforementioned private API
 @since 3.5
 */
+ (Internal_NUSAVirtualAssistantControllerV2 *)sharedController;

/**
@brief Starts a VA activity
 @since 3.5
  
 Starts the Virtual Assistant. User can utter VA commands. Request will be processed by DMVA and sends back the respective intent.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - StartVA has completed successfully and the Dragon Medical Virtual Assistant has transitioned into the VA Active state.
 
 VAResultCodeNoSessionError - Request can not be processed because session is not initialised.
 
 VAResultCodeApplicationStateError - Attempt to Start VA while not in Dictation, StandBy or Mic Off State.
 
@return VAResultCode
 */

- (VAResultCode) startVA;

/**
@brief Start processing a VA request
 @since 4.2
  
 Request to Process the VA command will be send to DMVA and it sends back the respective intent.
 
 The return value is one of the following:
 
 VAResultCodeSuccess - processVA has completed successfully and the Dragon Medical Virtual Assistant has transitioned into the VA Processing state.
 
 VAResultCodeNoSessionError - Request can not be processed because session is not initialised.
 
 VAResultCodeApplicationStateError - Attempt to process VA request while not in VA State.
 
@return VAResultCode
 */
- (VAResultCode) processVA;

/** @brief Get the settings button
 @since 3.5
 
  Returns a UIButton that, when tapped, will display the settings pane
 */
@property (nonatomic, strong) UIButton *settingsButton;

/** @brief Get the audio volume leve when VA is active
 @since 3.5
 
 Get the audio volume level when VA is active. Value ranges from 0 to 1.0.
 When VA is not active it return 0.0
 */
@property (nonatomic, readwrite) float audioLevel;

@end
