#ifndef SLUIS_LOCK_HPP
#define SLUIS_LOCK_HPP

#include "SluiceSocketClient.hpp"

/** The lock on a TimedDoor. */
class Lock {
private:
    /** The side of the timed door this lock is on. */
    const DoorSide::DoorSide side;
public:
    Lock(DoorSide::DoorSide side);
    ~Lock();

    /**
     * Enable or disable this lock.
     * @param locked
     */
    void SetLocked(bool locked) const;
    /**
     * Get this lock's state.
     * @return
     */
    LockState::LockState GetLockState() const;
};

#endif  // SLUIS_LOCK_HPP