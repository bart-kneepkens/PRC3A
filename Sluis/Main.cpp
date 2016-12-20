/**
 * Main entry point for the Sluice program.
 */

#include <string>
#include <iostream>

#include "SluiceSocketClient.hpp"
#include "Sluice.hpp"

/**
 * The sluice control used by this program.
 */
ISluiceController* control;

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
    const std::string doorsTypeStr(argv[3]);
    std::cout << "[INFO] Captured arguments: hostname='" << hostName << "', port='" << port << "', doorsType='"
              << doorsTypeStr << "'." << std::endl;

    // Determine what kind of doors the sluice control should have, and then instantiate it. Throw error if fails.
    try {
        DoorType::DoorType doorsType = DoorType::toDoorType(doorsTypeStr);
        control = new Sluice(doorsType);
    } catch (std::invalid_argument ex) {
        std::cerr << ex.what() << std::endl;
        exit(1);
    }

    // Instantiate the socket client and open it, quitting if it fails.
    sluice_client::CLIENT = new sluice_client::SluiceClient(hostName, port);
    if (sluice_client::CLIENT->OpenConnection() < 0) {
        exit(1);
    }

    // Close the socket client.
    sluice_client::CLIENT->CloseConnection();
    return 0;
}