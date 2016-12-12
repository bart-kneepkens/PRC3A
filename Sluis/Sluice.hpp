#ifndef SLUIS_SLUICE_HPP
#define SLUIS_SLUICE_HPP

#include "Door.hpp"
#include "ISluiceController.hpp"
#include "TrafficLight.hpp"
#include "WaterSensor.hpp"

class Sluice : public ISluiceController {
private:
    WaterSensor waterSensor;

    Door frontDoor;
    Door backDoor;

    TrafficLight frontInLight;
    TrafficLight frontOutLight;
    TrafficLight backInLight;
    TrafficLight backOutLight;
public:
    Sluice();
    ~Sluice();

    Door GetDoor(DoorSide::DoorSide side) const;
    void AlarmButtonPressed();
    void ReleaseInButtonPressed();
    void ReleaseOutButtonPressed();
    void RestoreButtonPressed();
    void StartButtonPressed();
};

#endif  // SLUIS_SLUICE_HPP