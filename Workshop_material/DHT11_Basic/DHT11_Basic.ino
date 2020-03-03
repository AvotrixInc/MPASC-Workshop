#include <Wire.h> 
#include <DHT.h> 
#define DHTPIN 5 
#define DHTTYPE    DHT11     // DHT 11 the type of sensor in use 
DHT dht(DHTPIN, DHTTYPE); 

void setup() { 
 Serial.begin(115200); 
  dht.begin(); 
} 

void loop() { 
//read temperature and humidity 
  float t = dht.readTemperature(); 
  float h = dht.readHumidity(); 
  if (isnan(h) || isnan(t)) { 
    Serial.println("Failed to read from DHT sensor!"); 
  } 
delay(1000); 
} 
