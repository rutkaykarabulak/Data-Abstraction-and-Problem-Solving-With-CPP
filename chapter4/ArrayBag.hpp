//
//  ArrayBag.hpp
//  main
//
//  Created by Rutkay Karabulak on 12.10.2020.
//

#ifndef ArrayBag_hpp
#define ArrayBag_hpp

#include <stdio.h>
#include <iostream>
#include "BagInterface.hpp"
#include <vector>
using namespace std;

template <class ItemType>
class ArrayBag : public BagInterface<ItemType>{
private:
    static const int DEFAULT_CAPACIY = 6;
    ItemType items[DEFAULT_CAPACIY]; // Array of bag items
    int itemCount;
    int maxItems;
    // return -1 if the array doesn't contain that anEntry
    int getIndexOf(const ItemType& anEntry) const;
public:
    ArrayBag();
    ~ArrayBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
};

#endif /* ArrayBag_hpp */

// Implementation

template <class ItemType>
ArrayBag<ItemType>::ArrayBag(){
    itemCount = 0;
    maxItems = DEFAULT_CAPACIY;
} // end default constructor

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &newEntry){
    bool hasRoomToAdd = (itemCount < maxItems);
    if(hasRoomToAdd){
        items[itemCount] = newEntry;
        itemCount++;
    }
    return hasRoomToAdd;
} // end add

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const{
    vector<ItemType> bagContents;
    for(int i=0; i<itemCount; i++){
        bagContents.push_back(items[i]);
    }
    return bagContents;
}

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const{
    return itemCount;
}


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry){
    int locatedIndex = getIndexOf(anEntry);
    bool canRemove = (locatedIndex>-1 && !isEmpty());
    if(canRemove){
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }
    return canRemove;
} // end remove

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &anEntry) const{
    int indexOfEntry = getIndexOf(anEntry);
    bool isContain = indexOfEntry>-1;
    return isContain;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const{
    int frequency = 0;
    int currentIndex = 0;
    while(currentIndex!=itemCount){
        if(items[currentIndex] == anEntry)
            frequency++;
        
        currentIndex++;
    }
    return frequency;
}

template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &anEntry) const {
    int curIndex = 0;
    int index = -1;
    while(curIndex!=itemCount){
        if(items[curIndex] == anEntry){
            index = curIndex;
            break;;
        }else{
            curIndex++;
        }
    }
    return index;
}

template<class ItemType>
ArrayBag<ItemType>::~ArrayBag(){
    clear();
} 

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear