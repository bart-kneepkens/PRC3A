#pragma once

#include "Dir.h"

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