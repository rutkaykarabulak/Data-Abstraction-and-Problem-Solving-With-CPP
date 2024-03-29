/** Interface for ADT sorted list
 * @file SortedListInterface.hpp
*/

#ifndef sorted_list_interface_hpp
#define sorted_list_interface_hpp

template<class ItemType>
class SortedListInterface {
public:
    /// @brief Inserts the new entry into the list's proper position
    /// so that list remains sorted.
    /// @param newEntry to be inserted.
    virtual void insertSorted(const ItemType& newEntry) = 0;

    /// @brief Removes the first occurance of given entry from the list.
    /// @param anItem to be removed.
    /// @return true if removal is successful, false otherwise.
    virtual bool removeSorted(const ItemType& anItem) = 0;

    /// @brief Returns the position of given entry in the list, or where it should have inserted.
    /// @param anItem 
    /// @return position of entry if it exists, 0 otherwise.
    virtual int getPosition(const ItemType& anItem) const = 0;

    /// @brief Removes the entry in given position if entry is in the list.
    /// @param position of the entry to be removed.
    /// @return true if removal is successful, false otherwise.
    virtual bool remove(int position) = 0;

    /// @brief Checks whether the list is empty or not.
    /// @return true if list is empty, false otherwise.
    virtual bool isEmpty() const = 0;

    /// @brief Gets the current number of items in this list.
    /// @return 
    virtual int getLength() const = 0;

    /// @brief Removes the all entries in the list.
    virtual void clear() = 0;

    /// @brief Gets the entry in the given position.
    /// @param position to be searched.
    /// @return Entry that is found.
    virtual ItemType getEntry(int position) const = 0;

    /// @brief Destructor
    virtual ~SortedListInterface() = default;

};
#endif