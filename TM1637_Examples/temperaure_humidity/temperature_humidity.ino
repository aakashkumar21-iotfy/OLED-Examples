#include "SevenSegmentTM1637.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

const uint8_t keys[8] = {0b11101000,
                        0b11101001,
                        0b11101010,
                        0b11101011,
                        0b11110100,
                        0b11110101,
                        0b11110110,
                        0b11110111};

#define KEY_DHT keys[0]
#define KEY_HUMD keys[1]

#define DHTPIN 5     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11

const byte PIN_CLK = 9;   // define CLK pin (any digital pin)
const byte PIN_DIO = 4;   // define DIO pin (any digital pin)

SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  dht.begin();
  display.setBacklight(100);  // set the brightness to 100 %
  delay(1000);                // wait 1000 ms
};

int temp;
int hum;
void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  // Print to Serial
  Serial.print("Temp:");
  Serial.print(temp);
  Serial.print(" Hum:");
  Serial.println(hum);
  // Print to display
  display.print(temp);
  display.setCursor(0,2);
  display.print(hum);
  display.setCursor(0,0);    
  delay(2000);
};