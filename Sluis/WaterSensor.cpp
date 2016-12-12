#include "WaterSensor.hpp"

WaterSensor::WaterSensor(unsigned int port) : port(port) {}

WaterSensor::~WaterSensor() {}

WaterLevel::WaterLevel WaterSensor::GetWaterLevel() const {
    return GetSluiceWaterLevel(port);
}




