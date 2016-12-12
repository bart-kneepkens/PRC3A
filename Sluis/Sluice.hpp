#ifndef SLUIS_SLUICE_HPP
#define SLUIS_SLUICE_HPP

#include "ButtonListener.hpp"
#include "Door.hpp"
#include "Network.hpp"
#include "TrafficLight.hpp"

class Sluice {
private:
    ButtonListener startListener;
    ButtonListener alarmListener;
    ButtonListener restoreListener;
    ButtonListener releaseInListener;
    ButtonListener releaseOutListener;

    Network network;

    Door frontDoor;
    Door backDoor;

    TrafficLight frontInLight;
    TrafficLight frontOutLight;
    TrafficLight backInLight;
    TrafficLight backOutLight;
public:
    Sluice();
    ~Sluice();

    Door GetDoor(DoorSide side) const;
    void AlarmButtonPressed();
    void ReleaseInButtonPressed();
    void ReleaseOutButtonPressed();
    void RestoreButtonPressed();
    void StartButtonPressed();
};

#endif  // SLUIS_SLUICE_HPP