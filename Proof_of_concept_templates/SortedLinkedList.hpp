#ifndef PROOF_OF_CONCEPT_TEMPLATES_SORTEDLINKEDLIST_HPP
#define PROOF_OF_CONCEPT_TEMPLATES_SORTEDLINKEDLIST_HPP

#include "SortedLinkedListItem.hpp"

/**
 * The type of the contained values.
 */
template<class valueType>

/**
 * A sorted linked list. Note that changing the listed values may result in the list becoming unsorted.
 */
class SortedLinkedList {
private:
    /** The root of the linked list. */
    SortedLinkedListItem<valueType> *root;
public:\
    /** Constructor. */
    SortedLinkedList() {}

    /** Destructor. */
    ~SortedLinkedList() {}

    /**
     * Gets the root item of this list.
     * @return The root item of this list, or 0 if it has none.
     */
    SortedLinkedListItem<valueType> *GetRoot() const {
        return this->root;
    }

    /**
     * Sets the root item of this list.
     * @param root The new root item.
     */
    //void SetRoot(SortedLinkedListItem<valueType> *root) {
    //    this->root = root;
    //}

    /**
     * Gets the item at the specified index.
     * @param index The index of the item to get.
     * @return The item at the specified index, or 0 if no item is at the index.
     */
    SortedLinkedListItem<valueType> *GetByIndex(unsigned const int index) const {
        const SortedLinkedListItem<valueType> *current = root;
        unsigned int i = 0;

        // Iterate until either the index has been reached, or the next item is null.
        while (current != 0 && i < index) {
            current = current->GetNext();
            i++;
        }
        return current;
    }

    /**
     * Returns the number of items in this list.
     * @return The number of items in this list.
     */
    unsigned int Count() const {
        const SortedLinkedListItem<valueType> *current = root;
        unsigned int i = 0;

        // Iterate until the next item is null, counting all the way.
        while (current != 0) {
            current = current->GetNext();
            i++;
        }
        return i;
    }

    /**
     * Adds the supplied item to this list, guaranteeing the list stays sorted.
     * @param item
     */
    void Add(SortedLinkedListItem<valueType> const *const item) {
        // If this list is empty, simply set root to the new item.
        if (root == 0) {
            root = item;
            return;
        }

        // If the new item is smaller than root, replace root with the new item and set the new item's next item to root.
        if (item->GetValue() < root->GetValue()) {
            item->SetNext(root);
            root = item;
            return;
        }

        SortedLinkedListItem<valueType> *previous = root;
        SortedLinkedListItem<valueType> *current = root->GetNext();

        // Iterate until the next item is null, or the current item is greater than the new item.
        while (current != 0 && item->GetValue() < current->GetValue()) {
            previous = current;
            current = current->GetNext();
        }

        // Now correctly set item and previous.
        item->SetNext(current);
        previous->SetNext(item);
    }
};

#endif //PROOF_OF_CONCEPT_TEMPLATES_SORTEDLINKEDLIST_HPP
