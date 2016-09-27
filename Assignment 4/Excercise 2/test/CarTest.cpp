#include "gtest/gtest.h"
#include "Car.h"
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

class CarTest : public ::testing::Test {
    
protected:
    CarTest(){
        
    }
};


TEST_F(CarTest, test_destructor){
    Car* car = new Car("Cabrio", "Plastic", 2, 4);
    ASSERT_TRUE(car->getNrWheels() > 0);
    
    Wheel* wheel = car->getWheel(0);
    ASSERT_TRUE(wheel);
    
    delete car;
        //car = NULL;
    
    EXPECT_FALSE(car);
    
        //This doesn't work.
        //Wheel stays alive.
        //Would only work with shared pointers.
    EXPECT_FALSE(wheel);
}

TEST_F(CarTest, test_copy_constructor){
    Car car1 = Car("Cabrio", "Leather", 2, 4);
    
    Car car2 = Car(car1);
    
    CheckCarPropertiesEqual(car1, car2);
}

TEST_F(CarTest, test_operator){
    Car car1 = Car("Cabrio", "Leather", 2, 4);
    
    Car car2 = Car("", "", 3, 5);
    
    car2 = car1;
    
    CheckCarPropertiesEqual(car1, car2);

}