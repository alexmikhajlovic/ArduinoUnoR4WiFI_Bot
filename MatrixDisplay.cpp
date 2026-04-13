#include "MatrixDisplay.h"
#include "Config.h"

void MatrixDisplay::begin() {
  _matrix.begin();
  clear();
}

void MatrixDisplay::showBootMessage(const String& text) {
  printScrolling(text);
}

void MatrixDisplay::printScrolling(const String& text) {
  sanitizeToBuffer(text);
  _repeat = true;
  scrollOnce();
}

void MatrixDisplay::loop() {
  if (_repeat && millis() - _lastScroll > MATRIX_REPEAT_GAP_MS) {
    _lastScroll = millis();
    scrollOnce();
  }
}

void MatrixDisplay::clear() {
  _matrix.beginDraw();
  _matrix.clear();
  _matrix.endDraw();
}

void MatrixDisplay::sanitizeToBuffer(String text) {
  text.trim();
  if (text.length() == 0) text = "EMPTY";

  String cleaned = "   ";
  for (unsigned int i = 0; i < text.length(); i++) {
    char c = text[i];
    cleaned += (c >= 32 && c <= 126) ? c : ' ';
  }
  cleaned += "   ";
  cleaned.toUpperCase();

  if (cleaned.length() >= sizeof(_buffer)) {
    cleaned = cleaned.substring(0, sizeof(_buffer) - 1);
  }

  cleaned.toCharArray(_buffer, sizeof(_buffer));
}

void MatrixDisplay::scrollOnce() {
  _matrix.beginDraw();
  _matrix.stroke(0xFFFFFFFF);
  _matrix.textScrollSpeed(MATRIX_SCROLL_SPEED);
  _matrix.textFont(Font_5x7);
  _matrix.beginText(0, 1, 0xFFFFFF);
  _matrix.println(_buffer);
  _matrix.endText(SCROLL_LEFT);
  _matrix.endDraw();
}
