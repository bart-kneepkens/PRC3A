#pragma once

/**
 * Merges two linked sublists back together in sorted order.
 *
 * @param a first sublist to merge
 * @param b second sublist to merge
 * @return value of the first item in the resulting sorted linked list
 */
File *sortedMerge(File *a, File *b) {
    File *result = NULL;

    // If a is null, just return b.
    if (a == NULL) {
        return (b);
    }

    // If b is null, just return a.
    if (b == NULL) {
        return (a);
    }

    // Place a and b in sorted order, then do the same for their subsequent items.
    if (a->getName() <= b->getName()) {
        result = a;
        result->setNext(sortedMerge(a->getNext(), b));
    }
    else {
        result = b;
        result->setNext(sortedMerge(a, b->getNext()));
    }
    return (result);
}

/**
 * Splits the supplied linked list into two sublists.
 *
 * @param source the linked list to split
 * @param frontRef the first half of the linked list
 * @param backRef the second half of the linked list
 */
void frontBackSplit(File *source, File **frontRef, File **backRef) {
    // If the supplied linked list is empty or contains only one element, there's nothing to split.
    if (source == NULL || source->getNext() == NULL) {
        *frontRef = source;
        *backRef = NULL;
    }
    else {
        File *slow = source;
        File *fast = source->getNext();

        // Iterate through the linked list to find the middle point.
        while (fast != NULL) {
            fast = fast->getNext();

            if (fast != NULL) {
                slow = slow->getNext();
                fast = fast->getNext();
            }
        }

        // 'slow' should now be in front of the middle point, so we use it to split the linked list.
        *frontRef = source;
        *backRef = slow->getNext();
        slow->setNext(NULL);
    }
}

/**
 * Sorts the supplied linked list of Files.
 *
 * @param headRef pointer to the first File in the linked list.
 */
void mergeSort(File **headRef) {
    File *head = *headRef;

    // If the supplied File is null or its next File is null, then the list is already sorted.
    if ((head == NULL) || (head->getNext() == NULL)) {
        return;
    }

    File *a;
    File *b;

    // Split the linked list into two sub-lists.
    frontBackSplit(head, &a, &b);

    // Sort both of the sub-lists.
    mergeSort(&a);
    mergeSort(&b);

    // Now merge the sub-lists back together, giving us the sorted linked list.
    *headRef = sortedMerge(a, b);
}