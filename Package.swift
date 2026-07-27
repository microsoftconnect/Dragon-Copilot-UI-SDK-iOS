// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.
//
// GENERATED FILE — do not edit by hand.
// This manifest is rendered by the GitHub Actions release workflow
// (.github/workflows/publish-spm-manifest.yml) for the GitHub SPM distribution repo
// microsoftconnect/Dragon-Copilot-UI-SDK-iOS. The remote binary targets are downloaded
// from the matching GitHub release assets.
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
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/v5.0.0-beta-01/DragonCopilotTurnkey.xcframework.zip",
            checksum: "d04769ea44b4178eb288ab1e6553ed95625838cee278d5af4be8e587bdadeb51"
        ),
        .binaryTarget(
            name: "MicrosoftCognitiveServicesSpeech",
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/v5.0.0-beta-01/MicrosoftCognitiveServicesSpeech.xcframework.zip",
            checksum: "f4e2b5d859ae70fa4e1aa46d6f5b95273ece060f21ac3aef9ffeee34177f6011"
        ),
        .target(
            name: "DragonCopilotTurnkeyDependencies",
            dependencies: [
                "MicrosoftCognitiveServicesSpeech",
                .product(name: "DAXKit", package: "DAXKit-SDK-iOS")
            ],
            path: "Support/DragonCopilotTurnkeyDependencies"
        )
    ]
)
