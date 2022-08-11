#include <Arduino.h>
#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
#include <Adafruit_FreeTouch.h>
#include "RBD_QTouchButton.h"

namespace RBD {
  QTouchButton::QTouchButton(Adafruit_FreeTouch *qt, uint8_t touch_threshold, uint8_t release_threshold)
  : _debounce_timer() {
    _qt = qt;
    _touch_threshold = touch_threshold;
    _release_threshold = release_threshold;
    setDebounceTimeout(200);
  }

  void QTouchButton::setDebounceTimeout(unsigned long value) {
    _debounce_timer.setTimeout(value);
  }

  bool QTouchButton::isPressed() {
    _updateState();
    if (_invert) { return !_state; }
    else { return _state; }
  }

  bool QTouchButton::isReleased() {
    return !isPressed();
  }

  bool QTouchButton::onPressed() {
    if (isPressed() && !_has_been_pressed) {
      return _has_been_pressed = true;
    }
    return false;
  }

  bool QTouchButton::onReleased() {
    if (isReleased() && !_has_been_released) {
      return _has_been_released = true;
    }
    return false;
  }

  void QTouchButton::invertReading() {
    _invert = !_invert;
  }

  void QTouchButton::_updateState() {
    int32_t count = _qt->measure();
    int32_t diff = count - _last_count;
    _last_count = count;

    // if the change is positive, it's a touch
    if (diff > _touch_threshold) {
      _temp_state = true;
    // if the change is negative, it's a release
    } else if ((diff * -1) > _release_threshold) {
      _temp_state = false;
    }

    if (_debounce_timer.isExpired()) {
      if (_state != _temp_state) {
        _debounce_timer.restart();
        _state = _temp_state;
        if (_invert) {
          if (_state) { _has_been_pressed = false; }
          else { _has_been_released = false; }
        } else {
          if (_state) { _has_been_released = false; }
          else { _has_been_pressed = false; }
        }
      }
    }
  }
}
