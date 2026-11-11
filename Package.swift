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
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/6.0.0/DragonCopilotTurnkey.xcframework.zip",
            checksum: "3edcfe98b880f6ef73817ce98ffb422d5929b91f579ed30f886ea21a46c8a707"
        ),
        .binaryTarget(
            name: "MicrosoftCognitiveServicesSpeech",
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/6.0.0/MicrosoftCognitiveServicesSpeech.xcframework.zip",
            checksum: "d0c5322f33eb7615138faa7086a14b837bccc377dc92a4ba4f6443c6ced3862f"
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
