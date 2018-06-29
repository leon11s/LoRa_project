# Single Channel Gateway using Heltec WiFi LoRa ESP32

This is a tutorial on how to set Heltec WiFi LoRa ESP32 as a single channel gateway connected to the [TTN (The Things Network)](https://www.thethingsnetwork.org/).


## Setup

1) Install Arduino IDE from the [official page](https://www.arduino.cc/en/Main/Software)
2) Install Arduino core for ESP8266 WiFi chip as specified on this [ESP8266 Arduino core GitHub page](https://github.com/esp8266/Arduino)
3) Install Arduino core for ESP32 WiFi chip as specified on this  [ESP32 Arduino core GitHub page](https://github.com/espressif/arduino-esp32)
4) Download ZIP file from the [Single Channel LoRaWAN Gateway GitHub page](https://github.com/kersing/ESP-1ch-Gateway-v5.0)
5) Extract the ZIP file (preferably using [7-zip](http://www.7-zip.org/) )
6) Copy everything from “libraries” folder in the extracted file into your Arduino IDE libraries folder (it is usually something like C:\Users\username\Documents\Arduino\libraries)
7) Copy folder “ESP-sc-gway” from the extracted file into  your Arduino IDE libraries folder (it is usually something like C:\Users\username\Documents\Arduino\libraries)
8) Next we need to make some changes in the configuration file located in C:\Users\username\Documents\Arduino\libraries\ESP-sc-gway\ESP-sc-gway.h
- Change Gateway Ident definitions
```C
...//line 192
// Gateway Ident definitions
#define _DESCRIPTION "short_project_description_here"
#define _EMAIL "your_email"
#define _PLATFORM "plataform_name"
#define _LAT 40.058 //adjust for your gateway - Latitude
#define _LON 10.498 //adjust for your gateway - Longitude
#define _ALT 300 //adjust for your gateway - Altitude in meters
...
  ```
- Change ntp configuration based on your location
```C
...//line 200
// ntp
#define NTP_TIMESERVER "si.pool.ntp.org"	// Country and region specific
#define NTP_TIMEZONES	1				// How far is our Timezone from UTC
#define SECS_PER_HOUR	3600
#define NTP_INTR 0		// Do NTP processing with interrupts or in loop();
...
  ```
  - Change definition of wpas wpa[] (change the wifi SSID  and password and also take off the if-else-endif statement) from this:
  ```C
...//line 242
#if 0
wpas wpa[] = {
	{ "" , "" },							// Reserved for WiFi Manager
  { "aap", "aapPasswd" },
	{ "ape", "apePasswd" }
};
#else
// Place outside version control to avoid the risk of commiting it to github ;-)
#include "d:\arduino\wpa.h"
#endif
...
  ```
to this:
  ```C
...
wpas wpa[] = {
{ "" , "" }, // Reserved for WiFi Manager
{ "YOUR_WIFI_SSID", "YOUR_WIFI_PASSWD" }
};
...
  ```

9)  Start the Arduino IDE
10) Ensure you have installed both the SPIFFS and U8G2 libraries using “Sketch-> Include Library-> Manage Libraries”
11) Open the sketch “File->Examples->ESP-sc-gway” 
12) Plug in the Heltec board
13) Select your board in "Tools > Board" menu and select the COM port
> Windows should install all necessary drivers. In case you can't find the port of your device you need to manually install the USB to UART driver from [here](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).
14) When the device has booted and connected with your wifi network, find the IP address it is using from your router (or some WiFi network scanning app like Fing) and enter this IP address into a web browser to display a webpage with Gateway details
15) Copy the 8 byte “Gateway ID” from the device page
16) Log into the [TTN](https://www.thethingsnetwork.org/) console and setup a new gateway
> - You need to tick the “I’m using the legacy packet forwarder” checkbox 
> - Paste the 8 byte “Gateway ID” copied from the device webpage to the console
> - This [page](https://www.thethingsnetwork.org/docs/gateways/registration.html) can help you with the registration
17) That's it! Your gateway is ready!!! 