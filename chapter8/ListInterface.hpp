/** @file ListInterface.hpp*/

#ifndef List_Interface_hpp
#define List_Interface_hpp

#include <iostream>

using namespace std;
template<class ItemType>
class ListInterface{
    public:

    /** Checks whether this list is empty.
     * @return true if list is empty, false otherwise.
    */
    virtual bool isEmpty() const = 0;
    /** Gives the current number of element within the list.
     * @returns the number of item in list.
    */
    virtual int getLength() const = 0;
    /** Inserts an entry into this list at a given position.
    @pre None.
    @post If 1 <= position <= getLength() + 1 and the insertion is
    successful, newEntry is at the given position in the list, other entries are renumbered accordingly, and the returned value is true.
    @param newPosition The list position at which to insert newEntry. @param newEntry The entry to insert into the list.
    @returns True if insertion is successful, or false if not. 
    */
    virtual bool insert(int newPosition, const ItemType& newEntry) = 0;
    /** Removes the entry at a given position from this list.
    @pre None.
    @post If 1 <= position <= getLength() and the removal is successful,
    the entry at the given position in the list is removed, other
    items are renumbered accordingly, and the returned value is true. @param position The list position of the entry to remove.
    @returns True if removal is successful, or false if not.
    */
    virtual bool remove(int position) = 0;
    /** Removes all entries from this list.
    @post List contains no entries and the count of items is 0.
    */
    virtual void clear() = 0;
    /** Gets the entry at the given position in this list. 
    @pre 1 <= position <= getLength().
    @post The desired entry has been returned.
    @param position The list position of the desired entry. @return The entry at the given position.
    */
    virtual ItemType getEntry(int position) const = 0;
    /** Replaces the entry at the given position in this list.
    @pre 1 <= position <= getLength().
    @post The entry at the given position is newEntry.
    @param position The list position of the entry to replace. @param newEntry The replacement entry. */
    virtual void setEntry(int position, const ItemType& newEntry) = 0;

    virtual ~ListInterface() = default;

};

#endif