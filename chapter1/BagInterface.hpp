/** @file BagInterface.hpp */
#ifndef BagInterface_hpp
#define BagInterface_hpp

#include <vector>

template<class ItemType>
class BagInterface{
    public:
    /** Gets the current number of entries in bag.
    @return the integer number of entries currently in the bag*/
    virtual int getCurrentsize() const = 0;
    /** Sees whether bag is empty
     * @return True if the bag is empty, false otherwise
     */
    virtual bool isEmpty() const = 0:
    /** Adds a newEntry to the bag
     * @post If successful, newEntry is stored in the bag and the
     * count of items in the bag has increased by 1.
     * @param newEntry The object to be added as a new entry
     * @return True if addition is successful, false otherwise
     */
    virtual bool add(const ItemType& newEntry) = 0;
    /** Removes one occurrence of a given entry from this bag, if possible.
     * @post If successful, anEntry has been removed from the bag and the count of items in the bag has decreased by 1.
     * @param anEntry The entry to be removed.
     * @return True if removal was successful, or false if not. */
    virtual bool remove(const ItemType& anEntry) = 0;
    /** Removes all entries from this bag.
    @post Bag contains no items, and the count of items is 0. */
    virtual void clear() = 0;
    /** Counts the number of times a given entry appears in bag.
     * @param anEntry The entry to be counted.
     * @return The number of times anEntry appears in the bag. */
     virtual int getFrequencyOf(const ItemType& anEntry) = 0;
    /** Tests whether this bag contains a given entry.
     * @param anEntry The entry to locate.
     * @return True if bag contains anEntry, or false otherwise. */
    virtual bool contains(const ItemType& anEntry) const = 0;
    /** Empties and then fills a given vector with all entries that are in this bag.
     * @return A vector containing all the entries in the bag. */
    virtual vector<ItemType> toVector() const = 0;
}; // end BagInterface

#endif