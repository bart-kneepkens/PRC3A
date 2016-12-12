#include "Door.hpp"

Door::Door(unsigned int port, DoorSide::DoorSide side) : port(port), side(side), valveLow(Valve(port, side, 1)),
    valveMiddle(Valve(port, side, 2)), valveHigh(Valve(port, side, 3)) {}

Door::~Door() {}

void Door::Open() const {
    SetDoor(port, side, DoorParameter::Open);
}

void Door::Close() const {
    SetDoor(port, side, DoorParameter::Close);
}

void Door::Stop() const {
    SetDoor(port, side, DoorParameter::Stop);
}

DoorState::DoorState Door::GetState() const {
    return GetDoorState(port, side);
}

void Door::OpenValves() const {
    throw "Not implemented!";   // Do we need this function?
}

void Door::CloseValves() const {
    throw "Not implemented!";   // Do we need this function?
}






