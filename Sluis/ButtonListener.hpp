#ifndef SLUIS_BUTTONLISTENER_HPP
#define SLUIS_BUTTONLISTENER_HPP

#include "Button.hpp"

class ButtonListener {
private:
    Button button;
public:
    ButtonListener(Button& button);
    ~ButtonListener();

    void OnButtonPress();
};

#endif  // SLUIS_BUTTONLISTENER_HPP