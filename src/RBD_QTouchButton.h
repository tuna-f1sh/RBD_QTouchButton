#ifndef RBD_QTOUCHBUTTON_H
#define RBD_QTOUCHBUTTON_H

#include <Arduino.h>
#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
#include <Adafruit_FreeTouch.h>

namespace RBD {
  class QTouchButton {
    public:
      QTouchButton(Adafruit_FreeTouch *qt, uint8_t touch_threshold=30, uint8_t release_threshold=30);
      void setDebounceTimeout(unsigned long value);
      bool isPressed();
      bool isReleased();
      bool onPressed();
      bool onReleased();
      void invertReading();
    private:
      Adafruit_FreeTouch *_qt;
      bool _invert = false;
      bool _state = false;
      bool _temp_state = false;
      bool _has_been_pressed  = false;
      bool _has_been_released = false;
      uint8_t _touch_threshold;
      uint8_t _release_threshold;
      int32_t _last_count = 0;
      void _updateState();
      Timer _debounce_timer;
  };
}
#endif
