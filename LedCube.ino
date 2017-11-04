#include <Arduino.h>
#include "Pinout.h"

char outByte = 0x1;

/**************************************
 *     SETUP
 **************************************/
void setup() 
{
  setupPinDirections();
  setupStartingLevels();
}

/**************************************
 *     API
 **************************************/
void display(unsigned char d)
{
  digitalWrite(CLK, LOW);
  delay(100);

  int led_ON = 0;
  switch(d)
  {
    case 0:   led_ON = 8; break;
    case 1:   led_ON = 0; break;
    case 2:   led_ON = 1; break;
    case 4:   led_ON = 2; break;
    case 8:   led_ON = 3; break;
    case 16:   led_ON = 4; break;
    case 32:   led_ON = 5; break;
    case 64:   led_ON = 6; break;
    case 128:   led_ON = 7; break;
    default:  led_ON = 8; break;
  }

  
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(DATA(i), (i==led_ON ? HIGH: LOW));
    delay(400);
  }

  delay(1000);
  digitalWrite(CLK, HIGH);
}


void BlinkBuiltin()
{
  for (int i = 0; i<10; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }

  delay(400);
}

/**************************************
 *     LOOP
 **************************************/
void loop() 
{

  BlinkBuiltin();
  
  if (outByte == 0 || outByte > 8)
    outByte = 0x1;
  else
    outByte = outByte * 2 ;
    
  display(outByte);
  

}
