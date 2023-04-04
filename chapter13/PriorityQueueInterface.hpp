/** @file PriorityQueueInterface.hpp
 * The file that represents interface of PriorityQueue.
*/

#ifndef PriorityQueueInterface_hpp
#define PriorityQueueInterface_hpp

template<class ItemType>
class PriorityQueueInterface {
public:
    /// @brief Checks whether this queue is empty or not.
    /// @return True if queue is empty, false otherwise.
    virtual bool isEmpty() const = 0;

    /// @brief Adds a new item to the this queue depending on its priority
    /// @param newItem to be added this queue.
    /// @return True if inserting is successfull, false otherwise.
    virtual bool add(const ItemType& newItem) = 0;

    /// @brief Removes the entry with the highest priority from this queue.
    /// @return True if removal is successfull, false otherwise.
    virtual bool remove() = 0;

    /// @brief Checks for the entry in this queue with the highest priority.
    /// @return The highest priority item.
    virtual ItemType peek() const = 0;
};

#endif