# Arduino UNO R4 WiFi - Bot

[![Arduino UNO R4 WiFi](https://docs.arduino.cc/static/16cbbb52c1bd49edecf62ab3fe8d1d2e/image.svg)](https://docs.arduino.cc/hardware/uno-r4-wifi)


## 📦 Requirements

Before getting started, ensure you have the following:

- **Arduino IDE** (latest version recommended)
- **Arduino UNO R4 WiFi** board
- Required libraries:
  - [ArduinoJson](https://docs.arduino.cc/libraries/arduinojson)
  - [ArduinoGraphics](https://docs.arduino.cc/libraries/arduinographics)
  - [UniversalTelegramBot](https://docs.arduino.cc/libraries/universaltelegrambot)


## 🚀 Installation

### 1. Install Dependencies

Install the required libraries via the Arduino Library Manager:

- Open Arduino IDE  
- Go to **Sketch → Include Library → Manage Libraries**
- Search for and install each dependency listed above

### 2. Configure Secrets

Create your credentials file from the example:

```bash
cp Secrets.h.example Secrets.h
nano Secrets.h
```

Update the new file with your credentials.

### 3. Upload the Code

1. Connect your Arduino UNO R4 WiFi via USB
2. Select the correct Board and Port in the Arduino IDE
3. Click Upload

## 🛠️ Troubleshooting
- Ensure the correct board (UNO R4 WiFi) is selected
- Double-check WiFi credentials and bot token
- Verify all libraries are installed and up to date
- Open Serial Monitor for debugging output
