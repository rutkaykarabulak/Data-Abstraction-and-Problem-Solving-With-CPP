/** @file SortedListHasA.cpp 
 * This file is used to demonstrate sorted list implementation with ADT list
*/

#ifndef SortedListHasA_cpp
#define SortedListHasA_cpp
#include "./SortedListInterface.hpp"
#include "../chapter8/LinkedList.cpp"

template<class ItemType>
class SortedListHasA: public SortedListInterface<ItemType> {
private:
    ListInterface<ItemType>* list;
public:
    SortedListHasA();
    SortedListHasA(const SortedListHasA<ItemType>& sList);
    virtual ~SortedListHasA();

    void insertSorted(const ItemType& newItem);
    bool removeSorted(const ItemType& anItem);
    int getPosition(const ItemType& newEntry) const;

    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    void display() const;
};
#endif
// Implementation file

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA() {
    list = new LinkedList<ItemType>();
}

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& sList) {
    list = new LinkedList<ItemType>();
    for (int i = 1; i <= sList.getLength(); i++) {
        list->insert(1, sList->getEntry(i));
    }
}

template<class ItemType>
SortedListHasA<ItemType>::~SortedListHasA() {
    clear();
}

template<class ItemType>
void SortedListHasA<ItemType>::clear() {
    // stub
}

template<class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const{
    return list->isEmpty();
}

template<class ItemType>
int SortedListHasA<ItemType>::getLength() const {
    return list->getLength();
}

template<class ItemType>
bool SortedListHasA<ItemType>::remove(int position) {
    return list->remove(position);
}

template<class ItemType>
void SortedListHasA<ItemType>::insertSorted(const ItemType& newEntry) {
    int position = getPosition(newEntry);
    list->insert(position, newEntry);
} 

template<class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& anEntry) const {
    int position = 1;
    if (list->isEmpty()) {
        return 1;
    }
    while (position <= list->getLength() &&
    list->getEntry(position) < anEntry) {
        position++;
    }

    return position;
}

template<class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& anItem) {
    int position = getPosition(anItem);
    bool isExist = position <= list->getLength();
    if (isExist) {
        list->remove(position);
    }
    return isExist; // stub
}

template<class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const {
    return list->getEntry(position);
}

template<class ItemType>
void SortedListHasA<ItemType>::display() const {
    int position = 1;
    while (position <= list->getLength()) {
        std::cout << list->getEntry(position) << " ";
        position++;
    }
}