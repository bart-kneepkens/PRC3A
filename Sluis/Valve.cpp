#include "Valve.hpp"

Valve::Valve(DoorSide::DoorSide side, unsigned int index) : side(side), index(index) { };

Valve::~Valve() { };

void Valve::Open() const {
    sluice_client::SetValve(side, index, ValveState::Open);
}

void Valve::Close() const {
    sluice_client::SetValve(side, index, ValveState::Closed);
}

ValveState::ValveState Valve::GetState() const {
    return sluice_client::GetValveState(side, index);
};





