#include "LampController.h"

LampController::LampController(int pin) : pin(pin), isOn(false) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void LampController::turnOn() {
  digitalWrite(pin, HIGH);
  brightness = 255;
  isOn = true;
  notifyObservers(); // Предположим, что у вас есть такая функция в ObserverPattern
}

void LampController::turnOff() {
  digitalWrite(pin, LOW);
  brightness = 0;
  isOn = false;
  notifyObservers();
}

void LampController::toggle() {
  if (isOn) {
    turnOff();
  } else {
    turnOn();
  }
}

void LampController::setBrightness(int level) {
  analogWrite(pin, level);
  brightness = level;
  notifyObservers();
}

int LampController::getBrightness() {
  return brightness;
}

void LampController::addObserver(Observer* observer) {
  // Реализация метода
}

void LampController::removeObserver(Observer* observer) {
  // Реализация метода
}

void LampController::notifyObservers() {
  // Реализация метода
}
