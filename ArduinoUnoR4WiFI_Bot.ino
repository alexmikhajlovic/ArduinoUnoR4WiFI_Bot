#include "Secrets.h"
#include "Config.h"
#include "WifiManager.h"
#include "MatrixDisplay.h"
#include "TelegramService.h"
#include "CommandHandler.h"

WifiManager wifi;
MatrixDisplay matrixDisplay;
TelegramService telegram(BOT_TOKEN);
CommandHandler commands(telegram, matrixDisplay, wifi);

void setup() {
  Serial.begin(115200);
  delay(500);

  wifi.begin(WIFI_SSID, WIFI_PASS);
  telegram.begin();

  matrixDisplay.begin();
  matrixDisplay.showBootMessage("READY");
}

void loop() {
  wifi.loop();
  telegram.loop(commands);
  matrixDisplay.loop();
}
