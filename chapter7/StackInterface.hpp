/** @file StackInterface.hpp*/

#ifndef Stack_Interface_hpp
#define Stack_Interface_hpp

#include <iostream>
using namespace std;

template<class ItemType>
class StackInterface{

public:
    /** Sees whether stack is empty.
    @return true if stack is empty, false otherwise.
    */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the top of this stack.
    * @post If the operation is successful, newEntry is on top of the stack.
    * @param newEntry The object to be added as a new entry
    * @return True if addition is successful, false otherwise.
   */
    virtual bool push(const ItemType& newEntry) = 0;


    /** Removes the top of this stack.
    @post If the operation was successful, the top of the stack has been removed.
    @return True if the removal is successful or false if not. */
    virtual bool pop() = 0;

    /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and
    the stack is unchanged. @return The top of the stack. */
    virtual ItemType peek() const = 0;

    virtual ~StackInterface() = default;
}; // end StackInterace

#endif