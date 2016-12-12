#ifndef SLUIS_TRAFFICLIGHT_HPP
#define SLUIS_TRAFFICLIGHT_HPP

#include "Enumerators.hpp"

class TrafficLight {
private:
    TrafficLightState state;
public:
    TrafficLight();
    ~TrafficLight();

    TrafficLightState GetState() const;
    void SetState(TrafficLightState state);
};

#endif  // SLUIS_TRAFFICLIGHT_HPP