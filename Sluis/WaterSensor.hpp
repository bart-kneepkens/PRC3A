#ifndef SLUIS_WATERSENSOR_HPP
#define SLUIS_WATERSENSOR_HPP

#include "SluiceSocketClient.hpp"

class WaterSensor {
private:
    const unsigned int port;
public:
    WaterSensor(unsigned int port);
    ~WaterSensor();

    WaterLevel::WaterLevel GetWaterLevel() const;
};

#endif  // SLUIS_WATERSENSOR_HPP