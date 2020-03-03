#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
 
ESP8266WebServer server(80);
 
void setup() {
 
  Serial.begin(115200);
  WiFi.begin("Avotrix", "9987197583");  //Connect to the WiFi network
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
 
    delay(500);
    Serial.println("Waiting to connect…");
 
  }
 
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP
 
  server.on("/other", []() {   //Define the handling function for the path
    String a="<!DOCTYPE html> <html> <style> h1{ color: rgb(237,77,64); font-family: Arial, Helvetica, sans-serif; font-size: 350%; text-align: center; font-weight: bold; } h2{ color: rgb(45,62,80); font-family: Arial, Helvetica, sans-serif; text-align: center; font-weight: bold; } li{ 	font-family: Arial, Helvetica, sans-serif; 	color: rgb(45,62,80); 	font-weight: bold; } .b{ 	font-family: Arial, Helvetica, sans-serif; 	color: rgb(237,77,64); 	font-weight: bold; } </style> <body> 	<h1>Welcome to Avotrix</h1> 	<p><h2>What we offer?</h2></p> 	<ul> 		<li>Seminars</li> 		<li>Webinars</li> 		<li>Workshops</li> 		<li>IoT Courses</li> 		<li>Splunk Courses</li> 		<li>Hackathons</li> 		<li>Internship opportunities</li> 	</ul> 	<br><br><br> 	<footer><div class='b'>Kindly visit our website <a href='http://www.avotrix.com'>Avotrix</a> to know more about us or can reach us directly on 7777004497</div></footer> </body> </html>";
    
    server.send(200, "html", a);
 
  });
 
  server.on("/", root);    //Associate the handler function to the path
  server.begin();                    //Start the server
  Serial.println("Server listening");
 
}
 
void loop() {
 
  server.handleClient();         //Handling of incoming requests
 
}
 
void root() {            //Handler for the rooth path
 String html="<!DOCTYPE html><html><h1>Hello Welcome to Avotrix Workshop</h1></html>";
  server.send(200, "html", html);
 
}
