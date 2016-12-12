#ifndef SLUIS_ENUMERATORS_HPP
#define SLUIS_ENUMERATORS_HPP

#include <string>

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
    std::string toString(Command command);
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
    std::string toString(DoorParameter parameter);
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
    * Tries parsing the supplied string to a DoorState. If parsing failed, returns DoorState.Locked.
    *
    * @param value
    * @return
    */
    DoorState toDoorState(std::string value);
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
    std::string toString(DoorSide parameter);
}

namespace LockState {
    enum LockState {
        Working,
        Damaged
    };

    /**
    * Tries parsing the supplied string to a LockState. If parsing failed, returns LockState.Damaged.
    *
    * @param value
    * @return
    */
    LockState toLockState(std::string value);
}

namespace Power {
    enum Power {
        On,
        Off
    };

    /**
    * Tries parsing the supplied string to a Power. If parsing failed, returns Power.Off.
    *
    * @param value
    * @return
    */
    Power toPowerState(std::string value);

    /**
    * Parses the supplied Power to a string.
    *
    * @param state
    * @return
    */
    std::string toString(Power state);
}

namespace TrafficLightState {
    enum TrafficLightState {
        Red,
        Green
    };

    /**
    * Parses the supplied TrafficLightState to a string.
    *
    * @param parameter
    * @return
    */
    std::string toString(TrafficLightState parameter);
}

namespace ValveState {
    enum ValveState {
        Open,
        Closed
    };

    /**
    * Tries parsing the supplied string to a ValveState. If parsing failed, returns ValveState.Closed.
    *
    * @param value
    * @return
    */
    ValveState toValveState(std::string value);

    /**
    * Parses the supplied ValveState to a string.
    *
    * @param state
    * @return
    */
    std::string toString(ValveState state);
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
    * Tries parsing the supplied string to a WaterLevel. If parsing failed, returns WaterLevel.High.
    *
    * @param value
    * @return
    */
    WaterLevel toWaterLevel(std::string value);
}

#endif  // SLUIS_ENUMERATORS_HPP
