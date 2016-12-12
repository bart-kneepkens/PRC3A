#include "TimedDoor.hpp"

TimedDoor::TimedDoor(unsigned int port, DoorSide::DoorSide side) :
        Door(port, side), interval(2000), lock(Lock(port, side)) {}

TimedDoor::~TimedDoor() {}