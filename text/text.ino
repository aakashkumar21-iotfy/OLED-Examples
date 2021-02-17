#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin #(This module don't have reset pin :) )
#define SCREEN_ADDRESS 0x3C // Default Address

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void print_test();

void setup(){
 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  display.clearDisplay();
  print_test();
}

void print_test(){
  display.setTextSize(1);     
  // Normal 1:1 pixel scale
  
  display.setTextColor(SSD1306_WHITE); 
  // Set text color
  // color can be SSD1306_WHITE or SSD1306_BLACK
  
  display.println(F("Hello, world!"));
  display.print(F("Hello, world!"));
  // Print string to display
  // Wrap around F() to use Progmem instead of sram
  // Remember to call display() after drawing anything

  // int
  display.println(34);
  // float
  display.println(3.14);
  // hex
  display.print("0x");
  display.println(343, HEX);
  // binary
  display.print("0b");
  display.println(343, BIN);
  // Remember to call display() after drawing anything
//  display.display();
  display.setTextSize(2);
  display.print("123");
  display.display();
}

void loop(){
}
