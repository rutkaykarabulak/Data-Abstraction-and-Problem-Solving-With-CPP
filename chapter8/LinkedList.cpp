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
    LinkedList(const LinkedList<ItemType>* list);
    ~LinkedList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool append(const ItemType& newEntry); // it adds the given element to the end of list.
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
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>* list) {
    DoublyNode<ItemType>* originalHeadPtr = list->headPtr;
    DoublyNode<ItemType>* originalTailPtr = list->tailPtr;
    itemCount = list->itemCount;
    if(originalHeadPtr == nullptr) { // original bag is empty, so is copy
        headPtr = tailPtr = nullptr;
        itemCount = 0;
    } else {
        DoublyNode<ItemType>* currentNode = originalHeadPtr;
        headPtr = new DoublyNode<ItemType>(currentNode->getItem()); // initiliaze a new headptr
        
        DoublyNode<ItemType>* lastNodePtr = headPtr;
        currentNode = currentNode->getNext(); // advance the current node
        while(currentNode != nullptr && currentNode!=originalTailPtr) {
            // create a new node
            DoublyNode<ItemType>* newNodePtr = new DoublyNode<ItemType>(currentNode->getItem());
            // create a chain
            lastNodePtr->setNext(newNodePtr);
            newNodePtr->setPrevious(lastNodePtr);
            // new lastNodePtr
            lastNodePtr = newNodePtr;
            // advance currentNode
            currentNode = currentNode->getNext();
        }
        // now it's end of the original list
        tailPtr = new DoublyNode<ItemType>(originalTailPtr->getItem());
        lastNodePtr->setNext(tailPtr);
        tailPtr->setPrevious(lastNodePtr);
    }
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
    DoublyNode<ItemType>* entry = getNodePtr(position);
    return entry->getItem();
}


template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) {
    bool ableToGet = (position >= 1) && (itemCount >= position) && !isEmpty();
    if(!ableToGet) {
        throw out_of_range("setEntry() is called with an empty list or invalid position.");
    }
    DoublyNode<ItemType>* nodeToSet = getNodePtr(position);
    nodeToSet->setItem(newEntry);
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

template<class ItemType>
bool LinkedList<ItemType>::append(const ItemType& newItem) {
    bool success = false;
    if ((headPtr == nullptr) && (tailPtr == nullptr)) {
        // insertion will be the first item
        DoublyNode<ItemType>* newNodePtr = new DoublyNode<ItemType>(newItem);

        headPtr = tailPtr = newNodePtr;
        itemCount++;
        
        success = true;
    } else {
        DoublyNode<ItemType>* newNodePtr = new DoublyNode<ItemType>(newItem);
        tailPtr->setNext(newNodePtr);
        newNodePtr->setPrevious(tailPtr);
        tailPtr = newNodePtr;

        itemCount++;

        success = true;
    }

    return success;
}