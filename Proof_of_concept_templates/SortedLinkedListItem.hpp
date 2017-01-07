#ifndef PROOF_OF_CONCEPT_TEMPLATES_SortedLinkedLISTITEM_HPP
#define PROOF_OF_CONCEPT_TEMPLATES_SortedLinkedLISTITEM_HPP

/**
 * The type of the contained value.
 */
template<class valueType>

/**
 * A sorted linked list item, containing a non-null value and a pointer to the next item.
 */
class SortedLinkedListItem {
private:
    /** This item's non-null value. */
    valueType value;

    /** The next item, which may be none (null). */
    SortedLinkedListItem<valueType> *next;
public:
    /** Constructor. */
    SortedLinkedListItem(valueType value) : value(value) {
        next = 0;
    }

    /** Destructor. Not responsible for cleaning up the next item. */
    ~SortedLinkedListItem() {}

    /**
     * Gets the next item.
     * @return The next item, or 0 if there is no next item.
     */
    SortedLinkedListItem<valueType> *GetNext() const {
        return this->next;
    }

    /**
     * Sets the next item.
     * @param next The next item.
     */
    void SetNext(SortedLinkedListItem<valueType> *const next) {
        this->next = next;
    }

    /**
     * Gets this item's value.
     * @return This item's value.
     */
    valueType GetValue() const {
        return this->value;
    }
};

#endif //PROOF_OF_CONCEPT_TEMPLATES_SortedLinkedLISTITEM_HPP
