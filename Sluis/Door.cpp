#include "Door.hpp"

Door::Door(DoorSide::DoorSide side) : side(side), valveLow(Valve(side, 1)), valveMiddle(Valve(side, 2)), valveHigh(Valve(side, 3)) {}

Door::~Door() {}

void Door::Open() const {
    SetDoor(side, DoorParameter::Open);
}

void Door::Close() const {
    SetDoor(side, DoorParameter::Close);
}

void Door::Stop() const {
    SetDoor(side, DoorParameter::Stop);
}

DoorState::DoorState Door::GetState() const {
    return GetDoorState(side);
}

void Door::OpenValves() const {
    throw "Not implemented!";   // Do we need this function?
}

void Door::CloseValves() const {
    throw "Not implemented!";   // Do we need this function?
}






