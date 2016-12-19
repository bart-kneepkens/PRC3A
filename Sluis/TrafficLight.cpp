#include "TrafficLight.hpp"

TrafficLight::TrafficLight(unsigned int index) : index(index) {}

TrafficLight::~TrafficLight() {}

Power::Power TrafficLight::GetPower(TrafficLightColor::TrafficLightColor color) const {
    return sluice_client::GetTrafficLightPower(index, color);
}

void TrafficLight::SetPower(TrafficLightColor::TrafficLightColor color, Power::Power power) const {
    sluice_client::SetTrafficLight(index, color, power);
}




