#ifndef SLUIS_ENUMERATORS_HPP
#define SLUIS_ENUMERATORS_HPP

#include <string>

enum DoorState {
    Locked,
    Closed,
    Open,
    Closing,
    Opening,
    Stopped,
    MotorDamage
};

DoorState toDoorState(std::string value);

enum DoorSide {
    Left,
    Right
};

DoorSide toDoorSide(std::string value);

enum TrafficLightState {
    Red,
    Green
};

TrafficLightState toTrafficLightState(std::string value);

enum WaterLevel {
    Low,
    BelowValve2,
    AboveValve2,
    AboveValve3,
    High
};

WaterLevel toWaterLevel(std::string value);

enum LockState {
    Working,
    Damaged
};

LockState toLockState(std::string value);

#endif  // SLUIS_ENUMERATORS_HPP
