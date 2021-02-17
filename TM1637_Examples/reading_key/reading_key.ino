#include "SevenSegmentTM1637.h"
const byte PIN_CLK = 9;   // define CLK pin (any digital pin)
const byte PIN_DIO = 4;   // define DIO pin (any digital pin)
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

void setup() {
  Serial.begin(9600);
  display.begin();            // initializes the display
}
uint8_t input_data;
void loop(){
    input_data = display.comReadByte();
    if(input_data != 0xFF ){ // If no key is pressed tm1637 returns 0xFF
    for(int i=0; i<8; i++){
      if(keys[i] == input_data) {
        Serial.print("Read: ");
        Serial.println(input_data, BIN);
        Serial.print("Key: ");
        display.print(i+1); 
        Serial.println(i+1);
      }
    }
  }
}