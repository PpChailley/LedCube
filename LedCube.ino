#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Pinout.h"

unsigned char busData[] = {0x0,0x01,0xFE,0x02,0x04,0x08, 0x10, 0xEF,0x20, 0x40, 0x80};



/**************************************
 *     SETUP
 **************************************/
void setup() 
{
  setupPinDirections();
  setupStartingLevels();

  Serial.begin(9600);    
}

/**************************************
 *     API
 **************************************/
void display(unsigned char d)
{
  //DRIVE(OUTENA_, HIGH, 500);

  Serial.println(d, HEX);

  for (int i = 0; i<8; i++)
    digitalWrite(DATA(i), IF_BITSET(d,i,HIGH));

  delay(1000);
  DRIVE(CLK, LOW, 300);
  delay(1000);
  DRIVE(PLANE_SEL, LOW, 500);
  
}


void BlinkBuiltin()
{
  for (int i = 0; i<5; i++)
  {
    DRIVE(LED_BUILTIN, HIGH,50)
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
  static int dataIndex = 0;
  
  BlinkBuiltin();

  display(busData[dataIndex]);
  dataIndex = (dataIndex++) % sizeof(values);

  FADELOW(PWM, 2000);
  FADEHIGH(PWM, 2000);

}
