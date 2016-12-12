#ifndef SLUIS_DOOR_HPP
#define SLUIS_DOOR_HPP

#include "Enumerators.hpp"
#include "Valve.hpp"

class Door {
private:
    DoorState::DoorState state;

    Valve valveLow;
    Valve valveMiddle;
    Valve valveHigh;
public:
    Door();
    virtual ~Door();

    void Open();
    void Close();
    void Stop();
    DoorState::DoorState GetState() const;
    void OpenValves();
    void CloseValves();
};

#endif  // SLUIS_DOOR_HPP