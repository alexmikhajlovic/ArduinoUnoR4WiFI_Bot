#pragma once
#include <Arduino.h>
#include <WiFiSSLClient.h>
#include <UniversalTelegramBot.h>
#include "BotTypes.h"

class CommandHandler;

class TelegramService {
public:
  TelegramService(const char* token);
  void begin();
  void loop(CommandHandler& handler);
  bool sendMessage(const String& chatId, const String& text);
  UniversalTelegramBot& rawBot();

private:
  WiFiSSLClient _client;
  UniversalTelegramBot _bot;
  unsigned long _lastPoll = 0;
  long _lastUpdateId = 0;
};
