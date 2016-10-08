#ifndef Button_H
#define Button_H

#include <arduino.h>
#include "ButtonListener.h"

class Button  // Observes a button and fires events when its pressed.
{
public:
  Button(unsigned int pin);                                           // Constructor. Takes a button pin.
  void beActive();                                                    // Updates the button; should be called every loop.
  void addListener(ButtonListener* listener);                         // Adds a new event listener.
  void addListeners(ButtonListener*& listeners, unsigned int count);  // Adds several new event listeners.

private:
  bool IsPressed;                 // Whether the button is currently pressed or not.
  unsigned int ButtonPin;         // The button pin.
  unsigned int ListenersSize = 0; // Size of the Listeners array.
  ButtonListener* Listeners[0];   // Array of event listeners.
};

#endif
