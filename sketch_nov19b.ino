#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;


void setup() {
pinMode(7, INPUT_PULLUP);
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(5);


}

void loop() {
 int bState = digitalRead(7);

    Serial.println(bState);
    if (bState == HIGH) {

        Serial.println("pin high");
            tmrpcm.play("start.wav");


  } else {

      Serial.println("pin low");
  



  }

}
