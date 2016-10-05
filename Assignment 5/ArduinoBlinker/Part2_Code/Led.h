#ifndef Led_H
#define Led_H
#include "Timer.h"
#include "ButtonListener.h"
#include <arduino.h>

class Led : ButtonListener {
public:
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
};

#endif

