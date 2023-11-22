#include <SPI.h>
#include <RH_RF95.h>
#include <string.h>
#include "DHT.h"
#include <math.h>



//RF95 Setup
#define RF95_FREQ 868.0
RH_RF95 driver(8, 3); // Adafruit Feather M0 with RFM95 


void WaitForAcknowledgement(){
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);
  if (driver.waitAvailableTimeout(3000))
  { 
    //Waiting for a reply/acknowledgement from the server 
    if (driver.recv(buf, &len))
    {
     //Only increments count if the server acknowledges that it received a value
      count += 1;
      Serial.print("got reply: ");
      Serial.println((char*)buf);
      return;
    } 

    else
    {
      Serial.println("recv failed");
    }

  }

  else
  {
    //Client trying to transmit data, server not connecting
    Serial.println("No reply from server");
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
