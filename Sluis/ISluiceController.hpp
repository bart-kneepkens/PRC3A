#ifndef SLUIS_ISLUICECONTROLLER_HPP
#define SLUIS_ISLUICECONTROLLER_HPP

class ISluiceController {
public:
    ISluiceController() {};
    virtual ~ISluiceController() {};

    virtual void AlarmButtonPressed() const = 0;
    virtual void ReleaseInButtonPressed() const = 0;
    virtual void ReleaseOutButtonPressed() const = 0;
    virtual void RestoreButtonPressed() const = 0;
    virtual void StartButtonPressed() const = 0;
};

#endif  // SLUIS_ISLUICECONTROLLER_HPP
