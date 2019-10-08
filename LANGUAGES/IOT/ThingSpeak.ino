 /*
This sketch is a combination of ADAFruits DHT sketch, WiFi101 Webclient
and The arduino example from ThingSpeak
Modified by Stephen Borsay for the MKR1000, feel free to use
 */

#include <SPI.h> //you don't need this as we arn't using the shiled just chip
#include <WiFi101.h>
#include "DHT.h"
#include <LiquidCrystal.h>
#include <ThingSpeak.h>

#define PIN A1    // what pin we're connected to, pin1 is 5th pin from end

// Uncomment whatever DHT sensor type you're using!
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT21  // DHT 21
//#define DHTTYPE DHT22  // DHT 22

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

const char* apiKey ="3E3CF7GU0OE9P5EG"; // api from ThingSpeak 

const char* MY_SSID = "YAKUT";
const char* MY_PWD =  "fener1907";   //your network MY_PWDword
unsigned long chanel_id= 876799;
// #define WEBSITE "api.thingspeak.com"
//
int status = WL_IDLE_STATUS;
//// if you don't want to use DNS (and reduce your sketch size)
//// use the numeric IP instead of the name for the server:
////IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "https://api.thingspeak.com";    // name address for Google (using DNS)
//
//// Initialize the Ethernet client library
//// with the IP address and port of the server
//// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;



void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  lcd.begin(16, 2);

  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the presence of the shield:
//  if (WiFi.status() == WL_NO_SHIELD) {
//    Serial.println("WiFi shield not present");
//    // don't continue:
//    while (true);
//  }

//  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) 
  {
    Serial.print("Attempting to connect to MY_SSID: ");
    Serial.println(MY_SSID);
    //Connect to WPA/WPA2 network.Change this line if using open/WEP network
    status = WiFi.begin(MY_SSID, MY_PWD);

//    // wait 10 seconds for connection:
    delay(10000);
  }

    ThingSpeak.begin(client);
  Serial.println("Connected to wifi");
  printWifiStatus();
  
}

void loop() {

   // Wait a few seconds between measurements.
  delay(100000);

  //prefer to use float, but package size or float conversion isnt working
  //will revise in future with a string fuction or float conversion function


  // Read temperature as Celsius (the default)


  int reading = analogRead(PIN);


// good code check
  float voltage = reading * 3.1;

  Serial.print("reading ");
 Serial.print(reading);
    Serial.print("\n");

  voltage /= 1024.0;

  Serial.print(voltage);
    Serial.print("\n");

  float temperatureC = (voltage - 0.5) * 100 ;

  Serial.print(temperatureC); Serial.println(" degrees C");

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");

  lcd.setCursor(0, 0); // Lcd first row is 0
lcd.print(temperatureC); lcd.print(" C");
lcd.setCursor(0, 1);// Lcd second row is 1
lcd.print(temperatureF);lcd.print(" F");

// good code check
   
  // if you get a connection, report back via serial:
  //if (client.connect(server, 80)) {
    

ThingSpeak.setField(1,temperatureC);
ThingSpeak.setField(2,temperatureF);

ThingSpeak.writeFields(chanel_id,apiKey);


          client.print("POST /update HTTP/1.1\n");  
          client.print("Host: api.thingspeak.com\n");
          client.print("Connection: close\n");
          
          client.print("Content-Type: application/x-www-form-urlencoded\n");
          client.print("Content-Length: ");

          client.stop();
          delay(1000);
   // } 

}


void printWifiStatus() {
  // print the MY_SSID of the network you're attached to:
  Serial.print("MY_SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
