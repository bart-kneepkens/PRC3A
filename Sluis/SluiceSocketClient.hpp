#ifndef SLUIS_SLUICESOCKETCLIENT_HPP
#define SLUIS_SLUICESOCKETCLIENT_HPP

#include <string>
#include <sstream>
#include <iostream>         // For printing test messages.

#include "Enumerators.hpp"

std::string UIntToString(unsigned int integer);

bool SetDoor(DoorSide::DoorSide side, DoorParameter::DoorParameter parameter);

bool SetValve(DoorSide::DoorSide side, unsigned int valveIndex, ValveState::ValveState valveState);

bool SetTrafficLight(unsigned int trafficLightIndex, TrafficLightState::TrafficLightState color, Power::Power power);

bool SetLockPower(DoorSide::DoorSide side, Power::Power power);

DoorState::DoorState GetDoorState(DoorSide::DoorSide side);

ValveState::ValveState GetValveState(DoorSide::DoorSide side, unsigned int valveIndex);

Power::Power GetTrafficLightPower(unsigned int trafficLightIndex, TrafficLightState::TrafficLightState color);

WaterLevel::WaterLevel GetWaterLevel();

LockState::LockState GetLockState(DoorSide::DoorSide side);

#endif //SLUIS_SLUICESOCKETCLIENT_HPP
