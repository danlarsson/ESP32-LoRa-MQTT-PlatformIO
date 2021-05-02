#include "settings.h"

#ifndef DISPLAY_H             // Only include header once
    #define DISPLAY_H

    #include <Arduino.h>
    #include <Wire.h>
    #include <Adafruit_SSD1306.h>
    #include <Adafruit_GFX.h>

    void display_splash();
    void display_setup();
    void update_display(String, int, int);

#endif

