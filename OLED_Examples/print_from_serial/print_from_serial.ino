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
bool cp;
bool scrolling = false;

void loop() {
  if( Serial.available() >0 ){
    in_string = Serial.readString(); 
    if(in_string[0] == '/'){
      switch(in_string[1]){
        case 'c': display.cp437(true); cp = true; break;
        case 's': display.cp437(false); cp = false; break;
        case 'd': display.clearDisplay(); display.display(); display.setCursor(0,0);  break;
        case '1': display.setTextSize(1); break;
        case '2': display.setTextSize(2); break;
        case 'l': if(!scrolling){
                    scrolling = true;
                    display.startscrollleft(0x00, 0xFF);
                  }
                  else {
                     scrolling = false;
                     display.stopscroll();
                  }
                  break;
        case 'r': if(!scrolling){
                    scrolling = true;
                    display.startscrollright(0x00, 0x00);
                  }
                  else {
                     scrolling = false;
                     display.stopscroll();
                  }
                  break;
        
      }
    }
    else{
      if(cp){
        for(char &c: in_string) display.write(c);
        display.display();
      }
      else{
        display.print(in_string);
        display.display();
      }
      
    }
  }
}
