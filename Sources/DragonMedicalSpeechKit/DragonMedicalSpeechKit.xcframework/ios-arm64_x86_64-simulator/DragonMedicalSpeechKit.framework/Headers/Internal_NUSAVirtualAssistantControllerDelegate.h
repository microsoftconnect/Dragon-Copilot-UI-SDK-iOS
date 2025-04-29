//
//  Internal_NUSAVirtualAssistantControllerDelegate.h
//  MobileSpeechSDK
//
//  Copyright © 2019 Nuance Communications, Inc. All rights reserved.
//

#import "NUSAVirtualAssistantControllerDelegate.h"

#ifndef Internal_NUSAVirtualAssistantControllerDelegate_h
#define Internal_NUSAVirtualAssistantControllerDelegate_h

@protocol Internal_NUSAVirtualAssistantControllerDelegate <NUSAVirtualAssistantControllerDelegate>
@optional

/**
    Use this method to get notified when the SDK starts processing the dialog.
 */
- (void) didStartDialogProcessing;

@end

#endif /* Internal_NUSAVirtualAssistantControllerDelegate_h */
