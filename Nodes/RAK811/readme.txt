***********
Problem!
**********

RAK811 sam od sebe deluje. Ce se z njim pove�e� preko kompa lahko z at+<command> upravlja� z njim.
Ampak Arduino+RAK811 NE DELUJE.

Z Brin�kotom sva �la cez vse.
Kabli so pravilno vezani (TX na Arduino se ve�e na TX na RAK811, ker je potem na RAK811 zamenjano).
Arduino po�ilja zadeve.
RAK811 zna odgovort (ce ne druzga, k ga reseta� Arduino dobi "Welcome to RAK811"). 
PROBLEM je biu potem, k si dejansko at+<command> poslau. Ker kle ni vec zaznal odgovora (niti ERROR-1).
Na koncu smo pr�li do tega.
> Arduino po�lje signal.
> RAK811 cip zazna signal.
> RAK811 cip ne po�lje odgovora




RAK811 official GitHub.
https://github.com/RAKWireless/RAK811-AT-Command

How to connect RAK811 to The Things Network
https://github.com/RAKWireless/RAK811-AT-Command/blob/master/Application%20Notes/How%C2%A0To%C2%A0Connect%C2%A0Lora%C2%A0RAK811%C2%A0to%C2%A0The%20Things%20Network.pdf

************
Lahko se sam spodnjem primeru sledi.
************

Getting Started with LoRa RAK811
https://www.hackster.io/naresh-krish/getting-started-with-the-rak811-lora-node-67f157

Using the board as a standalone LoRa node.
The RAK 811 already has an AT command based firmware running on it out of the box that supports a wide variety of operations. The board can be used along with an Arduino UNO as well via the serial port which I will cover in another article. The board can also be programmed using the STM32 coIDE. This will also be covered in a different tutorial


- zdownloada� Realterm za komunikacijo (UART z RAK811). Tm mor� met: 8Data bits, 0 parity bits, 1 stop bit.
Najde� port.
Baud je 115200 (default). Klikne� "OPEN".
Gre� pod "Send"
Tm ma� te ukaze "at+<command>". Send ASCII.
Obkljukan mor� met +CR in +LF


