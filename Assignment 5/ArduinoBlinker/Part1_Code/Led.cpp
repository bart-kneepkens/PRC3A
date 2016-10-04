#include "Led.h"


Led::Led(int pin) {
  mytimer = Timer();
  LedPin = pin;
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
  if (mytimer.Elapsed()) {
    HandleEvent();
    mytimer.Start(BlinkTime);
  }
}
void Led::HandleEvent() {
  if (digitalRead(LedPin) == HIGH)
    Off();
  else
    On();
}



















