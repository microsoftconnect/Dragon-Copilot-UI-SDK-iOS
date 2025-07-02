//
//  Internal_NMVirtualAssistantAudioDelegate.h
//  MobileSpeechSDK
//
//  Created by Yan Tran on 1/25/19.
//  Copyright © 2019 Nuance Communications, Inc. All rights reserved.
//

#ifndef Internal_NMVirtualAssistantAudioDelegate_h
#define Internal_NMVirtualAssistantAudioDelegate_h

#import <Foundation/Foundation.h>

@protocol Internal_NMVirtualAssistantAudioDelegate <NSObject>

- (void) onVAStart;
- (void) onVAData: (NSData*) objcData;
- (void) onVAStop;
- (void) stopDialogFromDelegate;

@end
#endif /* Internal_NMVirtualAssistantAudioDelegate_h */
