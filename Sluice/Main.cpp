/**
 * Main entry point for the Sluice program.
 */

#include <string>
#include <iostream>
#include <stdlib.h>

#include "SluiceSocketClient.hpp"
#include "Sluice.hpp"

/**
 * The sluice control used by this program.
 */
Sluice *control;

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
int main(int argc, char *argv[]) {
    // Make sure we have enough arguments supplied.
    if (argc < 4) {
        std::cerr << "[ERROR] Not enough arguments supplied! Required: 3 (hostname, port, and doors type)."
                  << std::endl;
        exit(1);
    }

    // Obtain arguments.
    char *hostName = argv[1];
    const unsigned int port = atoi(argv[2]);
    const std::string doorsTypeStr(argv[3]);

    // Instantiate the socket client and open it, quitting if it fails.
    sluice_client::CLIENT = new sluice_client::SluiceClient(hostName, port);
    if (sluice_client::CLIENT->OpenConnection() != 0) {
        exit(1);
    }

    // Determine what kind of doors the sluice control should have, and then instantiate it. Throw error if fails.
    try {
        DoorType::DoorType doorsType = DoorType::toDoorType(doorsTypeStr);
        Door *lowWaterDoor = 0;
        Door *highWaterDoor = 0;

        switch (doorsType) {
            case DoorType::Timed:
                lowWaterDoor = new TimedDoor(DoorSide::LowWater);
                highWaterDoor = new TimedDoor(DoorSide::HighWater);
                break;
            case DoorType::NeedsNewMotors:
                lowWaterDoor = new DoorThatNeedsNewMotors(DoorSide::LowWater);
                highWaterDoor = new DoorThatNeedsNewMotors(DoorSide::HighWater);
                break;
            default:
                lowWaterDoor = new Door(DoorSide::LowWater);
                highWaterDoor = new Door(DoorSide::HighWater);
                break;
        }

        control = new Sluice(lowWaterDoor, highWaterDoor);
        control->Run();
    } catch (std::invalid_argument ex) {
        std::cerr << ex.what() << std::endl;
        exit(1);
    }

    // For as long as the user does not quit the program, keep looping to capture user input.
    bool exit = false;
    while (!exit) {
        // Present user with options.
        std::cout << "\n########################" << std::endl;
        std::cout << "[ CHOOSE AN ACTION ]" << std::endl;
        std::cout << "1: Signal ships may enter sluice;" << std::endl;
        std::cout << "2: Start sluice process;" << std::endl;
        std::cout << "3: Signal ships may leave sluice;" << std::endl;
        std::cout << "4: Emergency stop;" << std::endl;
        std::cout << "5: Continue after emergency stop;" << std::endl;
        std::cout << "6: Exit program." << std::endl;
        std::cout << "########################" << std::endl << std::endl;
        std::cout << "[INPUT] " << std::endl;

        // Capture user input.
        char input;
        std::cin >> input;
        std::cin.ignore();

        // Instantiate correct thread / take proper action according to input.
        switch (input) {
            case '1':
                control->ReleaseInButtonPressed();
                break;
            case '2':
                control->StartButtonPressed();
                break;
            case '3':
                control->ReleaseOutButtonPressed();
                break;
            case '4':
                control->AlarmButtonPressed();
                break;
            case '5':
                control->RestoreButtonPressed();
                break;
            case '6':
                exit = true;
                break;
            default:
                break;
        }
    }

    // Close and delete the socket client.
    delete control;
    return 0;
}
