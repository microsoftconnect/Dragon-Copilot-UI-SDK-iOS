//
//  Internal_NUSAVuiControllerDelegate.h
//  Dragon Medical SpeechKit
//
//  Copyright 2017 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 0.0.0.0
//

#import <DragonMedicalSpeechKit/NUSAVuiControllerDelegate.h>
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief Internal_NUSAVuiControllerDelegate delegate messages.

	@xmlonly<nmFramework>NuanceSpeechAnywhere</nmFramework>@endxmlonly
	@since 3.2

	Internal delegate messages sent by the NUSAVuiController class to its delegate receiver. All messages
	provided by the protocol are optional and can be implemented by the receiver.
 */
@protocol Internal_NUSAVuiControllerDelegate <NUSAVuiControllerDelegate>
@optional

/** @brief Sent when an application is showing the correction window￼
 @since 3.2

	Sent to the receiver whenever the correction window is displayed.  Permits the keyboard to be removed or the content scrolled as needed.

 @param rectCorrectionBox the rectangle for the correction dialog
*/
- (void) vuiControllerDidShowCorrection:(CGRect) rectCorrectionBox;

/** @brief Sent when an application stops showing the correction window￼
 @since 3.2

	Sent to the receiver whenever the correction window stops being displayed.  Permits the receiver's GUI to reset.
*/- (void) vuiControllerDidStopShowCorrection;

@end
