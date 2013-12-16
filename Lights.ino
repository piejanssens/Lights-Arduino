#include <RCSwitch.h>
#include <SPI.h>
#include <Ethernet.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  //init the Serial with 9600 baud
  Serial.begin(9600);

  pinMode(10, OUTPUT);                       // set the SS pin as an output (necessary!)
  digitalWrite(10, HIGH);                    // but turn off the W5100 chip!

   //enable the Receive on interrupt 0 (its Port 2 on Arduino)
  mySwitch.enableReceive(0);
  //enable the Send on Port 3
  mySwitch.enableTransmit(3); 

  Serial.println("Start");
}

void loop() {

  mySwitch.switchOn("11010", "00100");

  // Wait a second
  delay(1000);
  
  // Switch off
  mySwitch.switchOff("11010", "00100");
  
  // Wait another second
  delay(1000); 
}
