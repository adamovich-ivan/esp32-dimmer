#ifndef LAMP_CONTROLLER_H
#define LAMP_CONTROLLER_H

#include <Arduino.h>

class LampController {
public:
  LampController(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void turnOn() {
    digitalWrite(pin, HIGH);
    brightness = 255;
  }

  void turnOff() {
    digitalWrite(pin, LOW);
    brightness = 0;
  }

  void setBrightness(int level) {
    analogWrite(pin, level);
    brightness = level;
  }

  int getBrightness() {
    return brightness;
  }

private:
  int pin;
  int brightness = 0;
};

#endif // LAMP_CONTROLLER_H
