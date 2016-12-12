#include "Sluice.hpp"

Sluice::Sluice(unsigned int port, DoorType::DoorType doorType) :
        frontInLight(TrafficLight(port, 1)),
        frontOutLight(TrafficLight(port, 2)),
        backInLight(TrafficLight(port, 3)),
        backOutLight(TrafficLight(port, 4)),
        waterSensor(WaterSensor(port)) {

    switch (doorType) {
        case DoorType::Timed:
            frontDoor = new TimedDoor(port, DoorSide::Left);
            backDoor = new TimedDoor(port, DoorSide::Right);
            break;
        case DoorType::NeedsNewMotors:
            frontDoor = new DoorThatNeedsNewMotors(port, DoorSide::Left);
            backDoor = new DoorThatNeedsNewMotors(port, DoorSide::Right);
            break;
        default:
            frontDoor = new Door(port, DoorSide::Left);
            backDoor = new Door(port, DoorSide::Right);
            break;
    }
}

Sluice::~Sluice() {
    delete frontDoor;
    delete backDoor;
}

const Door* Sluice::GetDoor(DoorSide::DoorSide side) const {
    return (side == DoorSide::Left) ? frontDoor : backDoor;
}

void Sluice::AlarmButtonPressed() const {
    throw "Not yet implemented!";
}

void Sluice::ReleaseInButtonPressed() const {
    throw "Not yet implemented!";
}

void Sluice::ReleaseOutButtonPressed() const {
    throw "Not yet implemented!";
}

void Sluice::RestoreButtonPressed() const {
    throw "Not yet implemented!";
}

void Sluice::StartButtonPressed() const {
    throw "Not yet implemented!";
}






