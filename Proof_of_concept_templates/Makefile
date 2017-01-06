CFLAGS=-Wall -Werror -ggdb -O0

ITEM_SOURCES=SortedLinkedListItem.hpp

TEST_LIBS=-lgtest -lgtest_main -pthread

GCC=g++

all: item

item: $(ITEM_SOURCES) Makefile
	@$(GCC) $(CFLAGS) $(ITEM_SOURCES) -o $@

clean:
	@rm -rf item

