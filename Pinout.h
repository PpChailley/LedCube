#ifndef __PINOUT_H__
  #define __PINOUT_H__

  #include <Arduino.h>







  #define PIN_D2    2   // OK
  #define PIN_D3    3   // OK
  #define PIN_D4    4   // OK
  #define PIN_D5    5   // OK
  #define PIN_D6    6     // OK
  #define PIN_D7    7     // OK
  #define PIN_D8    8     // OK
  #define PIN_D9    9
  #define PIN_D10   10    // OK
  #define PIN_D11   11
  #define PIN_D12   12    // OK



  #define DATA(x)       \
        (x==0? PIN_D12: \
        (x==1? PIN_D11: \
        (x==2? PIN_D10: \
        (x==3? PIN_D9: \
        (x==4? PIN_D8: \
        (x==5? PIN_D7: \
        (x==6? PIN_D6: \
        (x==7? PIN_D5: -1 ))))))))
  
  
  #define OUTENA_     14
  #define CLK         2
  #define PLANE_SEL   4
  #define PWM         3

  inline void setupPinDirections();
  inline void setupStartingLevels();

#endif //__PINOUT_H__
