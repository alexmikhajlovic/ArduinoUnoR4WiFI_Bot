#pragma once
#include <Arduino.h>
#include <WiFiS3.h>

class WifiManager {
  public:
    void begin(const char* ssid, const char* pass);
    void loop();
    bool isConnected();
    String localIP();
    long rssi();

  private:
    const char* _ssid = nullptr;
    const char* _pass = nullptr;
    unsigned long _lastRetry = 0;
    void connect();
};
