/** @file ArrayList.cpp*/
#ifndef Array_List_cpp
#define Array_List_cpp

#include "ListInterface.hpp"
#include "../components/DoublyNode.cpp"
#include <iostream>

using namespace std;
template<class ItemType>
class ArrayList: public ListInterface<ItemType> {
    private:
    static const int ITEM_CAPACITY = 10;
    ItemType* items;
    int itemCount;

    public: 
    ArrayList();
    ~ArrayList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newItem);
    bool remove(int position);
    void clear();
    ItemType getEntry(int positin) const;
    void setEntry(int position, const ItemType& newEntry);
    void display() const;

};

#endif

/** Implementation file*/

template<class ItemType>
ArrayList<ItemType>::ArrayList() {
    items = new ItemType[ITEM_CAPACITY];
    itemCount = 0;
}

template<class ItemType>
ArrayList<ItemType>::~ArrayList() {
    delete items;
    items = nullptr;
    itemCount = 0;
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newItem) {
    bool hasSpace = (itemCount != ITEM_CAPACITY) && (1<= newPosition <= itemCount + 1);
    // shift all entries towards en of the array to make space for new entry
    if(hasSpace) {
        for(int i=itemCount; i>=newPosition; i--) {
        items[i] = items[i-1];
        }
        items[newPosition - 1] = newItem;
        itemCount++;
    }
    return true;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (itemCount >= position);
    if(ableToRemove) {
        for(int i = position - 1; i < itemCount; i++) {
            items[i] = items[i + 1];
        }
        itemCount--;
    }

    return ableToRemove;
}

template<class ItemType>
void ArrayList<ItemType>::clear() {
    // STUB
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if(ableToGet) {
        return items[position - 1];
    } else {
        throw out_of_range("getEntry() is called with an empty list or invalid position.");
    }
}

template<class ItemType>
void ArrayList<ItemType>::setEntry(int position, const ItemType& newEntry) {
    bool ableToSet = (position >= 1 ) && (itemCount >= position);
    if(ableToSet) {
        items[position - 1 ] = newEntry;
    } else {
        throw out_of_range("setEntry() is called with an empty list or invalid position.");
    }
}

template<class ItemType>
void ArrayList<ItemType>::display() const {
    for(int i=0; i<itemCount; i++) {
        cout << items[i] << " ";
    }
}