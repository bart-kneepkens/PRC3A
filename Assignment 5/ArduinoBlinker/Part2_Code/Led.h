#ifndef Led_H
#define Led_H

#include "Timer.h"
#include "ButtonListener.h"
#include <arduino.h>

class Led : public ButtonListener { // Manages a single led.
public:
  enum State { BLINKING, ONFOR5, OFFAFTER5 }; // Enumerator for led states.
  
  Led(unsigned int pin);        // Constructor. Takes a led pin.
  void On();                    // Turns the managed led on.
  void Off();                   // Turns the managed led off.
  void Blink(float frequency);  // Instructs the led to start blinking.
  void beActive();              // Updates the led; should be called every loop.
  void HandleButtonClick();     // Inherited from ButtonListener.
 
private:
  Timer mytimer = Timer();  // Underlying timer.
  unsigned int LedPin;      // The led pin.
  unsigned int BlinkTime;   // The time in milliseconds between blinks.
  State MyState = BLINKING; // The state the led is currently in.
};

#endif

