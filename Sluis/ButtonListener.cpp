#include "ButtonListener.hpp"

ButtonListener::ButtonListener(Button &button, ISluiceController &sluiceController) : button(button),
    sluiceController(sluiceController)  {}

ButtonListener::~ButtonListener() {}

void ButtonListener::OnButtonPress() {
    throw "Not yet implemented!";   // What do we expect this method to do?
}


