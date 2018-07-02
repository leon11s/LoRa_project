#include "DHT.h"

#define DHTPIN 7     // what digital pin we're connected to

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 meritve!");
  dht.begin();
}

void loop() {
  // Beremo vlago
  float vlaga = dht.readHumidity();
  // Beremo temperaturo v stopinjah C
  float temperatura = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(vlaga) || isnan(temperatura)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Vlaga: ");
  Serial.print(vlaga);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C ");

    // Wait a few seconds between measurements.
  delay(2000);

}
