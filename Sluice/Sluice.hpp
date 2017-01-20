#ifndef SLUIS_SLUICE_HPP
#define SLUIS_SLUICE_HPP

#include <unistd.h>
#include <pthread.h>

#include "DoorThatNeedsNewMotors.hpp"
#include "TimedDoor.hpp"
#include "TrafficLight.hpp"
#include "WaterSensor.hpp"

/** Controls a single sluice. */
class Sluice {
private:
    /** The default duration of sleeps in busy-waiting loops. */
    // static const unsigned int SLEEP_DURATION = 250;

    /** Water sensor for measuring water height. */
    const WaterSensor waterSensor;

    /** The sluice door on the left. */
    Door *lowWaterDoor;
    /** The sluice door on the right. */
    Door *highWaterDoor;

    /** The left-most traffic light. */
    const TrafficLight lowWaterInLight;
    /** The second-most left traffic light. */
    const TrafficLight lowWaterOutLight;
    /** The second-most right traffic light. */
    const TrafficLight highWaterInLight;
    /** The right-most traffic light. */
    const TrafficLight highWaterOutLight;

    /** The type of this sluice's doors. */
    const DoorType::DoorType doorType;

    /** This sluice's current state. */
    SluiceState::SluiceState sluiceState;
    /** This sluice's previous state. Used for when recovering from an emergency stop. */
    SluiceState::SluiceState previousState;
    /** Mutex used for enforcing thread-safe getting and setting of sluiceState. */
    pthread_mutex_t sluiceStateMutex;

    /** The thread used by Run. */
    pthread_t runningThread;

    /**
     * Thread-safe setter for this sluice's current state.
     * @param state
     */
    void SetSluiceState(SluiceState::SluiceState state);

    /**
     * Function used for the POSIX thread created and ran by non-static void Run().
     * @param threadArgs Pointer to a Sluice instance. May not be NULL.
     * @return
     */
    void static *Run(void *threadArgs);

public:
    Sluice(DoorType::DoorType doorType = DoorType::Normal);

    ~Sluice();

    /**
    * Thread-safe getter for this sluice's current state.
    * @return
    */
    SluiceState::SluiceState GetSluiceState();

    /**
     * Starts running this sluice controller. Should only be called once.
     * Non-blocking, as it creates and runs in a separate thread.
     */
    void Run();

    /** Called when the alarm/emergency button has been pressed. */
    void AlarmButtonPressed();

    /** Called when ships may be signalled to enter the sluice. */
    void ReleaseInButtonPressed();

    /** Called when ships may be signalled to leave the sluice. */
    void ReleaseOutButtonPressed();

    /** Called to recover from an emergency state. */
    void RestoreButtonPressed();

    /** Called to start the main sluice process. */
    void StartButtonPressed();
};

#endif  // SLUIS_SLUICE_HPP