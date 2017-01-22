#include "Sluice.hpp"

Sluice::Sluice(DoorType::DoorType doorType) :
        previousState(sluiceState),
        doorType(doorType),
        lowWaterInLight(TrafficLight(1)),
        lowWaterOutLight(TrafficLight(2)),
        highWaterInLight(TrafficLight(4)),
        highWaterOutLight(TrafficLight(3)),
        waterSensor(WaterSensor()),
        sluiceState(waterSensor.GetWaterLevel() ==
                            WaterLevel::High ? SluiceState::IdlingOnHighWater : SluiceState::IdlingOnLowWater) {

    switch (doorType) {
        case DoorType::Timed:
            lowWaterDoor = new TimedDoor(DoorSide::LowWater);
            highWaterDoor = new TimedDoor(DoorSide::HighWater);
            break;
        case DoorType::NeedsNewMotors:
            lowWaterDoor = new DoorThatNeedsNewMotors(DoorSide::LowWater);
            highWaterDoor = new DoorThatNeedsNewMotors(DoorSide::HighWater);
            break;
        default:
            lowWaterDoor = new Door(DoorSide::LowWater);
            highWaterDoor = new Door(DoorSide::HighWater);
            break;
    }
}

Sluice::~Sluice() {
    delete lowWaterDoor;
    delete highWaterDoor;
}

void Sluice::AlarmButtonPressed() {
    const SluiceState::SluiceState curSluiceState = this->GetSluiceState();

    // Only act if we aren't already idling in emergency.
    if (curSluiceState != SluiceState::WaitingForRecovery) {
        // Store previous state and set state to emergency.
        SetSluiceState(SluiceState::WaitingForRecovery);
        previousState = curSluiceState;

        // Emergency stop doors and valves.
        lowWaterDoor->EmergencyStop();
        highWaterDoor->EmergencyStop();

        // Set all red lights on and all green lights off.
        this->lowWaterInLight.SwitchToRedLights();
        this->lowWaterOutLight.SwitchToRedLights();
        this->highWaterInLight.SwitchToRedLights();
        this->highWaterOutLight.SwitchToRedLights();
    }
}

void Sluice::ReleaseInButtonPressed() {
    // According to the current state, toggle the correct lights.
    switch (this->GetSluiceState()) {
        case (SluiceState::IdlingOnLowWater):
            // Only toggle the light if the door is open.
            if (this->lowWaterDoor->GetState() == DoorState::Open) {
                lowWaterInLight.ToggleLights();
            }
            break;
        case (SluiceState::IdlingOnHighWater):
            // Only toggle the light if the door is open.
            if (this->highWaterDoor->GetState() == DoorState::Open) {
                highWaterInLight.ToggleLights();
            }
            break;
        default:
            break;
    }
}

void Sluice::ReleaseOutButtonPressed() {
    // According to the current state, toggle the correct lights.
    switch (this->GetSluiceState()) {
        case (SluiceState::IdlingOnLowWater):
            // Only toggle the light if the door is open.
            if (this->lowWaterDoor->GetState() == DoorState::Open) {
                lowWaterOutLight.ToggleLights();
            }
            break;
        case (SluiceState::IdlingOnHighWater):
            // Only toggle the light if the door is open.
            if (this->highWaterDoor->GetState() == DoorState::Open) {
                highWaterOutLight.ToggleLights();
            }
            break;
        default:
            break;
    }
}

void Sluice::RestoreButtonPressed() {
    // Only act if we are idling in emergency. Restore normal operations.
    if (this->GetSluiceState() == SluiceState::WaitingForRecovery) {
        SetSluiceState(previousState);
        lowWaterDoor->RecoverFromEmergency();
        highWaterDoor->RecoverFromEmergency();
    }
}

