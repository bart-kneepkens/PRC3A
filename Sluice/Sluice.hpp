#ifndef SLUIS_SLUICE_HPP
#define SLUIS_SLUICE_HPP

#include <mutex>

#include "DoorThatNeedsNewMotors.hpp"
#include "ISluiceController.hpp"
#include "TimedDoor.hpp"
#include "TrafficLight.hpp"
#include "WaterSensor.hpp"

class Sluice : public ISluiceController {
private:
    const WaterSensor waterSensor;

    const Door* leftDoor;
    const Door* rightDoor;

    const TrafficLight leftInLight;
    const TrafficLight leftOutLight;
    const TrafficLight rightInLight;
    const TrafficLight rightOutLight;

    const DoorType::DoorType doorType;

    SluiceState::SluiceState sluiceState = SluiceState::Idle;
    std::mutex sluiceStateMutex;

    SluiceState::SluiceState GetSluiceState();
    void SetSluiceState(SluiceState::SluiceState state);
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