# DHT11 - reading temperatue and humidity
This is a simple example of reading the temperature and humidity every 2 seconds from the DHT11 sensror with The Things Uno. The data is send to the serial console.
## About DHT11
- Ultra low cost
- 3 to 5V power and I/O
- 2.5mA max current use during conversion (while requesting data)
- Good for 20-80% humidity readings with 5% accuracy
- Good for 0-50°C temperature readings ±2°C accuracy
- No more than 1 Hz sampling rate (once every second)
- Body size 15.5mm x 12mm x 5.5mm
- 4 pins with 0.1" spacing

## Setup

1) Install Arduino IDE from the  [official page](https://www.arduino.cc/en/Main/Software)
2) Install the following libraries:
 - [Adafruit Unified Sensor Driver](https://github.com/adafruit/Adafruit_Sensor)
- [DHT sensor library by Adafruit](https://github.com/adafruit/DHT-sensor-library)
3) Connect your DHT11 sensor (4 pins) to The Things Uno:
-  **VCC**  - connect to 3.3 - 5V power. Sometime 3.3V power isn't enough in which case try 5V power.
- **Data out -**  connect to a digital pin (digital pin 2 in our example)
- Not connected
- **Ground -** black wire

> Simply ignore pin 3, its not used. You need to to place a 10 Kohm resistor between VCC and the data pin, to act as a medium-strength pull up on the data line. 
4) Download the example in this folder - 03_DHT11_sensor_simple.ino 
5) Open the example. You can modify the following:
- Change the pin which is connected to the DHT sensor based on your circuite
```C
...
// Pin which is connected to the DHT sensor.
#define DHTPIN 2 
...
  ```
  - The interval for reading the data from the sensor (1000 is minimal)
```C
...
// interval at which to read the data (milliseconds)
const long interval = 2000;           
...
  ```
  
6) Use Micro-USB cable to connect The Things Uno to an USB port of your computer
7)  In Arduino IDE select Tools > Board > Arduino Leonardo
8)  Navigate to Tools > Port and select the port that identifies as Arduino Leonardo
9) Upload the sketch and open the Serial monitor to check the data