# DHT11 - sending temperatue and humidity to TTN

This is an example of sending the temperature and humidity from the DHT11 sensor over The Things Network to an application with The Things Uno.

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
2) Install the TTN library:
	- Navigate to Sketch > Include Library > Manage Libraries....
	- Search for TheThingsNetwork and click the result to select it.
	- Click the Install button which should appear.
	> or you can download the library from [here](https://github.com/TheThingsNetwork/arduino-device-lib)				

3) Connect your DHT11 sensor (4 pins) to The Things Uno:
-  **VCC**  - connect to 3.3 - 5V power. Sometime 3.3V power isn't enough in which case try 5V power.
- **Data out -**  connect to a digital pin (digital pin 2 in our example)
- Not connected
- **Ground -** black wire

> Simply ignore pin 3, its not used. You need to to place a 10 Kohm resistor between VCC and the data pin, to act as a medium-strength pull up on the data line. 
4) Download the example in this folder - 04_DHT11_sensor_send_to_ttn.ino 
5) Open the example. You can modify the following:
- Change the pin which is connected to the DHT sensor based on your circuite

6) Connect the The Things Uno to your computer using the Micro-USB cable.
7) Select  **Tools > Board > Arduino Leonardo**
8) Select  **Tools > Port**  > the port that identifies as  **Arduino Leonardo**:
> On Windows, you might need to [install drivers](https://www.arduino.cc/en/Guide/ArduinoLeonardoMicro#toc2).

function Decoder(bytes, port) {
  // Decode an uplink message from a buffer
  // (array) of bytes to an object of fields.
  var decoded = {};

  // Decode bytes to int
  if(bytes[0] == 255) {
    var temperatureVal = (bytes[0] << 8) | bytes[1];
    temperatureVal = temperatureVal - 65536;
  }else{
    var temperatureVal = (bytes[0] << 8) | bytes[1];
  }
  
  var humidityVal = bytes[2];

  decoded.temperature = temperatureVal;
  decoded.humidity = humidityVal;
  
  return decoded;
}
}

https://github.com/TheThingsNetwork/workshops/tree/master/The%20Things%20Network