#include "gtest/gtest.h"
#include "Scan.h"

class ScanTest : public ::testing::Test {

protected:
	Scan * scan;

	ScanTest() {
		scan = new Scan(0);
	}

	~ScanTest() {
		delete scan;
	}
};
