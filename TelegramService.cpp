#include "TelegramService.h"
#include "CommandHandler.h"
#include "Config.h"

TelegramService::TelegramService(const char* token)
  : _bot(token, _client) {}

void TelegramService::begin() {
  Serial.println("Telegram service ready.");
}

void TelegramService::loop(CommandHandler& handler) {
  if (millis() - _lastPoll < BOT_POLL_MS) return;
  _lastPoll = millis();

  int numNewMessages = _bot.getUpdates(_lastUpdateId);

  while (numNewMessages) {
    for (int i = 0; i < numNewMessages; i++) {
      BotMessage msg;
      msg.chatId = _bot.messages[i].chat_id;
      msg.text = _bot.messages[i].text;
      msg.fromName = _bot.messages[i].from_name;
      if (msg.fromName == "") msg.fromName = "friend";
      msg.updateId = _bot.messages[i].update_id;

      handler.handle(msg);
      _lastUpdateId = msg.updateId + 1;
    }

    numNewMessages = _bot.getUpdates(_lastUpdateId);
  }
}

bool TelegramService::sendMessage(const String& chatId, const String& text) {
  return _bot.sendMessage(chatId, text, "");
}

UniversalTelegramBot& TelegramService::rawBot() {
  return _bot;
}
