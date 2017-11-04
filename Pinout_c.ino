#include "pinout.h"


/***************************** 
 *  PINS DIRECTION
 *****************************/
inline void setupPinDirections()
{

  for (int i = 0; i < 40; i++)
  {
    pinMode(i, OUTPUT);
  }
  
  
  /*
  pinMode(LED_BUILTIN, OUTPUT);
    
  for (int i = 0; i < 8; i++)
  {
    pinMode(DATA(i), OUTPUT);
  }
  pinMode(OUTENA_, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(PLANE_SEL, OUTPUT);
  pinMode(PWM, OUTPUT);
  */
}

/***************************** 
 *  PINS INIT VALUES
 *****************************/
inline void setupStartingLevels()
{
/*
  digitalWrite(LED_BUILTIN, LOW);
  
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(DATA(i), LOW);
  }
  digitalWrite(OUTENA_, LOW);
  digitalWrite(CLK, LOW);
  digitalWrite(PLANE_SEL, LOW);
  analogWrite(PWM, 128);
  */
}
