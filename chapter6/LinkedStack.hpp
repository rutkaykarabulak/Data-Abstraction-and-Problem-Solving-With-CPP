/** @file LinkedStack.hpp */
#ifndef Linked_Stack_hpp
#define Linked_Stack_hpp


#include "StackInterface.hpp"
#include <iostream>
#include <vector>
using namespace std;

template<class ItemType>
class LinkedStack: public StackInterface<ItemType>{
private:
    Node<ItemType>* topptr; // pointer that points to the top of the stack
    int             itemCount; // current item amount inside stack

public:
    LinkedStack();
    LinkedStack(const LinkedStack<ItemType>& aStack);
    ~LinkedStack();
    bool isEmpty() const;
    ItemType peek() const;
    bool push(const ItemType &anEntry);
    bool pop();
    void writeContent() const;
    vector<ItemType> to_vector() const;
    /**
Suppose that the ADT stack included a method remove(n) that removes the topmost n entries from a stack.
Specify this method by writing comments and a header.
Consider the various ways that the method could behave when the stack does not contain at least n entries.*/

    /** Removes topmost n entries from the stack
     * @pre stack must contain more or equal n element
     * @post topmost n element removed from stack
     * @returns true if deletion is successful, false otherwise.
    */
    bool remove(const int n);
}; // end LinkedStack

#endif

/** Implementation file */

template<class ItemType>
LinkedStack<ItemType>::LinkedStack():
topptr(nullptr),itemCount(0)
{
    // an empty stack initially
} // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack){
    itemCount = aStack.itemCount;
    vector<ItemType> content = aStack.to_vector();

    // create a new topptr
    topptr = new Node<ItemType>(content[content.size()-1]);

    // create a new node to link previous topptr
    Node<ItemType>* newNode = nullptr;
    for(int i=content.size()-2; i>=0; i--){
        // create a new node to link previous topptr
        newNode = new Node<ItemType>(content[i]);
        // link with previous topptr
        newNode->setNext(topptr);
        // new topptr
        topptr = newNode;
    } // end for
} // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack(){
    while(topptr!=nullptr){
        // save current topptr to delete later
        Node<ItemType>* nodeToDelete = topptr;
        // new topptr is topptr's next
        topptr = topptr->getNext();
        // break the link, fail-safe programming
        nodeToDelete->setNext(nullptr);
        // delete content of nodeToDelete
        delete nodeToDelete;
        nodeToDelete = nullptr;
    } // end while
    // now topptr is nullptr
    topptr = nullptr;
    itemCount = 0;
} // end destructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    // or return topptr==nullptr
    return itemCount==0;
} // end isEmpty

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    return topptr->getItem();
} // end peek

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    bool canRemove = topptr!=nullptr;

    if(canRemove){
        // nodeToDelete points to current top of stack
        Node<ItemType>* nodeToDelete = topptr;
        // new top is set to next of previous top
        topptr = topptr->getNext();
        // Break the link to avoid errors
        nodeToDelete->setNext(nullptr);
        // Removal
        delete nodeToDelete;
        nodeToDelete = nullptr;
        itemCount--;   
    } // not removable
    return canRemove;
} // end pop

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& anEntry){
    // Create a new node with a given anEntry
    Node<ItemType>* newNode = new Node<ItemType>(anEntry);
    // Set newNode's next to the previous top
    newNode->setNext(topptr);
    // new topptr is newNode
    topptr = newNode;
    // itemCount is increased by 1
    itemCount++;

    return true;
} // end push

template<class ItemType>
void LinkedStack<ItemType>::writeContent() const{
    Node<ItemType>* currentNode = topptr;

    while(currentNode!=nullptr){
        cout << currentNode->getItem() << " ";
        currentNode = currentNode->getNext();
    } // end while 
    // now currentNode is nullptr
    currentNode = nullptr;
} // end writeContent

template<class ItemType>
vector<ItemType> LinkedStack<ItemType>::to_vector() const{
    vector<ItemType> stackContents;
    Node<ItemType>* currentNode = topptr;

    while(currentNode!=nullptr){
        stackContents.push_back(currentNode->getItem());
        currentNode = currentNode->getNext();
    } // end while

    return stackContents;
}

template<class ItemType>
bool LinkedStack<ItemType>::remove(const int n){
    bool canRemove = topptr!=nullptr && itemCount>=n;
    int i=0;

    while(canRemove && i<n){
        i++;
        // hold current node to delete later
        Node<ItemType>* nodeToDelete = topptr;
        // new topptr
        topptr = topptr->getNext();
        // break the chain
        // fail-safe programming
        nodeToDelete->setNext(nullptr);
        // delete content of nodeToDelete
        delete nodeToDelete;
        nodeToDelete = nullptr;
        itemCount--;
    }

    return canRemove;
}