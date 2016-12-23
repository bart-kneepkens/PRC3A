#include "Sluice.hpp"

Sluice::Sluice(DoorType::DoorType doorType) :
        sluiceState(SluiceState::Idle),
        doorType(doorType),
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

void Sluice::AlarmButtonPressed() {
    throw "Not yet implemented!";
}

void Sluice::ReleaseInButtonPressed() {
    // Make sure we're in the correct state to start, e.g. a door is currently open.
    if (MayToggleLights()) {
        // Identify what traffic light to toggle, and then do so.
        const TrafficLight trafficLight = leftDoor->GetState() == DoorState::Open ? leftInLight : rightInLight;
        trafficLight.ToggleLights();
    }
}

void Sluice::ReleaseOutButtonPressed() {
    // Make sure we're in the correct state to start, e.g. a door is currently open.
    if (MayToggleLights()) {
        // Identify what traffic light to toggle, and then do so.
        const TrafficLight trafficLight = leftDoor->GetState() == DoorState::Open ? leftOutLight : rightOutLight;
        trafficLight.ToggleLights();
    }
}

void Sluice::RestoreButtonPressed() {
    throw "Not yet implemented!";
}

void Sluice::StartButtonPressed() {
    // Make sure we're in the correct state to start.
    if (this->GetSluiceState()!= SluiceState::Idle) {
        throw std::runtime_error("[WARNING] It is not allowed to start the sluice process at this time.");
    }

    // Set our state.
    this->SetSluiceState(SluiceState::Started);

    // Set all red lights on and all green lights off.
    this->leftInLight.SwitchToRedLights();
    this->leftOutLight.SwitchToRedLights();
    this->rightInLight.SwitchToRedLights();
    this->rightOutLight.SwitchToRedLights();

    // According to current water level, decide which components to operate on.
    WaterLevel::WaterLevel waterLevel = this->waterSensor.GetWaterLevel();
    WaterLevel::WaterLevel desiredWaterLevel = waterLevel == WaterLevel::Low ? WaterLevel::High : WaterLevel::Low;
    const Door* doorToClose = waterLevel == WaterLevel::Low ? this->leftDoor : this->rightDoor;
    const Door* doorWhoseValvesToOpen = waterLevel == WaterLevel::Low ? this->rightDoor : this->leftDoor;

    // Check whether the correct door is closed/locked yet. If not...
    DoorState::DoorState doorToCloseState = doorToClose->GetState();
    if (doorToCloseState != DoorState::Closed && doorToCloseState != DoorState::Locked) {
        // Close the correct door.
        doorToClose->Close();

        // If this is a timed door, make sure to lock it after closing.
        if (this->doorType == DoorType::Timed) {
            while (doorToClose->GetState() != DoorState::Closed) {}
            ((TimedDoor *) doorToClose)->lock.SetLocked(true);
        }
        // If this is a door with defunct motors, make sure to continuously restart it.
        else if (this->doorType == DoorType::NeedsNewMotors) {
            while ((doorToCloseState = doorToClose->GetState()) != DoorState::Closed) {
                if (doorToCloseState != DoorState::Closing) {
                    doorToClose->Close();
                }
            }
        }
        // If this is a normal or any other type of door, just wait until it's closed.
        else {
            while (doorToClose->GetState() != DoorState::Closed) {}
        }
    }

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

    // If this is a timed door, make sure to unlock it before opening.
    DoorState::DoorState doorWhoseValvesToOpenState = doorWhoseValvesToOpen->GetState();
    if (doorWhoseValvesToOpenState == DoorState::Locked) {
        ((TimedDoor*) doorWhoseValvesToOpen)->lock.SetLocked(false);
        doorWhoseValvesToOpen->Open();
        while (doorWhoseValvesToOpen->GetState() != DoorState::Open) {}
    }
    // If this is a door with defunct motors, make sure to continuously restart it while opening.
    else if (this->doorType == DoorType::NeedsNewMotors) {
        doorWhoseValvesToOpen->Open();
        while ((doorWhoseValvesToOpenState = doorWhoseValvesToOpen->GetState()) != DoorState::Open) {
            if (doorWhoseValvesToOpenState != DoorState::Opening) {
                doorWhoseValvesToOpen->Open();
            }
        }
    }
    // If this is a normal or any other type of door, just wait until it's opened.
    else {
        doorWhoseValvesToOpen->Open();
        while (doorWhoseValvesToOpen->GetState() != DoorState::Open) {}
    }

    // Set our state.
    this->SetSluiceState(SluiceState::Idle);
}

SluiceState::SluiceState Sluice::GetSluiceState() {
    pthread_mutex_lock(&sluiceStateMutex);
    SluiceState::SluiceState state = this->sluiceState;
    pthread_mutex_unlock(&sluiceStateMutex);
    return state;
}

void Sluice::SetSluiceState(SluiceState::SluiceState state) {
    pthread_mutex_lock(&sluiceStateMutex);
    this->sluiceState = state;
    pthread_mutex_unlock(&sluiceStateMutex);
}

bool Sluice::MayToggleLights() {
    return this->GetSluiceState() == SluiceState::Idle &&
            (leftDoor->GetState() == DoorState::Open || rightDoor->GetState() == DoorState::Open);
}





