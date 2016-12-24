#include "Valve.hpp"

Valve::Valve(DoorSide::DoorSide side, unsigned int index) : side(side), index(index),
                                                            previousState(ValveState::Closed) { };

Valve::~Valve() { };

void Valve::Open() const {
    sluice_client::CLIENT->SetValve(side, index, ValveState::Open);
}

void Valve::Close() const {
    sluice_client::CLIENT->SetValve(side, index, ValveState::Closed);
}

ValveState::ValveState Valve::GetState() const {
    return sluice_client::CLIENT->GetValveState(side, index);
}

void Valve::EmergencyClose() {
    previousState = GetState();
    if (previousState != ValveState::Closed) {
        this->Close();
    }
}

void Valve::RecoverFromEmergency() {
    if (previousState != ValveState::Closed) {
        sluice_client::CLIENT->SetValve(side, index, previousState);
    }
};





