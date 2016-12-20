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
    // Make sure we're in the correct state to start, e.g. a door is currently open.
    DoorState::DoorState leftDoorState = leftDoor->GetState();
    if (leftDoorState != DoorState::Open && rightDoor->GetState() != DoorState::Open) {
        throw std::runtime_error("[ERROR] Neither the left nor the right door was open when release in button was pressed");
    }

    // Identify what traffic light to set to green, and then do so.
    const TrafficLight trafficLight = leftDoorState == DoorState::Open ? leftInLight : rightInLight;
    trafficLight.SetPower(TrafficLightColor::Red, Power::Off);
    trafficLight.SetPower(TrafficLightColor::Green, Power::On);
}

void Sluice::ReleaseOutButtonPressed() const {
    // Make sure we're in the correct state to start, e.g. a door is currently open.
    DoorState::DoorState leftDoorState = leftDoor->GetState();
    if (leftDoorState != DoorState::Open && rightDoor->GetState() != DoorState::Open) {
        throw std::runtime_error("[ERROR] Neither the left nor the right door was open when release out button was pressed");
    }

    // Identify what traffic light to set to green, and then do so.
    const TrafficLight trafficLight = leftDoorState == DoorState::Open ? leftOutLight : rightOutLight;
    trafficLight.SetPower(TrafficLightColor::Red, Power::Off);
    trafficLight.SetPower(TrafficLightColor::Green, Power::On);
}

void Sluice::RestoreButtonPressed() const {
    //throw "Not yet implemented!";
}

void Sluice::StartButtonPressed() const {
    // Make sure we're in the correct state to start, e.g. the water level is either high or low.
    WaterLevel::WaterLevel waterLevel = this->waterSensor.GetWaterLevel();
    if (waterLevel != WaterLevel::High && waterLevel != WaterLevel::Low) {
        throw std::runtime_error("[ERROR] WaterLevel was neither Low nor High when start button was pressed");
    }

    // Set all red lights on and all green lights off.
    this->leftInLight.SetPower(TrafficLightColor::Red, Power::On);
    this->leftInLight.SetPower(TrafficLightColor::Green, Power::Off);
    this->leftOutLight.SetPower(TrafficLightColor::Red, Power::On);
    this->leftOutLight.SetPower(TrafficLightColor::Green, Power::Off);
    this->rightInLight.SetPower(TrafficLightColor::Red, Power::On);
    this->rightInLight.SetPower(TrafficLightColor::Green, Power::Off);
    this->rightOutLight.SetPower(TrafficLightColor::Red, Power::On);
    this->rightOutLight.SetPower(TrafficLightColor::Green, Power::Off);

    // Close both doors and wait until they're closed.
    this->leftDoor->Close();
    this->rightDoor->Close();
    while (this->leftDoor->GetState() != DoorState::Closed) {}
    while (this->rightDoor->GetState() != DoorState::Closed) {}

    // According to current water level, decide which components to operate on.
    WaterLevel::WaterLevel desiredWaterLevel = waterLevel == WaterLevel::Low ? WaterLevel::High : WaterLevel::Low;
    const Door* doorWhoseValvesToOpen = waterLevel == WaterLevel::Low ? this->rightDoor : this->leftDoor;

    // Open bottom valve.
    doorWhoseValvesToOpen->valveLow.Open();

    // If water level is high, only the left lower valve needs be opened, but if water level is low, at first only the
    // right lower valve is opened until the middle one is under water, then the middle one is opened until the top one
    // is under water, then the top one is opened as well.
    if (waterLevel == WaterLevel::Low) {
        while (this->waterSensor.GetWaterLevel() != WaterLevel::AboveValve2) {}
        doorWhoseValvesToOpen->valveMiddle.Open();
        while (this->waterSensor.GetWaterLevel() != WaterLevel::AboveValve3) {}
        doorWhoseValvesToOpen->valveHigh.Open();
    }

    // Wait until water level has risen sufficiently.
    while (this->waterSensor.GetWaterLevel() != desiredWaterLevel) {}

    // Close all valves.
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






