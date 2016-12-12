#ifndef SLUIS_TRAFFICLIGHT_HPP
#define SLUIS_TRAFFICLIGHT_HPP

#include "SluiceSocketClient.hpp"

class TrafficLight {
private:
    const unsigned int port;
    const unsigned int index;
public:
    TrafficLight(unsigned int port, unsigned int index);
    ~TrafficLight();

    Power::Power GetPower(TrafficLightColor::TrafficLightColor color) const;
    void SetPower(TrafficLightColor::TrafficLightColor color, Power::Power power) const;
};

#endif  // SLUIS_TRAFFICLIGHT_HPP