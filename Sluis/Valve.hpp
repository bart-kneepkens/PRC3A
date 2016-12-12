#ifndef SLUIS_VALVE_HPP
#define SLUIS_VALVE_HPP

#include "SluiceSocketClient.hpp"

class Valve {
private:
    const DoorSide::DoorSide side;
    const unsigned int index;
public:
    Valve(DoorSide::DoorSide side, unsigned int index);
    ~Valve();

    void Open() const;
    void Close() const;
    ValveState::ValveState GetState() const;
};

#endif  // SLUIS_VALVE_HPP