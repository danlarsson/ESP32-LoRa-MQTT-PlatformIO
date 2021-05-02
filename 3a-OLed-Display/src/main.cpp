/**
 *                     -- Write some text to the OLED-Display --
 *  
 * The code looks much cleener and is easier to read if we split it up in different files.
 * 
 * SA3ARK - 2021
 **/

#include <Arduino.h>
#include "display_include.h"
#include "settings.h"


void setup() {
  Serial.begin(115200);
  display_setup();  // Initiate the Display
  display_splash(); // Show Splash Page
}

void loop() {
  delay(3000);  // Wait for 3 seconds
  update_display("TestText", -10, 20);  // Show some data on the display
  
  while(1);  // Stop the code.
}