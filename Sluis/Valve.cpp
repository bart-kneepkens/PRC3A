#include "Valve.hpp"

Valve::Valve(unsigned int port, DoorSide::DoorSide side, unsigned int index) : port(port), side(side), index(index) { };

Valve::~Valve() { };

void Valve::Open() const {
    SetValve(port, side, index, ValveState::Open);
}

void Valve::Close() const {
    SetValve(port, side, index, ValveState::Closed);
}

ValveState::ValveState Valve::GetState() const {
    return GetValveState(port, side, index);
};





