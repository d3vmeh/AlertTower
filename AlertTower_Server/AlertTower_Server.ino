#include <SPI.h>
#include <RH_RF95.h>
#include <string.h>
#include "DHT.h"
#include <math.h>



//RF95 Setup
#define RF95_FREQ 868.0
RH_RF95 driver(8, 3); // Adafruit Feather M0 with RFM95 

AlertTower tower;

struct AlertTower{
  char id[3];
  char message[3];
  float temperatureF;
};

void TransmitMessage(AlertTower tower){
  uint8_t buf[sizeof(tower)];
  memcpy(buf, &tower, sizeof(tower));
  driver.send(buf, sizeof(tower));
}

bool WaitForFeedback(){
return true;
}



void setup() {
  //Initializing RF95 Module
  if (!driver.init())
    Serial.println("init failed");

  //Setting RF95 Frequency
  if (!driver.setFrequency(RF95_FREQ)) {
    Serial.println("setFrequency failed");
    while (1);
  }
  Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);
  driver.setTxPower(15, false);

}

void loop() {
  // put your main code here, to run repeatedly:

}
