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
public:
    Sluice(DoorType::DoorType doorType = DoorType::Normal);
    ~Sluice();

    const Door* GetDoor(DoorSide::DoorSide side) const;
    void AlarmButtonPressed() const;
    void ReleaseInButtonPressed() const;
    void ReleaseOutButtonPressed() const;
    void RestoreButtonPressed() const;
    void StartButtonPressed() const;
};

#endif  // SLUIS_SLUICE_HPP