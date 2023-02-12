#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 
#define OLED_RESET 0   // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

#define ONE_WIRE_PIN D2
 
OneWire oneWire(ONE_WIRE_PIN);
DallasTemperature sensors(&oneWire);
 
void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.display();
}
 
void loop() {
    // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  
  sensors.requestTemperatures();
  display.println(sensors.getTempCByIndex(0));
  display.display();
  delay(1000);
}
