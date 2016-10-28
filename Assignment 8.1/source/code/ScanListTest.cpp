#include "gtest/gtest.h"
#include "ScanList.h"

TEST (ScanListTest, addScan_to_empty) {
	ScanList* scanList = new ScanList();	
	int serial = 100;
	
	scanList->addScan(serial);

	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial);
	
	delete scanList;
}

TEST (ScanListTest, addScan_to_start) {
	ScanList* scanList = new ScanList();
	int serial1 = 100;
	int serial2 = 101;
	int serial3 = 102;
	
	scanList->addScan(serial2);
	scanList->addScan(serial3);
	scanList->addScan(serial1);
	
	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial1);
	EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial2);
	EXPECT_EQ(scanList->getScanByNr(2)->getSerialNumber(), serial3);
	
	delete scanList;
}

TEST (ScanListTest, addScan_to_middle) {
	ScanList* scanList = new ScanList();
	int serial1 = 100;
	int serial2 = 101;
	int serial3 = 102;
	
	scanList->addScan(serial1);
	scanList->addScan(serial3);
	scanList->addScan(serial2);
	
	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial1);
	EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial2);
	EXPECT_EQ(scanList->getScanByNr(2)->getSerialNumber(), serial3);
	
	delete scanList;
}

TEST (ScanListTest, addScan_to_end) {
	ScanList* scanList = new ScanList();
	int serial1 = 100;
	int serial2 = 101;
	int serial3 = 102;
	
	scanList->addScan(serial1);
	scanList->addScan(serial2);
	scanList->addScan(serial3);
	
	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial1);
	EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial2);
	EXPECT_EQ(scanList->getScanByNr(2)->getSerialNumber(), serial3);	
	
	delete scanList;
}

TEST (ScanListTest, removeScan_from_empty) {
	ScanList* scanList = new ScanList();
	int serial = 100;
	
	EXPECT_FALSE(scanList->removeScan(serial));	
	
	delete scanList;
}

TEST (ScanListTest, removeScan_non_existant) {
	ScanList* scanList = new ScanList();
	int serial1 = 100;
	int serial2 = 101;
	int serial3 = 102;
	int serial4 = 103;
	
	scanList->addScan(serial1);
	scanList->addScan(serial2);
	scanList->addScan(serial3);
	
	EXPECT_FALSE(scanList->removeScan(serial4));
	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial1);
	EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial2);
	EXPECT_EQ(scanList->getScanByNr(2)->getSerialNumber(), serial3);	
	
	delete scanList;
}

TEST (ScanListTest, removeScan_from_start) {
	ScanList* scanList = new ScanList();
	int serial1 = 100;
	int serial2 = 101;
	int serial3 = 102;
	
	scanList->addScan(serial1);
	scanList->addScan(serial2);
	scanList->addScan(serial3);
	
	EXPECT_TRUE(scanList->removeScan(serial1));
	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial2);
	EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial3);
	EXPECT_TRUE(scanList->getScanByNr(2) == 0);
	
	delete scanList;
}

TEST (ScanListTest, removeScan_from_middle) {
	ScanList* scanList = new ScanList();
	int serial1 = 100;
	int serial2 = 101;
	int serial3 = 102;
	
	scanList->addScan(serial1);
	scanList->addScan(serial2);
	scanList->addScan(serial3);
	
	EXPECT_TRUE(scanList->removeScan(serial2));
	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial1);
	EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial3);	
	EXPECT_TRUE(scanList->getScanByNr(2) == 0);
	
	delete scanList;
}

TEST (ScanListTest, removeScan_from_end) {
	ScanList* scanList = new ScanList();
	int serial1 = 100;
	int serial2 = 101;
	int serial3 = 102;
	
	scanList->addScan(serial1);
	scanList->addScan(serial2);
	scanList->addScan(serial3);
	
	EXPECT_TRUE(scanList->removeScan(serial3));
	EXPECT_EQ(scanList->getScanByNr(0)->getSerialNumber(), serial1);
	EXPECT_EQ(scanList->getScanByNr(1)->getSerialNumber(), serial2);	
	EXPECT_TRUE(scanList->getScanByNr(2) == 0);
	
	delete scanList;
}

TEST (ScanListTest, getTimesRecycled) {
	ScanList* scanList = new ScanList();
	int serial = 100;
	int expectedRecyled = 0;
	
	scanList->addScan(serial);
	EXPECT_EQ(scanList->getTimesRecycled(serial), expectedRecyled);
	scanList->addScan(serial);
	EXPECT_EQ(scanList->getTimesRecycled(serial), ++expectedRecyled);
	
	delete scanList;
}
