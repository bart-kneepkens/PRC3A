#include "gtest/gtest.h"
#include "Wheel.h"

static void CheckWheelPropertiesEqual(Wheel& wheel, Wheel& other){
    EXPECT_NE(&wheel, &other);
    EXPECT_EQ(wheel.getMaterial(), other.getMaterial());
    EXPECT_EQ(wheel.getDiameter(), other.getDiameter());
}

class WheelTest : public ::testing::Test{
    
protected:
    Wheel* wheel;
    
    WheelTest(){
        wheel = new Wheel(8,"Chrome");
    }
    
    ~WheelTest(){
        delete wheel;
        wheel = NULL;
    }
    
};

TEST_F(WheelTest, test_default_copy_constructor){
    Wheel wheel1 = Wheel(18, "Silver");
    
    // For the implicit copy constructor to be called, wheel2 needs to be initialised first.
    Wheel wheel2 = Wheel(1, "cccccc");
    
    wheel2 = Wheel(wheel1);
    
    CheckWheelPropertiesEqual(wheel1, wheel2);
}

TEST_F(WheelTest, test_default_assignment_operator){
    Wheel wheel1 = Wheel(18, "Silver");
    
    Wheel wheel2 = Wheel(1, "ccccc");
    
    wheel2 = wheel1;
    
    CheckWheelPropertiesEqual(wheel1, wheel2);
}