#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"
#include <DHT.h>
 
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);
 
#define DHTPIN D4
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
 
void setup()   
{
  Serial.begin(115200);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
 display.display();
}
 
void loop() 
{
  delay(1000);


  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float bat = ESP.getVcc();// / 1024;
  // Check if any reads failed and exit early (to try again). 
  if (isnan(h) || isnan(t) || isnan(f)) {
    display.println("Failed to read from DHT sensor!");
    return;
  }
         // Efface l'écran et positionne le curseur dans le coin supérieur gauche - clear display and set cursor on the top left corner
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  // Température en Celcius - Temperature in Celcius
  display.println("Temp.");
  display.print(t);
  display.println(" c");
  // Humidité en % - Humidity in % 
  display.println("Humidity");
  display.print(h);
  display.println(" %");
  display.display();
}
