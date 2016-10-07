#ifndef Led_H
#define Led_H

#include "Timer.h"
#include "ButtonListener.h"
#include <arduino.h>

class Led : public ButtonListener {
public:
  enum State { BLINKING, ONFOR5, OFFAFTER5 };
  
  Led(int pin);
  ~Led();
  
  void On();
  void Off();
  void Blink(float frequency);
  void beActive();
  void HandleButtonClick();
 
private:
  Timer mytimer;
  int LedPin;
  int BlinkTime;
  State MyState;
};

#endif

