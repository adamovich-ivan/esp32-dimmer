#include "HomeSpan.h"  

class MyLightBulb : public Service::LightBulb {
  public:
    SpanCharacteristic *power;      
    SpanCharacteristic *brightness; 

    MyLightBulb() : Service::LightBulb() {
      power = new Characteristic::On();
      brightness = new Characteristic::Brightness(50); 
    }
 
    boolean update() {
      // Здесь код для управления физическим устройством
      return true;
    }
};

//Nazwa: Orange_Swiatlowod_60A0 
//Hasło: No25UXzfUEevFYs9oG

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

  new MyLightBulb(); // Наш кастомный сервис для лампочки
}  

void loop(){
  homeSpan.poll();  // Запуск HomeSpan
}  
