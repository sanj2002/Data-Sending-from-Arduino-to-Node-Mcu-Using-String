#define BLYNK_TEMPLATE_ID "TMPLUeoE95KX" // Templet ID from Blynk Website
#define BLYNK_DEVICE_NAME "Health Monitor"

#include<Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int PulseSensorPurplePin = A0; // Mention the Input pin if any Sensor Connected to the ESP8266
int Signal;               
int Threshold = 550;


char auth[] = "VZrM6Ekrgur8JERPEliIBBvGOcPp--sk"; // Auth Token is Avialbale in the Blynk Website           
char ssid[] = "Hotspot"; // Hotspot Name                                     
char pass[] = "12345678@@##"; // Hotspot Password

void setup() {
  Wire.begin();
  Serial.begin(9600);
   Blynk.begin(auth, ssid, pass);
}


void loop() {
  Blynk.run();
  Signal = analogRead(PulseSensorPurplePin);
  Serial.println(Signal);
  Wire.requestFrom(2,15);
  String string,string1,string2,string3;
  do
  {
    char c = Wire.read();
    string = string+c;
    string1 = string.substring(0);
    string2 = string.substring(2);
    string3 = string.substring(5);
   } while (Wire.available());
   
 char buf1[10]; // How Much Buffer we need when Receiving Data from Arduino 
 char buf2[10]; // How Much Buffer we need when Receiving Data from Arduino
 char buf3[10]; // How Much Buffer we need when Receiving Data from Arduino
 
 Serial.println(string);
 string1.toCharArray(buf1, 10);
 int bpmi = atoi(buf1);
 Serial.println(bpmi);
 string2.toCharArray(buf2, 10);
 int temp = atoi(buf2);
 Serial.println(temp);
 string3.toCharArray(buf3, 10);
 int hum = atoi(buf3);
 Serial.println(hum);
  
    Blynk.virtualWrite(V0, (Signal));
    Blynk.virtualWrite(V1, String(temp));
    Blynk.virtualWrite(V2, String(hum));
    }
