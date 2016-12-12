#ifndef SLUIS_TRAFFICLIGHT_HPP
#define SLUIS_TRAFFICLIGHT_HPP

#include "Enumerators.hpp"

class TrafficLight {
private:
    TrafficLightState::TrafficLightState state;
public:
    TrafficLight();
    ~TrafficLight();

    TrafficLightState::TrafficLightState GetState() const;
    void SetState(TrafficLightState::TrafficLightState state);
};

#endif  // SLUIS_TRAFFICLIGHT_HPP