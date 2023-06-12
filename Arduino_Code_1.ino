#include <SoftwareSerial.h>
#include <DHT.h>
#include <Wire.h>

#define DHTPIN 2 // Sensor Input pin Connection to Arduino
#define DHTTYPE DHT11 // Sensor Input pin Connection to Arduino

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(A1,INPUT);
  Serial.begin(9600);
  Wire.begin(2);
  Wire.onRequest(Request);
  dht.begin();// Sensor Setup and Intalising
}

char air[5]; // How Many Character Send from Arduino to ESP8266 Mention in Digits 
char temp[5]; // How Many Character Send from Arduino to ESP8266 Mention in Digits 
char hum[5];  // How Many Character Send from Arduino to ESP8266 Mention in Digits 

void loop() {
  char cdata; // Character Loop 
  int airquality = analogRead(A1); // Mention In Integer form from data Recived by Sensor 
  int temperature = dht.readTemperature(); // Mention In Integer form from data Recived by Sensor
  int humidity = dht.readHumidity(); // Mention In Integer form from data Recived by Sensor

  // Send the sensor data to the ESP8266
  Serial.print("Airquality: ");
  Serial.print(airquality);
  Serial.print(", Temperature: ");
  Serial.print(temperature);
  Serial.print(", Humidity: ");
  Serial.println(humidity);
  
   itoa(airquality,air,10);
    Serial.println(air);
  
    itoa(temperature,temp,10);
    Serial.println(temp);

    itoa(humidity,hum,10);
    Serial.println(hum);

  
}
void Request()
{
  Wire.write(air); 
  Wire.write(","); 
  Wire.write(temp);
  Wire.write(",");
  Wire.write(hum);
  Wire.write("\n");
}
