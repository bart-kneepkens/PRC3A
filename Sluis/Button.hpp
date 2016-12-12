#ifndef SLUIS_BUTTON_HPP
#define SLUIS_BUTTON_HPP

class Button {
private:
    int state;
public:
    Button();
    ~Button();

    int GetState() const;
};

#endif  // SLUIS_BUTTON_HPP