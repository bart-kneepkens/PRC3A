#ifndef SLUIS_BUTTONLISTENER_HPP
#define SLUIS_BUTTONLISTENER_HPP

#include "Button.hpp"
#include "ISluiceController.hpp"

class ButtonListener {
private:
    Button button;
    ISluiceController& sluiceController;
public:
    ButtonListener(Button& button, ISluiceController& sluiceController);
    ~ButtonListener();

    void OnButtonPress();
};

#endif  // SLUIS_BUTTONLISTENER_HPP