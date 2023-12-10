// main.cpp
#include "HomeSpan.h"
 
#include "AppleHome/AppleHomeIntegration.h"
#include "LedController.h"

AppleHomeIntegration *appleHomeIntegration;
LedController ledController(2); // Используйте пин, к которому подключен ваш светодиод
 

void setup() {
  Serial.begin(115200);
  
  homeSpan.setPairingCode("11122333");
  homeSpan.setQRID("111-22-333");

  homeSpan.begin(Category::Lighting,"HomeSpan LightBulb"); 

  new SpanAccessory();                              
  new Service::AccessoryInformation();            
  new Characteristic::Identify();              
  new Characteristic::Manufacturer("HomeSpan");   
  new Characteristic::SerialNumber("123-ABC");    
  new Characteristic::Model("120-Volt Lamp");     
  new Characteristic::FirmwareRevision("0.9");   

 
  ledController.begin();
  appleHomeIntegration = new AppleHomeIntegration(&ledController);
}


void loop() {
  homeSpan.poll();


  // Пример использования:
  // mySmartLight->setPower(true);
  // mySmartLight->setBrightness(75);
}
