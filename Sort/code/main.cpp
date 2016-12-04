#include <iostream>
#include <fstream>
#include "FileStructure.h"
#include<stdio.h>
#include<stdlib.h>

void printFileNames(File *file, std::ofstream &out, std::string path = "") {
    while (file != NULL) {
        out << (path + file->getName()) << "\n";
        file = file->getNext();
    }
}

void printDirNames(Dir *dir, std::ofstream &out, std::string path = "") {
    while (dir != NULL) {
        const std::string childPath = path + dir->getName() + "/";
        out << childPath << "\n";
        printDirNames(dir->getFirstSubdir(), out, childPath);
        printFileNames(dir->getFirstFile(), out, childPath);
        dir = dir->getNext();
    }
}

void bubbleSortFiles(File **head) {

    unsigned int count = 0;
    File *start = *head;

    while (start != NULL) { //grab count
        count++;
        start = start->getNext();
    }

    for (unsigned int i = 0; i < count; ++i) { //for every element in the list

        File *curr = *head;
        File *trail = *head;

        while (curr->getNext() != NULL) { //for the rest of the elements in the list
            if (curr->getName() > curr->getNext()->getName()) { //compare curr and curr->next

                File *temp = curr->getNext(); //swap pointers for curr and curr->next
                curr->setNext(temp->getNext());
                temp->setNext(curr);

                //now we need to setup pointers for trail and possibly head
                if (curr == *head) { //this is the case of the first element swapping to preserve the head pointer
                    *head = trail = temp;
                } else { //setup trail correctly
                    trail->setNext(temp);
                }
                curr = temp; //update curr to be temp since the positions changed
            }
            //advance pointers
            trail = curr;
            curr = curr->getNext();
        }
    }
}

void bubbleSortDirs(Dir **head) {

    unsigned int count = 0;
    Dir *start = *head;

    while (start != NULL) { //grab count
        Dir *firstSubdir = start->getFirstSubdir();
        Dir **firstSubDirPtr = &firstSubdir;
        bubbleSortDirs(firstSubDirPtr);
        start->setFirstSubdir(*firstSubDirPtr);

        File *firstFile = start->getFirstFile();
        File **firstFilePtr = &firstFile;
        bubbleSortFiles(firstFilePtr);
        start->setFirstFile(*firstFilePtr);

        count++;
        start = start->getNext();
    }

    for (unsigned int i = 0; i < count; ++i) { //for every element in the list

        Dir *curr = *head;
        Dir *trail = *head;

        while (curr->getNext() != NULL) { //for the rest of the elements in the list
            if (curr->getName() > curr->getNext()->getName()) { //compare curr and curr->next

                Dir *temp = curr->getNext(); //swap pointers for curr and curr->next
                curr->setNext(temp->getNext());
                temp->setNext(curr);

                //now we need to setup pointers for trail and possibly head
                if (curr == *head) { //this is the case of the first element swapping to preserve the head pointer
                    *head = trail = temp;
                } else { //setup trail correctly
                    trail->setNext(temp);
                }
                curr = temp; //update curr to be temp since the positions changed
            }
            //advance pointers
            trail = curr;
            curr = curr->getNext();
        }
    }
}


int main() {
    FileStructure f;
    Dir headVal;

    std::cout << "Loading 'data/gibberish.bin'... " << std::flush;
    f.loadFile("data/gibberish.bin", headVal);
    std::cout << "Done!" << std::endl;

    Dir *head = &headVal;
    Dir **headPtr = &head;

    std::cout << "Saving to 'unsorted.bin'... " << std::flush;
    f.saveFile(**headPtr, "unsorted.bin");
    std::cout << "Done!" << std::endl;

    std::ofstream unsortedfile("unsorted.txt");
    printDirNames(*headPtr, unsortedfile);
    unsortedfile.close();

    std::cout << "Applying bubble sort... " << std::flush;
    bubbleSortDirs(headPtr);
    std::cout << "Done!" << std::endl;

    std::ofstream sortedfile("sorted.txt");
    printDirNames(*headPtr, sortedfile);
    sortedfile.close();

    std::cout << "Saving to 'sorted.bin'... " << std::flush;
    f.saveFile(**headPtr, "sorted.bin");
    std::cout << "Done!" << std::endl;

    return 0;
}
