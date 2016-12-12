#ifndef SLUIS_DOOR_HPP
#define SLUIS_DOOR_HPP

#include "Enumerators.hpp"
#include "Lock.hpp"
#include "Valve.hpp"
#include "WaterSensor.hpp"

class Door {
private:
    DoorState state;
    Lock lock;

    WaterSensor sensorLeft;
    WaterSensor sensorRight;

    Valve valveLow;
    Valve valveMiddle;
    Valve valveHigh;
public:
    Door();
    virtual ~Door();

    void Open();
    void Close();
    void Stop();
    DoorState GetState() const;
    void OpenValves();
    void CloseValves();
};

#endif  // SLUIS_DOOR_HPP