/** Interface for ADT sorted list
 * @file sortedListInterface.cpp
*/

#ifndef sorted_list_interface_cpp
#define sorted_list_interface_cpp

template<class ItemType>
class sortedListInterface {
public:
    /// @brief Inserts the new entry into the list's proper position
    /// so that list remains sorted.
    /// @param newEntry to be inserted.
    virtual void insertSored(const ItemType& newEntry) = 0;

    /// @brief Removes the first occurance of given entry from the list.
    /// @param anItem to be removed.
    /// @return true if removal is successful, false otherwise.
    virtual bool removeSorted(const ItemType& anItem) = 0;

    /// @brief Removes the entry in given position if entry is in the list.
    /// @param position of the entry to be removed.
    /// @return true if removal is successful, false otherwise.
    virtual bool remove(const int& position) = 0;

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
    virtual ItemType getEntry(const int& position) const = 0;

};
#endif