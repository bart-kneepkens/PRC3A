#include "Led.h"
#include "Button.h"

Led led1(PIN5);
Led led2(9);
Led led3(11);
Led led4(10);
Button button1(1, &led1);
Timer timer1;

// the setup function runs once when you press reset or power the board
void setup()
{
  led1.Blink(3);
  led2.Blink(2);
  led3.Blink(3);  
  led4.Blink(5);
  timer1.Start(10000.0);
}

// the loop function runs over and over again forever
void loop()
{
  led1.beActive(); 
  led2.beActive();    
  led3.beActive();
  led4.beActive();
  button1.beActive();

  if (timer1.Elapsed()) {
    button1.RegisterValue = !button1.RegisterValue;
    timer1.Start(10000.0);
  }
}


