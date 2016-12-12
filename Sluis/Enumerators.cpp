#include "Enumerators.hpp"

std::string Command::toString(Command command) {
    if (command == Command::GetDoor) {
        return "GetDoor";
    }
    if (command == Command::GetDoorLock) {
        return "GetDoorLock";
    }
    if (command == Command::GetTrafficLight) {
        return "GetTrafficLight";
    }
    if (command == Command::GetWaterLevel) {
        return "GetWaterLevel";
    }
    if (command == Command::SetDoor) {
        return "SetDoor";
    }
    if (command == Command::SetDoorLock) {
        return "SetDoorLock";
    }
    return "SetTrafficLight";
}

std::string DoorParameter::toString(DoorParameter parameter) {
    if (parameter == DoorParameter::Open) {
        return "open";
    }
    if (parameter == DoorParameter::Close) {
        return "close";
    }
    return "stop";
}

DoorState DoorState::toDoorState(std::string value) {
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

std::string DoorSide::toString(DoorSide parameter) {
    if (parameter == DoorSide::Left) {
        return "Left";
    }
    return "Right";
}

LockState LockState::toLockState(std::string value) {
    if (value == "Working" || value == "lockWorking") {
        return LockState::Working;
    }
    return LockState::Damaged;
}

Power Power::toPowerState(std::string value) {
    if (value == "on") {
        return Power::On;
    }
    return Power::Off;
}

std::string Power::toString(Power state) {
    if (state == Power::On) {
        return "on";
    }
    return "off";
}

std::string TrafficLightState::toString(TrafficLightState parameter) {
    if (parameter == TrafficLightState::Green) {
        return "Green";
    }
    return "Red";
}

ValveState ValveState::toValveState(std::string value) {
    if (value == "Open" || value == "open") {
        return ValveState::Open;
    }
    return ValveState::Closed;
}

std::string ValveState::toString(ValveState state) {
    if (state == ValveState::Open) {
        return "open";
    }
    return "close";
}

WaterLevel WaterLevel::toWaterLevel(std::string value) {
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