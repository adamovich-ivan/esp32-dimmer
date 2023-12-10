#include "LedController.h"
#include <Arduino.h>

LedController::LedController(int pin) : ledPin(pin), ledState(LOW) {}

void LedController::begin() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Убедитесь, что светодиод выключен при запуске
}

void LedController::setLedState(bool on) {
  if (ledState != on) {
    ledState = on;
    digitalWrite(ledPin, ledState ? HIGH : LOW);
  }
}