void Sluice::StartButtonPressed() {
    // According to our current state, check what to do.
    switch (this->GetSluiceState()) {
        case (SluiceState::IdlingOnLowWater): {
            // If we're idling on low water, then set the lights to red, close the low water door,
            // and go to the next state.
            const DoorState::DoorState lowWaterDoorState = lowWaterDoor->GetState();
            if (lowWaterDoorState != DoorState::Closed && lowWaterDoorState != DoorState::Locked) {
                this->lowWaterDoor->Close();
            }
            this->lowWaterInLight.SwitchToRedLights();
            this->lowWaterOutLight.SwitchToRedLights();
            this->SetSluiceState(SluiceState::ClosingLowWaterDoor);
            break;
        }
        case (SluiceState::IdlingOnHighWater): {
            // If we're idling on high water, then set the lights to red, close the high water door,
            // and go to the next state.
            const DoorState::DoorState highWaterDoorState = highWaterDoor->GetState();
            if (highWaterDoorState != DoorState::Closed && highWaterDoorState != DoorState::Locked) {
                this->highWaterDoor->Close();
            }
            this->highWaterInLight.SwitchToRedLights();
            this->highWaterOutLight.SwitchToRedLights();
            this->SetSluiceState(SluiceState::ClosingHighWaterDoor);
            break;
        }
        default:
            break;
    }
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

void Sluice::Run() {
    pthread_create(&runningThread, NULL, Run, this);
}

void *Sluice::Run(void *threadArgs) {
    Sluice *sluice = (Sluice*) threadArgs;
    bool loop = true;

    while (loop) {
        const SluiceState::SluiceState curState = sluice->GetSluiceState();
        switch (curState) {
            case (SluiceState::WaitingForRecovery):
                // Do nothing, just idling.
                break;
            case (SluiceState::IdlingOnHighWater):
                // Do nothing, just idling.
                break;
            case (SluiceState::ClosingHighWaterDoor): {
                DoorState::DoorState highWaterDoorState = sluice->highWaterDoor->GetState();
                // If the high water door has closed...
                if (highWaterDoorState == DoorState::Closed || highWaterDoorState == DoorState::Locked) {
                    // Do after close behavior.
                    sluice->highWaterDoor->AfterCloseBehavior();
                    // Open the low water door's lower valve.
                    sluice->lowWaterDoor->valveLow.Open();
                    // Move to the next state.
                    sluice->SetSluiceState(SluiceState::OpeningLowWaterDoorLowerValve);
                }
                // Else, do closing behavior.
                else {
                    sluice->highWaterDoor->DuringClosingBehavior();
                }
                break;
            }
            case (SluiceState::OpeningLowWaterDoorLowerValve): {
                // If the low water door's lower valve has opened, then move onto the next state.
                if (sluice->lowWaterDoor->valveLow.GetState() == ValveState::Open) {
                    sluice->SetSluiceState(SluiceState::WaitingForWaterLevelLow);
                }
                break;
            }
            case (SluiceState::WaitingForWaterLevelLow): {
                // If the water level has reached low, close the low water door's lower valve, then move onto the
                // next state.
                if (sluice->waterSensor.GetWaterLevel() == WaterLevel::Low) {
                    sluice->lowWaterDoor->valveLow.Close();
                    sluice->SetSluiceState(SluiceState::ClosingLowWaterDoorLowerValve);
                }
                break;
            }
            case (SluiceState::ClosingLowWaterDoorLowerValve): {
                // If the low water door's lower valve has closed, then open the low water door and
                // move onto the next state.
                if (sluice->lowWaterDoor->valveLow.GetState() == ValveState::Closed) {
                    sluice->lowWaterDoor->BeforeOpenBehavior();
                    sluice->lowWaterDoor->Open();
                    sluice->SetSluiceState(SluiceState::OpeningLowWaterDoor);
                }
                break;
            }
            case (SluiceState::OpeningLowWaterDoor): {
                DoorState::DoorState lowWaterDoorState = sluice->lowWaterDoor->GetState();
                // If the low water door has opened, then move to the next state.
                if (lowWaterDoorState == DoorState::Open) {
                    sluice->SetSluiceState(SluiceState::IdlingOnLowWater);
                }
                // Else, do opening behavior.
                else {
                    sluice->lowWaterDoor->DuringOpeningBehavior();
                }
                break;
            }
            case (SluiceState::IdlingOnLowWater):
                // Do nothing, just idling.
                break;
            case (SluiceState::ClosingLowWaterDoor): {
                DoorState::DoorState lowWaterDoorState1 = sluice->lowWaterDoor->GetState();
                // If the low water door has closed...
                if (lowWaterDoorState1 == DoorState::Closed || lowWaterDoorState1 == DoorState::Locked) {
                    // Do after close behavior.
                    sluice->lowWaterDoor->AfterCloseBehavior();
                    // Open the high water door's lower valve.
                    sluice->highWaterDoor->valveLow.Open();
                    // Move to the next state.
                    sluice->SetSluiceState(SluiceState::OpeningHighWaterDoorLowerValve);
                }
                // Else, do closing behavior.
                else {
                    sluice->lowWaterDoor->DuringClosingBehavior();
                }
                break;
            }
            case (SluiceState::OpeningHighWaterDoorLowerValve): {
                // If the high water door's lower valve has opened, then move onto the next state.
                if (sluice->highWaterDoor->valveLow.GetState() == ValveState::Open) {
                    sluice->SetSluiceState(SluiceState::WaitingForWaterLevelAboveMiddleValve);
                }
                break;
            }
            case (SluiceState::WaitingForWaterLevelAboveMiddleValve): {
                // If the water level has reached above the middle valves, then open the high water door's middle valve
                // and move to the next state.
                if (sluice->waterSensor.GetWaterLevel() == WaterLevel::AboveValve2) {
                    sluice->highWaterDoor->valveMiddle.Open();
                    sluice->SetSluiceState(SluiceState::OpeningHighWaterDoorMiddleValve);
                }
                break;
            }
            case (SluiceState::OpeningHighWaterDoorMiddleValve): {
                // If the high water door's middle valve has opened, then move onto the next state.
                if (sluice->highWaterDoor->valveMiddle.GetState() == ValveState::Open) {
                    sluice->SetSluiceState(SluiceState::WaitingForWaterLevelAboveUpperValve);
                }
                break;
            }
            case (SluiceState::WaitingForWaterLevelAboveUpperValve): {
                // If the water level has reached above the upper valves, then open the high water door's upper valve
                // and move to the next state.
                if (sluice->waterSensor.GetWaterLevel() == WaterLevel::AboveValve3) {
                    sluice->highWaterDoor->valveHigh.Open();
                    sluice->SetSluiceState(SluiceState::OpeningHighWaterDoorUpperValve);
                }
                break;
            }
            case (SluiceState::OpeningHighWaterDoorUpperValve): {
                // If the high water door's upper valve has opened, then move onto the next state.
                if (sluice->highWaterDoor->valveHigh.GetState() == ValveState::Open) {
                    sluice->SetSluiceState(SluiceState::WaitingForWaterLevelHigh);
                }
                break;
            }
            case (SluiceState::WaitingForWaterLevelHigh): {
                // If the water level has reached high, then close all high water door's valves
                // and move to the next state.
                if (sluice->waterSensor.GetWaterLevel() == WaterLevel::High) {
                    sluice->highWaterDoor->valveHigh.Close();
                    sluice->highWaterDoor->valveMiddle.Close();
                    sluice->highWaterDoor->valveLow.Close();
                    sluice->SetSluiceState(SluiceState::ClosingHighWaterDoorAllValves);
                }
                break;
            }
            case (SluiceState::ClosingHighWaterDoorAllValves): {
                // If all high water door's valves have closed, then open the high water door and
                // move to the next state.
                if (sluice->highWaterDoor->valveHigh.GetState() == ValveState::Closed &&
                        sluice->highWaterDoor->valveMiddle.GetState() == ValveState::Closed &&
                            sluice->highWaterDoor->valveLow.GetState() == ValveState::Closed) {
                    sluice->highWaterDoor->BeforeOpenBehavior();
                    sluice->highWaterDoor->Open();
                    sluice->SetSluiceState(SluiceState::OpeningHighWaterDoor);
                }
                break;
            }
            case (SluiceState::OpeningHighWaterDoor): {
                DoorState::DoorState highWaterDoorState1 = sluice->highWaterDoor->GetState();
                // If the high water door has opened, then move to the next state.
                if (highWaterDoorState1 == DoorState::Open) {
                    sluice->SetSluiceState(SluiceState::IdlingOnHighWater);
                }
                // Else, do opening behavior.
                else {
                    sluice->highWaterDoor->DuringOpeningBehavior();
                }
                break;
            }
        }
    }
    return NULL;
}





