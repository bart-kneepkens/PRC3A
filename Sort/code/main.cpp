#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FileStructure.h"
//#include "BubbleSort.h"
//#include "MergeSort.h"
#include "MSMultiThreaded.h"

int main() {
    FileStructure f;
    Dir headVal;

    /*Dir headVal = Dir("dicks");
    Dir* next1 = new Dir("cocks");
    Dir* next2 = new Dir("balls");
    headVal.setNext(next1);
    next1->setNext(next2);
    File* f1 = new File("dicks.txt");
    File* f2 = new File("cocks.jpg");
    next2->setFirstFile(f1);
    f1->setNext(f2);*/

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

    //bubbleSortDirs(headPtr);
    mergeSortDirsAndSubDirs(headPtr);

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
