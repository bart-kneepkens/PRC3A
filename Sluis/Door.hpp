#ifndef SLUIS_DOOR_HPP
#define SLUIS_DOOR_HPP

#include "SluiceSocketClient.hpp"
#include "Valve.hpp"

class Door {
private:
    const unsigned int port;
    const Valve valveLow;
    const Valve valveMiddle;
    const Valve valveHigh;
protected:
    const DoorSide::DoorSide side;
public:
    Door(unsigned int port, DoorSide::DoorSide side);
    virtual ~Door();

    void Open() const;
    void Close() const;
    void Stop() const;
    DoorState::DoorState GetState() const;
    void OpenValves() const;
    void CloseValves() const;
};

#endif  // SLUIS_DOOR_HPP