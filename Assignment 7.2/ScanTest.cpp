#include "gtest/gtest.h"
#include "Scan.h"

TEST (ScanTest, test_properties) {

	// setup
	int serialNo = 0;
	int timesRecycled = 0;
	Scan* s1 = new Scan(serialNo);		// initialize, setting serial number
	Scan* s2 = new Scan(serialNo + 1);
	s1->setNext(s2);					// set next scan

	// properties tests
	EXPECT_EQ(s1->getSerialNumber(), serialNo);			// test serial number
	EXPECT_EQ(s1->getNext(), s2);						// test next scan
	EXPECT_EQ(s1->getTimesRecycled(), timesRecycled);	// test recycle

	// extra test for times recycled
	s1->recycle();
	EXPECT_EQ(s1->getTimesRecycled(), ++timesRecycled);

	// clean-up
	delete s1;
	delete s2;
}
