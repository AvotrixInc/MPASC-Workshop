#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h> 
#include <DHT.h> 
#define DHTPIN 5 
#define DHTTYPE    DHT11     // DHT 11 the type of sensor in use 

DHT dht(DHTPIN, DHTTYPE); 

String group="-1";
String roll="-1";
const char* ssid = "Avotrix"; 
const char* password = "9987197583"; 

void setup()  
{ 

  Serial.begin(115200); 
  WiFi.begin(ssid, password); 
  dht.begin(); 
  while (WiFi.status() != WL_CONNECTED)  
  { 
    delay(1000); 
    Serial.println("Connecting..."); 
  } 
} 

void loop()  

{ 
  float t = dht.readTemperature(); 
  float h = dht.readHumidity(); 
  if (isnan(h) || isnan(t)) { 
    Serial.println("Failed to read from DHT sensor!"); 
    t=-100; 
    h=-100; 
  } 
  if (WiFi.status() == WL_CONNECTED)  
  { 
    Serial.println("Connected"); 
    HTTPClient http; //Object of class HTTPClient 
    String url = "http://api.thingspeak.com/update?api_key=KSGE8ZQ3QPX5YKTP&field1="+group+"&field2="+String(t)+"&field3="+String(h)+"&field4="+roll; 
    http.begin(url); 
    int httpCode = http.GET(); 
    Serial.println(httpCode); 
    String s=http.getString(); 
    Serial.println(s); 
    http.end(); //Close connection 
  } 

  delay(6000); 

} 
