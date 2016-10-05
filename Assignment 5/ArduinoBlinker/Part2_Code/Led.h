#ifndef Led_H
#define Led_H
#include "Timer.h"
#include <arduino.h>

class Led : ButtonListener {
public:
  Led(int pin);
  ~Led();

  void On();
  void Off();
  void Blink(float frequency);
  void beActive();
 
private:
  void HandleButtonClick(/* ....*/);
  Timer mytimer;

  int LedPin;
  int BlinkTime;
};

#endif

