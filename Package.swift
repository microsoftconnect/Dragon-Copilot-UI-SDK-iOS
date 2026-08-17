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
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/5.0.0/DragonCopilotTurnkey.xcframework.zip",
            checksum: "f5b547943160f7795da0a24ba923fb8f5ab154ec9fd822de31e00cefb603e5b4"
        ),
        .binaryTarget(
            name: "MicrosoftCognitiveServicesSpeech",
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/5.0.0/MicrosoftCognitiveServicesSpeech.xcframework.zip",
            checksum: "076ecdb700c490e2de3ad49bb8d26d0712b4606824d487f99f1833bdefa0a2a9"
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
