CFLAGS=-Wall -Werror -ggdb -O0

SCAN_SOURCES=			code/Scan.cpp \
           						code/ScanTest.cpp

SCANLIST_SOURCES=	code/Scan.cpp \
			  				code/ScanList.cpp \
							code/ScanListTest.cpp	  

TEST_LIBS=-lgtest -lgtest_main -pthread

GCC=g++

all: scanTest scanListTest

scanTest: $(SCAN_SOURCES) Makefile code/Scan.h
	@$(GCC) $(CFLAGS) $(SCAN_SOURCES) $(TEST_LIBS) -o $@

scanListTest: $(SCANLIST_SOURCES) Makefile code/ScanList.h
	@$(GCC) $(CFLAGS) $(SCANLIST_SOURCES) $(TEST_LIBS) -o $@

clean:
	@rm -rf ScanTest ScanListTest

scanTestValgrind: scanTest
	@valgrind ./scanTest

scanListTestValgrind: scanListTest
	@valgrind ./scanListTest
