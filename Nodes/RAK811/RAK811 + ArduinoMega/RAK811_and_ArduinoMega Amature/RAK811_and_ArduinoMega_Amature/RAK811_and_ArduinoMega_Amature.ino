//string to hold the response of a command in rak811 
String response = ""; 
int counter = 0;


void setup() {
  //configure Serial1, this could also be a 
  //software serial. 
  Serial2.begin(115200);
  //configure the mail RX0 and TX0 port on arduino
  Serial.begin(115200); 
  
  while(Serial.available()){
    char ch = Serial.read();
    response += ch;
  }
  Serial.println("(Balki) Serial ostanek: \t"+response);
  response = "";
  
  while(Serial2.available()){
    char ch = Serial1.read();
    response += ch;
  }
  Serial.println("(Balki) Serial1 ostanek: \t"+response);
  response = "";
  
  Serial.println("(Balki) SETUP DONE");
} 


//the famous arduino loop function. runs continuosly 
void loop() { 
  Serial.println("(Balki) LOOP");
  //try getting the version of the board firmware 
  //Serial.println("(Balki) VERSION:");
  sendCommand("at+version\r\n"); 
  delay(3000);

} 

/** 
* Function to send a command to the  
* lora node and wait for a response 
*/ 

void sendCommand(String atComm){ 
  //Serial.println("(Balki) Command send to be sent to RAK811 \t"+atComm);
  //Serial.println("(Balki) Response when entering sendCommand() \t"+response);
  
  response = ""; 

  //Serial.println("(Balki) Response should be nothing now: \t"+response);

  //char buf[] = {'a','t','+','v','e','r','s','i','o','n'};
  //Serial1.write(buf, 10);
  Serial2.println("lrnfddn");
  delay(10);
  
  //Serial.println("(Balki) Serial1.print(atComm)");
  Serial.println("(Balki) entering WHILE loop");

  Serial.println(Serial2.available());
  response = Serial2.readString(); 
  Serial.println(response);
   
  //Serial.println(response);
}




/** 
* send the rak811 to sleep for time  
* specified in millis paramteer 
*/ 

void sleep(unsigned long milliseconds){ 
 sendCommand("at+sleep\r\n"); 
 delay(milliseconds); 
 //send any charcater to wakeup; 
 sendCommand("***\r\n"); 
} 



/** 
* reset board after the specified time delay millisenconds 
* <mode> = 0 Reset and restart module 
= 1 Reset LoRaWAN or LoraP2P stack and Module will reload LoRa 
configuration from EEPROM 
*/ 

void resetChip(int mode, unsigned long delaySec=0){ 
 delay(delaySec); 
 String command = (String)"at+reset=" + mode + (String)"\r\n"; 
 sendCommand(command); 
} 


/** 
* Reload the default parameters of LoraWAN or LoraP2P setting 
*/ 

void reload(unsigned long delaySec){ 
 delay(delaySec); 
 sendCommand("at+reload\r\n"); 
} 


/** 
* Function to set module mode 
* <mode> = 0 LoraWAN Mode (default mode) 
= 1 LoraP2P Mode 
*/ 
void setMode(int mode){ 
 String command = (String)"at+mode=" + mode + (String)"\r\n"; 
 sendCommand(command);   
} 



/** 
* Function to send data to a lora gateway; 
* <type> = 0 send unconfirmed packets 
= 1 send confirmed packets 
<port> = 1-223 port number from 1 to 223 
<data>= <hex value> hex value(no space). The Maximum length of <data> 64 bytes 
*/ 

void sendData(int type, int port, String data){ 
 String command = (String)"at+send=" + type + "," + port + "," + data + (String)"\r\n"; 
 sendCommand(command); 
} 


/** 
* Function to send a join request 
* allowed methods "otaa" and "abp" 
*/ 

void sendJoinReq(String method){ 
 String command = (String)"at+join=" + method + "\r\n"; 
 sendCommand(command); 
} 

/** 
* Function to set the connection config 
* < dev_addr >:<address> 
<address>-------------------4 bytes hex number representing the 
device address from 00000001 – 
FFFFFFFE 
<dev_eui>:<eui> 
<eui>-------------------------- 8-byte hexadecimal number 
representing the device EUI 
<app_eui>:<eui> 
<eui>----------------------------8-byte hexadecimal number 
representing the application EUI 
<app_key>:<key> 
- 11 - 
<key>----------------------------16-byte hexadecimal number 
representing the application key 
<nwks_key>:<key> 
<key>-------------------------16-byte hexadecimal number 
representing the network session key 
<apps_key>:<key> 
<key>------------------------ 16-byte hexadecimal number representing 
the application session key 
<tx_power>:<dbm> 
<dbm>------------------- LoRaWAN Tx Power 
<adr>:<status> 
<status>----------------------------- string value representing 
the state, either “on” or “off”. 
<dr>:<data rate> 
<data rate>-----------------------decimal number representing the 
data rate, from 0 and 4, but within 
the limits of the data rate range for 
the defined channels. 
< public_net >:<status> 
<status>------------------- string value representing 
the state, either “on” or “off”. 
< rx_delay1 >:<delay> 
<delay>-------------------decimal number representing 
the delay between the transmission 
and the first Reception window 
in milliseconds, from 0 to 65535. 
*/ 
void setConnConfig(String key, String value){ 
 sendCommand("at+set_config=" + key + ":" + value + "\r\n"); 
} 
