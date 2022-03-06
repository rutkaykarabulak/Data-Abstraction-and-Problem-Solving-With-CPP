/** @file LinkedList.cpp*/

#ifndef Linked_list_cpp
#define Linked_list_cpp
#include "ListInterface.hpp"
#include "../components/DoublyNode.cpp"
#include <string>


template<class ItemType>
class LinkedList: public ListInterface<ItemType> {
    private:
    DoublyNode<ItemType>* headPtr; // poins to the beginning of list.
    DoublyNode<ItemType>* tailPtr; // points to the end of list.
    int itemCount;
    /** Searches for an entry in given position if list is not empty.
     * @return the entry in given position.
    */
    DoublyNode<ItemType>* getNodePtr(int position) const; 

    public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    void setEntry(int position, const ItemType& newEntry);
    void display() const;
};
#endif

/** Implementation file */

template<class ItemType>
LinkedList<ItemType>::LinkedList() : 
headPtr(nullptr),
tailPtr(nullptr),
itemCount(0)
{
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}


template<class ItemType>
int LinkedList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    bool ableToAdd = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if(!ableToAdd) {
        throw out_of_range("Given position is not valid for inserting.");
    }
    // inserting head or tail of the list is easier then other inserting attempts.
    if (newPosition == 1) { // inserting to head
        DoublyNode<ItemType>* newNodePtr = new DoublyNode<ItemType>(newEntry);
        if(headPtr == nullptr) {
            headPtr = tailPtr = newNodePtr;
        } else {
            newNodePtr->setNext(headPtr);
            headPtr->setPrevious(newNodePtr);
            headPtr = newNodePtr;
        }
    } else if (newPosition == itemCount + 1) { // inserting to tail
        DoublyNode<ItemType>* newNodePtr = new DoublyNode<ItemType>(newEntry);
        tailPtr->setNext(newNodePtr);
        newNodePtr->setPrevious(tailPtr);
        tailPtr = newNodePtr;
    } else {
        DoublyNode<ItemType>* nodeToReplaced = getNodePtr(newPosition);
        DoublyNode<ItemType>* previousNodePtr = nodeToReplaced->getPrevious();

        DoublyNode<ItemType>* newNodePtr =
        new DoublyNode<ItemType>(newEntry, nodeToReplaced, previousNodePtr);
        // create the new chain.
        previousNodePtr->setNext(newNodePtr);
        nodeToReplaced->setPrevious(newNodePtr);
    }
    itemCount++;
    return ableToAdd;
}


template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && !isEmpty() && (itemCount >= position);
    if(ableToRemove) {
        // removing head or tail is easier then other deleting attemps as same as inserting.
        if(position == 1) {
            DoublyNode<ItemType>* nodeToDelete = headPtr;
            headPtr = headPtr->getNext();
            // break the chain
            headPtr->setPrevious(nullptr);
            nodeToDelete->setNext(nullptr);
            // delete the node
            delete nodeToDelete;
            nodeToDelete = nullptr; // fail-safe programming
        } else if(position == itemCount) {
            DoublyNode<ItemType>* nodeToDelete = tailPtr;
            tailPtr = tailPtr->getPrevious(); 
            // break the chain
            nodeToDelete->setPrevious(nullptr);
            tailPtr->setNext(nullptr);
            // delete the node
            delete nodeToDelete;
            nodeToDelete = nullptr; // fail-safe programming
        } else {
            DoublyNode<ItemType>* nodeToDelete = getNodePtr(position);
            DoublyNode<ItemType>* previousNodePtr = nodeToDelete->getPrevious();
            DoublyNode<ItemType>* nextNodePtr = nodeToDelete->getNext();
            // break the chain
            nodeToDelete->setNext(nullptr);
            nodeToDelete->setPrevious(nullptr);
            // create a new chain
            previousNodePtr->setNext(nextNodePtr);
            nextNodePtr->setPrevious(previousNodePtr);
            // delete the node
            delete nodeToDelete;
            nodeToDelete = nullptr; // fail-safe programming
        }
        itemCount--;
    } else {
        throw out_of_range("Trying to attemp remove from an empty list or invalid position.");
    }

    return ableToRemove; // STUB
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    while(!isEmpty()) {
        remove(1);
    }
}


template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    DoublyNode<ItemType>* entry = getEntry(position);
    return entry;
}


template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) {
    // STUB
}

template<class ItemType>
DoublyNode<ItemType>* LinkedList<ItemType>::getNodePtr(int position) const {
    bool ableToGet = (position >= 1) && (itemCount >= position) && !isEmpty();
    if(!ableToGet) {
        throw out_of_range("Given position is not valid to check if there is a entry in there.");
    }

    DoublyNode<ItemType>* currentNode = headPtr;
    for(int i = 0; i<position - 1; i++) {
        currentNode = currentNode->getNext();
    }
    return currentNode;
}

template<class ItemType>
void LinkedList<ItemType>:: display() const {
    DoublyNode<ItemType>* currentNode = headPtr;

    while(currentNode!=nullptr) {
        cout << currentNode->getItem() << " ";
        currentNode = currentNode->getNext();
    }
}