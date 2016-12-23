#ifndef SLUIS_SLUICE_HPP
#define SLUIS_SLUICE_HPP

#include "DoorThatNeedsNewMotors.hpp"
#include "ISluiceController.hpp"
#include "TimedDoor.hpp"
#include "TrafficLight.hpp"
#include "WaterSensor.hpp"

/** Controls a single sluice. */
class Sluice : public ISluiceController {
private:
    /** Water sensor for measuring water height. */
    const WaterSensor waterSensor;

    /** The sluice door on the left. */
    const Door* leftDoor;
    /** The sluice door on the right. */
    const Door* rightDoor;

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
    /** Mutex used for enforcing thread-safe getting and setting of sluiceState. */
    pthread_mutex_t sluiceStateMutex;

    /**
     * Thread-safe getter for this sluice's current state.
     * @return
     */
    SluiceState::SluiceState GetSluiceState();
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
public:
    Sluice(DoorType::DoorType doorType = DoorType::Normal);
    ~Sluice();

    void AlarmButtonPressed();
    void ReleaseInButtonPressed();
    void ReleaseOutButtonPressed();
    void RestoreButtonPressed();
    void StartButtonPressed();
};

#endif  // SLUIS_SLUICE_HPP