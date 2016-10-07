#include "Led.h"

Led::Led(int pin) {
  mytimer = Timer();
  LedPin = pin;
  MyState = BLINKING;
  pinMode(LedPin, OUTPUT);
}

Led::~Led() { }

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
  switch (MyState) {
    case BLINKING:
      if (mytimer.Elapsed()) {
        if (digitalRead(LedPin) == HIGH)
          Off();
        else
          On();     
        mytimer.Start(BlinkTime);
      }
      break;
    case ONFOR5:
      if (mytimer.Elapsed()) {
        Off();
        MyState = OFFAFTER5;
      }
      break;
    case OFFAFTER5: /* Do nothing */ break;
  }
}

void Led::HandleButtonClick() {
  switch (MyState) {
    case BLINKING: 
      MyState = ONFOR5;
      mytimer.Start(5000.0);
      On();
      break;
    case ONFOR5: /* Do nothing */ break;
    case OFFAFTER5: 
      MyState = BLINKING;
      mytimer.Start(BlinkTime);
      break;
  }
}



















