#include "Door.hpp"

Door::Door(DoorSide::DoorSide side) : side(side), valveLow(Valve(side, 1)),
                                      valveMiddle(Valve(side, 2)), valveHigh(Valve(side, 3)) {}

Door::~Door() {}

void Door::Open() const {
    sluice_client::CLIENT->SetDoor(side, DoorParameter::Open);
}

void Door::Close() const {
    sluice_client::CLIENT->SetDoor(side, DoorParameter::Close);
}

DoorState::DoorState Door::GetState() const {
    return sluice_client::CLIENT->GetDoorState(side);
}

void Door::EmergencyStop() {
    // Save door state and then stop it.
    previousState = GetState();
    if (previousState == DoorState::Opening || previousState == DoorState::Closing) {
        sluice_client::CLIENT->SetDoor(side, DoorParameter::Stop);
    }

    // Emergency close all the valves.
    valveLow.EmergencyClose();
    valveMiddle.EmergencyClose();
    valveHigh.EmergencyClose();
}

void Door::RecoverFromEmergency() {
    // Recover door state.
    if (previousState == DoorState::Opening) {
        sluice_client::CLIENT->SetDoor(side, DoorParameter::Open);
    } else if (previousState == DoorState::Closing) {
        sluice_client::CLIENT->SetDoor(side, DoorParameter::Close);
    }

    // Recover valve states.
    valveLow.RecoverFromEmergency();
    valveMiddle.RecoverFromEmergency();
    valveHigh.RecoverFromEmergency();
}

void Door::BeforeOpenBehavior() const { /* Does nothing by default. */ }

void Door::AfterCloseBehavior() const { /* Does nothing by default. */ }

void Door::DuringOpeningBehavior() const { /* Does nothing by default. */ }

void Door::DuringClosingBehavior() const { /* Does nothing by default. */ }








