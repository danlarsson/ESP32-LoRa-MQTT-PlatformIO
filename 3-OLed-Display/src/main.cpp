/**
 *     -- Write some text to the OLED-Display --
 * 
 * SA3ARK - 2021
 **/

#include <Arduino.h>

//Libraries for OLED Display
//#include <Adafruit_I2CDevice.h>  // Hack to solve a bug https://community.platformio.org/t/adafruit-gfx-lib-will-not-build-any-more-pio-5/15776/13
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// Default Pins
// https://github.com/espressif/arduino-esp32/blob/b92c58d74b151c7a3b56db4e78f2d3c90c16446f/variants/ttgo-lora32-v1/pins_arduino.h

//OLED pins [TTGO32 LoRa OLED]
//#define OLED_SDA 4
//#define OLED_SCL 15
//#define OLED_RST 16

//OLED pins [TTGO32 T-Beam]
//#define OLED_SDA 22
//#define OLED_SCL 21
//#define OLED_RST 16

// OLED Screen size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


// Define OLED Screen as display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

void setup() {
  Serial.begin(115200);

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

  // Show some text
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

void loop() {
  // No code here today
}