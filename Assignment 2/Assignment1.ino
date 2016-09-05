// Timer class. Call PeriodHasPassed whenever you want to check whether the
// interval (defined in milliseconds) has passed.
class Timer {
  
  private:
    int interval; // the interval, in milliseconds.
    long lastTimestamp; // timestamp of the last time PeriodHasPassed() was called.
    
  public:
    // Constructor, taking a frequency.
    Timer(double frequency) : interval(1000 / frequency), lastTimestamp(0) { }
    // Returns whether the interval has passed since the last call to this function.
    bool PeriodHasPassed() {
      long curTimestamp = millis();
      if (curTimestamp - lastTimestamp >= interval) {
        lastTimestamp = curTimestamp;
        return true;
      }
      return false;
    }
};

// Led class, which turns a led on or off on the supplied frequency.
class Led {
  
  private:  
    int pinNr;  // pin number of the led.
    Timer timer; // the timer this led uses.
    
  public: 
    // constructor, taking a led's pin number and a frequency.
    Led(int pinNr, double frequency) : pinNr(pinNr), timer(Timer(frequency)) {
      pinMode(pinNr, OUTPUT);
    }
    // Call this in loop() so that it checks every time whether the light needs be toggled.
    void Update() {
      if (timer.PeriodHasPassed()) {
        digitalWrite(pinNr, !digitalRead(pinNr));
      }
    }
};

// The leds we'll be using.
Led* led1;
Led* led2;
Led* led3;

void setup() {
  // Instantiate new leds.
  Led tmp1 = Led(13, 1);
  Led tmp2 = Led(6, 0.5); 
  Led tmp3 = Led(7, 2);

  // Assign them to global vars.
  led1 = &tmp1;
  led2 = &tmp2;
  led3 = &tmp3;
}

void loop() {
  // Call the Update-functions of all leds.
  led1->Update();
  led2->Update();
  led3->Update();
}
