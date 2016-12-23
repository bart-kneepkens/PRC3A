#ifndef SLUIS_TRAFFICLIGHT_HPP
#define SLUIS_TRAFFICLIGHT_HPP

#include "SluiceSocketClient.hpp"

/** One of four of a sluice's traffic lights. */
class TrafficLight {
private:
    /** This traffic light's index. Used for building its corresponding string commands. */
    const unsigned int index;

    /**
     * Gets the power state of the specified color of this traffic light.
     * @param color
     * @return
     */
    Power::Power GetPower(TrafficLightColor::TrafficLightColor color) const;
    /**
     * Sets the power state of the specified color of this traffic light.
     * @param color
     * @param power
     */
    void SetPower(TrafficLightColor::TrafficLightColor color, Power::Power power) const;
public:
    TrafficLight(unsigned int index);
    ~TrafficLight();

    /**
     * Toggles this traffic light's colors, swapping from green on & red off to green off & red on, and vice versa.
     */
    void ToggleLights() const;
    /**
     * Turns off this traffic light's green color and turns on its red color.
     */
    void SwitchToRedLights() const;
};

#endif  // SLUIS_TRAFFICLIGHT_HPP