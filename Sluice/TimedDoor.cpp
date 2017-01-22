#include "TimedDoor.hpp"

TimedDoor::TimedDoor(DoorSide::DoorSide side) :
        Door(side), lock(Lock(side)) {}

TimedDoor::~TimedDoor() {}

void TimedDoor::BeforeOpenBehavior() const {
    lock.SetLocked(false);
}

void TimedDoor::AfterCloseBehavior() const {
    lock.SetLocked(true);
}
