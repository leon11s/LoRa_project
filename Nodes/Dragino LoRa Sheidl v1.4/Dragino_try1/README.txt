Make sure the activation methode is ABP.
In the code, change to the correct:
NWKSKEY
APPSKEY
DEVADDR

You find this on the TTN site.

The messages seem to be hopping between 868.1, 868.3, 868.5.
First the message is sent on 868.1, then on 868.3, then on 868.5 (which I think is as per LoRa Allience "guidelines"), but since e are using single channel gateway this might interfeer with prototyping.
But sometimes they still get picked up (maybe by FE gateways?)

CONNECTING SENSOR:
First I will try a DHT11 example.
Dragino Shield mounted on Arduino Uno.
DHTPIN 5 -> this pin can be just any pin, as the shield has some pins already occupied.
(check the documentation to see which pins are free). Last time I checked these were SCL, SDA, REF, 5, 4, 3, 1, 0, A0, A1, A2, A3, A4, A5.

