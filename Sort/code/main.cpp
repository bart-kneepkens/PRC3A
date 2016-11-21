#include <iostream>

#include "FileStructure.h"

int main()
{
    FileStructure f;
    Dir head;
    
    f.loadFile("data/gibberish.bin", head);

    // next line is only to show what kind of data we're working with
    // remove this line to increase performance!
    std::cout << head.toString(false);
    
    // sort all data
    // todo: your code here!
    

    // save sorted data into a new file called sorted.bin
    f.saveFile(head, "sorted.bin");

    return 0;
}
