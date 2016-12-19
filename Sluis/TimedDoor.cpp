#include "TimedDoor.hpp"

TimedDoor::TimedDoor(DoorSide::DoorSide side) :
        Door(side), interval(2000), lock(Lock(side)) {}

TimedDoor::~TimedDoor() {}