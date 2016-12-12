#include "SluiceComplex.hpp"
#include "SluiceSocketClient.hpp"

int main (int argc, char* argv[]) {

    /*SetDoor(DoorSide::Left, DoorParameter::Close);
    SetValve(DoorSide::Left, 1, ValveState::Closed);
    SetTrafficLight(1, TrafficLightState::Green, Power::Off);
    SetLockPower(DoorSide::Left, Power::Off);
    GetDoorState(DoorSide::Left);
    GetValveState(DoorSide::Left, 1);
    GetTrafficLightPower(1, TrafficLightState::Green);
    GetWaterLevel();
    GetDoorLockState(DoorSide::Left);*/

    std::string dicks = "5";

    std::string& cocks = dicks;

    dicks = "10";

    std::cout << cocks << std::endl;

    return 0;
}