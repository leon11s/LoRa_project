/*
 * No code was good, so I'm writting it on my own.
 * RAK811 OTAA Example was confusing. Couldn't decipher which Serial connection was being used for what (it declared new Serial connection and then tried to pass it to their library, but then it also tried to use it to communicate with Arduino).
 */
String RAK811_response = ""; // String in which to write the response we get from RAK811



void setup() {
  Serial.begin(115200); // Start the communication with PC
  while(Serial.available()){
    RAK811_response += (char)Serial.read();
  }
  Serial.println("SETUP -> Serial.read() ostanki");
  
  Serial1.begin(115200); // Start communication with RAK811
  /*
   * Arduino TX1 -> RAK811 RX
   * Arduino RX1 -> RAK811 TX
   * CHECK if this is correct. In one example it says that they are switched on the RAK811 board
   */
   while(Serial1.available()){
    RAK811_response += (char)Serial1.read();
    Serial.println("SETUP -> Serial1.read() ostanki");
   }
   delay(2000);
   Serial.println("SETUP DONE");
}


void loop() {
  Serial.println("LOOP \n *******************************");
  Serial1.print("at+version\r\n"); // you must end your commands with Carrige Return (CR - \r) and New Line (LF - \n)
  while(Serial1.available()){
    Serial.println("Serial1.available() \t"+(String)Serial1.available()+"\t\t"+ RAK811_response);
    char ch = Serial1.read();
    RAK811_response += ch; 
  }
  Serial.println(RAK811_response);
  RAK811_response = "";
  delay(5000);
}
