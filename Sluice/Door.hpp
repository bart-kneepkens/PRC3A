#ifndef SLUIS_DOOR_HPP
#define SLUIS_DOOR_HPP

#include "SluiceSocketClient.hpp"
#include "Valve.hpp"

/** A sluice door, of which there are two in each sluice (a left one and a right one). */
class Door {
protected:
    /** The side this door is on. */
    const DoorSide::DoorSide side;
public:
    /** The lowest valve in the door. */
    const Valve valveLow;
    /** The middle valve in the door. */
    const Valve valveMiddle;
    /** The top valve in the door. */
    const Valve valveHigh;

    Door(DoorSide::DoorSide side);

    virtual ~Door();

    /** Starts opening this door. */
    void Open() const;

    /** Starts closing this door. */
    void Close() const;

    /** Stops the door from moving, whatever it is currently doing. */
    void Stop() const;

    /**
     * Gets the current state of the door.
     * @return
     */
    DoorState::DoorState GetState() const;
};

#endif  // SLUIS_DOOR_HPP