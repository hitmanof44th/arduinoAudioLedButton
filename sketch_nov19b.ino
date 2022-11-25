#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
int laststate = -1;

//==================================================
void setup() {
pinMode(7, INPUT_PULLUP);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(5);

}

//==================================================
void loop() {
 int bState = digitalRead(7);


 if(bState != laststate){

    Serial.println("bstate:"+bState);
     Serial.println("last:"+laststate);
 
    laststate = bState;
        Serial.println("laststate:"+laststate);
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

digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
 Serial.println("stop actions");
   tmrpcm.play("finished.wav");

      delay(3000); 

}

//==================================================
int startActions(){

int Count = 0;

digitalWrite(6, LOW);
 Serial.println("startactions");
       delay(1000);
  tmrpcm.play("start.wav");


  for (Count; Count <= 16; Count++)
  {
 
      digitalWrite(5, LOW);
      delay(500);
      digitalWrite(5, HIGH);
      delay(500);

      if(Count == 8){
       tmrpcm.play("start.wav");
      }
  }


      digitalWrite(5, LOW);
 

    // delay(16000); 

}
