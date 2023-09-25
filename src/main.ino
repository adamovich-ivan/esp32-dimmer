#include "Arduino.h"
// #include "arduino_homekit_server.h"
#include "PhysicalButton/PhysicalButton.h"  // Импорт нового класса PhysicalButton
#include "WiFiConfig/WiFiConfig.h"
#include "LampController.h"  // Импорт класса LampController

// extern "C" homekit_server_config_t config;
// extern "C" homekit_characteristic_t name;
extern "C" char ACCESSORY_NAME[32];
extern "C" void accessory_init();

#define PIN_LED 2
#define PIN_BTN 4  // Пин кнопки
#define PIN_LAMP 5  // Пин для лампочки

WiFiConfig wifiConfig("Orange_Swiatlowod_AFEA_2.4", "R7EP375RFJHF");
PhysicalButton physicalButton(PIN_BTN);  // Создание объекта класса PhysicalButton
LampController lamp(PIN_LAMP);  // Создание объекта lamp класса LampController

void setup() {
  Serial.begin(115200);
  
  wifiConfig.connectToWiFi();  //инициализация wifi
  
  physicalButton.begin();  // Инициализация кнопки
  homekit_setup(); //инициализация apple home
  lamp.turnOff();  // Инициализация лампочки (выключена)

    pinMode(PIN_LED, OUTPUT);
}


void loop() {

  physicalButton.loop();
  uint32_t time = millis();  // Текущее время в миллисекундах
  static uint32_t next_heap_millis = 0;  // Время для следующего вывода информации о куче

  if (time > next_heap_millis) {  // Если пришло время для вывода
    // Вывод информации о свободной памяти и других системных параметрах
    printf("FreeHeap: %d B\n", ESP.getFreeHeap());
    next_heap_millis = time + 5000;  // Установка времени для следующего вывода
  }
  
  // Здесь можно добавить код для управления лампочкой через LampController
  // Например, lampController.turnOn(); или lampController.setBrightness(128);
  
  delay(5);  // Задержка в 5 миллисекунд для стабильности работы
}

void homekit_setup() {
  accessory_init();
  // arduino_homekit_setup(&config);
}
