//Determine which type of DHT sensor is used.
#include "DHT.h" //DHT Bibliothek
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 0
Adafruit_SSD1306 display(OLED_RESET);

//Pin an welchem der DHT11 Sensor angeschlossen ist.
//Beim DHT11 Shield ist es der digitale Pin D4.
#define DHTPIN D4 
 
//Festlegen welcher Typ von DHT Sensor verwendet wird.
#define DHTTYPE DHT11

//Initialize the sensor with the pin and type
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600); //Begin serial communication at 9600 baud.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay(); 
  dht.begin(); //DHT communication begin.
}
 
void loop() {
  //DHT22 sensor returns a new value every 2 seconds.
  //Value so it is not worth to run the loop constantly. 
  //to let it run.
  delay(2000);
 
  //read the temperature and humidity
  double humidity = dht.readHumidity();
  //read the temperature in degrees Celsius
  double temperatureC = dht.readTemperature();
  //read temperature in degrees Fahrenheit
  //the boolean parameter is used to "control" whether
  //read the temperature in Fahrenheit or Celsius.
  double temperatureF = dht.readTemperature(true);
 
  //Check if the values were read successfully.
  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
    Serial.println("Error reading data.");
    return;
  }
   //clears display
  display.clearDisplay();
  display.setTextSize(1);

  //display temperature
  display.setCursor(32,8);
  display.println("DHT22");
  display.setCursor(32,9);
  display.println("_____");  
  display.setCursor(32,17);
  String tempValue = String(temperatureC);
  display.println("T: "+tempValue+"C");

//display humidity
  display.setCursor(32,25);
  String humValue = String(humidity);
  display.println("H: "+humValue+"%");
  
  display.display();
  delay(2000);
}
