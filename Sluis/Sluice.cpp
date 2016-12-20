#include "Sluice.hpp"

Sluice::Sluice(DoorType::DoorType doorType) :
        leftInLight(TrafficLight(1)),
        leftOutLight(TrafficLight(2)),
        rightInLight(TrafficLight(4)),
        rightOutLight(TrafficLight(3)),
        waterSensor(WaterSensor()) {

    switch (doorType) {
        case DoorType::Timed:
            leftDoor = new TimedDoor(DoorSide::Left);
            rightDoor = new TimedDoor(DoorSide::Right);
            break;
        case DoorType::NeedsNewMotors:
            leftDoor = new DoorThatNeedsNewMotors(DoorSide::Left);
            rightDoor = new DoorThatNeedsNewMotors(DoorSide::Right);
            break;
        default:
            leftDoor = new Door(DoorSide::Left);
            rightDoor = new Door(DoorSide::Right);
            break;
    }
}

Sluice::~Sluice() {
    delete leftDoor;
    delete rightDoor;
}

const Door* Sluice::GetDoor(DoorSide::DoorSide side) const {
    return (side == DoorSide::Left) ? leftDoor : rightDoor;
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
    // Close both doors and wait until they're closed.

}






