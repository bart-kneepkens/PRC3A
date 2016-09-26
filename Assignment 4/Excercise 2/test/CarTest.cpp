#include "gtest/gtest.h"
#include "Car.h"

class CarTest : public ::testing::Test {
    
protected:
    CarTest(){
        
    }
    
};


TEST_F(CarTest, test_anything)
{
    EXPECT_TRUE(true);
}