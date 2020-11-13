/** @file LinkedStack.hpp
 * description: Implementation of ADT Stack by using Linked Nodes
*/

#ifndef Linked_Stack_hpp
#define Linked_Stack_hpp

#include <iostream>
#include "StackInterface.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"
using namespace std;
template<class ItemType>
class LinkedStack: public StackInterface<ItemType>{
private:
    Node<ItemType>* topptr; // pointer that points to the top of stack
    int itemCount; // holds amount of item in stack
public:
    
    // this class is using dynamically allocated memory, therefore we need explicit destructor and copy constructor
    LinkedStack(); // default constructor
    LinkedStack(const LinkedStack<ItemType>& aLinkedStack); // copy constructor
    ~LinkedStack(); // explicit destructor

    // Stack operations
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
    void display() const;
    //To the ADT stack given in this chapter, add a void method remove(n) that removes and discards the topmost n
    //entries from a stack. Write a link-based implementation for this method.
    bool remove(const int n);
}; // end LinkedStack
#endif

/* IMPLEMENTATION FILE */

template<class ItemType>
LinkedStack<ItemType>::LinkedStack():
topptr(nullptr), itemCount(0)
{
    // Initialize an empty stack
} // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aLinkedBag)
{
     Node<ItemType>* originalTopptr = aLinkedBag.topptr;
     itemCount = aLinkedBag.itemCount;
     if(originalTopptr == nullptr){
        topptr = nullptr; // if original topptr is null, so topptr
     }
     else // if original stack is not empty
     {
        topptr = new Node<ItemType>();
        topptr->setItem(originalTopptr->getItem());

        // pointer that points to last node in new Stack
        Node<ItemType>* lastPtr = topptr;
        while(originalTopptr!=nullptr){
            // advance originalTopptr
            originalTopptr = originalTopptr->getNext();
            // create a new node
            Node<ItemType>* newNodeptr = new Node<ItemType>();
            newNodeptr->setItem(originalTopptr->getItem());
            // create a link between lasptr
            lastPtr->setNext(newNodeptr);
            //now lastptr is newnode
            lastPtr = lastPtr->getNext();
        }// end while
        // now originaltopptr is nullptr
        lastPtr->setNext(nullptr); // flag end of chain

     }
     
} // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
    // pop until stack is empty
    while(!isEmpty()){
        pop();
    }
    /*The destructor given for the link-based implementation of the ADT stack calls pop. Although easy to write,
     this destructor can be inefficient due to repeated method calls.
    Write another implementation for the destructor that deallocates the linked nodes directly without calling pop.*/
    
} // end destructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    return topptr==nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){
    // Create a new node with a given entry
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    // Set newNodePtr's next node to topptr
    newNodePtr->setNext(topptr);

    // new topptr is newNodePtr
    topptr = newNodePtr;

    // re allocated the node
    newNodePtr = nullptr;
    // increase itemcount by one
    itemCount++;

    return true;   
} // end push

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    if(isEmpty()){
        throw PrecondViolatedExcep("pop() performed from an empty stack");
    }

    // stack is not empty, so you can pop from it
    
    // Hold information of node to be deleted
    Node<ItemType>* nodeToDelete = topptr;

    // set next topptr
    topptr = topptr->getNext();

    // break the link between topptr and previous top, fail-safe programming
    nodeToDelete->setNext(nullptr);

    // delete content of nodeToDelete
    delete nodeToDelete; // delete content of nodeToDelete
    nodeToDelete = nullptr;
    itemCount--;

    return true;
} // end pop

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    if(topptr==nullptr){
        throw PrecondViolatedExcep("peek() performed from an empty stack");
    }

    // Stack is not empty, now peek
    return topptr->getItem();
} // end peek

template<class ItemType>
void LinkedStack<ItemType>::display() const{
    if(isEmpty()){
        throw PrecondViolatedExcep("display() performed from an empty stack");
    }
    Node<ItemType>* currentNode = topptr;
    int i = 0; // counter
    while(currentNode!=nullptr && i<itemCount){
        cout << "("<<currentNode->getItem() << ")" << endl;
        i++;
        currentNode = currentNode->getNext();
    } // now current node points to the nullptr
}   // end display

template<class ItemType>
bool LinkedStack<ItemType>::remove(const int n){
    if(isEmpty() || n>itemCount){
        throw PrecondViolatedExcep("remove(n) performed from an empty stack or n is greater than item count in a stack");
    }

    // Conditions are okay, you can perform remove
    int i = 0;
    while(!isEmpty() && i<n){
        // Hold information of node to be deleted
    Node<ItemType>* nodeToDelete = topptr;
    // advance topptr
    topptr = topptr->getNext();
    // break the link between nodeToDelete and topptr, fail-safe programming
    nodeToDelete->setNext(nullptr);
    // delete content of nodeToDelete
    delete nodeToDelete;
    i++;
    } 
    
    return true;
}