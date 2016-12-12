#include "Valve.hpp"

Valve::Valve(DoorSide::DoorSide side, unsigned int index) : side(side), index(index) { };

Valve::~Valve() { };

void Valve::Open() const {
    SetValve(side, index, ValveState::Open);
}

void Valve::Close() const {
    SetValve(side, index, ValveState::Closed);
}

ValveState::ValveState Valve::GetState() const {
    return GetValveState(side, index);
};





