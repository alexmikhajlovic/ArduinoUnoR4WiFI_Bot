#include "CommandHandler.h"
#include "TelegramService.h"
#include "MatrixDisplay.h"
#include "WifiManager.h"
#include "Secrets.h"

CommandHandler::CommandHandler(TelegramService& telegram, MatrixDisplay& matrix, WifiManager& wifi)
  : _telegram(telegram), _matrix(matrix), _wifi(wifi) {}

String CommandHandler::extractArgs(const String& text) {
  int spaceIndex = text.indexOf(' ');
  if (spaceIndex < 0) return "";
  String args = text.substring(spaceIndex + 1);
  args.trim();
  return args;
}

void CommandHandler::handle(const BotMessage& msg) {
  if (msg.chatId != ALLOWED_CHAT_ID) {
    _telegram.sendMessage(msg.chatId, "Unauthorized chat.");
    return;
  }

  if (msg.text == "/start") {
    String reply = "Hello, " + msg.fromName + "!\n";
    reply += "Commands:\n";
    reply += "/start\n/status\n/print your text";
    _telegram.sendMessage(msg.chatId, reply);
  }
  else if (msg.text == "/status") {
    String reply = "Board online\n";
    reply += "IP: " + _wifi.localIP() + "\n";
    reply += "RSSI: " + String(_wifi.rssi()) + " dBm";
    _telegram.sendMessage(msg.chatId, reply);
  }
  else if (msg.text.startsWith("/print")) {
    String args = extractArgs(msg.text);
    if (args.length() == 0) {
      _telegram.sendMessage(msg.chatId, "Usage:\n/print your text here");
    } else {
      _matrix.printScrolling(args);
      _telegram.sendMessage(msg.chatId, "Printing:\n" + args);
    }
  }
  else {
    _telegram.sendMessage(msg.chatId, "Unknown command.");
  }
}
