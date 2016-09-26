#include "gtest/gtest.h"
#include "Car.h"

class CarTest : public ::testing::Test {
    
protected:
    CarTest(){
        
    }
    
};


TEST_F(CarTest, test_destructor){
    EXPECT_TRUE(true);
}

TEST_F(CarTest, test_copy_constructor){
    
}

TEST_F(CarTest, test_operator){
    
}