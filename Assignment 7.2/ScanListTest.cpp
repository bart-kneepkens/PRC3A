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

// Add scan tests

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
    
    EXPECT_EQ(scanList->getScanByNr(0)->getNext(), scanList->getScanByNr(1));
}

TEST_F(ScanListTest, test_add_scan_to_single_item_list_after){
    int serial1 = 100;
    scanList->addScan(serial1);
    
    int serial2 = 101;
    scanList->addScan(serial2);
    
    EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial2);
    
    EXPECT_EQ(scanList->getScanByNr(0)->getNext(), scanList->getScanByNr(1));
}

TEST_F(ScanListTest, test_add_existing_scan_single_item_list){
    int serial = 100;
    scanList->addScan(serial);
    
    Scan* scan = scanList->getScanByNr(0);
    
    EXPECT_EQ(scan->getTimesRecycled(), 0);
    
    scanList->addScan(serial);
    
    EXPECT_EQ(scan->getTimesRecycled(), 1);
}

TEST_F(ScanListTest, test_add_existing_scan_multiple_item_list){
    int serials [4] = {100, 101, 102, 104};
    
    for (int i = 0; i < 4; i++) {
        scanList->addScan(serials[i]);
    }
    
    EXPECT_EQ(scanList->getScanByNr(3)->getSerialNumber(), serials[3]);
    EXPECT_EQ(scanList->getScanByNr(3)->getTimesRecycled(), 0);
    
    scanList->addScan(serials[3]);
    
    EXPECT_EQ(scanList->getScanByNr(3)->getTimesRecycled(), 1);
    
    for (int i = 0; i <= 8; i++) {
        scanList->addScan(serials[3]);
    }
    
    EXPECT_EQ(scanList->getScanByNr(3)->getTimesRecycled(), 10);
}

TEST_F(ScanListTest, test_add_scan_to_multiple_item_list){
    int serials [4] = {100, 101, 102, 104};
    
    for (int i = 0; i < 4; i++) {
        scanList->addScan(serials[i]);
    }
    
    EXPECT_EQ(scanList->getScanByNr(3)->getSerialNumber(), serials[3]);
    
    int serialToBeAdded = 103;
    
    scanList->addScan(serialToBeAdded);
    
    EXPECT_EQ(scanList->getScanByNr(3)->getSerialNumber(), serialToBeAdded);
    EXPECT_EQ(scanList->getScanByNr(4)->getSerialNumber(), serials[3]);
    
    // Make sure the linking is OK.
    EXPECT_EQ(scanList->getScanByNr(2)->getNext(), scanList->getScanByNr(3));
    EXPECT_EQ(scanList->getScanByNr(3)->getNext(), scanList->getScanByNr(4));
}

// Remove scan tests

TEST_F(ScanListTest, test_remove_non_existing_scan){
    EXPECT_FALSE(scanList->removeScan(1));
}

TEST_F(ScanListTest, test_remove_only_scan){
    int serial = 100;
    scanList->addScan(serial);
    EXPECT_TRUE(scanList->removeScan(serial));
}

TEST_F(ScanListTest, test_remove_scan_check_order){
    int serials [4] = {100, 101, 102, 103};
    
    for (int i = 0; i < 4; i++) {
        scanList->addScan(serials[i]);
    }
    
    EXPECT_TRUE(scanList->removeScan(serials[2]));
    
    EXPECT_EQ(scanList->getScanByNr(2)->getSerialNumber(), serials[3]);
    
    // Make sure the link is OK.
    EXPECT_EQ(scanList->getScanByNr(1)->getNext()->getSerialNumber(), serials[3]);
}
