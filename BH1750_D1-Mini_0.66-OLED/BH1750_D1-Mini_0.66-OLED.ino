#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <BH1750.h>

#define OLED_RESET 0 // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

BH1750 light(0x23);

void setup() {
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  display.clearDisplay();
  display.setCursor(2, 0);
  display.setTextSize(1);
  
  if (light.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    display.println("L: ");
    display.print(light.readLightLevel());
  }
  else {
    display.println("Error!");
  }
  
  display.display();
  delay(1000);
}
