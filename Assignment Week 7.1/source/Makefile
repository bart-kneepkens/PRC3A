CFLAGS=-Wall -Werror -ggdb -O0 -Iproduct

SCAN_SOURCES=code/Scan.cpp \
            test/ScanTest.cpp

SCANLIST_SOURCES=code/Scan.cpp \
			  code/ScanList.cpp \
			  test/ScanListTest.cpp

TEST_LIBS=-lgtest -lgtest_main -lpthread

GCC=g++

all: ScanTest ScanListTest

scanTest: $(SCAN_SOURCES) Makefile code/Scan.h
	@$(GCC) $(CFLAGS) $(SCAN_SOURCES) $(TEST_LIBS) -o $@

scanListTest: $(SCANLIST_SOURCES) Makefile code/ScanList.h
	@$(GCC) $(CFLAGS) $(SCANLIST_SOURCES) $(TEST_LIBS) -o $@

clean:
	@rm -rf ScanTest ScanListTest

scanTestValgrind: ScanTest
	@valgrind ./ScanTest

scanListTestValgrind: ScanListTest
	@valgrind ./ScanListTest
