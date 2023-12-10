#ifndef APPLE_HOME_INTEGRATION_H
#define APPLE_HOME_INTEGRATION_H

#include "HomeSpan.h"
#include "LedController.h"

class AppleHomeIntegration : public Service::LightBulb {
public:
  SpanCharacteristic *power;      
  SpanCharacteristic *brightness;
  LedController* ledController;

  AppleHomeIntegration(LedController* controller);
  boolean update() override;
};

#endif // APPLE_HOME_INTEGRATION_H
