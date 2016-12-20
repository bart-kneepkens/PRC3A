#include "Sluice.hpp"

Sluice::Sluice(DoorType::DoorType doorType) :
        frontInLight(TrafficLight(1)),
        frontOutLight(TrafficLight(2)),
        backInLight(TrafficLight(3)),
        backOutLight(TrafficLight(4)),
        waterSensor(WaterSensor()) {

    switch (doorType) {
        case DoorType::Timed:
            frontDoor = new TimedDoor(DoorSide::Left);
            backDoor = new TimedDoor(DoorSide::Right);
            break;
        case DoorType::NeedsNewMotors:
            frontDoor = new DoorThatNeedsNewMotors(DoorSide::Left);
            backDoor = new DoorThatNeedsNewMotors(DoorSide::Right);
            break;
        default:
            frontDoor = new Door(DoorSide::Left);
            backDoor = new Door(DoorSide::Right);
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
    //throw "Not yet implemented!";
}

void Sluice::ReleaseInButtonPressed() const {
    //throw "Not yet implemented!";
}

void Sluice::ReleaseOutButtonPressed() const {
    //throw "Not yet implemented!";
}

void Sluice::RestoreButtonPressed() const {
    //throw "Not yet implemented!";
}

void Sluice::StartButtonPressed() const {
    //throw "Not yet implemented!";
}






