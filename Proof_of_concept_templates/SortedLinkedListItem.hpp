#ifndef PROOF_OF_CONCEPT_TEMPLATES_SortedLinkedLISTITEM_HPP
#define PROOF_OF_CONCEPT_TEMPLATES_SortedLinkedLISTITEM_HPP

/**
 * The type of the contained value.
 */
template<class valueType>

/**
 * A sorted linked list item, containing a value and a pointer to the next item.
 */
class SortedLinkedListItem {
private:
    /** This item's value. */
    const valueType *const value;

    /** The next item. */
    const SortedLinkedListItem<valueType> *next;
public:
    /** Constructor. */
    SortedLinkedListItem(const valueType *const value) : value(value) {}

    /** Destructor. */
    virtual ~SortedLinkedListItem() {}

    /**
     * Returns whether or not this item has a succeeding item.
     * @return true if this item has a succeeding item, otherwise false.
     */
    bool HasNext() const {
        return next != 0;
    }

    /**
     * Gets the next item.
     * @return The next item.
     */
    const SortedLinkedListItem<valueType> *GetNext() const {
        return this->next;
    }

    /**
     * Sets the next item. Note that setting this manually may result in the list becoming unsorted.
     * @param next The next item.
     */
    void SetNext(SortedLinkedListItem<valueType> const *const next) {
        this->next = next;
    }

    /**
     * Gets this item's value.
     * @return This item's value, or 0 if it has none.
     */
    const valueType *GetValue() const {
        return this->value;
    }
};

#endif //PROOF_OF_CONCEPT_TEMPLATES_SortedLinkedLISTITEM_HPP
