/**
 * Main entry point for the Sluice program.
 */

#include <pthread.h>
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
 * Thread for when the release in button was pressed.
 * @param threadArgs
 * @return
 */
void *ReleaseInButtonThread(void *threadArgs) {
    try {
        control->ReleaseInButtonPressed();
    }
    catch (const std::exception &ex) {
        //std::cerr << ex.what() << std::endl;
        // Pretend we log this to a file or something.
    }
    return NULL;
}

/**
 * Thread for when the start button was pressed.
 * @param threadArgs
 * @return
 */
void *StartButtonThread(void *threadArgs) {
    try {
        control->StartButtonPressed();
    }
    catch (const std::exception &ex) {
        //std::cerr << ex.what() << std::endl;
        // Pretend we log this to a file or something.
    }
    return NULL;
}

/**
 * Thread for when the release out button was pressed.
 * @param threadArgs
 * @return
 */
void *ReleaseOutButtonThread(void *threadArgs) {
    try {
        control->ReleaseOutButtonPressed();
    }
    catch (const std::exception &ex) {
        //std::cerr << ex.what() << std::endl;
        // Pretend we log this to a file or something.
    }
    return NULL;
}

/**
 * Thread for when the alarm/emergency button was pressed.
 * @param threadArgs
 * @return
 */
void *AlarmButtonThread(void *threadArgs) {
    try {
        control->AlarmButtonPressed();
    }
    catch (const std::exception &ex) {
        //std::cerr << ex.what() << std::endl;
        // Pretend we log this to a file or something.
    }
    return NULL;
}

/**
 * Thread for when the restore/recover button was pressed.
 * @param threadArgs
 * @return
 */
void *RestoreButtonThread(void *threadArgs) {
    try {
        control->RestoreButtonPressed();
    }
    catch (const std::exception &ex) {
        //std::cerr << ex.what() << std::endl;
        // Pretend we log this to a file or something.
    }
    return NULL;
}

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
    //std::cout << "[INFO] Captured arguments: hostname='" << hostName << "', port='" << port << "', doorsType='"
    //          << doorsTypeStr << "'." << std::endl;

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
    if (sluice_client::CLIENT->OpenConnection() != 0) {
        exit(1);
    }

    // For as long as the user does not quit the program, keep looping to capture user input.
    bool exit = false;
    while (!exit) {
        // Present user with options.
        std::cout << "\n########################" << std::endl;
        std::cout << "[ LAST STATE: " << SluiceState::ToString(control->GetSluiceState()) << ". CHOOSE AN ACTION ]" << std::endl;
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
        pthread_t threadID;

        // Instantiate correct thread / take proper action according to input.
        switch (input) {
            case '1':
                pthread_create(&threadID, NULL, ReleaseInButtonThread, NULL);
                break;
            case '2':
                pthread_create(&threadID, NULL, StartButtonThread, NULL);
                break;
            case '3':
                pthread_create(&threadID, NULL, ReleaseOutButtonThread, NULL);
                break;
            case '4':
                pthread_create(&threadID, NULL, AlarmButtonThread, NULL);
                break;
            case '5':
                pthread_create(&threadID, NULL, RestoreButtonThread, NULL);
                break;
            case '6':
                //std::cout << "[INFO] Exiting program..." << std::endl;
                exit = true;
                break;
            default:
                //std::cerr << "[WARNING] Not a valid action!" << std::endl;
                break;
        }
    }

    // Close and delete the socket client.
    delete control;
    return 0;
}
