#include "Led.h"

Led::Led(unsigned int pin) {
  LedPin = pin;
  pinMode(LedPin, OUTPUT);
}

void Led::On() {
  digitalWrite(LedPin, HIGH);
}

void Led::Off() {
  digitalWrite(LedPin, LOW);
}

void Led::Blink(float frequency) {
  BlinkTime = (unsigned long) 1000.0 / frequency;
  mytimer.Start(BlinkTime);
}

void Led::beActive() { 
  switch (MyState) {  // According to the current state, take appropriate actions.
    
    case BLINKING:  // If blinking, just keep on blinking.
      if (mytimer.Elapsed()) {
        if (digitalRead(LedPin) == HIGH)
          Off();
        else
          On();     
        mytimer.Start(BlinkTime);
      }
      break;
      
    case ONFOR5:  // If we're in ONFOR5 state and 5 seconds have passed, move to OFFAFTER5 state.
      if (mytimer.Elapsed()) {
        Off();
        MyState = OFFAFTER5;
      }
      break;
      
    case OFFAFTER5: /* Do nothing */ break;
  }
}

void Led::HandleButtonClick() {
  switch (MyState) {  // According to the current state, take appropriate actions.
    
    case BLINKING:  // If blinking, move to ONFOR5 state.
      MyState = ONFOR5;
      mytimer.Start(5000.0);
      On();
      break;
      
    case ONFOR5: /* Do nothing */ break;
    
    case OFFAFTER5: // If in OFFAFTER5 state, return to BLINKING state.
      MyState = BLINKING;
      mytimer.Start(BlinkTime);
      break;
  }
}



















