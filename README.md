# Dragon-Copilot-UI-SDK-iOS

## Introduction

Dragon Copilot Embedded for Mobile is an SDK that you can integrate with your iOS apps. When initialized, the SDK launches the Dragon Copilot web UI and gives your app access to the full suite of Dragon Copilot features and capabilities.

This document outlines the steps to embed Dragon Copilot Embedded for Mobile seamlessly into your iOS mobile apps.

This enables your users to:

- Perform ambient recording and stream audio to Dragon Copilot for generative AI processing in a reliable and secure manner.
- Review AI-generated notes and transcripts in the web UI.
- Use hands-free dictation of speech to text.
- Ask patient-related questions and receive answers from the AI engine.

The SDK is distributed via the Swift Package Manager, making it easy to embed and achieve the desired functionality in your iOS apps.

---

## Release Flow (AzDO → GitHub Release → SPM)

### Overview

```
AzDO pipeline
    └── Builds xcframework zips
    └── Publishes GitHub Release (e.g. v4.0.0) with zip assets
            └── triggers GitHub Actions: publish-spm-manifest.yml
                    └── Downloads zip assets from the release
                    └── Computes SHA-256 checksums
                    └── Renders Package.swift from .github/templates/Package.swift.tmpl
                    └── Commits Package.swift to default branch
                    └── Force-updates the same release tag (v4.0.0) to the manifest commit
```

### Required release assets

Each GitHub Release **must** include the following assets (exact names):

| Asset filename | Description |
|---|---|
| `DragonCopilotTurnkey.xcframework.zip` | Dragon Copilot Turnkey xcframework archive |
| `MicrosoftCognitiveServicesSpeech.xcframework.zip` | Microsoft Cognitive Services Speech xcframework archive |

The workflow will fail with a clear error message if either asset is missing.

### Tag behaviour

Release tags (e.g. `v4.0.0`) are created by AzDO and then **force-updated once** by the
GitHub Actions workflow to point at the commit that contains the generated `Package.swift`.

- The **tag name is never changed** — `v4.0.0` stays `v4.0.0`.
- The tag reference (commit SHA) is updated once per release to include the manifest.
- Consumers resolving `v4.0.0` via SwiftPM will receive the correct URL-based manifest.

> **Note:** There is a brief window between when AzDO publishes the release and when the
> workflow completes where the tag points to a commit without the rendered `Package.swift`.
> Do not add the package to a project until the workflow succeeds.

### Consuming the SDK via SwiftPM

In Xcode: **File → Add Package Dependencies** and enter:

```
https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS
```

Select the desired version rule (e.g. `v4.0.0` or **Up to Next Major Version** from `4.0.0`).

### Repository settings required (one-time)

1. **Settings → Actions → General → Actions permissions**: Actions must be enabled.
2. **Settings → Actions → General → Workflow permissions**: Set to **Read and write permissions**.  
   This allows the built-in `GITHUB_TOKEN` to commit `Package.swift` and force-update the tag.

### Troubleshooting

| Symptom | Likely cause | Fix |
|---|---|---|
| Workflow fails at asset download | Missing zip in GitHub Release | Verify AzDO uploaded both zips before publishing the release |
| Workflow fails at `git push` | Insufficient token permissions | Confirm Workflow permissions = Read and write in repo settings |
| SwiftPM cannot resolve package | Tag still points to pre-workflow commit | Wait for the workflow to complete, then retry |
