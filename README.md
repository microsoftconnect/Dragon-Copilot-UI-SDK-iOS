# Dragon-Copilot-UI-SDK-iOS

# Introduction

Dragon Copilot Embedded for Mobile is an SDK that you can integrate with your iOS apps. When initialized, the SDK launches the Dragon Copilot web UI and gives your app access to the full suite of Dragon Copilot features and capabilities.

This document outlines the steps to embed Dragon Copilot Embedded for Mobile seamlessly into your iOS mobile apps.

This enables your users to:

- Perform ambient recording and stream audio to Dragon Copilot for generative AI processing in a reliable and secure manner.
- Review AI-generated notes and transcripts in the web UI.
- Use hands-free dictation of speech to text.
- Ask patient-related questions and receive answers from the AI engine.

The SDK is distributed via the Swift Package Manager, making it easy to embed and achieve the desired functionality in your iOS apps.

## Swift Package Manager Integration

Add the package in Xcode via **File → Add Package Dependencies** and enter:

```
https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS
```

Select the desired version (e.g. `v4.0.0`) and choose the **DragonCopilotTurnkey** library product.

---

## Release Flow

Releases are published by an Azure DevOps pipeline that uploads the binary xcframework archives and creates a GitHub Release. A GitHub Actions workflow then automatically generates and commits the `Package.swift` manifest.

### Expected release asset names

Every GitHub Release **must** contain exactly these two assets:

| Asset | Description |
|---|---|
| `DragonCopilotTurnkey.xcframework.zip` | Main Dragon Copilot Turnkey xcframework |
| `MicrosoftCognitiveServicesSpeech.xcframework.zip` | Microsoft Cognitive Services Speech xcframework |

### Release sequence

1. **Azure DevOps** runs the release pipeline, uploads both `.xcframework.zip` assets, and publishes a GitHub Release (e.g. `v4.0.0`).
2. **GitHub Actions** workflow (`.github/workflows/publish-spm-manifest.yml`) triggers automatically on `release.published`.
3. The workflow downloads the release assets, computes SHA-256 checksums, and renders `Package.swift` from `.github/templates/Package.swift.tmpl`.
4. `Package.swift` is committed to the default branch (if the content changed).
5. The **same release tag** (e.g. `v4.0.0`) is force-updated to point at the manifest commit.  
   ⚠️ **Note:** Tags are force-updated exactly once during this finalization step. The tag name never changes — `v4.0.0` stays `v4.0.0`. Consumers should allow a brief delay after a release is first published before resolving the package in Xcode to ensure finalization is complete.

### Repository settings required

- **Settings → Actions → General → Workflow permissions**: set to **Read and write permissions** so the built-in `GITHUB_TOKEN` can commit `Package.swift` and update the tag. No additional secrets are required.
