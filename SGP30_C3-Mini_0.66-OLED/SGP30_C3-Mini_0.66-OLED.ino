#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SGP30.h>

#define OLED_RESET 7 // GPIO0 corresponds to pin 7 for the C3-mini 
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_SGP30 sgp30; 

void setup()
{
Wire.begin(8,10);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  

  if (sgp30.begin() == false)
  {

    while (1)
      ;
  }


}

void loop()
{

  delay(1000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(40, 10);
  display.setTextColor(WHITE);

  if (sgp30.IAQmeasure())
  {

    display.println("CO2: ");
    display.setTextSize(1);
    display.setCursor(75, 10);
    display.println(sgp30.eCO2);

    display.setTextSize(1);
     display.setCursor(40, 23);
    display.println("TVOC: ");

    display.setTextSize(1);
     display.setCursor(75, 23);
    display.println(sgp30.TVOC);

    display.display();
  }
  else
  {
    display.println("Error!");
    display.display();

    while (1)
    {
      ;
    }
    
  }
  
  
}
