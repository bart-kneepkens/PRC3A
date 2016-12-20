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
    this->leftDoor->Close();
    this->rightDoor->Close();
    while (this->leftDoor->GetState() != DoorState::Closed) {}
    while (this->rightDoor->GetState() != DoorState::Closed) {}

    // According to current water level, decide which components to operate on.
    WaterLevel::WaterLevel waterLevel = this->waterSensor.GetWaterLevel();
    if (waterLevel != WaterLevel::High && waterLevel != WaterLevel::Low) {
        throw std::runtime_error("[ERROR] WaterLevel was neither Low nor High when start button was pressed");
    }
    WaterLevel::WaterLevel desiredWaterLevel = waterLevel == WaterLevel::Low ? WaterLevel::High : WaterLevel::Low;
    const Door* doorWhoseValvesToOpen = waterLevel == WaterLevel::Low ? this->rightDoor : this->leftDoor;

    // Open valves.
    doorWhoseValvesToOpen->valveLow.Open();
    doorWhoseValvesToOpen->valveMiddle.Open();
    doorWhoseValvesToOpen->valveHigh.Open();

    // Wait until water level has risen sufficiently.
    while (this->waterSensor.GetWaterLevel() != desiredWaterLevel) {}

    // Close valves.
    doorWhoseValvesToOpen->valveLow.Close();
    doorWhoseValvesToOpen->valveMiddle.Close();
    doorWhoseValvesToOpen->valveHigh.Close();

    // Wait until the valves have closed.
    while (doorWhoseValvesToOpen->valveLow.GetState() != ValveState::Closed) {}
    while (doorWhoseValvesToOpen->valveMiddle.GetState() != ValveState::Closed) {}
    while (doorWhoseValvesToOpen->valveHigh.GetState() != ValveState::Closed) {}

    // Open the correct door and wait until it's opened.
    doorWhoseValvesToOpen->Open();
    while (doorWhoseValvesToOpen->GetState() != DoorState::Open) {}
}






