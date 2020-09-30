/******************************************************************************
   MicroOLED_Demo.ino
   SFE_MicroOLED Library Demo
   Jim Lindblom @ SparkFun Electronics
   Original Creation Date: October 27, 2014

   This sketch uses the MicroOLED library to draw a 3-D projected
   cube, and rotate it along all three axes.

   Development environment specifics:
    Arduino 1.0.5
    Arduino Pro 3.3V
    Micro OLED Breakout v1.0

   This code is beerware; if you see me (or any other SparkFun employee) at the
   local, and you've found our code helpful, please buy us a round!

   Distributed as-is; no warranty is given.
 ******************************************************************************/
//#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

#include "RTC.h" //Include RTC library included with the Aruino_Apollo3 core
APM3_RTC myClock; //Create instance of RTC class

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_RESET 9  // Connect RST to pin 9
#define PIN_DC    8  // Connect DC to pin 8
#define PIN_CS    10 // Connect CS to pin 10
#define DC_JUMPER 0 // Set to either 0 (SPI, default) or 1 (I2C) based on jumper, matching the value of the DC Jumper

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// Declare a MicroOLED object. The parameters include:
// 1 - Reset pin: Any digital pin
// 2 - D/C pin: Any digital pin (SPI mode only)
// 3 - CS pin: Any digital pin (SPI mode only, 10 recommended)

MicroOLED oled(PIN_RESET, PIN_DC, PIN_CS); //Example SPI declaration, comment out if using I2C
//MicroOLED oled(PIN_RESET, DC_JUMPER); //Example I2C declaration, uncomment if using I2C

// I2C is great, but will result in a much slower update rate. The
// slower framerate may be a worthwhile tradeoff, if you need more
// pins, though.

const int middleY = oled.getLCDHeight() / 2;
const int middleX = oled.getLCDWidth() / 2;

unsigned long lastDraw = 0;
const int CLOCK_SPEED = 1000;

void setup()
{
  Serial.begin(115200);
  Serial.println("SparkFun RTC Example");

  myClock.setToCompilerTime();
  
  delay(100);
  //Wire.begin(); //set up I2C bus, uncomment if you are using I2C

  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  delay(1000);     // Delay 1000 ms
  oled.clear(PAGE); // Clear the buffer.

  //randomSeed(analogRead(A0) + analogRead(A1));  
}

void tellTime()
{
  myClock.getTime();

  int timeHour = myClock.hour;
  int timeMin = myClock.minute;
  
  String dispTime = timeHour + ":" + timeMin;
 
  oled.setFontType(2);
  oled.setCursor(middleX - (oled.getFontWidth() * (dispTime.length() / 2)),
                 middleY - (oled.getFontHeight() / 2));
  oled.print(dispTime);
}

void loop()
{
   if (lastDraw + CLOCK_SPEED < millis())
  {
    lastDraw = millis();
    // Add a second, update minutes/hours if necessary:
    tellTime();
  }
}
