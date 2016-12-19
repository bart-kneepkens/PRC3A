/**
 * Main entry point for the Sluice program.
 */

#include <string>
#include <iostream>

#include "SluiceSocketClient.hpp"

/**
 * Expects the following two arguments:
 * 1. The hostname of the server;
 * 2. What port we will be communicating through;
 * 3. What type of doors the sluice should have.
 *
 * The following options are valid for the simulation program:
 * 1. Hostname: localhost, Port: 5555, Doors Type: Normal;
 * 2. Hostname: localhost, Port: 5556, Doors Type: Normal;
 * 3. Hostname: localhost, Port: 5557; Doors Type: Timed;
 * 4. Hostname: localhost, Port: 5558; Doors Type: NeedsNewMotors.
 *
 * @param argc
 * @param argv
 * @return
 */
int main (int argc, char* argv[]) {
    // Make sure we have enough arguments supplied.
    if (argc < 4) {
        std::cerr << "[ERROR] Not enough arguments supplied! Required: 3 (hostname, port, and doors type)." << std::endl;
        exit(1);
    }

    // Obtain arguments.
    char* hostName = argv[1];
    const int port = atoi(argv[2]);
    const std::string doorsType(argv[3]);
    std::cout << "[INFO] Captured arguments: hostname='" << hostName << "', port='" << port << "', doorsType='"
              << doorsType << "'." << std::endl;

    // Instantiate the socket client and open it, quitting if it fails.
    sluice_client::CLIENT = new sluice_client::SluiceClient(hostName, port);
    if (sluice_client::CLIENT->OpenConnection() < 0) {
        exit(1);
    }

    sluice_client::CLIENT->GetDoorState(DoorSide::Left);

    // Close the socket client.
    sluice_client::CLIENT->CloseConnection();




    /*SetDoor(DoorSide::Left, DoorParameter::Close);
    SetValve(DoorSide::Left, 1, ValveState::Closed);
    SetTrafficLight(1, TrafficLightColor::Green, Power::Off);
    SetLockPower(DoorSide::Left, Power::Off);
    GetDoorState(DoorSide::Left);
    GetValveState(DoorSide::Left, 1);
    GetTrafficLightPower(1, TrafficLightColor::Green);
    GetSluiceWaterLevel();
    GetDoorLockState(DoorSide::Left);*/

    //SluiceComplex complex = SluiceComplex();

    //std::cout << complex.GetSluice(0).GetDoor(DoorSide::Left)->GetState() << std::endl;

    return 0;
}