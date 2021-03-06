    //============================================================================
    // Name        : menu.cpp
    // Author      : Freddy Hurkmans
    // Version     :
    // Copyright   : copyright Freddy Hurkmans
    // Description : Assignment 1 example
    //============================================================================

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "RentalAdministration.h"
#include "cars/Limousine.h"
#include "cars/Sedan.h"

static void addTestDataToAdministration(RentalAdministration* administration)
{
    string licencePlates[] = {"SD-001", "SD-002", "SD-003", "SD-004", "LM-001", "LM-002"};
    
    for (int i = 0; i < 4; i++)
    {
        Car* sedan = new Sedan("BMW", "535d", 2012 + i, licencePlates[i], false);
        administration->Add(sedan);
    }
    for (int i = 4; i < 6; i++)
    {
        Car* limousine = new Limousine("Rolls Roys", "Phantom Extended Wheelbase", 2015, licencePlates[i], true);
        administration->Add(limousine);
    }
}

static void printCars(const RentalAdministration* administration)
{
    cout << ("Printing Cars...\n");
    cout << ("===============\n");
    
    for (unsigned int i = 0; i < administration->GetCars().size(); i++) {
        cout << administration->GetCars().at(i)->ToString();
        cout << "\n";
    }
}

static size_t selectCar(const RentalAdministration* administration)
{
    cout << ("Please enter the number of the car you'd like to select.\n");
    cout << ("===============\n");
    
    for (unsigned int i = 0; i < administration->GetCars().size(); i++) {
        stringstream sstm;
        
        sstm << i << ". " << administration->GetCars().at(i)->ToString();
        cout << sstm.str();
        cout << "\n";
    }
    
    int choice = 0;
    
    cin >> choice;
    cin.ignore();
    
    return choice;
}

static void rentCar(RentalAdministration* administration, size_t carNumber)
{
    Car* selected = administration->GetCars().at(carNumber);
    administration->RentCar(selected->GetLicencePlate());
    
    cout << ("===============\n");
    cout << ("Rented car with licence plate : " + selected->GetLicencePlate() + "\n");
    cout << ("===============\n");
}

static void returnCar(RentalAdministration* administration, size_t carNumber)
{
    Car* selected = administration->GetCars().at(carNumber);
    
    cout << ("How many kilometers did you drive?\n");
    
    int kilometers;
    
    cin >> kilometers;
    cin.ignore();
    
    administration->ReturnCar(selected->GetLicencePlate(), kilometers);
    
    stringstream sstm;
    sstm << kilometers;
    
    cout << ("===============\n");
    cout << ("Return car with licence plate : " + selected->GetLicencePlate() + " after " + sstm.str() +  " KM.\n");
    cout << ("===============\n");
}

static void printIfCarNeedsCleaning(const RentalAdministration* administration, size_t carNumber)
{
    Car* selected = administration->GetCars().at(carNumber);
    
    if(selected->NeedsCleaning()){
        cout << ("This car does need cleaning.\n");
    }
    else{
        cout << ("This car is brandschoon.");
    }
}

static void cleanCar(RentalAdministration* administration, size_t carNumber)
{
    Car* selected = administration->GetCars().at(carNumber);
    administration->CleanCar(selected->GetLicencePlate());
}


static void showMenu( void )
{
    cout << ("\n\nCar Rental menu\n");
    cout << ("===============\n");
    cout << ("(1) Show all cars\n");
    cout << ("(2) Select car\n");
    cout << ("(3) Rent selected car\n");
    cout << ("(4) Return selected car\n");
    cout << ("(5) Check if car needs cleaning\n");
    cout << ("(6) Clean car\n");
    cout << ("-----------------------\n");
    cout << ("(9) QUIT\n\n");
    cout << ("Choice : ");
}

int main( void )
{
    bool quit = false;
    size_t carNumber = 0;
    
    RentalAdministration administration;
    
    addTestDataToAdministration(&administration);
    
    while (!quit)
    {
        char choice = '\0';
        showMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice)
        {
            case '1' :
                printCars(&administration);
                break;
            case '2' :
                carNumber = selectCar(&administration);
                break;
            case '3' :
                rentCar(&administration, carNumber);
                break;
            case '4' :
                returnCar(&administration, carNumber);
                break;
            case '5' :
                printIfCarNeedsCleaning(&administration, carNumber);
                break;
            case '6' :
                cleanCar(&administration, carNumber);
                break;
            case '9' :
                quit = true;
                break;
            default:
                cout << "\n\nI did not understand your choice (" << choice << ")" << endl;
                break;
        }
    }
    
    return 0;
}
