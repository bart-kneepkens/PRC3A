#include "SluiceComplex.hpp"
#include "SluiceSocketClient.hpp"

int main (int argc, char* argv[]) {

    /*SetDoor(DoorSide::Left, DoorParameter::Close);
    SetValve(DoorSide::Left, 1, ValveState::Closed);
    SetTrafficLight(1, TrafficLightColor::Green, Power::Off);
    SetLockPower(DoorSide::Left, Power::Off);
    GetDoorState(DoorSide::Left);
    GetValveState(DoorSide::Left, 1);
    GetTrafficLightPower(1, TrafficLightColor::Green);
    GetSluiceWaterLevel();
    GetDoorLockState(DoorSide::Left);*/

    SluiceComplex complex = SluiceComplex();

    std::cout << complex.GetSluice(0).GetDoor(DoorSide::Left)->GetState() << std::endl;

    return 0;
}