#ifndef SLUIS_ISLUICECONTROLLER_HPP
#define SLUIS_ISLUICECONTROLLER_HPP

class ISluiceController {
public:
    ISluiceController();
    virtual ~ISluiceController();

    virtual void AlarmButtonPressed() = 0;
    virtual void ReleaseInButtonPressed() = 0;
    virtual void ReleaseOutButtonPressed() = 0;
    virtual void RestoreButtonPressed() = 0;
    virtual void StartButtonPressed() = 0;
};

#endif  // SLUIS_ISLUICECONTROLLER_HPP
