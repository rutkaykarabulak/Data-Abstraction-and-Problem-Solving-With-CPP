#ifndef Linked_Bag_hpp
#define Linked_Bag_hpp

#include "Node.hpp"
#include "BagInterface.hpp"
#include <iostream>
using namespace std;

template<class ItemType>
class LinkedBag: public BagInterface<ItemType>{

private:
    Node<ItemType>* headptr; // pointer that points to head
    int             itemCount; // count of items in linked bag
    Node<ItemType>* tailptr; // pointer that points to end of the chain

    // returns null pointer if a target couldn't find in the linked bag
    Node<ItemType>* getPointerTo(const ItemType& target) const;

    // returns 0 if bag is empty, works recursively
    int sizeHelper(Node<ItemType>* currentNode, int itemSize) const;

    // returns 0 if given entry is not appearing in a bag, works recursively
    int frequencyHelper(Node<ItemType>* currentNode, const ItemType& anEntry, int frequency) const;

public:
LinkedBag();
LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
~LinkedBag();
int getCurrentSize() const;
bool isEmpty() const;
bool add(const ItemType& newEntry);
bool remove(const ItemType& anEntry);
void clear();
bool contains(const ItemType& anEntry) const;
int getFrequencyOf(const ItemType& anEntry) const;
vector<ItemType> toVector() const;
void writeContent() const;

}; // end linkedbag

#endif


// IMPLEMENTATION FILE 


template<class ItemType>
LinkedBag<ItemType>::LinkedBag(){
    headptr = nullptr;
    tailptr = nullptr;
    itemCount = 0;
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag){
    Node<ItemType>* originalHead = aBag.headptr;
    itemCount = aBag.itemCount;

    if(originalHead==nullptr){
        headptr = nullptr; // original bag is empty, so copy is;
    }else{ // Copy the original bag

        // new head of copied bag
        headptr = new Node<ItemType>(originalHead->getItem());

        // We're copying the original node that's why we have to point to the last node
        Node<ItemType>* newLastNode = headptr;
        // Advance the original head, traversing
        originalHead = originalHead->getNext();

        while(originalHead!=nullptr){
            // Create a new node from original bag
            Node<ItemType>* newNode = new Node<ItemType>(originalHead->getItem());
            // Now our previous last node "newLastNode" needs to point to new node
            newLastNode->setNext(newNode);
            // Now our current last node is "newNode"
            newLastNode = newLastNode->getNext();
            // advance originalHead
            originalHead = originalHead->getNext();
        } // end while
        // now newLastNode is point to nullPtr
        newLastNode->setNext(nullptr); // flag to end of chain
    } // end else
} //end copied constructor

// add node to end of the chain
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
Node<ItemType>* newNode = new Node<ItemType>();
    if(isEmpty()){ // If bag is empty
        // create a new node
        Node<ItemType>* newNode = new Node<ItemType>();
        // set newNode's item
        newNode->setItem(newEntry);
        // bag has only one item that's why tail and head points to same node
        headptr = tailptr = newNode;
        // itemCount increase by one
        itemCount++;
    }else{ // If bag contains more than one item
        // Create a new node
        Node<ItemType>* newNode = new Node<ItemType>();
        newNode->setItem(newEntry);
        // link tailptr with 'newNode'
        tailptr->setNext(newNode);
        // New tailptr is our newNode
        tailptr = tailptr->getNext();
        // itemCount increase 1
        itemCount++;
    }
    return true;
}

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const{
    vector<ItemType> bagContents;

    Node<ItemType>* currentNode = headptr;
    int counter = 0;
    while(currentNode!=nullptr && counter<itemCount){
        bagContents.push_back(currentNode->getItem());
        counter++;
        currentNode = currentNode->getNext();
    }

    return bagContents;

}
template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const{
return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
    /* 
    return itemCount; // first version of getCurrentSize();
    */

    // Recursive verison of getCurrent size
    int result = 0;
    result = sizeHelper(headptr,0);
    return result;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry)!=nullptr);
} // end contains

template<class ItemType>
void LinkedBag<ItemType>::clear(){
    Node<ItemType>* nodeToDelete = nullptr;

    while(headptr!=nullptr){
        nodeToDelete = headptr;
        headptr = headptr->getNext();
        // fail-safe programming
        nodeToDelete->setNext(nullptr);
        delete nodeToDelete;
    } // end while
    // now headptr is nullptr
    nodeToDelete = nullptr;
    itemCount = 0; 

    // Recursion version of clear
    //clearHelper(headptr);
} // end clear

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    Node<ItemType>* anEntryPtr = getPointerTo(anEntry);
    bool canRemove = !isEmpty() && anEntryPtr!=nullptr;

    if(canRemove){
        anEntryPtr->setItem(headptr->getItem());
        Node<ItemType>* nodeToDelete = headptr;
        headptr = headptr->getNext();
        // fail-safe programming
        nodeToDelete->setNext(nullptr);
        delete nodeToDelete;
        nodeToDelete = nullptr;
        itemCount--;    
    }

    return canRemove;
} // end remove


template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    int counter = 0 ;
    Node<ItemType>* currentNode = headptr;

    while(currentNode!=nullptr && counter<itemCount){
        if(currentNode->getItem() == anEntry)
            frequency++;
        currentNode = currentNode->getNext();
        counter++;
    }
    return frequency; 


    /* Recursive version of getFrequencyOf
    int result = 0;
    Node<ItemType>* currentNode = headptr;
    result = frequencyHelper(currentNode,anEntry,0);
    currentNode = nullptr;
    return result; */

} // end getFrequencyOf

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const{
    Node<ItemType>* currentNode = headptr;
    int counter = 0;
    while(currentNode!=nullptr&&counter<itemCount){
        if(currentNode->getItem() == target){
            return currentNode;
        }else{
            currentNode = currentNode->getNext();
            counter++;
        }
    }
    return currentNode;
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag(){
    clear();
}

template<class ItemType>
void LinkedBag<ItemType>::writeContent() const{
Node<ItemType>* currentNode = headptr;
int counter = 0;
while(currentNode!=nullptr && counter<itemCount){
    cout << currentNode->getItem() << " " ;
    counter++;
    currentNode = currentNode->getNext();
}
}

template<class ItemType>
int LinkedBag<ItemType>::sizeHelper(Node<ItemType>* currentNode, int itemSize) const{
    if(currentNode!=nullptr){
        currentNode = currentNode->getNext();
        itemSize = sizeHelper(currentNode,itemSize+1);
    } // end if
    // now currentNode is nullptr
    return itemSize;
}

template<class ItemType>
int LinkedBag<ItemType>::frequencyHelper(Node<ItemType>* currentNode, const ItemType& anEntry, int frequency) const{
    if(currentNode!=nullptr){
        if(currentNode->getItem() == anEntry){
            currentNode = currentNode->getNext();
            frequency = frequencyHelper(currentNode,anEntry,frequency+1);
        }else{
            currentNode = currentNode->getNext();
            frequency = frequencyHelper(currentNode,anEntry,frequency);
        }
    }
    return frequency;
}