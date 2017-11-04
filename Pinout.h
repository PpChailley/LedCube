#ifndef __PINOUT_H__
  #define __PINOUT_H__

  #include <Arduino.h>

  #define DATA(x)   (12-x)
  #define OUTENA_     14
  #define CLK         2
  #define PLANE_SEL   4
  #define PWM         3

  inline void setupPinDirections();
  inline void setupStartingLevels();

#endif //__PINOUT_H__
