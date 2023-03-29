/** @file SortedListIsA.cpp 
 * This class is used to represent sorted list representation as a linkedlist.
*/

#ifndef SortedListIsA_cpp
#define SortedListIsA_cpp

#include "../chapter8/LinkedList.cpp"

template<class ItemType>
class SortedListIsA: public LinkedList<ItemType> {
public:
    SortedListIsA();
    SortedListIsA(const SortedListIsA<ItemType>& sList);
    virtual ~SortedListIsA();

    void insertSorted(const ItemType& newEntry);
    bool removeSorted(const ItemType& anEntry);
    int getPosition(const ItemType& anEntry) const;

    // the inhertied methods remove, clear, getEntry, isempty, and 
    // getLength have the specifications as given in ListINterface.

    // The following methods must be overriden to disable their
    // effect on a sorted list;
    bool insert(int newPosition, const ItemType& newEntry); 
    void setEntry(int position, const ItemType& newEntry);
};
#endif

// Implementation file 

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA() {}

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA(const SortedListIsA<ItemType>& sList):
LinkedList<ItemType>(sList) {}

template<class ItemType>
SortedListIsA<ItemType>::~SortedListIsA() {
    std::cout << "Destructor is called" << " ";
}

template<class ItemType>
void SortedListIsA<ItemType>::insertSorted(const ItemType& newEntry) {
    LinkedList<ItemType>::insert(getPosition(newEntry), newEntry);
}

template<class ItemType>
bool SortedListIsA<ItemType>::removeSorted(const ItemType& anEntry) {
    int position = getPosition(anEntry);
    bool isExist = position <= LinkedList<ItemType>::getLength();
    if (!LinkedList<ItemType>::isEmpty() && isExist) {
        LinkedList<ItemType>::remove(position);
    }
    return isExist;
}

template<class ItemType>
int SortedListIsA<ItemType>::getPosition(const ItemType& anEntry) const{
    int position = 1;
    if (LinkedList<ItemType>::isEmpty()) {
        return 1;
    }
    while (position <= LinkedList<ItemType>::getLength() &&
    LinkedList<ItemType>::getEntry(position) < anEntry) {
        position++;
    }

    return position;
}

template<class ItemType>
bool SortedListIsA<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    return false;
}

template<class ItemType>
void SortedListIsA<ItemType>::setEntry(int position, const ItemType& newEntry) {
    // stub
}
