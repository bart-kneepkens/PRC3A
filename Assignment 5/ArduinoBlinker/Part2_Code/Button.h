#ifndef Button_H
#define Button_H
#include <arduino.h>

class Button 
{
public:
  Button(int pin);
  bool IsPressed();

private:
  int ButtonPin;
};

#endif
