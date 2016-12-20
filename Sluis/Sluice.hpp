#ifndef SLUIS_SLUICE_HPP
#define SLUIS_SLUICE_HPP

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
public:
    Sluice(DoorType::DoorType doorType = DoorType::Normal);
    ~Sluice();

    void AlarmButtonPressed() const;
    void ReleaseInButtonPressed() const;
    void ReleaseOutButtonPressed() const;
    void RestoreButtonPressed() const;
    void StartButtonPressed() const;
};

#endif  // SLUIS_SLUICE_HPP