//
//  Internal_NUSAVuiController.h
//  Dragon Medical SpeechKit
//
//  Copyright (c) 2017 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 0.0.0.0
//
#import <DragonMedicalSpeechKit/NUSAVuiController.h>
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** @brief NUSAVuiController extension for internal use only.

	@xmlonly<nmFramework>NuanceSpeechAnywhere</nmFramework>@endxmlonly
	@since 3.2

	This interface adds functionality for internal use only.
*/
@interface Internal_NUSAVuiController : NUSAVuiController

/** @brief Choose which Correction Option, or remove correction dialog
 @since 3.2

 Chooses which correction item to select from the correction dialog

 @param itemID.  If you send this "nil", the Correction dialog will be removed.

*/
- (void)chooseCorrection: (NSString*) itemID;

@end


