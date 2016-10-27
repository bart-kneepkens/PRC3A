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

TEST_F(ScanListTest, test_add_scan_to_single_item_list_before){
    int serial1 = 100;
    scanList->addScan(serial1);
    
    int serial2 = 99;
    scanList->addScan(serial2);
    
    EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial1);
    EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial2);
}

TEST_F(ScanListTest, test_add_scan_to_single_item_list_after){
    int serial1 = 100;
    scanList->addScan(serial1);
    
    int serial2 = 101;
    scanList->addScan(serial2);
    
    EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial2);
}
