/**
 * Exposes functions which send requests to the simulation server via sockets and return replies to the caller.
 */

#ifndef SLUIS_SLUICESOCKETCLIENT_HPP
#define SLUIS_SLUICESOCKETCLIENT_HPP

#include <string>
#include <sstream>      // For parsing ints to strings.
#include <iostream>     // For printing debug messages.

#include "Enumerators.hpp"

/**
 * Convenience function for parsing an unsigned integer to a string.
 *
 * @param integer
 * @return
 */
std::string UIntToString(unsigned int integer);

/**
 * Instructs the specified door to open, close, or stop.
 *
 * @param port
 * @param side
 * @param parameter
 * @return whether this was done succesfully
 */
bool SetDoor(unsigned int port, DoorSide::DoorSide side, DoorParameter::DoorParameter parameter);

/**
 * Instructs the specified valve of the specified door to open or close.
 *
 * @param port
 * @param side
 * @param valveIndex
 * @param valveState
 * @return whether this was done succesfully
 */
bool SetValve(unsigned int port, DoorSide::DoorSide side, unsigned int valveIndex, ValveState::ValveState valveState);

/**
 * Instructs the specified colored light of the specified traffic light to turn on or off.
 *
 * @param port
 * @param trafficLightIndex
 * @param color
 * @param power
 * @return whether this was done succesfully
 */
bool SetTrafficLight(unsigned int port, unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color, Power::Power power);

/**
 * Instructs the lock of the specified door to turn on or off.
 *
 * @param port
 * @param side
 * @param power
 * @return whether this was done succesfully
 */
bool SetLockPower(unsigned int port, DoorSide::DoorSide side, Power::Power power);

/**
 * Retrieves the door state of the specified door.
 *
 * @param port
 * @param side
 * @return
 */
DoorState::DoorState GetDoorState(unsigned int port, DoorSide::DoorSide side);

/**
 * Returns the valve state of the specified valve of the specified door.
 *
 * @param port
 * @param side
 * @param valveIndex
 * @return
 */
ValveState::ValveState GetValveState(unsigned int port, DoorSide::DoorSide side, unsigned int valveIndex);

/**
 * Returns the power status of the specified light color of the specified traffic light.
 *
 * @param port
 * @param trafficLightIndex
 * @param color
 * @return
 */
Power::Power GetTrafficLightPower(unsigned int port, unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color);

/**
 * Returns the current water level.
 *
 * @param port
 * @return
 */
WaterLevel::WaterLevel GetSluiceWaterLevel(unsigned int port);

/**
 * Returns the current lock state of the specified door.
 *
 * @param port
 * @param side
 * @return
 */
LockState::LockState GetDoorLockState(unsigned int port, DoorSide::DoorSide side);

#endif //SLUIS_SLUICESOCKETCLIENT_HPP
