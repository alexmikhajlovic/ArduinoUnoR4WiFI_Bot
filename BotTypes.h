#pragma once
#include <Arduino.h>

struct BotMessage {
  String chatId;
  String text;
  String fromName;
  long updateId;
};

struct ParsedCommand {
  String name;
  String args;
};
