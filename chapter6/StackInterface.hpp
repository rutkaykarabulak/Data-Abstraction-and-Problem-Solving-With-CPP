/** @file StackInterface.hpp */

#ifndef Stack_Interface_hpp
#define Stack_Interface_hpp

#include <iostream>
#include "Node.hpp"
using namespace std;

template <class ItemType>
class StackInterface{
public:
    virtual bool isEmpty() const = 0;

    virtual bool push(const ItemType& anEntry)  = 0;

    virtual bool pop() = 0;
    
    virtual ItemType peek() const =  0;

    virtual ~StackInterface() = default;
};

#endif
