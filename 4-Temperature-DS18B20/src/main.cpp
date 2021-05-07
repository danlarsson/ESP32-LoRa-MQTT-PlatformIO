#include <Arduino.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to GPIO 4
#define ONE_WIRE_BUS 13

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

DeviceAddress Thermometer;

String readDSTemperatureC() {
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);

  if(tempC == -127.00) {
    Serial.println("Failed to read from DS18B20 sensor");
    return "--";
  } else {
    return String(tempC);
  }
}


void setup(){
  Serial.begin(115200);

  sensors.begin();
  delay(20);

  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);   // First device is 0?
  Serial.println(" devices.");

  sensors.getAddress(Thermometer, 0);
  
  // sensors.setResolution(Thermometer, 9);

  Serial.print("Device 0 Resolution: ");
  Serial.println(sensors.getResolution(Thermometer), DEC);

}

void loop(){
    String temperatureC = readDSTemperatureC();
    Serial.println(temperatureC);

    delay(20000);
}