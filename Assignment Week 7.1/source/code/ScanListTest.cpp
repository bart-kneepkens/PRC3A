#include "gtest/gtest.h"
#include "ScanList.h"

class ScanListTest : public ::testing::Test {

protected:
	ScanList * scanList;

	ScanListTest() {
		scanList = new ScanList();
	}

	~ScanListTest() {
		delete scanList;
	}
};