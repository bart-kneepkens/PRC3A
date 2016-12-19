/**
 * Main entry point for the Sluice program.
 */

#include <string>
#include <iostream>

#include "SluiceSocketClient.hpp"

/**
 * Expects the following two arguments:
 * 1. What port we will be communicating through;
 * 2. What type of doors the sluice should have.
 *
 * The following options are valid for the simulation program:
 * 1. Port: 5555, Doors Type: Normal;
 * 2. Port: 5556, Doors Type: Normal;
 * 3. Port: 5557; Doors Type: Timed;
 * 4. Port: 5558; Doors Type: NeedsNewMotors.
 *
 * @param argc
 * @param argv
 * @return
 */
int main (int argc, char* argv[]) {
    // Make sure we have enough arguments supplied.
    if (argc < 3) {
        std::cerr << "Not enough arguments supplied! Required: 2 (port and doors type)." << std::endl;
        exit(1);
    }

    // Obtain arguments.
    const int port = atoi(argv[1]);
    const std::string doorsType(argv[2]);
    std::cout << "Captured arguments: port=" << port << " and doors type=" << doorsType << "." << std::endl;







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