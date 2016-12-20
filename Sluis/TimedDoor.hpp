#ifndef SLUIS_TIMEDDOOR_HPP
#define SLUIS_TIMEDDOOR_HPP

#include "Door.hpp"
#include "Lock.hpp"

class TimedDoor : public Door {
public:
    TimedDoor(DoorSide::DoorSide side);
    ~TimedDoor();
    const Lock lock;
};

#endif  // SLUIS_TIMEDDOOR_HPP