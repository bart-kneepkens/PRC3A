#include "Enumerators.hpp"

namespace Command {
    std::string ToString(Command command) {
        if (command == Command::GetDoor) {
            return "GetDoor";
        }
        if (command == Command::GetDoorLock) {
            return "GetDoorLockState";
        }
        if (command == Command::GetTrafficLight) {
            return "GetTrafficLight";
        }
        if (command == Command::GetWaterLevel) {
            return "GetSluiceWaterLevel";
        }
        if (command == Command::SetDoor) {
            return "SetDoor";
        }
        if (command == Command::SetDoorLock) {
            return "SetDoorLock";
        }
        return "SetTrafficLight";
    }
}

namespace DoorParameter {
    std::string ToString(DoorParameter parameter) {
        if (parameter == DoorParameter::Open) {
            return "open";
        }
        if (parameter == DoorParameter::Close) {
            return "close";
        }
        return "stop";
    }
}

namespace DoorState {
    DoorState ToDoorState(std::string value) {
        if (value == "Closed" || value == "doorClosed") {
            return DoorState::Closed;
        }
        if (value == "Open" || value == "doorOpen") {
            return DoorState::Open;
        }
        if (value == "Closing" || value == "doorClosing") {
            return DoorState::Closing;
        }
        if (value == "Opening" || value == "doorOpening") {
            return DoorState::Opening;
        }
        if (value == "Stopped" || value == "doorStopped") {
            return DoorState::Stopped;
        }
        if (value == "MotorDamage" || value == "motorDamage") {
            return DoorState::MotorDamage;
        }
        return DoorState::Locked;
    }
}

namespace DoorSide {
    std::string ToString(DoorSide parameter) {
        if (parameter == DoorSide::Left) {
            return "Left";
        }
        return "Right";
    }
}

namespace LockState {
    LockState ToLockState(std::string value) {
        if (value == "Working" || value == "lockWorking") {
            return LockState::Working;
        }
        return LockState::Damaged;
    }
}

namespace Power {
    Power ToPowerState(std::string value) {
        if (value == "on") {
            return Power::On;
        }
        return Power::Off;
    }

    std::string ToString(Power state) {
        if (state == Power::On) {
            return "on";
        }
        return "off";
    }
}

namespace TrafficLightColor {
    std::string ToString(TrafficLightColor parameter) {
        if (parameter == TrafficLightColor::Green) {
            return "Green";
        }
        return "Red";
    }
}

namespace ValveState {
    ValveState ToValveState(std::string value) {
        if (value == "Open" || value == "open") {
            return ValveState::Open;
        }
        return ValveState::Closed;
    }

    std::string ToString(ValveState state) {
        if (state == ValveState::Open) {
            return "open";
        }
        return "close";
    }
}

namespace WaterLevel {
    WaterLevel ToWaterLevel(std::string value) {
        if (value == "Low" || value == "low") {
            return WaterLevel::Low;
        }
        if (value == "BelowValve2" || value == "belowValve2") {
            return WaterLevel::BelowValve2;
        }
        if (value == "AboveValve2" || value == "aboveValve2") {
            return WaterLevel::AboveValve2;
        }
        if (value == "AboveValve3" || value == "aboveValve3") {
            return WaterLevel::AboveValve3;
        }
        return WaterLevel::High;
    }
}