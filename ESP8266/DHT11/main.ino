/*
* Aim: Interface DHT11 with NodeMCU using SImpleDHT and Send Data to Blynk Cloud
*/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>
 
char auth[] = "BlynkAuthCode";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";
char pass[] = "Password";
 
/* for DHT11, 
      VCC: 5V or 3V
      GND: GND
      DATA (S): 2
*/
int DHTpin = 2;
SimpleDHT11 dht(DHTpin);
BlynkTimer timer;
 

void sendSensor()
{
  byte temperature = 0;
  byte humidity = 0;

  dht.read(&temperature, &humidity, NULL);
  
  Blynk.virtualWrite(V5, (int)temperature);
  Blynk.virtualWrite(V6, (int)humidity);

  // DHT11 sampling rate = 1hz
  delay(1500);
}

 
void setup()
{
  // Debug console
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
