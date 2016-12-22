/**
 * Exposes several enumerators and convenience methods for parsing them to and from strings.
 */

#ifndef SLUIS_ENUMERATORS_HPP
#define SLUIS_ENUMERATORS_HPP

#include <string>
#include <stdexcept>

namespace SluiceState {
    enum SluiceState {
        Idle,
        Started,
        Emergency
    };
}

namespace Command {
    enum Command {
        GetDoor,
        GetDoorLock,
        GetTrafficLight,
        GetWaterLevel,
        SetDoor,
        SetDoorLock,
        SetTrafficLight
    };

    /**
    * Parses the supplied Command to a string.
    *
    * @param command
    * @return
    */
    std::string ToString(Command command);
}

namespace DoorParameter {
    enum DoorParameter {
        Open,
        Close,
        Stop
    };

    /**
    * Parses the supplied DoorParameter to a string.
    *
    * @param parameter
    * @return
    */
    std::string ToString(DoorParameter parameter);
}

namespace DoorState {
    enum DoorState {
        Locked,
        Closed,
        Open,
        Closing,
        Opening,
        Stopped,
        MotorDamage
    };

    /**
    * Tries parsing the supplied string to a DoorState.
    *
    * @throws invalid_argument if the string could not be parsed.
    * @param value
    * @return
    */
    DoorState ToDoorState(std::string value);
}

namespace DoorSide {
    enum DoorSide {
        Left,
        Right
    };

    /**
    * Parses the supplied DoorSide to a string.
    *
    * @param parameter
    * @return
    */
    std::string ToString(DoorSide parameter);
}

namespace LockState {
    enum LockState {
        Working,
        Damaged
    };

    /**
    * Tries parsing the supplied string to a LockState.
    *
    * @throws invalid_argument if the string could not be parsed.
    * @param value
    * @return
    */
    LockState ToLockState(std::string value);
}

namespace Power {
    enum Power {
        On,
        Off
    };

    /**
    * Tries parsing the supplied string to a Power.
    *
    * @throws invalid_argument if the string could not be parsed.
    * @param value
    * @return
    */
    Power ToPowerState(std::string value);

    /**
    * Parses the supplied Power to a string.
    *
    * @param state
    * @return
    */
    std::string ToString(Power state);
}

namespace DoorType {
    enum DoorType {
        Normal,
        NeedsNewMotors,
        Timed
    };

    /**
    * Tries parsing the supplied string to a DoorType.
    *
    * @throws invalid_argument if the string could not be parsed.
    * @param value
    * @return
    */
    DoorType toDoorType(std::string value);
}

namespace TrafficLightColor {
    enum TrafficLightColor {
        Red,
        Green
    };

    /**
    * Parses the supplied TrafficLightColor to a string.
    *
    * @param parameter
    * @return
    */
    std::string ToString(TrafficLightColor parameter);
}

namespace ValveState {
    enum ValveState {
        Open,
        Closed
    };

    /**
    * Tries parsing the supplied string to a ValveState.
    *
    * @throws invalid_argument if the string could not be parsed.
    * @param value
    * @return
    */
    ValveState ToValveState(std::string value);

    /**
    * Parses the supplied ValveState to a string.
    *
    * @param state
    * @return
    */
    std::string ToString(ValveState state);
}

namespace WaterLevel {
    enum WaterLevel {
        Low,
        BelowValve2,
        AboveValve2,
        AboveValve3,
        High
    };

    /**
    * Tries parsing the supplied string to a WaterLevel.
    *
    * @throws invalid_argument if the string could not be parsed.
    * @param value
    * @return
    */
    WaterLevel ToWaterLevel(std::string value);
}

#endif  // SLUIS_ENUMERATORS_HPP
