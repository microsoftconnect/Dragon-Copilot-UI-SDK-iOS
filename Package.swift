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
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/v5.0.0-beta-5535282/DragonCopilotTurnkey.xcframework.zip",
            checksum: "482b5d2dd81037ba3ade61ccf621dc788e9ff91896ed1e97f65033aa8e1cbee4"
        ),
        .binaryTarget(
            name: "MicrosoftCognitiveServicesSpeech",
            url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS/releases/download/v5.0.0-beta-5535282/MicrosoftCognitiveServicesSpeech.xcframework.zip",
            checksum: "32d3e44cbc0bf128ac2492812c89954399722e184667540a8ae23c430cb8251a"
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
