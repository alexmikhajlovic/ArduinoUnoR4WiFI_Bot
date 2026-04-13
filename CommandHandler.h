#pragma once
#include <Arduino.h>
#include "BotTypes.h"

class TelegramService;
class MatrixDisplay;
class WifiManager;

class CommandHandler {
public:
  CommandHandler(TelegramService& telegram, MatrixDisplay& matrix, WifiManager& wifi);
  void handle(const BotMessage& msg);

private:
  TelegramService& _telegram;
  MatrixDisplay& _matrix;
  WifiManager& _wifi;

  String extractArgs(const String& text);
};
