#ifndef SLUIS_TIMEDDOOR_HPP
#define SLUIS_TIMEDDOOR_HPP

#include "Door.hpp"
#include "Lock.hpp"

/** A faulty door that needs to be locked quickly after closing or it gets damaged. */
class TimedDoor : public Door {
public:
    TimedDoor(DoorSide::DoorSide side);

    ~TimedDoor();

    /** This door's lock. */
    const Lock lock;

    virtual void BeforeOpenBehavior() const;    // Overrides Door::BeforeOpenBehavior()

    virtual void AfterCloseBehavior() const;    // Overrides Door::AfterCloseBehavior()
};

#endif  // SLUIS_TIMEDDOOR_HPP