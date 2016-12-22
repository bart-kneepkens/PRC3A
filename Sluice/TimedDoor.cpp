#include "TimedDoor.hpp"

TimedDoor::TimedDoor(DoorSide::DoorSide side) :
        Door(side), lock(Lock(side)) {}

TimedDoor::~TimedDoor() {}