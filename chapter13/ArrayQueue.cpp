/** @file ArrayQueue.cpp
 * Array based implementation of queue interface.
*/

#ifndef ArrayQueue_cpp
#define ArrayQueue_cpp
#include <stdexcept>
#include "QueueInterface.hpp"
#include <iostream>
const int MAX_ITEMS = 10; // for test purposes

template<class ItemType>
class ArrayQueue: public QueueInterface<ItemType> {
private:    
    int front; // index of front
    int back; // index of back
    int itemCount; // item amount in this queue.
    ItemType items[MAX_ITEMS];
public:
    ArrayQueue();
    // copy constructor and destructor is provided by compiler.
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    /** @throw PrecondViolatedExcep if queue is empty. */
    ItemType peek() const;
    
    void display() const;
};
#endif

// implementation file

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
    front = 0;
    back = MAX_ITEMS - 1;
    itemCount = 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newItem) {
    bool result = false;

    if (itemCount < MAX_ITEMS) {
        back = (back+1) % MAX_ITEMS;
        items[back] = newItem;
        itemCount++;
        result = true;
    }
    return result;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() {
    bool result = false;
    if (!isEmpty()) {
        front = (front+1) % MAX_ITEMS;
        itemCount--;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peek() const {
    if (isEmpty()) {
        throw std::logic_error("Empty array");
    }

    return items[front];
}



template<class ItemType>
void ArrayQueue<ItemType>::display() const{
    // todo
}