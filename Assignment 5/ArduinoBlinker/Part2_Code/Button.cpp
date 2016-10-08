#include "Button.h"

Button::Button(unsigned int pin) {
  ButtonPin = pin;
}

void Button::beActive() {
  bool isCurrentlyPressed = digitalRead(ButtonPin);

  // If the button is newly pressed, just set IsPressed.
  if (!IsPressed && isCurrentlyPressed)
    IsPressed = true;
    
  // Else if the button was just released, fire event.
  else if (IsPressed && !isCurrentlyPressed) {
    IsPressed = false;    
    for (unsigned int i = 0; i < ListenersSize; i++) {
      Listeners[i]->HandleButtonClick();
    }
  }
}

void Button::addListener(ButtonListener* listener) {
  Listeners[ListenersSize++] = listener;
}

