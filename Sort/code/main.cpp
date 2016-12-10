#include <iostream>
#include "FileStructure.h"
#include "MergeSortFiles.h"
#include "MergeSortDirs.h"

/**
 * Sorts the supplied linked directory list and all of its containing linked directory lists
 * and linked file lists.
 *
 * @param headRef pointer to the linked directory list to sort
 */
void mergeSortRecursive(Dir **headRef) {
    if (*headRef != NULL) {

        // Sort the supplied linked directory list.
        mergeSort(headRef);
        Dir *start = *headRef;

        // Sort the sub-dirs and files contained in each dir of the linked list.
        while (start != NULL) {

            // Sort the sub-dirs, making sure to set the first subdir to the new first one.
            Dir *firstSubdir = start->getFirstSubdir();
            Dir **firstSubDirPtr = &firstSubdir;
            mergeSortRecursive(firstSubDirPtr);
            start->setFirstSubdir(*firstSubDirPtr);

            // Sort the containing files, making sure to set the first file to the new first one.
            File *firstFile = start->getFirstFile();
            File **firstFilePtr = &firstFile;
            mergeSort(firstFilePtr);
            start->setFirstFile(*firstFilePtr);

            // Go to the next dir.
            start = start->getNext();
        }
    }
}

int main() {
    FileStructure f;
    Dir headVal;

    // Load the unsorted data from disk.
    std::cout << "Loading 'data/gibberish.bin'... " << std::flush;
    f.loadFile("data/gibberish.bin", headVal);
    std::cout << "Done!" << std::endl;

    Dir *head = &headVal;
    Dir **headPtr = &head;

    // Sort the unsorted data.
    std::cout << "Applying sort... " << std::flush;
    mergeSortRecursive(headPtr);
    std::cout << "Done!" << std::endl;

    // Save the sorted data on disk.
    std::cout << "Saving to 'sorted.bin'... " << std::flush;
    f.saveFile(**headPtr, "sorted.bin");
    std::cout << "Done!" << std::endl;

    // Optional: print the resulting sorted linked list.
    //std::cout << (**headPtr).toString(false) << std::endl;

    return 0;
}
