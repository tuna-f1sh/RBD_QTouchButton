/* Project: touch_test */

#include <Arduino.h>
#include <Wire.h>

#include "RBD_QTouchButton.h"

#define Serial SerialUSB

Adafruit_FreeTouch qt = Adafruit_FreeTouch(A3, OVERSAMPLE_32, RESISTOR_50K, FREQ_MODE_NONE);
RBD::QTouchButton btn0(&qt);

void setup() {
  qt.begin();
}

void loop() {
  if (btn0.onPressed()) {
    Serial.println("pressed");
  } else if (btn0.onReleased()) {
    Serial.println("released");
  }
}
