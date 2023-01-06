/** @file Node.cpp
 * Node is a component that holds both data and pointer to the next node.
*/

#ifndef Node_cpp
#define Node_cpp

#include <iostream>
using namespace std;

template<class ItemType>
class Node {
private:
    ItemType item; // data that node holds.
    Node<ItemType>* nextNode; // node that node itself points.
public:
    Node(); // default constructor
    Node(const ItemType& anItem); // constructor that creates node with an item
    Node(const ItemType& anItem, Node<ItemType>* nextNode);

    // returns item that node itself holds
    ItemType getItem() const;
    // returns next node of node itself points
    Node<ItemType>* getNext() const;
    // sets item to given item
    void setItem(const ItemType& anItem);
    // sets nextNode to given node
    void setNext(Node<ItemType>* nextNode);
};
#endif

// Implementation file 

template<class ItemType>
Node<ItemType>::Node():
nextNode(nullptr)
{

} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem):
item(anItem), nextNode(nullptr)
{

} // end parameterized constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr):
item(anItem), nextNode(nextNodePtr)
{

} // end parameterized constructor

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return nextNode;
} // end getNext

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    nextNode = nextNodePtr;
}