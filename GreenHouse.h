#ifndef GH
#define GH

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "Wprogram.h"
#endif

class GreenHouse{
  public:
    GreenHouse(bool displayMsg);
    void buzzerOff();
    void soundBuzzer();
    long getGasSensorVal(int pinNumber);
    long getLDR(int pinNumber);
    long getSoilMoisture(int pinNumber);
    void begin(int BaudRate=9600);
    float getHumidityVal();
    float getTemperatureVal();

  private:
    bool _msg;
       
};
#endif
