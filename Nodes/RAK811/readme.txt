RAK811 official GitHub.
https://github.com/RAKWireless/RAK811-AT-Command

How to connect RAK811 to The Things Network
https://github.com/RAKWireless/RAK811-AT-Command/blob/master/Application%20Notes/How%C2%A0To%C2%A0Connect%C2%A0Lora%C2%A0RAK811%C2%A0to%C2%A0The%20Things%20Network.pdf

- kolkr vidm se Arduino rab sam za komunikacijo (komp > arduino > RAK). Sam to se sliš brezveze.
TO-DO
> pogledat kako se kodo uploada direkt na RAK, da ne rabm arduinota zravn dajat.


Arduino + RAK811
https://www.hackster.io/naresh-krish/using-the-rak811-lora-module-with-arduino-a38de8


RAK811
at+<command> list
https://github.com/RAKWireless/RAK811-AT-Command/blob/master/Software%20Development/RAK811%C2%A0LoRa%C2%A0AT%C2%A0Command%C2%A0V1.3.pdf




************
Lahko se sam spodnjem primeru sledi. Sam še nimamo gatewaya in ne mormo sprobat vse
************

Getting Started with LoRa RAK811
https://www.hackster.io/naresh-krish/getting-started-with-the-rak811-lora-node-67f157

Using the board as a standalone LoRa node.
The RAK 811 already has an AT command based firmware running on it out of the box that supports a wide variety of operations. The board can be used along with an Arduino UNO as well via the serial port which I will cover in another article. The board can also be programmed using the STM32 coIDE. This will also be covered in a different tutorial


- zdownloadaš Realterm za komunikacijo (UART z RAK811). Tm morš met: 8Data bits, 0 parity bits, 1 stop bit.
Najdeš port.
Baud je 115200 (default). Klikneš "OPEN".
Greš pod "Send"
Tm maš te ukaze "at+<command>". Send ASCII.
Obkljukan morš met +CR in +LF
