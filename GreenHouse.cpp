#include "GreenHouse.h"

#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define buzzer 6

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

GreenHouse::GreenHouse(bool displayMsg){
//  _buzzerPin = BuzzerPin;
//  _msg = displayMsg;
  dht.begin();
  pinMode(buzzer,OUTPUT);
}

void GreenHouse::begin(int BaudRate){
  
//  dht.begin();
  Serial.begin(BaudRate);
  if(_msg){
    Serial.println("Successful GreenHouse instanciation...");  
  }
  
//  pinMode(_buzzerPin,OUTPUT);
  Serial.println("**All Instialized and good to Go...**");
  Serial.println("----------------------------------------");
}


float GreenHouse::getHumidityVal(){
  delay(1000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  return h;
}

float GreenHouse::getTemperatureVal(){
  delay(1000);
  float t = dht.readTemperature();
  return t;
}

void GreenHouse::buzzerOff(){
  digitalWrite(buzzer,LOW);
}


void GreenHouse::soundBuzzer(){
  digitalWrite(buzzer,HIGH);
}


////usage: getGasSensorVal(value)
////where value is the pin number of where you have connected the gas sensor
long GreenHouse::getGasSensorVal(int pinNumber){
  double gas_level = analogRead(pinNumber);
  return gas_level;
}


long GreenHouse::getLDR(int pinNumber){
  double ldr_val = analogRead(pinNumber);  
  return ldr_val;
}


long GreenHouse::getSoilMoisture(int pinNumber){
  double soilMoistureVal = analogRead(pinNumber);
  return soilMoistureVal;
}
