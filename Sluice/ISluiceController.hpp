#ifndef SLUIS_ISLUICECONTROLLER_HPP
#define SLUIS_ISLUICECONTROLLER_HPP

/** Interface for sluice controllers, enforcing them to implement the specified functions. */
class ISluiceController {
public:
    ISluiceController() {};
    virtual ~ISluiceController() {};

    /** Called when the alarm/emergency button has been pressed. */
    virtual void AlarmButtonPressed() = 0;
    /** Called when ships may be signalled to enter the sluice. */
    virtual void ReleaseInButtonPressed() = 0;
    /** Called when ships may be signalled to leave the sluice. */
    virtual void ReleaseOutButtonPressed() = 0;
    /** Called to recover from an emergency state. */
    virtual void RestoreButtonPressed() = 0;
    /** Called to start the main sluice process. */
    virtual void StartButtonPressed() = 0;
};

#endif  // SLUIS_ISLUICECONTROLLER_HPP
