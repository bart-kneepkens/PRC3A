#include "gtest/gtest.h"
#include "Scan.h"

class ScanTest : public ::testing::Test{
protected:
    Scan* scan;
    
    ScanTest(){
        scan = new Scan(1);
    }
    
    ~ScanTest(){
        delete scan;
        scan = NULL;
    }
};

// Not going to test getters and setters.

TEST_F(ScanTest, test_recycle){
    EXPECT_EQ(scan->getTimesRecycled(), 0);
    
    for (int i = 0; i <= 9; i++) {
        scan->recycle();
    }
    
    EXPECT_EQ(scan->getTimesRecycled(), 10);
}
