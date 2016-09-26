#include "gtest/gtest.h"
#include "Car.h"
#include <iostream>

static void CheckCarProperties(Car& car, Car& other){
    EXPECT_EQ(car.getLicencePlate(), other.getLicencePlate());
    EXPECT_EQ(car.getModel(), other.getModel());
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
    Car carPtr1 = Car("Cabrio", "Leather", 2, 4);
    
    Car carPtr2 = Car(carPtr1);
    
    CheckCarProperties(carPtr1, carPtr2);
}

TEST_F(CarTest, test_operator){
        //EXPECT_TRUE(false);
    
        //const Car carPtr1 = Car("Cabrio", "Leather", 2, 4);
        //Car carPtr2 = carPtr1;
    
        //*carPtr2 = *carPtr1;
    
        //CheckCarProperties(carPtr1, carPtr2);
}