#ifndef SLUIS_TIMEDDOOR_HPP
#define SLUIS_TIMEDDOOR_HPP

#include "Door.hpp"
#include "Lock.hpp"

class TimedDoor : public Door {
public:
    TimedDoor();
    ~TimedDoor();
private:
    int interval;
    Lock lock;
};

#endif  // SLUIS_TIMEDDOOR_HPP