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
    Valve valveLow;
    /** The middle valve in the door. */
    Valve valveMiddle;
    /** The top valve in the door. */
    Valve valveHigh;
    /** This door's previous state. Used for when recovering from an emergency stop. */
    DoorState::DoorState previousState;

    Door(DoorSide::DoorSide side);

    virtual ~Door();

    /** Starts opening this door. */
    void Open() const;

    /** Starts closing this door. */
    void Close() const;

    /** Emergency stops this door and closes its valves. */
    void EmergencyStop();

    /** Continues this door's behavior as it was before the emergency stop. */
    void RecoverFromEmergency();

    /**
     * Gets the current state of the door.
     * @return
     */
    DoorState::DoorState GetState() const;

    /**
     * Special behavior to be invoked before this door is opened. Does nothing by default.
     */
    virtual void BeforeOpenBehavior() const;

    /**
     * Special behavior to be invoked after this door is closed. Does nothing by default.
     */
    virtual void AfterCloseBehavior() const;

    /**
     * Special behavior to be invoked while this door is opening. Does nothing by default.
     */
    virtual void DuringOpeningBehavior() const;

    /**
     * Special behavior to be invoked while this door is closing. Does nothing by default.
     */
    virtual void DuringClosingBehavior() const;
};

#endif  // SLUIS_DOOR_HPP