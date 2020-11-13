/** @file ArrayStack.hpp
 * description = Implementation of ADT Stack by usin Arrays
*/

#ifndef Array_Stack_hpp
#define Array_Stack_hpp

#include <iostream>
#include "StackInterface.hpp"
#include <vector>
using namespace std;

const int MAX_SIZE = 6; // max size of stack array

template<class ItemType>
class ArrayStack: public StackInterface<ItemType>{
private:
    ItemType items[MAX_SIZE]; // Array of stack items
    int top; // index of top
    int itemCount; // Amount of items in curent stack

public:

    ArrayStack(); // default constructor

    // due to this class is not using dynamically memory, we don't need to implement exlicit destructor and copy constructor

    bool isEmpty() const;

    bool push(const ItemType& newEntry);

    bool pop();

    ItemType peek() const;
    
    vector<ItemType> toVector() const; // returns a vector that contains stack items from top to bottom 

    /*To the ADT stack given in this chapter, add a void method remove(n) that removes and discards the topmost n
    entries from a stack. Write a link-based implementation for this method.*/
    bool remove(const int n);

}; // end ArrayStack

#endif

/* IMPLEMENTATION FILE */

template<class ItemType>
ArrayStack<ItemType>::ArrayStack():
top(-1), itemCount(0)
{
    // Initiliazes an empty array stack
} // end default constructor

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const{
    return top==-1;
} // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry){
    if(itemCount == MAX_SIZE){
        throw logic_error("You can't push further more");
    } // end if

    // Stack is not full
    top++;
    items[top] = newEntry;
    itemCount++;
    return true;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop(){
    if(isEmpty()){
        throw logic_error("You can't pop from an empty stack");
    }

    // if stack is not empty
    top--;
    itemCount--;
    return true;
} // end pop

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const{
    if(isEmpty()){
        throw logic_error("You can't peek top of the stack while it's empty");
    }

    // you can check if it's not an empty stack
    return items[top];
} // end peek

template<class ItemType>
vector<ItemType> ArrayStack<ItemType>::toVector() const{
    int i = 0;
    vector<ItemType> aVector;
    for(i=top; i>=0 ; i--){
        aVector.push_back(items[i]);
    }
    return aVector;
}

template<class ItemType>
bool ArrayStack<ItemType>::remove(const int n){
    if(isEmpty() || n>itemCount){
        throw logic_error("remove(n) performed from an empty or in unsual conditions");
    }
    int i = 0;
    while(!isEmpty() && i<n){
        top--;
        itemCount--;
        i++;
    }
    return true;
}