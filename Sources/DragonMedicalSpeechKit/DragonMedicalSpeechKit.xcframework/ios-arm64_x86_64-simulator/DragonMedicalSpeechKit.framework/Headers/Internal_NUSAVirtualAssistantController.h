//
//  Internal_NUSAVirtualAssistantController.h
//  MobileSpeechSDK
//
//  Copyright © 2019 Nuance Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DragonMedicalSpeechKit/NUSAVirtualAssistantController.h>
#import <UIKit/UIKit.h>

@interface Internal_NUSAVirtualAssistantController : NUSAVirtualAssistantController

/** @brief Get the audio volume leve when VA is active
 @since 3.5
 
 Get the audio volume level when VA is active. Value ranges from 0 to 1.0.
 When VA is not active it return 0.0
 */
@property (nonatomic, readonly) float audioLevel;

/** @brief Returns the shared instance of NUSAVirtualAssistantController which supports the aforementioned private API
 @since 3.5
 */
+ (Internal_NUSAVirtualAssistantController *)sharedController;

/** @brief Starts a VA dialog
 @since 3.5
 
Set the SDK in VA dialog mode with the following conditions:

openWithModel was called successfully
NUSAVuiController was successfully created
Microphone state should be in one of supported states: microphone off, dictation.
Note: If SDK is already in VA mode or playing TTS - method will return `NO` with `outError`.
@param outError the error object
@return YES if successfully switched to VA mode or NO if switch to VA failed, see `outError` for error details
 */
- (BOOL) startDialog: (NSError * __autoreleasing *) outError;

/** @brief Get the settings button
 @since 3.5
 
  Returns a UIButton that, when tapped, will display the settings pane
 */
@property (nonatomic, strong) UIButton *settingsButton;


/**
 @brief Resume a paused dialog
 @discussion Setting 'PauseMicWhenDialogActive' needs to be set when calling 'openWithModel:' a dialog needs to be paused on receiving active state.
 @since 3.5R2
 @return YES when dialog is resumed, NO when one of the above condition is not met
 */
- (BOOL)resumeDialog;

@end
