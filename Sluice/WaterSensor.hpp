#ifndef SLUIS_WATERSENSOR_HPP
#define SLUIS_WATERSENSOR_HPP

#include "SluiceSocketClient.hpp"

/** A sluice's water sensor, keeping track of the water level within the sluice. */
class WaterSensor {
public:
    WaterSensor();
    ~WaterSensor();

    /**
     * Gets the current water level within the sluice.
     * @return
     */
    WaterLevel::WaterLevel GetWaterLevel() const;
};

#endif  // SLUIS_WATERSENSOR_HPP