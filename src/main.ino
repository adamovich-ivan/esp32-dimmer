// main.cpp
#include "HomeSpan.h"

#include "AppleHome/AppleHomeIntegration.h"
#include "LedController.h"

const int zeroCrossingPin = 4; // Пин, к которому подключен детектор нуля
const int dimmerPin = 5;       // Пин, к которому подключено SSR
volatile int dimmingValue = 128; // Уровень диммирования (0-128), 128 для примера

AppleHomeIntegration *appleHomeIntegration;
LedController ledController(2); // Используйте пин, к которому подключен ваш светодиод

void handleZeroCross() {
  int dimTime = (78 * dimmingValue); // Расчёт времени задержки для сети 50 Гц
  digitalWrite(dimmerPin, HIGH); // Включаем SSR
  delayMicroseconds(dimTime);    // Задержка
  digitalWrite(dimmerPin, LOW);  // Выключаем SSR
}

void setup() {
  Serial.begin(115200);
  
  pinMode(zeroCrossingPin, INPUT_PULLUP); // Включение внутренней подтяжки может быть необходимо в зависимости от вашего детектора нуля
  pinMode(dimmerPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(zeroCrossingPin), handleZeroCross, RISING);

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

  // Здесь можно добавить код для изменения переменной dimmingValue, например, на основе взаимодействия с HomeKit
  // Пример использования:
  // mySmartLight->setPower(true);
  // mySmartLight->setBrightness(75);
}
