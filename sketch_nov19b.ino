#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
int laststate = -1;

//==================================================
void setup() {
pinMode(7, INPUT_PULLUP);
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(6);

}

//==================================================
void loop() {
 int bState = digitalRead(7);


 if(bState != laststate){

    Serial.println(bState);
    laststate = bState;
    if (bState == HIGH) {

   
            Serial.println("pin high");
            stopActions();
  

  } else {
    
  
       startActions();
      Serial.println("pin low");

  
  }


  }

}

//==================================================
int stopActions(){

 Serial.println("stop actions");
   tmrpcm.play("finished.wav");
      delay(3000); 

}

//==================================================
int startActions(){

 Serial.println("startactions");
  tmrpcm.play("start.wav");
     delay(16000); 

}
