#include "GreenHouse.h"

GreenHouse greenhouse(true);

void setup() {
  greenhouse.begin(9600);
}

void loop() {
  float humidity = greenhouse.getHumidityVal();
  float temperature = greenhouse.getTemperatureVal();
  if (isnan(humidity) || isnan(temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity Values: ");
  Serial.println(humidity);
  Serial.print("Temperature Values: ");
  Serial.println(temperature);

  float gasValue = greenhouse.getGasSensorVal("A0");
  Serial.print("Gas Values: ");
  Serial.println(gasValue);
  float threshold = 300.00;
  gasValue >= threshold ?greenhouse.buzzerOff():greenhouse.soundBuzzer();


  float light = greenhouse.getLDR("A1");

  float moisture = greenhouse.getSoilMoisture("A2");
  Serial.print("Light Values: ");
  Serial.println(light);
  Serial.print("Moisture Values: ");
  Serial.println(moisture);
}
