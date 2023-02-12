// Get to know more throug this link https://chipglobe-dev.web.app/
# Digital Weather Station

A digital weather station based on the ESP8266 D1-mini and environmental shield.

## Overview
This weather station collects data from the environment (temperature, humidity, and atmospheric pressure) using the environmental shield, and sends it to a remote server using the ESP8266 D1-mini. The data can be visualized in real-time using a web interface.

## Hardware Requirements
- ESP8266 D1-mini
- Environmental shield

## Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software) for programming the ESP8266 D1-mini
- [ESP8266 library for Arduino](https://github.com/esp8266/Arduino)
- [Adafruit BME280 library](https://github.com/adafruit/Adafruit_BME280_Library)

## Installation
1. Clone this repository to your local machine using `git clone https://github.com/YOUR-USERNAME/Digital-Weather-Station.git`
2. Open the project in the Arduino IDE and upload the code to the ESP8266 D1-mini.
3. Connect the environmental shield to the ESP8266 D1-mini.
4. Power the ESP8266 D1-mini using a USB cable.

## Usage
1. Open a web browser and navigate to the IP address of the ESP8266 D1-mini.
2. The weather data collected from the environmental shield will be displayed on the web page in real-time.

## Contributing
If you would like to contribute to this project, please fork this repository and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
