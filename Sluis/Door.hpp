#ifndef SLUIS_DOOR_HPP
#define SLUIS_DOOR_HPP

#include "SluiceSocketClient.hpp"
#include "Valve.hpp"

class Door {
protected:
    const DoorSide::DoorSide side;
public:
    const Valve valveLow;
    const Valve valveMiddle;
    const Valve valveHigh;

    Door(DoorSide::DoorSide side);

    virtual ~Door();

    void Open() const;

    void Close() const;

    void Stop() const;

    DoorState::DoorState GetState() const;
};

#endif  // SLUIS_DOOR_HPP