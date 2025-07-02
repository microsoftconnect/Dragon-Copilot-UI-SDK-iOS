// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "DragonCopilotTurnkey",
    platforms: [
        .iOS(.v16)
    ],
    products: [
        .library(
            name: "DragonCopilotTurnkey",
            targets: ["DragonCopilotTurnkey", "DragonCopilotTurnkeyDependencies"]
        )
    ],
    targets: [
        .binaryTarget(
            name: "DragonCopilotTurnkey",
            path: "Sources/DragonCopilotTurnkey/DragonCopilotTurnkey.xcframework"
        ),
        .binaryTarget(
            name: "DAXKit",
            path: "Sources/DAXKit/DAXKit.xcframework"
        ),
        // DragonMedicalSpeechKit Version is 6.2.8.1
        .binaryTarget(
            name: "DragonMedicalSpeechKit",
            path: "Sources/DragonMedicalSpeechKit/DragonMedicalSpeechKit.xcframework"
        ),
        .binaryTarget(
            name: "MicrosoftCognitiveServicesSpeech",
            path: "Sources/MicrosoftCognitiveServicesSpeech/MicrosoftCognitiveServicesSpeech.xcframework"
        ),
        .target(
            name: "DragonCopilotTurnkeyDependencies",
            dependencies: [
                "DAXKit",
                "DragonMedicalSpeechKit",
                "MicrosoftCognitiveServicesSpeech"
            ],
            path: "Sources/DragonCopilotTurnkeyDependencies"
        )
    ]
)
