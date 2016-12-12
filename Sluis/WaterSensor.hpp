#ifndef SLUIS_WATERSENSOR_HPP
#define SLUIS_WATERSENSOR_HPP

#include "Enumerators.hpp"

class WaterSensor {
public:
    WaterSensor();
    ~WaterSensor();

    WaterLevel::WaterLevel GetWaterLevel() const;
};

#endif  // SLUIS_WATERSENSOR_HPP