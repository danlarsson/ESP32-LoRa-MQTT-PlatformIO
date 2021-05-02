#include <Arduino.h>

//Include libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

//LoRa Tansciever pins setup [TTGO32 LoRa OLED] [TTGO T-Beam]
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

// Lora frequence Select
//433E6 for Asia
#define BAND 866E6
#define SPRED 8      // Spreading Factor - ranges from 6-12,default 7

// Define the LED pin 
// [TTGO32 LoRa OLED]  GPIO 2
// [TTGO32 T-Beam]  GPIO 14
#define LED LED_BUILTIN    // Use PlatformIO board configuration


void setup() {
  Serial.begin(115200);  // Set serial port speed

  pinMode(LED, OUTPUT);  // Set LED pin to Output

  Serial.println("Welcome to LoRa TX");
  
  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);

  // Starting LoRa on selected frequency
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
  // Set LoRa Spreading Factor
  LoRa.setSpreadingFactor(SPRED);           
  Serial.println("LoRa started"); 
}


void loop() {
  digitalWrite(LED, HIGH);   // LED ON
  Serial.println("Sending packet");

  LoRa.beginPacket();         // Starting LoRa TX
  LoRa.print("Hej hej ");
  LoRa.print("Jomenhej ");
  LoRa.print("Blir det problem nu?");
  LoRa.endPacket();          // Ending LoRa TX

  Serial.println("Packet sent");
  digitalWrite(LED, LOW);    //LED OFF

  delay(5000);   // Wait for 5 seconds
}