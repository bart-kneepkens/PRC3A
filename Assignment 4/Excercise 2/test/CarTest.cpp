#include "gtest/gtest.h"
#include "Car.h"
#include <iostream>

static void CheckCarProperties(Car& car, Car& other){
    EXPECT_EQ(car.getLicencePlate(), other.getLicencePlate());
    EXPECT_EQ(car.getModel(), other.getModel());
    EXPECT_EQ(car.getNrWheels(), other.getNrWheels());
    
        // Test each wheel.
    for (int i = 0; i < car.getNrWheels(); i++) {
            // The addresses should not be equal.
        EXPECT_NE(car.getWheel(i), other.getWheel(i));
            //The diameter should be equal.
        EXPECT_EQ(car.getWheel(i)->getDiameter(), other.getWheel(i)->getDiameter());
            //The material should be equal.
        EXPECT_EQ(car.getWheel(i)->getMaterial(), other.getWheel(i)->getMaterial());
    }
}

class CarTest : public ::testing::Test {
    
protected:
    CarTest(){
        
    }
    
};


TEST_F(CarTest, test_destructor){
    EXPECT_TRUE(true);
}

TEST_F(CarTest, test_copy_constructor){
    Car car1 = Car("Cabrio", "Leather", 2, 4);
    
    Car car2 = Car(car1);
    
    CheckCarProperties(car1, car2);
}

TEST_F(CarTest, test_operator){
    Car car1 = Car("Cabrio", "Leather", 2, 4);
    
    Car car2 = car1;
    
    CheckCarProperties(car1, car2);

}