//
//  NUSASessionWebView.h
//  DragonMedicalSpeechKit
//
//  Created by Vikram Naik on 07/01/21.
//  Copyright © 2021 Nuance Communications, Inc. All rights reserved.
//
#import <DragonMedicalSpeechKit/NUSASession.h>

@interface NUSASessionWebView : NUSASession

/**
     @brief To enable or disable Auto Speech Enable WebViewReport Functionality.
     @discussion  This parameter decides Speech Enabling WebView Report behavior.
 
                              If Set to YES, WebView Report is SpeechEnabled by iOS SDK whenever speech supported HTML is loaded/reloaded.
                              If Set to NO, iOS SDK does not SpeechEnable HTML page, it depends on Integrator to SpeechEnable HTML page,
                              by calling the existing Synchronize call on Vuicontroller.
 
     @since 3.9 R2
     @param autoSpeechEnableWebViewReport BOOL value needs to be passed which will decide WebView Report Created Should be Speech Enabled by iOS SDK / Integrator.
     By Default, this is YES in iOS SDK.
 
 */
- (void)registerForSpeechRecognition:(BOOL)autoSpeechEnableWebViewReport;



/**
     @brief The selection of a CE element when focused is only set to the end for the very first time it is focused.
            We don't interfere with the Browser's default behaviour.
     @discussion  Setting this value to false, the selection will always be at the end when the element is focused.
     (Exception: a selection pending from a SR result, this is queued and applied when focused)
     @since 4.1 R2
     @param isDefaultSelection BOOL value needs to be passed which will decide
     By Default, this is YES in iOS SDK.
 */
- (void)setDefaultSelectionForContentEditable:(BOOL)isDefaultSelection;

@end
