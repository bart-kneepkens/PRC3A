CFLAGS=-Wall -Werror -ggdb -O0

SCAN_SOURCES=			Scan.cpp \
           						ScanTest.cpp 

SCANLIST_SOURCES=	Scan.cpp \
			  				ScanList.cpp \
							ScanListTest.cpp	  

TEST_LIBS=-lgtest -lgtest_main -pthread

GCC=g++

all: scanTest scanListTest

scanTest: $(SCAN_SOURCES) Makefile Scan.h
	@$(GCC) $(CFLAGS) $(SCAN_SOURCES) $(TEST_LIBS) -o $@

scanListTest: $(SCANLIST_SOURCES) Makefile ScanList.h
	@$(GCC) $(CFLAGS) $(SCANLIST_SOURCES) $(TEST_LIBS) -o $@

clean:
	@rm -rf ScanTest ScanListTest

scanTestValgrind: scanTest
	@valgrind ./scanTest

scanListTestValgrind: scanListTest
	@valgrind ./scanListTest

