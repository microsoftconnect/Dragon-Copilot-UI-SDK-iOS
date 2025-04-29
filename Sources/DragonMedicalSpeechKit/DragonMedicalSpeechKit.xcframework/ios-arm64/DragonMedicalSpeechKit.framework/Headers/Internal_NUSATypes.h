//
//  Internal_NUSATypes.h
//  Dragon Medical SpeechKit
//
//  Copyright (c) 2014 Nuance Communications, Inc. All rights reserved.
//
//  SDK version: 0.0.0.0
//

#import <Foundation/Foundation.h>

/** @brief Audio quality.
 *
 */
typedef enum Internal_NUSAAudioQualityInternal {
    /** @brief The audio quality is ok. */
    Internal_NUSAAudioQualityIsOK		= 0,
    /** @brief The audio quality is too loud. */
    Internal_NUSAAudioQualityIsTooLoud,
    /** @brief The audio quality is too noisy. */
    Internal_NUSAAudioQualityIsTooNoisy,
    /** @brief The audio quality is too soft. */
    Internal_NUSAAudioQualityIsTooSoft,
} Internal_NUSAAudioQuality;

//
// constants for NUSASessionInternal showView:
//
/** @brief commands ("what can i say") view */
extern NSString* const Internal_kNUSAViewContentCommands;
/** @brief help view */
extern NSString* const Internal_kNUSAViewContentHelp;
/** @brief add word view */
extern NSString* const Internal_kNUSAViewContentAddWord;
/** @brief autotexts view */
extern NSString* const Internal_kNUSAViewContentAutotexts;
extern NSString* const Internal_kNUSAViewContentSettings;
extern NSString* const Internal_kNUSAViewContentIndex;


/** @brief Customer FeedBack Result
 *
 */
typedef enum FeedBackResultCode {
    /** @brief When feedback is stored successfully. */
    FeedBackResultIsOK        = 0,
    /** @brief Current Server does not Support Store Feedback Functionality. */
    FeedBackResultNotFound,
    /** @brief SDK Not Initialized. */
    FeedBackResultSdkNotInitialized,
    /** @brief Invalid Input Parameters. */
    FeedBackResultInvalidInputParameters,
} FeedBackResultCode;
