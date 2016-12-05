#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FileStructure.h"
//#include "BubbleSort.h"
#include "MergeSort.h"

int main() {
    FileStructure f;
    Dir headVal;

    std::cout << "Loading 'data/gibberish.bin'... " << std::flush;
    f.loadFile("data/gibberish.bin", headVal);
    std::cout << "Done!" << std::endl;

    Dir *head = &headVal;
    Dir **headPtr = &head;

//    std::cout << "Saving to 'unsorted.bin'... " << std::flush;
//    f.saveFile(**headPtr, "unsorted.bin");
//    std::cout << "Done!" << std::endl;

    //std::ofstream unsortedfile("unsorted.txt");
    //unsortedfile << (**headPtr).toString(false);
    //unsortedfile.close();

    std::cout << "Applying sort... " << std::flush;
    timespec ts_beg, ts_end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_beg);;

    bubbleSortDirs(headPtr);
    //mergeSortDirsAndSubDirs(headPtr);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_end);
    std::cout << "Done!" << std::endl;
    std::cout << (ts_end.tv_sec - ts_beg.tv_sec) + (ts_end.tv_nsec - ts_beg.tv_nsec) / 1e9 << " sec" << std::endl;

    std::ofstream sortedfile("sorted.txt");
    sortedfile << (**headPtr).toString(false);
    sortedfile.close();

    std::cout << "Saving to 'sorted.bin'... " << std::flush;
    f.saveFile(**headPtr, "sorted.bin");
    std::cout << "Done!" << std::endl;

    return 0;
}
