#include "SluiceSocketClient.hpp"

std::string UIntToString(unsigned int integer) {
    std::stringstream ss;
    ss << integer;
    return ss.str();
}

bool SetDoor(unsigned int port, DoorSide::DoorSide side, DoorParameter::DoorParameter parameter) {
    const std::string command = Command::ToString(Command::SetDoor) +
            DoorSide::ToString(side) + ":" + DoorParameter::ToString(parameter);
    std::cout << command << std::endl;
    return true;
}

bool SetValve(unsigned int port, DoorSide::DoorSide side, unsigned int valveIndex, ValveState::ValveState valveState) {
    const std::string command = Command::ToString(Command::SetDoor) +
            DoorSide::ToString(side) + "Valve" + UIntToString(valveIndex) + ":" + ValveState::ToString(valveState);
    std::cout << command << std::endl;
    return true;
}

bool SetTrafficLight(unsigned int port, unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color, Power::Power power) {
    const std::string command = Command::ToString(Command::SetTrafficLight) + UIntToString(trafficLightIndex) +
            TrafficLightColor::ToString(color) + ":" + Power::ToString(power);
    std::cout << command << std::endl;
    return true;
}

bool SetLockPower(unsigned int port, DoorSide::DoorSide side, Power::Power power) {
    const std::string command = Command::ToString(Command::SetDoorLock) + DoorSide::ToString(side) +
            ":" + Power::ToString(power);
    std::cout << command << std::endl;
    return true;
}

DoorState::DoorState GetDoorState(unsigned int port, DoorSide::DoorSide side) {
    const std::string command = Command::ToString(Command::GetDoor) + DoorSide::ToString(side);
    std::cout << command << std::endl;
    return DoorState::Closed;
}

ValveState::ValveState GetValveState(unsigned int port, DoorSide::DoorSide side, unsigned int valveIndex) {
    const std::string command = Command::ToString(Command::GetDoor) + DoorSide::ToString(side) +
            "Valve" + UIntToString(valveIndex);
    std::cout << command << std::endl;
    return ValveState::Closed;
}

Power::Power GetTrafficLightPower(unsigned int port, unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color) {
    const std::string command = Command::ToString(Command::GetTrafficLight) + UIntToString(trafficLightIndex) +
            TrafficLightColor::ToString(color);
    std::cout << command << std::endl;
    return Power::Off;
}

WaterLevel::WaterLevel GetSluiceWaterLevel(unsigned int port) {
    const std::string command = Command::ToString(Command::GetWaterLevel);
    std::cout << command << std::endl;
    return WaterLevel::High;
}

LockState::LockState GetDoorLockState(unsigned int port, DoorSide::DoorSide side) {
    const std::string command = Command::ToString(Command::GetDoorLock) + DoorSide::ToString(side);
    std::cout << command << std::endl;
    return LockState::Damaged;
}

