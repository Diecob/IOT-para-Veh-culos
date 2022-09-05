#define BLYNK_TEMPLATE_ID "TMPLQoiNncJM"
#define BLYNK_DEVICE_NAME "auto"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_NODE_MCU_BOARD
#include "BlynkEdgent.h"

void setup() {
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  //pinMode(15, OUTPUT);
  //pinMode(0, OUTPUT);
  Serial.begin(115200);
  delay(100);
  
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  delay(0);
}
BLYNK_WRITE(V0)
{
  if(param.asInt()==1){
    digitalWrite(14, LOW);
  }
  else{
    digitalWrite(14, HIGH);
  }
}
BLYNK_WRITE(V1)
{
  if(param.asInt()==1){
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);
    Blynk.virtualWrite(V0, 255);
  }
  else{
    digitalWrite(12, HIGH);
  }
}
BLYNK_WRITE(V2)
{
  if(param.asInt()==1){
    digitalWrite(13, LOW);
  }
  else{
    digitalWrite(13, HIGH);
  }
}
BLYNK_WRITE(V3)
{
  if(param.asInt()==1){
    digitalWrite(16, LOW);
  }
  else{
    digitalWrite(16, HIGH);
  }
}
BLYNK_WRITE(V4)
{
  if(param.asInt()==1){
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(5, HIGH);
  }
}BLYNK_WRITE(V5)
{
  if(param.asInt()==1){
    digitalWrite(4, LOW);
  }
  else{
    digitalWrite(4, HIGH);
  }
}
//BLYNK_WRITE(V6)
//{
//  if(param.asInt()==1){
//    digitalWrite(15, LOW);
//  }
//  else{
//    digitalWrite(15, HIGH);
//  }
//}
//BLYNK_WRITE(V7)
//{
//  if(param.asInt()==1){
//    digitalWrite(0, LOW);
//  }
//  else{
//    digitalWrite(0, HIGH);
//  }
//}
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0,V1,V2,V3,V4,V5);
}
