/**
 * Exposes functions which send requests to the simulation server via sockets and return replies to the caller.
 */

#ifndef SLUIS_SLUICESOCKETCLIENT_HPP
#define SLUIS_SLUICESOCKETCLIENT_HPP

#include <string>
#include <sstream>      // For parsing ints to strings.
#include <iostream>     // For printing debug messages.
#include <netdb.h>
#include <unistd.h>
#include <cstring>

#include "Enumerators.hpp"

namespace sluice_client {

    namespace {
        /**
        * Convenience function for parsing an unsigned integer to a string.
        *
        * @param integer
        * @return
        */
        std::string UIntToString(unsigned int integer);
    }

    class SluiceClient {
    private:
        const char *serverName;
        const unsigned int port;
        int socketId = -1;
    public:
        SluiceClient(char *serverName, unsigned int port);

        ~SluiceClient();

        int GetSocketId() const;

        int OpenConnection();

        int CloseConnection() const;

        /**
        * Instructs the specified door to open, close, or stop.
        *
        * @param side
        * @param parameter
        * @return whether this was done succesfully
        */
        bool SetDoor(DoorSide::DoorSide side, DoorParameter::DoorParameter parameter) const;

        /**
        * Instructs the specified valve of the specified door to open or close.
        *
        * @param side
        * @param valveIndex
        * @param valveState
        * @return whether this was done succesfully
        */
        bool SetValve(DoorSide::DoorSide side, unsigned int valveIndex, ValveState::ValveState valveState) const;

        /**
        * Instructs the specified colored light of the specified traffic light to turn on or off.
        *
        * @param trafficLightIndex
        * @param color
        * @param power
        * @return whether this was done succesfully
        */
        bool
        SetTrafficLight(unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color, Power::Power power) const;

        /**
        * Instructs the lock of the specified door to turn on or off.
        *
        * @param side
        * @param power
        * @return whether this was done succesfully
        */
        bool SetLockPower(DoorSide::DoorSide side, Power::Power power) const;

        /**
        * Retrieves the door state of the specified door.
        *
        * @param side
        * @return
        */
        DoorState::DoorState GetDoorState(DoorSide::DoorSide side) const;

        /**
        * Returns the valve state of the specified valve of the specified door.
        *
        * @param side
        * @param valveIndex
        * @return
        */
        ValveState::ValveState GetValveState(DoorSide::DoorSide side, unsigned int valveIndex) const;

        /**
        * Returns the power status of the specified light color of the specified traffic light.
        *
        * @param trafficLightIndex
        * @param color
        * @return
        */
        Power::Power GetTrafficLightPower(unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color) const;

        /**
        * Returns the current water level.
        *
        * @return
        */
        WaterLevel::WaterLevel GetSluiceWaterLevel() const;

        /**
        * Returns the current lock state of the specified door.
        *
        * @param side
        * @return
        */
        LockState::LockState GetDoorLockState(DoorSide::DoorSide side) const;
    };

    /**
     * Global instance of SluiceClient class. Instantiate once per program to have a single global instance of SluiceClient.
     */
    extern SluiceClient* CLIENT;
}

#endif //SLUIS_SLUICESOCKETCLIENT_HPP
