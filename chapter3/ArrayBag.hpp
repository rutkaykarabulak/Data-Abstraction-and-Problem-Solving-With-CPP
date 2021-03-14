/** @file ArrayBag.hpp*/
#ifndef Array_Bag_hpp
#define Array_Bag_hpp

#include "BagInterface.hpp"
#include <iostream>
#include <vector>
using namespace std;

template<class ItemType>
class ArrayBag: public BagInterface<ItemType>{
private:
    static const int DEFAULT_CAPACITY = 5; // Small size to test for a full bag
    ItemType items[DEFAULT_CAPACITY]; // Array of bag items
    int itemCount; // Current count of bag items
    int maxItems; // max capacity of the bag

    // Returns either the index of the element in the array items that 
    // contains the given target or -1, if the array does not contain 
    // the target.
    int getIndexOf(const ItemType& anEntry) const;

public:
    ArrayBag(); // default constructor
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
}; // end ArrayBag
#endif

/** Implementation file */

template<class ItemType>
ArrayBag<ItemType>::ArrayBag()
: itemCount(0), maxItems(DEFAULT_CAPACITY)
{

} // end default constructor

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry){
    bool hasRoomToAdd = (itemCount<maxItems);
    if(hasRoomToAdd){
        items[itemCount] = newEntry;
        itemCount++;
    }
    return hasRoomToAdd;
} // end add

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const{
    vector<ItemType> v;

    for(int i=0; i<itemCount; i++)
        v.push_back(items[i]);
    return v;
} // end toVector

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const{
    return itemCount == 0;
} // end isEmpty

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const{
    return itemCount;
} // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>:: remove(const ItemType& anEntry){
    int index = getIndexOf(anEntry);
    bool canRemove = !isEmpty() && index>-1; // fail-safe programming
    if(canRemove){
        itemCount--;
        items[index] = items[itemCount];
    } // end if
    
    return canRemove;
} // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear(){
    itemCount = 0;
} // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
    int frequency = 0;
    if(isEmpty()){
        return 0;
    }else{
        int i = 0;
        while(i<itemCount){
            if(items[i] == anEntry){
                frequency++;
            }
            i++;
        } // end while
    }
    return frequency;
} // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const{
    // return getFrequencyOf(anEntry) > 0;
    // this one is so unpractical
    // we need to quit from the loop as soon as we've found the target that we are looking for
    return getIndexOf(anEntry)!=-1;
} // end contains

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& anEntry) const{
    int i = 0;
    int index = -1;

    while(i<itemCount){
        if(items[i] == anEntry){
            index = i;
            break;
        }
        i++;
    }
    return index;
} // end getIndexOf