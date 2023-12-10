#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

class LedController {
public:
  LedController(int pin);
  void begin();
  void setLedState(bool on);

private:
  int ledPin;
  bool ledState;
};

#endif // LED_CONTROLLER_H
