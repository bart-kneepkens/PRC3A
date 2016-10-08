#ifndef ButtonListener_H
#define ButtonListener_H

class ButtonListener {  // Interface for classes that listen to button events.
public:
  virtual void HandleButtonClick() = 0; // Called when a button is pressed and released.
};

#endif
