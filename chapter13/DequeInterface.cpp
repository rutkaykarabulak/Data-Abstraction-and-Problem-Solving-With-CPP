/** @file DequeInterface.cpp
 * Interface for double ended queue.
*/

#ifndef DequeInterface_cpp
#define DequeInterface_cpp

template<class ItemType>
class DequeInterface {
public:
    /// @brief Pushes the new item back of this queue.
    /// @param newItem to be added to the back of this queue.
    virtual void push_back(const ItemType& newItem) = 0;

    /// @brief Pushes the new item back of this queue.
    /// @param newItem to be added to the back of this queue.
    virtual void push_front(const ItemType& newItem) = 0;

    /// @brief Removes anItem from the back of this queue.
    /// @param anItem to be removed.
    virtual void pop_back(const ItemType& anItem) = 0;

    /// @brief Removes anItem from the front of this queue.
    /// @param anItem to be removed.
    virtual void pop_front(const ItemType& anItem) = 0;

    /// @brief Returns the first item in this queue, aka item in front.
    /// @return The item in front of queue, throws an error if queue is empty.
    virtual ItemType peek() const = 0;

    /// @brief Checks whether the queue is empty or not.
    /// @return True if queue is empty, false otherwise.
    virtual bool isEmpty() const = 0;
};
#endif