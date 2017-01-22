#include "DoorThatNeedsNewMotors.hpp"

DoorThatNeedsNewMotors::DoorThatNeedsNewMotors(DoorSide::DoorSide side) :
        Door(side) {}

DoorThatNeedsNewMotors::~DoorThatNeedsNewMotors() {}

void DoorThatNeedsNewMotors::DuringClosingBehavior() const {
    if (this->GetState() != DoorState::Closing) {
        Close();
    }
}

void DoorThatNeedsNewMotors::DuringOpeningBehavior() const {
    if (this->GetState() != DoorState::Opening) {
        Open();
    }
}




