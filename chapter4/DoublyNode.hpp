/** @file DoublyNode.hpp */

#ifndef Doubly_Node_hpp
#define Doubly_Node_hpp

#include <iostream>
using namespace std;

template<class ItemType>
class DoublyNode{

private:
ItemType item;
DoublyNode<ItemType>* next;
DoublyNode<ItemType>* previous;

public:

DoublyNode();
DoublyNode(const ItemType& anEntry);
DoublyNode(const ItemType& anEntry, DoublyNode<ItemType>* next,DoublyNode<ItemType>* previous);

void setItem(const ItemType& anItem);
void setNext(const DoublyNode<ItemType>* next)
void setPrevious(const DoublyNode<ItemType>* previous);
ItemType getItem() const;
DoublyNode<ItemType> getNext() const;
DoublyNode<ItemType> getPrevious() const;

};

#endif