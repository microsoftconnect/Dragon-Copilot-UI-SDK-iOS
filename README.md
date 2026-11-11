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

Use semantic versions for dependency rules:

- Stable releases (recommended):
  ```swift
  .package(url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS", from: "5.0.0")
  ```
- Prerelease/beta validation:
  ```swift
  .package(url: "https://github.com/microsoftconnect/Dragon-Copilot-UI-SDK-iOS", exact: "5.0.0-beta-01")
  ```

Then choose the **DragonCopilotTurnkey** library product.
