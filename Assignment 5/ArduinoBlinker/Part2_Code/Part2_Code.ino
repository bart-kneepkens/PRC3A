#include "Led.h"
#include "Button.h"

// Our components.
static const Led led1(13);
static const Led led2(9);
static const Led led3(11);
static const Led led4(10);
static const Button button1(1);

void setup()
{
  // Setup the leds for blinking.
  led1.Blink(3);
  led2.Blink(2);
  led3.Blink(3);  
  led4.Blink(5);

  // Make the leds listen to button presses.
  button1.addListener(&led1);
  button1.addListener(&led2);
  button1.addListener(&led3);
  button1.addListener(&led4);
}

void loop()
{
  // Make the leds do their checks.
  led1.beActive(); 
  led2.beActive();    
  led3.beActive();
  led4.beActive();

  // Make the button do its check.
  button1.beActive();
}


