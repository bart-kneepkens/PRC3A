#ifndef SLUIS_SLUICE_HPP
#define SLUIS_SLUICE_HPP

#include "DoorThatNeedsNewMotors.hpp"
#include "TimedDoor.hpp"
#include "TrafficLight.hpp"
#include "WaterSensor.hpp"
#include <unistd.h>

/** Controls a single sluice. */
class Sluice {
private:
    /** The default duration of sleeps in busy-waiting loops. */
    static const unsigned int SLEEP_DURATION = 250;

    /** Water sensor for measuring water height. */
    const WaterSensor waterSensor;

    /** The sluice door on the left. */
    Door *leftDoor;
    /** The sluice door on the right. */
    Door *rightDoor;

    /** The left-most traffic light. */
    const TrafficLight leftInLight;
    /** The second-most left traffic light. */
    const TrafficLight leftOutLight;
    /** The second-most right traffic light. */
    const TrafficLight rightInLight;
    /** The right-most traffic light. */
    const TrafficLight rightOutLight;

    /** The type of this sluice's doors. */
    const DoorType::DoorType doorType;

    /** This sluice's current state. */
    SluiceState::SluiceState sluiceState;
    /** This sluice's previous state. Used for when recovering from an emergency stop. */
    SluiceState::SluiceState previousState;
    /** Mutex used for enforcing thread-safe getting and setting of sluiceState. */
    pthread_mutex_t sluiceStateMutex;

    /**
     * Thread-safe setter for this sluice's current state.
     * @param state
     */
    void SetSluiceState(SluiceState::SluiceState state);

    /**
     * Whether or not the traffic lights may currently be toggled.
     * @return
     */
    bool MayToggleLights();

    /**
     * Checks whether we're currently in the emergency state, and takes action accordingly. Will block for as long
     * as the emergency state is active, then sets all the states back to their previous states.
     */
    void CheckForEmergency();

public:
    Sluice(DoorType::DoorType doorType = DoorType::Normal);

    ~Sluice();

    /**
    * Thread-safe getter for this sluice's current state.
    * @return
    */
    SluiceState::SluiceState GetSluiceState();

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