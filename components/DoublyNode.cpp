/** @file DoublyNode.hpp
 * In a doubly linked chain, each node can point to the previous node as well as to the next node.
 * Figure 4-9 shows a doubly linked chain and its head pointer. Define a class to represent a node in a doubly linked chain.
*/
#ifndef Doubly_Node_cpp
#define Doubly_Node_cpp

#include <iostream>
using namespace std;

template<class ItemType>
class DoublyNode{
private:
    ItemType item; // item that holds a data.
    DoublyNode<ItemType>* next; // pointer that points to next DoublyNode
    DoublyNode<ItemType>* previous; // pointer that points to next DoublyNode
public:
    DoublyNode();
    DoublyNode(const ItemType& anItem);
    DoublyNode(const ItemType& anItem, DoublyNode<ItemType>* nextDoublyptr, DoublyNode<ItemType>* previousDoublyptr);
    // This class is not using dynamically allocated memory, therefore no need to either explicit destructor or copy constructor

    // sets item to given anItem
    void setItem(const ItemType& anItem);
    // sets next to given nextDoublyptr
    void setNext(DoublyNode<ItemType>* nextDoublyptr);
    // sets next to given previousDoublyptr
    void setPrevious(DoublyNode<ItemType>* previousDoublyptr);
    // returns current item of DoublyNode
    ItemType getItem() const;
    // returns next doublynode that current node points to
    DoublyNode<ItemType>* getNext() const;
    // returns previous doublynode that current node points to
    DoublyNode<ItemType>* getPrevious() const;
    

}; // end DoublyNode

#endif

// Implementation File

template<class ItemType>
DoublyNode<ItemType>::DoublyNode():
next(nullptr), previous(nullptr)
{

} // end default constructor

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem):
item(anItem), next(nullptr), previous(nullptr)
{

} // end paramaterized constructor

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& anItem, DoublyNode<ItemType>* nextDoublyptr, DoublyNode<ItemType>* previousDoublyptr):
item(anItem), next(nextDoublyptr), previous(previousDoublyptr)
{

} // end paramaterized constructor

template<class ItemType>
void DoublyNode<ItemType>::setItem(const ItemType& anItem){
    item = anItem;
} // end setItem

template<class ItemType>
void DoublyNode<ItemType>::setNext(DoublyNode<ItemType>* nextDoublyptr){
    next = nextDoublyptr;
} // end setNext

template<class ItemType>
void DoublyNode<ItemType>::setPrevious(DoublyNode<ItemType>* previousDoublyptr){
    previous = previousDoublyptr;
} // end setPrevious

template<class ItemType>
ItemType DoublyNode<ItemType>::getItem() const{
    return item;
} // end getItem

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getNext() const{
    return next;
} // end getNext

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getPrevious() const{
    return previous;
} // end getPrevious

