#include <TheThingsNetwork.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Set your DevAddr, NwkSKey, AppSKey and the frequency plan
const char *devAddr = "26011F33";
const char *nwkSKey = "29FE1A8A743001E78FF3EF4294F2A9D6";
const char *appSKey = "64B0DADCACA7A38CED4E658D99DB7307";

#define loraSerial Serial1
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

//DHT11
#define DHTPIN            2         // Pin which is connected to the DHT sensor.
#define DHTTYPE           DHT11     // DHT 11 

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);
DHT_Unified dht(DHTPIN, DHTTYPE);


void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);

   // Initialize DHT.
  dht.begin();
  debugSerial.println("DTH11 ready");
 
  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000)
    ;

  //Activate the device via ABP.
  debugSerial.println("-- PERSONALIZE"); 
  ttn.personalize(devAddr, nwkSKey, appSKey);

  debugSerial.println("-- STATUS");
  ttn.showStatus();
 
}

void loop()
{
  debugSerial.println("-- LOOP");
  
  // Read the temperature and humididty
  float temperatureReading = getDhtTemperature();
  float humidityReading = getDhtHumidity();
  
  // Encode float as int
  int16_t temperatureReadingInt = (int16_t) temperatureReading;
  int16_t humidityReadingInt = (int16_t) humidityReading;
  
  // Log the values
  debugSerial.print("Temperature: ");
  debugSerial.println(temperatureReadingInt);
  debugSerial.print("Humidity: ");
  debugSerial.println(humidityReadingInt);

  // Encode int as bytes
  byte payload[3];
  payload[0] = highByte(temperatureReadingInt);
  payload[1] = lowByte(temperatureReadingInt);
  payload[2] = lowByte(humidityReadingInt);
  
  ttn.sendBytes(payload, sizeof(payload));

  //Wait 10 s
  delay(10000);
}

float getDhtTemperature(){
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    return 0.0;
  }
  else {
    return event.temperature;
  }
}

float getDhtHumidity(){
  sensors_event_t event; 
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
     return 0.0;
  }
  else {
    return event.relative_humidity;
  }
}

