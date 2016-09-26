#include "gtest/gtest.h"
#include "Truck.h"

class TruckTest : public ::testing::Test{
    
protected:
    TruckTest(){
        
    }
};

TEST_F(TruckTest, test_construction_values_copied_correctly)
{
    EXPECT_TRUE(true);
}