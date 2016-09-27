#include "gtest/gtest.h"
#include "Truck.h"
#include <iostream>

static void CheckCarPropertiesEqual(Car& car, Car& other){
    EXPECT_NE(&car, &other);
    EXPECT_EQ(car.getLicencePlate(), other.getLicencePlate());
    EXPECT_EQ(car.getModel(), other.getModel());
    EXPECT_EQ(car.getNrWheels(), other.getNrWheels());
    
        // Test each wheel.
    for (int i = 0; i < car.getNrWheels(); i++) {
            // The addresses should not be equal.
        EXPECT_NE(car.getWheel(i), other.getWheel(i));
            //The diameter should be equal in value.
        EXPECT_EQ(car.getWheel(i)->getDiameter(), other.getWheel(i)->getDiameter());
            //The material should be equal in value.
        EXPECT_EQ(car.getWheel(i)->getMaterial(), other.getWheel(i)->getMaterial());
    }
}

static void CheckTruckPropertiesEqual(Truck& truck, Truck& other){
    EXPECT_NE(&truck, &other);
    
    CheckCarPropertiesEqual(truck, other);
    
    EXPECT_EQ(truck.getPower(), other.getPower());
}

class TruckTest : public ::testing::Test{
    
protected:
    TruckTest(){
        
    }
};

TEST_F(TruckTest, test_destructor){
    Truck* truck = new Truck("Scania", "Plastic", 20, 12, 300);
    ASSERT_TRUE(truck->getNrWheels() > 0);
    
    Wheel* wheel = truck->getWheel(0);
    ASSERT_TRUE(wheel);
    
    delete truck;
    truck = NULL;
    
    EXPECT_FALSE(truck);
    EXPECT_FALSE(wheel);
}

TEST_F(TruckTest, test_copy_constructor){
    Truck truck1 = Truck("DAF", "Leather", 20, 18, 420);
    Truck truck2 = Truck(truck1);
    
    CheckTruckPropertiesEqual(truck1, truck2);
}

TEST_F(TruckTest, test_operator){
    Truck truck1 = Truck("Cabrio", "Leather", 20, 4, 420);
    Truck truck2 = Truck("ccc", "ccc", 21, 8, 12);
    
    truck2 = truck1;
    
    CheckTruckPropertiesEqual(truck1, truck2);
}