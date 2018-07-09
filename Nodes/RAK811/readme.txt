***********
Problem!
**********

RAK811 sam od sebe deluje. Ce se z njim povežeš preko kompa lahko z at+<command> upravljaš z njim.
Ampak Arduino+RAK811 NE DELUJE.

Z Brinškotom sva šla cez vse.
Kabli so pravilno vezani (TX na Arduino se veže na TX na RAK811, ker je potem na RAK811 zamenjano).
Arduino pošilja zadeve.
RAK811 zna odgovort (ce ne druzga, k ga resetaš Arduino dobi "Welcome to RAK811"). 
PROBLEM je biu potem, k si dejansko at+<command> poslau. Ker kle ni vec zaznal odgovora (niti ERROR-1).
Na koncu smo pršli do tega.
> Arduino pošlje signal.
> RAK811 cip zazna signal.
> RAK811 cip ne pošlje odgovora




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


- zdownloadaš Realterm za komunikacijo (UART z RAK811). Tm morš met: 8Data bits, 0 parity bits, 1 stop bit.
Najdeš port.
Baud je 115200 (default). Klikneš "OPEN".
Greš pod "Send"
Tm maš te ukaze "at+<command>". Send ASCII.
Obkljukan morš met +CR in +LF


