/** @file LinkedQueue.cpp 
 * Implementation of linked-based queue interface.
*/

#ifndef LinkedQueue_cpp
#define LinkedQueue_cpp

#include "./QueueInterface.hpp"
#include "../components/DoublyNode.cpp"
#include <iostream>
template<class ItemType>
class LinkedQueue: public QueueInterface<ItemType> {
private:
    DoublyNode<ItemType>* frontPtr; // points to the front of this queue.
    DoublyNode<ItemType>* backPtr;  // points to the back of this queue.
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<ItemType>& aQueue);
    virtual ~LinkedQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType& newItem);
    bool dequeue();
    ItemType peek() const;

    /// @brief Prints each element in this queue.
    void display() const;
};
#endif

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue():
frontPtr(nullptr),
backPtr(nullptr) 
{
    
}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& aQueue) {
    // will cover later
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {
    if (!isEmpty()) {
        DoublyNode<ItemType>* currentNode = frontPtr;
        DoublyNode<ItemType>* nodeToDelete = nullptr;
        while (currentNode != nullptr) {
            nodeToDelete = currentNode;
            currentNode = currentNode->getNext();
            delete nodeToDelete;
            nodeToDelete = nullptr;
        }
    }
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
    return (frontPtr == nullptr && backPtr == nullptr);
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newItem) {
    DoublyNode<ItemType>* newNodePtr = new DoublyNode<ItemType>(newItem);
    if (isEmpty()) {
        frontPtr = newNodePtr;
        backPtr = newNodePtr;
    } else {
        newNodePtr->setPrevious(backPtr);
        backPtr->setNext(newNodePtr);
        backPtr = newNodePtr;
    }
    return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    bool result = false;
    if (!isEmpty()) {
        DoublyNode<ItemType>* nodeToDelete = frontPtr;
        if (frontPtr == backPtr) {
            // special case
            frontPtr = nullptr;
            backPtr = nullptr;
        } else {
        frontPtr = frontPtr->getNext();
        // break the chain
        frontPtr->setPrevious(nullptr);
        nodeToDelete->setNext(nullptr);
        }
        // de-allocate
        delete nodeToDelete;
        nodeToDelete = nullptr;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peek() const{
    return frontPtr->getItem();
}

template<class ItemType>
void LinkedQueue<ItemType>::display() const {
    DoublyNode<ItemType>* currentNode = frontPtr;

    while (currentNode != nullptr) {
        std::cout << currentNode->getItem() << endl;
        currentNode = currentNode->getNext();
    }
}