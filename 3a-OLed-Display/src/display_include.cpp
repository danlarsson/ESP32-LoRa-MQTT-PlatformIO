#include <Arduino.h>
#include "display_include.h"
#include "settings.h"

// Define OLED Screen as display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);


void display_setup() {
    //reset OLED display via software
    pinMode(OLED_RST, OUTPUT);
    digitalWrite(OLED_RST, LOW);
    delay(20);
    digitalWrite(OLED_RST, HIGH);

    //initialize OLED
    Wire.begin(OLED_SDA, OLED_SCL);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) {   // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        while (1); // Don't proceed, loop forever
    }
}


void display_splash() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("ESP32 OLED Display");
  display.setCursor(0,10);
  display.print("Working Fine");
  // Here we draw the line.
  display.drawLine(0, 20, 128, 20, WHITE);
  display.display();
}


void update_display(String LoRaData, int rssi, int snr) {
   display.clearDisplay();
   
   display.setCursor(0,0);
   display.print("  -DISPLAY TEST-");
   
   display.setCursor(0,20);
   display.print("Received packet:");
   
   display.setCursor(0,30);
   display.print(LoRaData);

   display.setCursor(0,40);
   display.print("RSSI:");
   display.setCursor(30,40);
   display.print(rssi);

   display.setCursor(60,40);
   display.print("SNR:");
   display.setCursor(90,40);
   display.print(snr);
   
   display.display();   
}