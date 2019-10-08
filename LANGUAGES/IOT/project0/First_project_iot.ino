//-----------------------------------------------
//This sketch is combined from Adafruit DHT sensor and tdicola for dht.h library
// https://learn.adafruit.com/dht/overview
// https://gist.github.com/teos0009/acad7d1e54b97f4b2a88
//other Authors Arduino and associated Google Script:
//Aditya Riska Putra
//Ahmed Reza Rafsanzani
//Ryan Eko Saputro
//See Also:
//http://jarkomdityaz.appspot.com/
//
//ELINS UGM
//
//Modified for Hackster.io project for the MKR1000
//by Stephen Borsay(Portland, OR, USA)
//Since Arduino can't https, we need to use Pushingbox API (uses http)to run
//the Google Script (uses https). Alternatly use Ivan's SecureWifi encryption


#include <WiFi101.h>
#include "DHT.h"

#define PIN A5    // what pin we're connected to, pin1 is 5th pin from end

// Uncomment whatever DHT sensor type you're using!
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT21  // DHT 21
//#define DHTTYPE DHT22  // DHT 22

DHT dht(PIN, DHTTYPE);

const char WEBSITE[] = ""; //pushingbox API server
const String devid = "vFEC09BDAD7EAEFE"; //device ID on Pushingbox for our Scenario

const char* MY_SSID = "YAKUT";
const char* MY_PWD =  "fener1907";


int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)


void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(MY_SSID);
    //Connect to WPA/WPA2 network.Change this line if using open/WEP network
    status = WiFi.begin(MY_SSID, MY_PWD);

    // wait 10 seconds for connection:
    delay(10000);
  }

  Serial.println("Connected to wifi");
  printWifiStatus();

}

void loop() {

  // Wait between measurements.
  delay(10000);

  //prefer to use float, but package size or float conversion isnt working
  //will revise in future with a string fuction or float conversion function


  // Read temperature as Celsius (the default)


  int reading = analogRead(PIN);

  String c = "c";
  String f = "f";


  float voltage = reading * 3.3;

  voltage /= 1024.0;

  float temperatureC = (voltage - 0.5) * 100 ;

  Serial.print(temperatureC); Serial.println(" degrees C");

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");

  // Check if any reads failed and exit early (to try again).


  // Compute heat index in Fahrenheit (the default)

  // Compute heat index in Celsius (isFahreheit = false)






  Serial.println("\nSending Data to Server...");
  // if you get a connection, report back via serial:
  WiFiClient client;  //Instantiate WiFi object, can scope from here or Globally

  //API service using WiFi Client through PushingBox then relayed to Google
  if (client.connect(WEBSITE, 80))
  {
    client.print("GET /pushingbox?devid=" + devid
                 + "&temperatureC="      + (String) temperatureC
                 + "&c="                 +  "c"
                 + "&temperatureF="     + (String) temperatureF
                 + "&f="                +  "f"

                );

    // HTTP 1.1 provides a persistent connection, allowing batched requests
    // or pipelined to an output buffer
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(WEBSITE);
    client.println("User-Agent: MKR1000/1.0");
    //for MKR1000, unlike esp8266, do not close connection
    client.println();
    Serial.println("\nData Sent");
  }
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
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
