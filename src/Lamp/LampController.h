#ifndef LAMP_CONTROLLER_H
#define LAMP_CONTROLLER_H

#include <Arduino.h>
#include "ObserverPattern.h"

class LampController : public Subject {
public:
  LampController(int pin);
  void turnOn();
  void turnOff();
  void toggle();
  void setBrightness(int level);
  int getBrightness();
  
  void addObserver(Observer* observer) override;
  void removeObserver(Observer* observer) override;
  void notifyObservers() override;

private:
  int pin;
  int brightness = 0;
  bool isOn;
};

#endif // LAMP_CONTROLLER_H
