//
//  Custom_NUSASession_Epic.h
//  DragonMedicalSpeechKit
//
//  Copyright © 2020 Nuance Communications, Inc. All rights reserved.
//
#import <DragonMedicalSpeechKit/NUSASession.h>
@interface Custom_NUSASession_Epic: NUSASession

/**
    @brief To enable or disable the stand by state of the Microphone.
    @discussion When in Microphone off state, this API when called with YES as parameter will place the microphone in Stand by. When the Microphone is in Stand by and this method is called with NO, will place the Microphone in off state.
    @since 3.5 R3
    @return YES when action succeeds
 */
- (BOOL)enableStandBy:(BOOL)enable;


@end

