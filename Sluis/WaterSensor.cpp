#include "WaterSensor.hpp"

WaterSensor::WaterSensor() {}

WaterSensor::~WaterSensor() {}

WaterLevel::WaterLevel WaterSensor::GetWaterLevel() const {
    return sluice_client::GetSluiceWaterLevel();
}




