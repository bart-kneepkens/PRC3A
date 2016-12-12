#include "TrafficLight.hpp"

TrafficLight::TrafficLight(unsigned int port, unsigned int index) : port(port), index(index) {}

TrafficLight::~TrafficLight() {}

Power::Power TrafficLight::GetPower(TrafficLightColor::TrafficLightColor color) const {
    return GetTrafficLightPower(port, index, color);
}

void TrafficLight::SetPower(TrafficLightColor::TrafficLightColor color, Power::Power power) const {
    SetTrafficLight(port, index, color, power);
}




