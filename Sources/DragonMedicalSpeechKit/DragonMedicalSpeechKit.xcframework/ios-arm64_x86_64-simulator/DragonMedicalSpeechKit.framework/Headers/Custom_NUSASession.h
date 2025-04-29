//
//  Custom_NUSASession.h
//  DragonMedicalSpeechKit
//
//  Copyright © 2018 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 0.0.0.0
//
#import <DragonMedicalSpeechKit/NUSASession.h>
@interface Custom_NUSASession: NUSASession

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Correction screen/Correction menu handling.
//////////////////////////////////////////////////////////////////////////////////////////

/** @brief Enables the correction screen/correction menu for speech recognition.
 @since 3.4
 This method is used to display the correction menu when the "select text" or "correct text" command is recognized and text is selected. This needs to be called prior to calling openForApplication.
 @param value  Checks the correction screen/correction menu state.
 */
- (void) setCorrectionModeCapable: (BOOL) value;

/** @brief Check if the correction screen/correction menu is enabled.
 @since 3.4
 
 @return @c YES if the correction screen/correction menu is enabled, otherwise @c NO.
 */
- (BOOL) isCorrectionModeCapable;

@end
