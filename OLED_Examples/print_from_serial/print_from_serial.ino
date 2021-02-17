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
  Serial.begin(115200);
 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  display.clearDisplay();
  display.setTextSize(1);     
  // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); 
}


String in_string;
int char_count = 0; // chars recieved till now

void loop() {
  if( Serial.available() >0 ){
    in_string = Serial.readString();
    char_count += in_string.length();
    if(char_count >172){
      char_count = 0;
      display.clearDisplay();
    }
    display.print(in_string);
    display.display();
  }
}
