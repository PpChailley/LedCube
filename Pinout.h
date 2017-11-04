#ifndef __PINOUT_H__
  #define __PINOUT_H__

  #include <Arduino.h>


  /**
   *   Bit macros 
   */
  #define   NOT(l)   (l==HIGH?LOW:HIGH)
  
  #define   IF_BITSET(data, bitIndex, level)    \
              (  (d&(1<<i)) ? level : NOT(level) ) 

  #define   DRIVE(pin, level, duration)         \
                digitalWrite(pin, level);       \
                delay(duration);                \
                digitalWrite(pin, NOT(level));  

  #define   FADELOW(pin, duration)                                    \
                for (int fadeIndex=255; fadeIndex >=0; fadeIndex--)   \
                {                                                     \
                  analogWrite(pin,fadeIndex);                         \
                  delay(duration/256);                                \
                }                    

  #define   FADEHIGH(pin, duration)                                    \
                for (int fadeIndex=0; fadeIndex < 256; fadeIndex++)   \
                {                                                      \
                  analogWrite(pin,fadeIndex);                          \
                  delay(duration/256);                                 \
                }                    
              

  /**
   *   Pinout
   */
  #define DATA(x)   (12-x)
  #define OUTENA_     14
  #define CLK         2
  #define PLANE_SEL   4
  #define PWM         3

  inline void setupPinDirections();
  inline void setupStartingLevels();

#endif //__PINOUT_H__
