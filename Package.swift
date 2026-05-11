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
    dependencies: [
        .package(url: "https://github.com/microsoftconnect/DAXKit-SDK-iOS", .upToNextMajor(from: "1.6.0"))
    ],
    targets: [
        .binaryTarget(
            name: "DragonCopilotTurnkey",
            path: "Sources/DragonCopilotTurnkey/DragonCopilotTurnkey.xcframework"
        ),
        .binaryTarget(
            name: "MicrosoftCognitiveServicesSpeech",
            path: "Sources/MicrosoftCognitiveServicesSpeech/MicrosoftCognitiveServicesSpeech.xcframework"
        ),
        .target(
            name: "DragonCopilotTurnkeyDependencies",
            dependencies: [
                "MicrosoftCognitiveServicesSpeech", .product(name: "DAXKit", package: "DAXKit-SDK-iOS")
            ],
            path: "Sources/DragonCopilotTurnkeyDependencies"
        )
    ]
)
