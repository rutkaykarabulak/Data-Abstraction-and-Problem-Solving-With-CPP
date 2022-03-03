/** @file ListInterface.hpp*/

#ifndef List_Interface_hpp
#define List_Interface_hpp

#include <iostream>

using namespace std;
template<class ItemType>
class ListInterface{
    public:

    virtual bool isEmpty() const = 0;
    
    virtual int getLength() const = 0;

    virtual bool insert(const int& newPosition, const ItemType& newEntry) = 0;

    virtual bool remove(const int& position) = 0;

    virtual void clear() ;

    virtual ItemType getEntry() const = 0;

    virtual void setEntry(const int& position, const ItemType& newEntry) = 0;

    virtual ~ListInterface() = default;

};

#endif