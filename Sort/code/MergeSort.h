#pragma once

#include "Dir.h"

namespace {

/* See http://geeksforgeeks.org/?p=3622 for details of this
   function */
    Dir *sortedMergeDirs(Dir *a, Dir *b) {
        Dir *result = NULL;

        /* Base cases */
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        /* Pick either a or b, and recur */
        if (a->getName() <= b->getName()) {
            result = a;
            result->setNext(sortedMergeDirs(a->getNext(), b));
        } else {
            result = b;
            result->setNext(sortedMergeDirs(a, b->getNext()));
        }
        return (result);
    }

/* UTILITY FUNCTIONS */
/* Split the Dirs of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra Dir should go in the front list.
     Uses the fast/slow pointer strategy.  */
    void frontBackSplitDirs(Dir *source,
                            Dir **frontRef, Dir **backRef) {
        Dir *fast;
        Dir *slow;
        if (source == NULL || source->getNext() == NULL) {
            /* length < 2 cases */
            *frontRef = source;
            *backRef = NULL;
        } else {
            slow = source;
            fast = source->getNext();

            /* Advance 'fast' two Dirs, and advance 'slow' one Dir */
            while (fast != NULL) {
                fast = fast->getNext();
                if (fast != NULL) {
                    slow = slow->getNext();
                    fast = fast->getNext();
                }
            }

            /* 'slow' is before the midpoint in the list, so split it in two
              at that point. */
            *frontRef = source;
            *backRef = slow->getNext();
            slow->setNext(NULL);
        }
    }

    /* sorts the linked list by changing next pointers (not data) */
    void mergeSortDirs(Dir **headRef) {
        Dir *head = *headRef;
        Dir *a;
        Dir *b;

        /* Base case -- length 0 or 1 */
        if ((head == NULL) || (head->getNext() == NULL)) {
            return;
        }

        /* Split head into 'a' and 'b' sublists */
        frontBackSplitDirs(head, &a, &b);

        /* Recursively sort the sublists */
        mergeSortDirs(&a);
        mergeSortDirs(&b);

        /* answer = merge the two sorted lists together */
        *headRef = sortedMergeDirs(a, b);
    }

    /* See http://geeksforgeeks.org/?p=3622 for details of this
   function */
    File *sortedMergeFiles(File *a, File *b) {
        File *result = NULL;

        /* Base cases */
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        /* Pick either a or b, and recur */
        if (a->getName() <= b->getName()) {
            result = a;
            result->setNext(sortedMergeFiles(a->getNext(), b));
        } else {
            result = b;
            result->setNext(sortedMergeFiles(a, b->getNext()));
        }
        return (result);
    }

/* UTILITY FUNCTIONS */
/* Split the Dirs of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra Dir should go in the front list.
     Uses the fast/slow pointer strategy.  */
    void frontBackSplitFiles(File *source,
                            File **frontRef, File **backRef) {
        File *fast;
        File *slow;
        if (source == NULL || source->getNext() == NULL) {
            /* length < 2 cases */
            *frontRef = source;
            *backRef = NULL;
        } else {
            slow = source;
            fast = source->getNext();

            /* Advance 'fast' two Dirs, and advance 'slow' one Dir */
            while (fast != NULL) {
                fast = fast->getNext();
                if (fast != NULL) {
                    slow = slow->getNext();
                    fast = fast->getNext();
                }
            }

            /* 'slow' is before the midpoint in the list, so split it in two
              at that point. */
            *frontRef = source;
            *backRef = slow->getNext();
            slow->setNext(NULL);
        }
    }

    /* sorts the linked list by changing next pointers (not data) */
    void mergeSortFiles(File **headRef) {
        File *head = *headRef;
        File *a;
        File *b;

        /* Base case -- length 0 or 1 */
        if ((head == NULL) || (head->getNext() == NULL)) {
            return;
        }

        /* Split head into 'a' and 'b' sublists */
        frontBackSplitFiles(head, &a, &b);

        /* Recursively sort the sublists */
        mergeSortFiles(&a);
        mergeSortFiles(&b);

        /* answer = merge the two sorted lists together */
        *headRef = sortedMergeFiles(a, b);
    }
}

void mergeSortDirsAndSubDirs(Dir **headRef) {

    if (*headRef != NULL) {

//        std::cout<< "Sorting directory: " << (**headRef).getName() << std::endl;

        // Sort the current dir level.
        mergeSortDirs(headRef);

        // Iterate over all dirs on this level, sorting them.
        Dir *start = *headRef;
        while (start != NULL) {

            // Sort the subdirs, making sure to set the
            // first subdir to the possible new first one.
            Dir *firstSubdir = start->getFirstSubdir();
            Dir **firstSubDirPtr = &firstSubdir;
            mergeSortDirsAndSubDirs(firstSubDirPtr);
            start->setFirstSubdir(*firstSubDirPtr);

            // Sort the containing files, making sure to
            // set the first file to the possible new first one.
            File *firstFile = start->getFirstFile();
            File **firstFilePtr = &firstFile;
            mergeSortFiles(firstFilePtr);
            start->setFirstFile(*firstFilePtr);

            // To next dir on this level.
            start = start->getNext();
        }
    }
}