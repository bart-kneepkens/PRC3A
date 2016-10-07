#ifndef Button_H
#define Button_H

#include <arduino.h>
#include "ButtonListener.h"

class Button 
{
public:
  Button(int pin, ButtonListener* listener);
  ~Button();
  void beActive();

private:
  bool IsPressed;
  int ButtonPin;
  ButtonListener* Listener;
};

#endif
