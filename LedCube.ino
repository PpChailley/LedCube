#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Pinout.h"

unsigned char outByte = 0x0;

/**************************************
 *     SETUP
 **************************************/
void setup() 
{
  setupPinDirections();
  setupStartingLevels();

  outByte = 0x0;
  Serial.begin(9600);    
}

/**************************************
 *     API
 **************************************/
void display(unsigned char d)
{
    Serial.print("Displaying ");
    Serial.println(d, HEX);
    

  for (int i = 0; i<8; i++)
  {
    if ( (d&(0x1<<i)) != 0)
    {
      digitalWrite(DATA(i), HIGH); 
    }
    else
    {
      digitalWrite(DATA(i), LOW); 
    }
    delay(100);
  }

  delay(1000);
  digitalWrite(CLK, HIGH);
  delay(200);
  digitalWrite(CLK, LOW);

}


void BlinkBuiltin()
{
  for (int i = 0; i<5; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }

  delay(200);
}

void SweepBus()
{
  for (int i=0; i<8; i++)
  {
    digitalWrite(DATA(i), HIGH);
    delay(30);
    digitalWrite(DATA(i), LOW);
  }
}

/**************************************
 *     LOOP
 **************************************/
void loop() 
{
  BlinkBuiltin();

  display(outByte);
  outByte +=7;

  SweepBus();
  SweepBus();

}
