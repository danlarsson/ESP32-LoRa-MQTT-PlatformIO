#include <Arduino.h>

// Include libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

//LoRa Tansciever Setup Pins [TTGO32 LoRa OLED] [TTGO T-Beam]
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

// LoRa Frequency
//433E6 for Asia
#define BAND 866E6
#define SPRED 8      // Spreading Factor - ranges from 6-12,default 7

// Define the LED pin 
// [TTGO32 LoRa OLED]  GPIO 2
// [TTGO32 T-Beam]  GPIO 14
#ifndef LED_BUILTIN  // If not set in IDE
  #define LED_BUILTIN  2  // Use PlatformIO board configuration
#endif


void setup() {
  Serial.begin(115200);  // Set Serial port speed

  pinMode(LED_BUILTIN, OUTPUT);  // Set LED pin to Output data.

  Serial.println("Welcome to LoRa RX!");
  
  // SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  // Setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);

  // Start LoRa on right Frequency and stop if there is a problem.
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);  // Never ending loop.
  }
  
  LoRa.setSpreadingFactor(SPRED);           // ranges from 6-12, default 7 see API docs

  // Test CRC https://github.com/sandeepmistry/arduino-LoRa/issues/261
  // LoRa.enableCrc();

  // Test Sync Word to make a "hidden" network (default 0x34)
  // LoRa.setSyncWord(0x42);

  Serial.println("LoRa started"); 
}


String LoRaData;  // A place to save the LoRa RX 

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    digitalWrite(LED_BUILTIN, HIGH);  // LED ON
   
    Serial.print("Recieved Packet: ");

    // long freqErr = LoRa.packetFrequencyError();   // frequency offset between the receiver centre frequency and that of an incoming LoRa signal
    int rssi = LoRa.packetRssi();  // Get the Signal Strength 
    int snr = LoRa.packetSnr();    // Get the Signal to Noice Ratio
    
    // Recieve and print the data.
    while(LoRa.available()) {
      LoRaData = LoRa.readString();
      Serial.println(LoRaData);
    }

    Serial.print("RSSI: ");
    Serial.print(rssi);

    Serial.print(" / SNR: ");
    Serial.println(snr);
    Serial.println("");  // Empty Line

    digitalWrite(LED_BUILTIN, LOW);  // LED OFF
  }
}