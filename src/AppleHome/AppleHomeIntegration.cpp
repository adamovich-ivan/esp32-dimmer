#include "AppleHomeIntegration.h"

AppleHomeIntegration::AppleHomeIntegration(LedController* controller) : Service::LightBulb() {
  power = new Characteristic::On();
  brightness = new Characteristic::Brightness(50);
  ledController = controller;
}

boolean AppleHomeIntegration::update() {
  ledController->setLedState(power->getVal());

  Serial.print("Состояние лампочки: ");
  Serial.println(power->getVal() ? "Включено" : "Выключено");

  Serial.print("Яркость лампочки: ");
  Serial.println(brightness->getVal());

  return true;
}
