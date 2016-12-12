#include "Button.hpp"

Button::Button() {}

Button::~Button() {}

int Button::GetState() const {
    return state;
}

void Button::SetState(int state) {
    this->state = state;
}