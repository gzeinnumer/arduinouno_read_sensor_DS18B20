#include <OneWire.h>
#include <DallasTemperature.h>
 
const int oneWireBus = 2;   
 
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);
 
void setup(void) {
  Serial.begin(115200);
  Serial.println("Dallas Temperature IC Control Library Demo");
  sensors.begin();
}
 
void loop(void) {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  
  Serial.print("Celcius temperature ");
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print("Fahrenheit temperature ");
  Serial.print(temperatureF);
  Serial.println("ºF");
  delay(5000);
}
//https://naylampmechatronics.com/blog/46_Tutorial-sensor-de-temperatura-DS18B20.html
