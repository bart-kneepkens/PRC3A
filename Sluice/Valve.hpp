#ifndef SLUIS_VALVE_HPP
#define SLUIS_VALVE_HPP

#include "SluiceSocketClient.hpp"

/** One of three valves in a sluice's door. */
class Valve {
private:
    /** The side this valve's door is on. Used for building its corresponding string commands. */
    const DoorSide::DoorSide side;
    /** This valve's index in the door. Used for building its corresponding string commands. */
    const unsigned int index;
    /** This valve's previous state. Used for when recovering from an emergency stop. */
    ValveState::ValveState previousState;
public:
    Valve(DoorSide::DoorSide side, unsigned int index);

    ~Valve();

    /** Starts opening this valve. */
    void Open() const;

    /** Starts closing this valve. */
    void Close() const;

    /** Emergency closes this valve. */
    void EmergencyClose();

    /** Continues this valve's behavior as it was before the emergency close. */
    void RecoverFromEmergency();

    /**
     * Gets this valve's state.
     * @return
     */
    ValveState::ValveState GetState() const;
};

#endif  // SLUIS_VALVE_HPP