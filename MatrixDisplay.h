#pragma once
#include <Arduino.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

class MatrixDisplay {
  public:
    void begin();
    void loop();
    void showBootMessage(const String& text);
    void printScrolling(const String& text);
    void clear();

  private:
    ArduinoLEDMatrix _matrix;
    char _buffer[160];
    bool _repeat = false;
    unsigned long _lastScroll = 0;

    void sanitizeToBuffer(String text);
    void scrollOnce();
};
