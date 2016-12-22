#include "TrafficLight.hpp"

TrafficLight::TrafficLight(unsigned int index) : index(index) {}

TrafficLight::~TrafficLight() {}

Power::Power TrafficLight::GetPower(TrafficLightColor::TrafficLightColor color) const {
    return sluice_client::CLIENT->GetTrafficLightPower(index, color);
}

void TrafficLight::SetPower(TrafficLightColor::TrafficLightColor color, Power::Power power) const {
    sluice_client::CLIENT->SetTrafficLight(index, color, power);
}




