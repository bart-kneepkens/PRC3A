#include "SluiceSocketClient.hpp"
#include <iostream>
namespace sluice_client {

    namespace {

        const char DELIMITER = ';';
        unsigned const int BUFFER_SIZE = 16;
        const std::string ACK_MSG = "ack";

        std::string UIntToString(unsigned int integer) {
            std::stringstream ss;
            ss << integer;
            return ss.str();
        }
    }

    std::string SluiceClient::SendMsgAndGetReply(std::string msg) {
        // Append delimiter to msg.
        msg += DELIMITER;

        // Convert string to char array, then send it to server. If sending fails, close and exit.
        char sendBuffer[msg.length()];
        strcpy(sendBuffer, msg.c_str());
        if (write(socketId, sendBuffer, strlen(sendBuffer)) < 0) {
            perror("[ERROR] Error while writing to socket");
            CloseConnection();
            exit(1);
        }
        //std::cout << "[INFO] Sent message to server: '" << sendBuffer << "'." << std::endl;

        // Retrieve reply from server. If receiving fails, close and exit.
        char replyBuffer[BUFFER_SIZE];
        bzero(replyBuffer, BUFFER_SIZE);
        if (read(socketId, replyBuffer, BUFFER_SIZE - 1) < 0) {
            perror("[ERROR] Error while reading from socket");
            CloseConnection();
            exit(1);
        }
        //std::cout << "[INFO] Received reply from server: '" << replyBuffer << "'." << std::endl;

        // Parse buffer to string and return it.
        std::string replyString(replyBuffer);
        replyString.erase(replyString.size() - 1);  // Remove trailing delimiter character.
        return replyString;
    }

    SluiceClient::SluiceClient(char *serverName, unsigned int port) : serverName(serverName), port(port) {}

    SluiceClient::~SluiceClient() {
        CloseConnection();
    }

    int SluiceClient::GetSocketId() const {
        return this->socketId;
    }

    int SluiceClient::OpenConnection() {
        // Open up the client-side socket. If it fails, print error and exit.
        this->socketId = socket(AF_INET, SOCK_STREAM, 0);
        if (socketId < 0) {
            perror("[ERROR] Error while creating client-side socket");
            return 1;
        }
        //std::cout << "[INFO] Created client-side socket." << std::endl;

        // Check if server exists. If not, throw warning and exit.
        const hostent *server = gethostbyname(serverName);
        if (server == NULL) {
            const std::string serverNameStr(serverName);
            const std::string errorMsg = "[ERROR] Error while finding server with hostname '" + serverNameStr + "'";
            perror(errorMsg.c_str());
            CloseConnection();
            return 1;
        }
        //std::cout << "[INFO] Found server with hostname '" << serverName << "'." << std::endl;

        // Bind the socket to the port.
        sockaddr_in serv_addr;
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy(server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(port);

        // Connect to the server, throwing an error if it failed.
        if (connect(socketId, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("[ERROR] Error while connecting to server");
            CloseConnection();
            return 1;
        }
        //std::cout << "[INFO] Connected to server." << std::endl;
        return 0;
    }

    int SluiceClient::CloseConnection() const {
        return close(socketId);
        //std::cout << "[INFO] Closed client-side socket." << std::endl;
    }

    bool SluiceClient::SetDoor(DoorSide::DoorSide side, DoorParameter::DoorParameter parameter) {
        const std::string command = Command::ToString(Command::SetDoor) +
                                    DoorSide::ToString(side) + ":" + DoorParameter::ToString(parameter);
        return SendMsgAndGetReply(command) == ACK_MSG;
    }

    bool
    SluiceClient::SetValve(DoorSide::DoorSide side, unsigned int valveIndex, ValveState::ValveState valveState) {
        const std::string command = Command::ToString(Command::SetDoor) +
                                    DoorSide::ToString(side) + "Valve" + UIntToString(valveIndex) + ":" +
                                    ValveState::ToString(valveState);
        return SendMsgAndGetReply(command) == ACK_MSG;
    }

    bool
    SluiceClient::SetTrafficLight(unsigned int trafficLightIndex, TrafficLightColor::TrafficLightColor color,
                                  Power::Power power) {
        const std::string command = Command::ToString(Command::SetTrafficLight) + UIntToString(trafficLightIndex) +
                                    TrafficLightColor::ToString(color) + ":" + Power::ToString(power);
        return SendMsgAndGetReply(command) == ACK_MSG;
    }

    bool SluiceClient::SetLockPower(DoorSide::DoorSide side, Power::Power power) {
        const std::string command = Command::ToString(Command::SetDoorLock) + DoorSide::ToString(side) +
                                    ":" + Power::ToString(power);
        return SendMsgAndGetReply(command) == ACK_MSG;
    }

    DoorState::DoorState SluiceClient::GetDoorState(DoorSide::DoorSide side) {
        const std::string command = Command::ToString(Command::GetDoor) + DoorSide::ToString(side);
        std::string replyString = SendMsgAndGetReply(command);
        DoorState::DoorState state = DoorState::ToDoorState(replyString);
        return state;
    }

    ValveState::ValveState SluiceClient::GetValveState(DoorSide::DoorSide side, unsigned int valveIndex) {
        const std::string command = Command::ToString(Command::GetDoor) + DoorSide::ToString(side) +
                                    "Valve" + UIntToString(valveIndex);
        std::string replyString = SendMsgAndGetReply(command);
        ValveState::ValveState state = ValveState::ToValveState(replyString);
        return state;
    }

    Power::Power SluiceClient::GetTrafficLightPower(unsigned int trafficLightIndex,
                                                    TrafficLightColor::TrafficLightColor color) {
        const std::string command = Command::ToString(Command::GetTrafficLight) + UIntToString(trafficLightIndex) +
                                    TrafficLightColor::ToString(color);
        std::string replyString = SendMsgAndGetReply(command);
        Power::Power state = Power::ToPowerState(replyString);
        return state;
    }

    WaterLevel::WaterLevel SluiceClient::GetSluiceWaterLevel() {
        const std::string command = Command::ToString(Command::GetWaterLevel);
        std::string replyString = SendMsgAndGetReply(command);
        WaterLevel::WaterLevel state = WaterLevel::ToWaterLevel(replyString);
        return state;
    }

    LockState::LockState SluiceClient::GetDoorLockState(DoorSide::DoorSide side) {
        const std::string command = Command::ToString(Command::GetDoorLock) + DoorSide::ToString(side);
        std::string replyString = SendMsgAndGetReply(command);
        LockState::LockState state = LockState::ToLockState(replyString);
        return state;
    }

    SluiceClient *CLIENT = NULL;
}

