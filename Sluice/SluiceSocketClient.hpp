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
#include <stdlib.h>

#include "Enumerators.hpp"

namespace sluice_client {

    namespace {
        /**
         * Delimiter for incoming and outgoing messages.
         */
        extern const char DELIMITER;

        /**
         * Default size for socket reading buffers.
         */
        extern const unsigned int BUFFER_SIZE;

        /**
         * Ack message expected back from the server from certain calls.
         */
        extern const std::string ACK_MSG;

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
        /** Hostname of the server this client is connecting to. */
        const char *serverName;
        /** Port on the server this client is connecting through. */
        const unsigned int port;
        /** Id of the client-side socket. */
        int socketId;
        /** Mutex for enforcing only one reply-response sequence is done at a time. */
        pthread_mutex_t sendMsgMutex;

        /**
         * Sends the supplied message through the socket, and returns any retrieved reply. The socket should already be
         * open before this function is called. Blocks until a reply is received.
         *
         * @param msg
         * @return
         */
        std::string SendMsgAndGetReply(std::string msg);

    public:
        SluiceClient(char *serverName, unsigned int port);

        ~SluiceClient();

        /**
         * Opens the connection to the server, returning 0 if it succeeded or something else otherwise.
         * @return
         */
        int OpenConnection();

        /**
         * Closes the connection to the server, returning 0 if it succeeded or something else otherwise.
         * @return
         */
        int CloseConnection() const;

        /**
        * Instructs the specified door to open, close, or stop.
        *
        * @param side
        * @param parameter
        * @return whether this was done succesfully (an 'ack' was received from the server)
        */
        bool SetDoor(DoorSide::DoorSide side, DoorParameter::DoorParameter parameter);

        /**
        * Instructs the specified valve of the specified door to open or close.
        *
        * @param side
        * @param valveIndex
        * @param valveState
        * @return whether this was done succesfully (an 'ack' was received from the server)
        */
        bool SetValve(DoorSide::DoorSide side, unsigned int valveIndex, ValveState::ValveState valveState);

        /**
        * Instructs the specified colored light of the specified traffic light to turn on or off.
        *
        * @param trafficLightIndex
        * @param color
        * @param power
        * @return whether this was done succesfully (an 'ack' was received from the server)
        */
        bool
        SetTrafficLight(unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color, Power::Power power);

        /**
        * Instructs the lock of the specified door to turn on or off.
        *
        * @param side
        * @param power
        * @return whether this was done succesfully (an 'ack' was received from the server)
        */
        bool SetLockPower(DoorSide::DoorSide side, Power::Power power);

        /**
        * Retrieves the door state of the specified door.
        *
        * @throws invalid_argument if the received reply could not be parsed to the enum.
        * @param side
        * @return
        */
        DoorState::DoorState GetDoorState(DoorSide::DoorSide side);

        /**
        * Returns the valve state of the specified valve of the specified door.
        *
        * @throws invalid_argument if the received reply could not be parsed to the enum.
        * @param side
        * @param valveIndex
        * @return
        */
        ValveState::ValveState GetValveState(DoorSide::DoorSide side, unsigned int valveIndex);

        /**
        * Returns the power status of the specified light color of the specified traffic light.
        *
        * @throws invalid_argument if the received reply could not be parsed to the enum.
        * @param trafficLightIndex
        * @param color
        * @return
        */
        Power::Power GetTrafficLightPower(unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color);

        /**
        * Returns the current water level.
        *
        * @throws invalid_argument if the received reply could not be parsed to the enum.
        * @return
        */
        WaterLevel::WaterLevel GetSluiceWaterLevel();

        /**
        * Returns the current lock state of the specified door.
        *
        * @throws invalid_argument if the received reply could not be parsed to the enum.
        * @param side
        * @return
        */
        LockState::LockState GetDoorLockState(DoorSide::DoorSide side);
    };

    /**
     * Global instance of SluiceClient class. Instantiate once per program to have a single global instance of SluiceClient.
     */
    extern SluiceClient *CLIENT;
}

#endif //SLUIS_SLUICESOCKETCLIENT_HPP
