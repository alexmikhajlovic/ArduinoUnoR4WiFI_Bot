#include "WifiManager.h"
#include "Config.h"

void WifiManager::begin(const char* ssid, const char* pass) {
  _ssid = ssid;
  _pass = pass;
  connect();
}

void WifiManager::connect() {
  Serial.println("Connecting to WiFi: " + String(_ssid) + " ");
  while (WiFi.begin(_ssid, _pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(2000);
  }
  Serial.println("WiFi connected: " + WiFi.localIP().toString());
}

void WifiManager::loop() {
  if (WiFi.status() != WL_CONNECTED && millis() - _lastRetry > WIFI_RETRY_MS) {
    _lastRetry = millis();
    connect();
  }
}

bool WifiManager::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}

String WifiManager::localIP() {
  return WiFi.localIP().toString();
}

long WifiManager::rssi() {
  return WiFi.RSSI();
}
