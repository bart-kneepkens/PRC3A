#ifndef PROOF_OF_CONCEPT_TEMPLATES_SORTEDLINKEDLIST_HPP
#define PROOF_OF_CONCEPT_TEMPLATES_SORTEDLINKEDLIST_HPP

#include <stdexcept>

#include "SortedLinkedListItem.hpp"

/**
 * The type of the contained values.
 */
template<class valueType>

/**
 * A sorted linked list. Note that altering the state of items added to this list removes the guarantee that this list
 * remains sorted.
 */
class SortedLinkedList {
private:
    /** The root of the linked list. */
    SortedLinkedListItem<valueType> *head;

    /** The iterator position over this linked list. */
    const SortedLinkedListItem<valueType> *iterator;
public:
    /** Constructor. */
    SortedLinkedList() {
        head = 0;
        iterator = 0;
    }

    /** Destructor. Deletes all SortedLinkedListItems, starting with root. */
    ~SortedLinkedList() {
        const SortedLinkedListItem<valueType> *current = head;
        while (current != 0) {
            const SortedLinkedListItem<valueType> *next = current->GetNext();
            delete current;
            current = next;
        }
    }

    /**
    * Adds the supplied value to this list.
    * @param value The value to add.
    */
    void Add(valueType value) {
        SortedLinkedListItem<valueType> *const item = new SortedLinkedListItem<valueType>(value);

        // If this list is empty, simply set head to the new item.
        if (head == 0) {
            head = item;
            iterator = head;
            return;
        }

        // If the new item is smaller than head, replace head with the new item and set the new item's next item to head.
        if (value < head->GetValue()) {
            item->SetNext(head);
            head = item;
            iterator = head;
            return;
        }

        SortedLinkedListItem<valueType> *current = head;
        SortedLinkedListItem<valueType> *next = head->GetNext();

        // Iterate until the next item is null, or the next item is greater than the new item.
        while (next != 0 && value > next->GetValue()) {
            current = next;
            next = next->GetNext();
        }

        // Now correctly set item and previous.
        item->SetNext(next);
        current->SetNext(item);
    }

    /**
     * Removes all occurences of the supplied value from this list.
     * @param value The value to remove from this list.
     */
    void Remove(const valueType value) {
        // If this list is empty, simply return.
        if (head == 0) {
            return;
        }

        // If head contains the value, remove and replace head until we have a head that doesn't contain the value.
        while (head->GetValue() == value) {
            SortedLinkedListItem<valueType> *newRoot = head->GetNext();
            delete head;
            head = newRoot;
            iterator = head;

            // If the list is now empty, simply return.
            if (head == 0) {
                return;
            }
        }

        SortedLinkedListItem<valueType> *previous = head;
        SortedLinkedListItem<valueType> *current = head->GetNext();

        // Iterate over the entire list, deleting all occurrences of the specified value.
        while (current != 0) {
            // If current does not contain the value, continue iterating.
            if (current->GetValue() != value) {
                previous = current;
                current = current->GetNext();
            }
                // If it does, then remove the current.
            else {
                SortedLinkedListItem<valueType> *newCurrent = current->GetNext();
                delete current;
                current = newCurrent;
                previous->SetNext(current);
            }
        }
    }

    /**
     * Instructs the list to begin iterating anew, setting the iterator pointer to the first value.
     */
    void Iterate() {
        iterator = head;
    }

    /**
     * Returns whether or not the item currently pointed to by the iterator has a value.
     * @return true if it does, false otherwise.
     */
    bool HasNext() const {
        return iterator != 0;
    }

    /**
     * Returns the value of the item currently pointed to by the iterator, and moves the iterator to the next item.
     * @return the value of the item currently pointed to by the iterator.
     * @throws std::out_of_range if there is no next item.
     */
    valueType Next() {
        if (iterator == 0) {
            throw std::out_of_range("SortedLinkedList.Next(...): There is no next item!");
        }
        valueType value = iterator->GetValue();
        iterator = iterator->GetNext();
        return value;
    }

    /**
     * Gets the value at the specified index.
     * @param index The index of the value to get.
     * @return The value at the specified index.
     * @throws std::out_of_range if the index is out of range.
     */
    valueType At(unsigned const int index) const {
        // If head is null, throw an exception.
        if (head == 0) {
            throw std::out_of_range("SortedLinkedList.AtIndex(...): Index is out of range!");
        }

        const SortedLinkedListItem<valueType> *current = head;
        unsigned int i = 0;

        // Iterate until the index has been reached.
        while (i < index) {
            current = current->GetNext();
            i++;

            // If the index wasn't reached before the end of the list, throw an exception.
            if (current == 0) {
                throw std::out_of_range("SortedLinkedList.AtIndex(...): Index is out of range!");
            }
        }
        return current->GetValue();
    }

    /**
     * Removes the value at the specified index. If the index is out of bounds, then the list remains unchanged.
     * @param index The index of the value to remove.
     */
    void RemoveAt(unsigned const int index) {
        // If this list is empty, simply return.
        if (head == 0) {
            return;
        }

        // If the specified index is 0, remove and replace head.
        if (index == 0) {
            SortedLinkedListItem<valueType> *newRoot = head->GetNext();
            delete head;
            head = newRoot;
            iterator = head;
            return;
        }

        SortedLinkedListItem<valueType> *previous = head;
        SortedLinkedListItem<valueType> *current = head->GetNext();
        unsigned int i = 1;

        // Iterate until the index has been reached.
        while (current != 0) {
            // If we've reached the index, remove the item and return.
            if (i == index) {
                SortedLinkedListItem<valueType> *next = current->GetNext();
                delete current;
                previous->SetNext(next);
                return;
            }
            // Else, continue iterating.
            previous = current;
            current = current->GetNext();
            i++;
        }
    }

    /**
     * Returns whether or not this list is empty.
     * @return true if this list is empty, otherwise false.
     */
    bool IsEmpty() const {
        return head == 0;
    }

    /**
     * Returns the number of values in this list.
     * @return The number of values in this list.
     */
    unsigned int Count() const {
        const SortedLinkedListItem<valueType> *current = head;
        unsigned int i = 0;

        // Iterate until the next item is null, counting all the way.
        while (current != 0) {
            current = current->GetNext();
            i++;
        }
        return i;
    }
};

#endif //PROOF_OF_CONCEPT_TEMPLATES_SORTEDLINKEDLIST_HPP
