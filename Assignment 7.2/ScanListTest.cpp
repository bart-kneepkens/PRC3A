#include "gtest/gtest.h"
#include "ScanList.h"

class ScanListTest : public ::testing::Test{
protected:
    ScanList* scanList;
    
    ScanListTest(){
        scanList = new ScanList();
    }
    
    ~ScanListTest(){
        delete scanList;
        scanList = NULL;
    }
};

TEST_F(ScanListTest, test_add_scan_to_empty_list){
    int serial = 100;
    scanList->addScan(serial);
    
    EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial);
}
