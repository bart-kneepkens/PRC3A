#include "Button.h"

Button::Button(int pin, ButtonListener* listener) {
  ButtonPin = pin;
  Listener = listener;
}

Button::~Button() {
  delete Listener;
}

void Button::beActive() {
  bool isCurrentlyPressed = RegisterValue;// digitalRead(ButtonPin);

  if (!IsPressed && isCurrentlyPressed) {
    IsPressed = true;
  }
  else if (IsPressed && !isCurrentlyPressed) {
    IsPressed = false;
    Listener->HandleButtonClick();
  }
}

